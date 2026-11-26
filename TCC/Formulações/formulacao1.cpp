#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ilcplex/ilocplex.h>

using namespace std;
ILOSTLBEGIN

ILOMIPINFOCALLBACK3(Callback_mipinfo, double&, lb, double&, ub, double&, gap) {/// Callback nomeada Callback_mipinfo com 3  argumentos do tipo double
	ub = getBestObjValue(); // Melhor lower bound da árvore de B&C
	if(lb < getIncumbentObjValue()){
		lb = getIncumbentObjValue(); // Valor da melhor solução incumbent (solução incumbent corrente)  encontrada durante o B&C
	} 
	gap = getMIPRelativeGap();
}

int main (int argc, char *argv[]){
    try{

		/**============================
		 *  Leitura dos dados
		 *=============================== */
		ifstream arq(argv[1]);
		if (!arq.is_open()){
			cout << "Error openning file: " << argv[1] << endl;
			arq.close();
			exit(EXIT_FAILURE);
		}
		
		int n; // Quantidade de nós
		arq >> n;
		float alpha; // Fator de desconto no custo de transporte em um link entre hubs
		vector<double >  codx(n); // Coordenada x dos nós (AP)
		vector<double >  cody(n); // Coordenada y dos nós (AP)
  	vector<vector<double > > w(n, vector<double>(n)); // declara um vetor de vetores para representar uma matriz com n linhas e n colunas - Quantidade de demanda a ser enviada entre os nós i e j
  	vector<vector<double > > r(n, vector<double>(n)); // Receita obtida por enviar uma unidade de demanda entre os nós i e j
  	vector<vector<double > > c(n, vector<double>(n)); // Custos por enviar uma unidade de demanda entre os nós i e j
  	vector<vector<double > > q(n, vector<double>(n)); // Custos operação de uma conexão direta entre os nós i e j
  	vector<double > s(n); // Custos fixos de instalação de um hub
  	vector<vector<double > > g(n, vector<double>(n)); // Custos de operação nos links inter-hubs
  	double soma = 0.0; // Soma para obter a média geral dos custos fixos de instalação hub - Dados AP
		
		for (int i = 0; i <  n; i++){ //Coletar demanda e custos CAB
		  for (int j = 0; j < n; j++){
		    arq >> w[i][j];
		    arq >> c[i][j];
		    soma = soma + w[i][j];
		  }
		}

		for (int i = 0; i <  n; i++){ //Escalonando demanda CAB
		  for (int j = 0; j < n; j++){
		    w[i][j] = w[i][j]/soma;
		  }
		}

		if (argc >= 3) //Coletar fator de desconto nos links inter-hubs CAB
		  alpha = atof(argv[2]);
		else alpha = 0.2;

		for (int i = 0; i <  n; i++){ //Coletar receita CAB
		  for (int j = 0; j < n; j++){
		    r[i][j] = atoi(argv[3]);
		  }
		}

		for (int i = 0; i <  n; i++){ //Coletar custo fixo de instalação CAB
		  s[i] = atoi(argv[4]);
		  }


		for (int i = 0; i <  n; i++){ //Coletar custo de operar links inter-hubs CAB
		  for (int j = 0; j < n; j++){
		    g[i][j] = atoi(argv[5]);
		  }
		}


		IloEnv env;
		IloModel mod(env);
		IloCplex cplex(mod);
	
		
		IloArray<IloNumVarArray> x(env, n); // ILOBOOL x[i][k] indica se o nó i foi alocado ao hub k
		for(int k = 0; k < n; k++){   
		  x[k] = IloNumVarArray(env, n, 0, 1, ILOBOOL); 
		}
		
		IloArray<IloNumVarArray> z(env, n); // ILOBOOL z[k][l] indica se um link inter-hub é operado entre os hubs l e k
		for(int k = 0; k < n; k++){   
			z[k] = IloNumVarArray(env, n, 0, 1, ILOBOOL); 
		}
		
		IloArray<IloArray<IloArray<IloNumVarArray> > > y(env, n); // ILOBOOL y[i][j][k][l] indica se a demanda entre os nós i e j é atendida através do caminho com primerio hub k e último hub l
		for(int i = 0; i < n; i++){
		  y[i] = IloArray<IloArray<IloNumVarArray> >(env, n);
		  for(int j = 0; j < n; j++){
		    y[i][j] = IloArray<IloNumVarArray>(env, n);
		    for(int k=0; k<n; k++){
		      y[i][j][k] = IloNumVarArray(env, n, 0, 1, ILOBOOL);  
		    }
		  }
		}
		
		IloArray<IloArray<IloNumVarArray> > f(env, n); // f[i][k][l] representa a quantidade de demanda originada no nó i e roteada no link inter hub k-l
		for(int i = 0; i < n; i++){
		  f[i] = IloArray<IloNumVarArray>(env, n);
		  for(int k = 0; k < n; k++){
		    f[i][k] = IloNumVarArray(env, n, 0, IloInfinity, ILOFLOAT);
		  }
		}

		
		
		// ====================================Formulação 1=================================================
		// maximize sum(i in 1..n, j in 1..n, k in 1..n, l in 1..n) r[i][j] * w[i][j] * y[i][j][k][l] 
		// - [ sum(i in 1..n, j in 1..n, k in 1..n, l in 1..n) (c[i][k] + c[l][j])*  w[i][j] * y[i][j][k][l]
		// + sum(i in 1..n, k in 1..n, l in 1..n) alpha * c[i][j] * f[i][k][l] +  sum(k in 1..n) s[k] * x[k][k] 
		// + sum(k in 1..n, l in 1..n) g[k][l] * z[k][l] ];
		// =================================================================================================

		IloExpr expfo(env);
		for (int k = 0; k <  n; k++){
			expfo -= s[k] * x[k][k];
			for(int l = 0; l < n; l++){
				expfo -=  g[k][l] * z[k][l];
			  for(int i = 0; i < n; i++){
			    expfo -= alpha * c[k][l] * f[i][k][l];
			    for(int j = 0; j < n; j++){
			      expfo += (r[i][j] -  c[i][k] - c[l][j]) * w[i][j] * y[i][j][k][l]; 
			    }
			  }
			}
		}  

		IloAdd(mod, IloMaximize(env, expfo));
		expfo.end();

		//===========================================================================
		// forall(i in 1..n, j in 1..n)  sum(k in 1..n, l in 1..n) y[i][j][k][l] <= 1 
		//===========================================================================
		for (int i = 0; i < n; i++){
		  for (int j =0; j < n; j++){
		  IloExpr r1(env);
		    for (int k = 0; k < n; k++){
		      for (int l = 0; l < n; l++){
		        r1 += y[i][j][k][l];
		      }
		    }
		    mod.add(r1 <= 1);
		    r1.end();
		  }
		}
		
		//========================================================================================================================================================================================================
		// forall(i in 1..n)  sum(k in 1..n) x[i][k] <= r (r alocação)
		//========================================================================================================================================================================================================
		for (int i = 0; i < n; i++){
		  IloExpr r5(env);
		  for (int k =0; k < n; k++){
		    r5 += x[i][k];  
		      }
		    mod.add(r5 <= 1);
		    r5.end();
		  }
		
		//===================================================
		// forall(i in 1..n, k in 1..n)  x[i][k] <= x[k][k]
		//===================================================
		for (int i = 0; i < n; i++){
		  for (int k = 0; k < n; k++){
		    mod.add(x[i][k] <= x[k][k]);
		  }
		}
		
		//===================================================================================================================
		// forall(i in 1..n, j in 1..n, k in 1..n, m in 1..n) y[i][j][k][m] <= x[i][k]
		//===================================================================================================================
		for (int i = 0; i < n; i++){
		  for (int j =0; j < n; j++){
		    for (int k =0; k < n; k++){
		      for (int m =0; m < n; m++){
		        mod.add(y[i][j][k][m] <= x[i][k]);
		      }
		    }
		  }
		}
		
		//===================================================================================================================
		// forall(i in 1..n, j in 1..n, k in 1..n, m in 1..n) y[i][j][k][m] <= x[j][m]
		//===================================================================================================================
		for (int i = 0; i < n; i++){
		  for (int j =0; j < n; j++){
		    for (int k =0; k < n; k++){
		      for (int m =0; m < n; m++){
		        mod.add(y[i][j][k][m] <= x[j][m]);
		      }
		    }
		  }
		}
		
		//========================================================================================================================================================================================================
		// forall(i in 1..n, k in 1..n)  sum(l in 1..n, l!k) f[i][l][k] + sum(j in 1..n, l in 1..n) w[i][j] * y[i][j][k][l]  == sum(l in 1..n, l!k) f[i][k][l] + sum(j in 1..n, l in 1..n) w[i][j] * y[i][j][l][k]
		//========================================================================================================================================================================================================
		for (int i = 0; i < n; i++){
		  for (int k =0; k < n; k++){
		    IloExpr r3(env);
		      for (int l = 0; l < n; l++){
		        if (l != k){
		          r3 += f[i][l][k] - f[i][k][l];  
		        }
		        for (int j = 0; j < n; j++){
		          r3 += w[i][j] * y[i][j][k][l] - w[i][j] * y[i][j][l][k];
		        }
		      }
		      mod.add(r3 == 0);
		      r3.end();
		  }
		}
		
		//=============================================================================================
		// forall(i in 1..n, k in 1..n, l in 1..n, l!k)  f[i][k][l] <= sum(j in 1..n) w[i][j] * z[k][l]
		//=============================================================================================
		for (int i = 0; i < n; i++){
		  for (int k =0; k < n; k++){
		    for (int l =0; l < n; l++){
		      if (l!=k){
		      IloExpr r4(env);
		        r4 += f[i][k][l];
		        for (int j = 0; j < n; j++){
		          r4 -= w[i][j] * z[k][l];
		        }		        		        
		        mod.add(r4 <= 0);
		        r4.end();
		      }
		    }
		  }
		}
		
		//===================================================
		// forall(k in 1..n, l in 1..n, l!k)  z[k][l] <= x[k][k]
		//===================================================
		for (int k = 0; k < n; k++){
		  for (int l = 0; l < n; l++){
		    if (l!=k)
		    mod.add(z[k][l] <= x[k][k]);
		  }
		}
		
		//===================================================
		// forall(k in 1..n, l in 1..n, l!k)  z[k][l] <= x[l][l]
		//===================================================
		for (int k = 0; k < n; k++){
		  for (int l = 0; l < n; l++){
		    if (l != k)
		    mod.add(z[k][l] <= x[l][l]);
		  }
		}
		
        cplex.setParam(IloCplex::EpGap, 0.0000001); // Definindo uma tolerancia
		    cplex.setParam(IloCplex::TiLim, 86400); // Tempo limite de resolução
		    cplex.setWarning(env.getNullStream()); // Eliminar warnings
		//  cplex.setOut(mono->env.getNullStream()); // Eliminar os logs do solver
		//  cplex.setParam(IloCplex::Threads, 4); // Definir a quantidade de threads
		 // cplex.setParam(IloCplex::Param::Benders::Strategy, 3); // Ativar Benders do solver


        IloTimer crono(env);// Variável para coletar o tempo
        double lb = 0; /// Callback_mipinfo
        double ub = 10e-10; /// Callback_mipinfo
        double gap; /// Callback_mipinfo
	      //double gap = 1; /// Callback_mipinfo
		    //cplex.use(Callback_mipinfo(env, lb, ub, gap));/// Callback_mipinfo

		    
		    for(int i = 0; i< n; i++){   //Pré-fixando variáveis
		      for(int j = 0; j < n; j++){
		        for(int k = 0; k < n; k++){
		          for(int l = 0; l < n; l++){
		            if ( r[i][j] < (c[i][k]+c[l][j]) )
		              y[i][j][k][l].setBounds(0, 0);
		          }
		        }
		      }
		    }
          
        crono.start();
        cplex.solve();
        crono.stop();
       
        if(cplex.getStatus() == IloAlgorithm::Optimal){
            lb = cplex.getObjValue();
            ub = cplex.getObjValue();
            gap = 0.0;
        }
        
        printf("%s\t%d\t%1.2f\t%1.2f\t%1.2f\t%1.2f\t%1.6f\n",  argv[1], n, alpha,  100 *  gap,  lb, ub, (double) crono.getTime());

        cout << " Valor função objetivo: " << cplex.getObjValue () << endl ;

        printf("Hubs Instalados:");
        for(int j = 0; j < n; j++){
          if( cplex.getValue(x[j][j]) >= 0.1){
            printf(" %d\t ", j+1);
          }
        }
        cout<<endl;


        /**=====================================
         *  Apresenta a configuração final
         * ====================================*/

        FILE *re;
        re = fopen("ResultadosF1unica.txt","aw+");
        fprintf(re, "\n Informações Gerais: " "%s\t%d\t%1.2f\t%1.2f\t%1.2f\t%1.2f \n",  argv[1], n, alpha,  r[0][0],  s[0], g[0][0] );
        fprintf(re, "\n Valor função objetivo: " "%f\t \n", (double) cplex.getObjValue ());
        fprintf(re, "\n Tempo de CPU: " "%f\t \n", (double) crono.getTime());
        // fprintf(re, "\n lb: " "%1.2f\t \t" "ub: " "%1.2f\t \t" "gap: " "%1.2f \n", lb, ub, 100 *  gap);
        fprintf(re, "\n Hubs: \n" );
        for(int j = 0; j < n; j++){
          if( cplex.getValue(x[j][j]) >= 0.1){
            fprintf(re, "%d\t \n", j+1);
          }
        }
          fprintf(re, "\n \n ====================================================================== \n \n");
    } 
    catch (IloException& ex) {
        cerr << "Error: " << ex << endl;
    }
    return 0;

}
