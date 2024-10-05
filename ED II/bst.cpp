#include <iostream>
using namespace std;

/* 
criando a estrutura da árvore: cada nó é composto por um valor (inteiro nesse caso), e dois ponteiros 
que representam a subárvore da esquerda e a subárvore da direita
O construtor inicializa a variável valor com o valor que será passado ao alocar um nó, e ambos os 
ponteiros são inicializados como NULL. 
*/

struct No{
    int valor;
    No* esq;
    No* dir;
    No(int valor) : valor(valor), esq(NULL), dir(NULL) {}
};

    /* 
    Função que insere os valores na árvore
    Os argumentos raiz e valor representam, respectivamente, 
    a raiz da subárvore onde o valor será inserido e o valor que será adicionado à árvore.
    */

No* insere(No* raiz, int valor){ 
    // se a raiz está vazia, um novo nó é alocado com o valor passado 
    if (raiz == NULL){
        return new No(valor);
    }
    
    // caso a raiz não seja nula, é verificado se o valor que 
    // será inserido é menor que o valor na raiz atual, se sim, o valor é inserido na subárvore da esquerda
    if (valor < raiz->valor){
        raiz->esq = insere(raiz->esq, valor);
    }
    
    // se o valor que se quer inserir é maior que o valor da raiz atual, o valor será inserido `s direita
    else if(valor > raiz->valor){
        raiz->dir = insere(raiz->dir, valor);
    }
    return raiz;
}

/* 
PERCURSOS

   Existem três tipos de percursos em árvores binárias: pré-ordem, em ordem e pós-ordem. 
   A diferença entre os percursos está no momento em que o nó pai é visitado.

   Função que executa o percurso em Pré-ordem: o pai é visitado antes dos filhos, então o percurso é Pai-Esquerda-Direta.
   Essa função não retorna nada e seu único argumento é a raiz  
   
*/

void pre(No* raiz){    
    if (raiz != NULL){              // se a raiz não for nula
        cout << raiz->valor << " "; // o valor da raiz será impresso seguido por um espaço
        pre(raiz->esq);             // a função é chamda recursivamente, agora processando os valores à esquerda da raiz
        pre(raiz->dir);             // a função é chamda recursivamente, agora processando os valores à direita da raiz
    }
}

// Função que executa o percurso em Em ordem: o pai é visitado entre os filhos, então o percurso é Esquerda-Pai-Direta.
void in(No* raiz){
    if (raiz != NULL){
        in(raiz->esq);
        cout << raiz->valor << " ";
        in(raiz->dir);
    }
}

// Função que executa o percurso em Pós-ordem: o pai é visitado depois dos filhos, então o percurso é Esquerda-Direta-Pai.
void post(No* raiz){
    if (raiz != NULL){
        post(raiz->esq);
        post(raiz->dir);
        cout << raiz->valor << " ";
    }
}

int main(){

    // coletando o número de casos que serão executados
    int casosTeste;
    cin >> casosTeste;

    for (int i = 0; i < casosTeste; i++){ // para cada caso
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

        // Mostrando na tela os 3 percursos para cada caso.
        cout << "Case " << i + 1 << ":" << endl;

        cout << "Pre.: "; 
        pre(raiz);
        cout << endl; 

        cout << "In..: ";
        in(raiz);
        cout << endl; 

        cout << "Post: ";
        post(raiz);
        cout << endl;

        cout << endl;
    }

    return 0;
}
