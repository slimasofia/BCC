// 1195 - BEECROWD
// link pro exercício: https://www.beecrowd.com.br/repository/UOJ_1195.html?origem=1

#include <iostream>
#include <sstream> 
#include <vector> 
using namespace std;

/* 
Criando a estrutura da árvore: cada nó é composto por um valor e dois ponteiros 
que representam a subárvore da esquerda e a subárvore da direita.
O construtor inicializa a variável valor com o valor que será passado ao alocar um nó, e ambos os 
ponteiros são inicializados como NULL. 
*/

struct No {
    int valor;
    No* esq;
    No* dir;
    No(int valor) : valor(valor), esq(NULL), dir(NULL) {}
};

/* 
Função que insere os valores na árvore.
Os argumentos raiz e valor representam, respectivamente, 
a raiz da subárvore onde o valor será inserido e o valor que será adicionado à árvore.
*/

No* insere(No* raiz, int valor) { 
    // se a raiz está vazia, um novo nó é alocado com o valor passado 
    if (raiz == NULL) {
        return new No(valor);
    }
    
    // caso a raiz não seja nula, é verificado se o valor que 
    // será inserido é menor que o valor na raiz atual, se sim, o valor é inserido na subárvore da esquerda (seguindo as propriedades da bst)
    if (valor < raiz->valor) {
        raiz->esq = insere(raiz->esq, valor);
    }
    // se o valor que se quer inserir é maior que o valor da raiz atual, o valor será inserido à direita
    else if (valor > raiz->valor) {
        raiz->dir = insere(raiz->dir, valor);
    }
    return raiz;
}

/* 
   PERCURSOS
   Existem três tipos de percursos em árvores binárias: pré-ordem, em ordem e pós-ordem. 
   A diferença entre os percursos está no momento em que o nó pai é visitado.

   Nas funções de percurso está sendo utilizando um vetor para armazenar os valores, 
   apenas para formatar corretamente a saída pro beecrowd  

*/

//Função que executa o percurso em Pré-ordem: o pai é visitado antes dos filhos, então o percurso é Pai-Esquerda-Direita.
void pre(No* raiz, vector<int>& valores) {  
    if (raiz != NULL) {                   // se a raiz não for nula
        valores.push_back(raiz->valor);   // armazena o valor da raiz 
        pre(raiz->esq, valores);          // a função é chamada recursivamente, agora processando os valores à esquerda da raiz
        pre(raiz->dir, valores);          // a função é chamada recursivamente, agora processando os valores à direita da raiz
    }
}

// Função que executa o percurso em Em ordem: o pai é visitado entre os filhos, então o percurso é Esquerda-Pai-Direta.
void in(No* raiz, vector<int>& valores) {
    if (raiz != NULL) {                   // se a raiz não for nula
        in(raiz->esq, valores);           // a função é chamada recursivamente, processando os valores à esquerda da raiz
        valores.push_back(raiz->valor);   // armazena o valor da raiz 
        in(raiz->dir, valores);           // a função é chamada recursivamente, agora processando os valores à direita da raiz
    }
}

// Função que executa o percurso em Pós-ordem: o pai é visitado depois dos filhos, então o percurso é Esquerda-Direta-Pai.
void post(No* raiz, vector<int>& valores) {
    if (raiz != NULL) {                   // se a raiz não for nula
        post(raiz->esq, valores);         // a função é chamada recursivamente processando os valores à esquerda da raiz
        post(raiz->dir, valores);         // a função é chamada recursivamente, agora processando os valores à direita da raiz
        valores.push_back(raiz->valor);   // armazena o valor da raiz 
    }
}

int main() {
    // coletando o número de casos que serão executados
    int casosTeste;
    cin >> casosTeste;

    // Armazenar os resultados de cada caso (para formatar corretamente a saída printando os casos apenas após todas as entradas)
    ostringstream resultados;

    for (int i = 0; i < casosTeste; i++) { // para cada caso
        No* raiz = NULL;                  // a raiz é inicializada como nula para garantir que cada caso de teste começa com uma árvore vazia, 
                                          // evitando que os dados de um caso afetem os outros.

        // coletando a quantidade de nós que a árvore terá
        int n;
        cin >> n;

        /*       
        Itera n vezes, onde n é o número de nós da árvore.
        Em cada iteração, um valor é lido da entrada, e a função 'insere' o adiciona na árvore.
        A raiz da árvore é atualizada conforme os nós são inseridos.
        */

        for (int j = 0; j < n; j++) {
            int numero;
            cin >> numero;
            raiz = insere(raiz, numero);
        }

        // Armazenando na string os 3 percursos para cada caso.
        resultados << "Case " << i + 1 << ":" << endl;

        resultados << "Pre.: "; 
        vector<int> preValores;  // Vetor para armazenar os valores do percurso pré-ordem
        pre(raiz, preValores);   // chamando a função com os valores armazenados
        for (size_t k = 0; k < preValores.size(); k++) {
            if (k > 0) resultados << " ";  // Adiciona um espaço apenas entre os números (para evitar erro na saída 
                                           // por conta de espaço após o último número de cada linha)
            resultados << preValores[k];   // Imprime os valores
        }
        resultados << endl; 

        resultados << "In..: ";
        vector<int> inValores;              // Vetor para armazenar os valores do percurso em ordem
        in(raiz, inValores);
        for (size_t k = 0; k < inValores.size(); k++) {
            if (k > 0) resultados << " ";   // Adiciona um espaço apenas entre os números
            resultados << inValores[k];     // Imprime os valores
        }
        resultados << endl; 

        resultados << "Post: ";
        vector<int> postValores;            // Vetor para armazenar os valores do percurso pós-ordem
        post(raiz, postValores);
        for (size_t k = 0; k < postValores.size(); k++) {
            if (k > 0) resultados << " ";   // Adiciona um espaço apenas entre os números
            resultados << postValores[k];   // Imprime os valores
        }
        resultados << endl;

        resultados << endl; // Adiciona uma linha em branco após cada caso
    }

    // Imprimindo todos os resultados após coletar todos os dados
    cout << resultados.str();

    return 0;
}