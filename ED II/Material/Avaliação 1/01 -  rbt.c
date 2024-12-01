#include <stdio.h>
#include <stdlib.h>

// definindo as variáveis que representam as cores dos nós
#define RED 1
#define BLACK 0

// estrutura doe um nó da árvore
typedef struct No{              // composta por:
    int valor;                  // o valor do nó
    struct No *esq, *dir, *p;   // ponteiros para os filhos da esquerda, da direita e para o pai
    int cor;                    // cor do nó
} No;

// estrutura da árvore: contém um ponteiro do tipo No para a raiz da árvore
typedef struct RedBlackTree {
    No *raiz; 
} RedBlackTree;

// Função para criar um nó a partir do valor passado
No* criaNo(int valor){
    No* no = (No*)malloc(sizeof(No)); // alocando o nó
    no->valor = valor;                // o atributo valor do no criado é o que é passado como argumento da função
    // os ponteiros para esquerda, direita e para o pai são inicializados com NULL
    no->esq = NULL;
    no->dir = NULL;
    no->p = NULL;
    no->cor = RED; // um nó novo é sempre vermelho
    return no;     // a função retorna o nó criado
}

/*
Função para rotacionar à direita
recebe como argumentos um ponteiro para a árvore e o nó B que precisa ser rotacionado
O objetivo da rotação à direita é tornar o filho esquerdo de 'B' o novo pai de 'B'.
*/
void giraDireita(RedBlackTree *tree, No* B){ 
    No *A = B->esq;     // Para isso, 'A' é definido como o novo nó raiz da subárvore onde 'B' estava
    B->esq = A->dir;    // O filho à direita de 'A' se torna o filho à esquerda de 'B'
    

    // Se 'A' tem um filho à direita, após a rotação, esse filho passará a ser o filho 
    // esquerdo de 'B'
    if (A->dir != NULL) { // se o filho á direita de 'A' não for NULL, 
        A->dir->p = B;    // o pai dele passa a ser 'B'
    }

    A->p = B->p; // O pai de 'A' passa a ser o antigo pai de 'B'

    if (B->p == NULL) {             // Se 'B' era raiz da árvore (pai == NULL),
        tree->raiz = A;             // 'A' é a nova raiz da árvore.
    } else if (B == B->p->dir) {    // Se 'B' era filho à direita do seu pai, 
        B->p->dir = A;              // agora o filho à direita do pai de 'B' é 'A'.
    } else {                        // Se 'B' era filho à esquerda do seu pai, 
        B->p->esq = A;              // agora o filho à esquerda do pai de 'B' é 'A'.
    }
    // 'B' se torna o filho à direita de 'A'
    A->dir = B;
    // O pai de 'B' passa a ser 'A'
    B->p = A;
}


/*
Função para rotacionar à esquerda (simétrica à anterior)
Recebe como argumentos um ponteiro para a árvore e o nó A que precisa ser rotacionado
*/
void giraEsquerda(RedBlackTree *tree, No* A){
    No *B = A->dir;
    A->dir = B->esq;
    if(B->esq != NULL){
        B->esq->p = A;
    }
    B->p = A->p;
    
    if(A->p == NULL){
        tree->raiz = B; 
    } else if (A == A->p->esq)
    {
        A->p->esq = B;
    }else {
        A->p->dir = B;
    }
    B->esq = A;
    A->p = B;
}

/* 
Função para arrumar as possíveis violações na árvore rubro-negra após a inserção.
Não seguir uma das propriedades baixo implica em uma violação na estrutura da árvore rubro-negra):
- Os nós folha são sempre pretos.
- A raíz é preta.
- Um nó novo é sempre vermelho
- Nenhum nó vermelho pode ter um pai vermelho.

X é um nó que foi inserido e que pode causar alguma violação.
A função considera 3 casos para "arrumar" considerando o tio e o pai de X e se X é um filho à esquerda ou à direita.
*/

void arrumar(RedBlackTree* tree, No* X) {           // recebe como argumentos um ponteiro para tree e um ponteiro para o nó X
    while (X != tree->raiz && X->p->cor == RED) {   // o laço continua enquanto: X não for raiz da árvore e o pai de X for vermelho
        
        if (X->p == X->p->p->esq) { // Se o pai de X é filho à esquerda:
            No* u = X->p->p->dir;   // Então o tio de X é o filho à direita do avô

            // Caso 1: O tio de X é vermelho
            if (u != NULL && u->cor == RED) {
                X->p->cor = BLACK;    // Pai de X se torna preto
                u->cor = BLACK;       // Tio de X se torna preto
                X->p->p->cor = RED;   // Avô de X se torna vermelho
                X = X->p->p;          // Continua a verificação a partir do avô
            
            // Caso 2: Tio de X é preto
            } else { 
                if (X == X->p->dir) {   // E X é filho à direita
                    X = X->p;           // X agora é igual ao seu pai; o nó que será rotacionado (o pai de X) agora se torna o nó X, 
                                        //de forma que a rotação seja feita no nó correto.
                    giraEsquerda(tree, X); // Rotação à esquerda no pai
                }

                // Caso 3: Tio de X é preto e X é filho à esquerda
                X->p->cor = BLACK; // após a rotação o pai de X se torna preto
                X->p->p->cor = RED; // e o avô de X se torna vermelho
                // Nova rotação agora à direita: o pai de X (agora preto) toma o lugar do avô de X, 
                //e o avô se move para a direita como o novo filho do pai de X. 
                giraDireita(tree, X->p->p); 
            }

        } else { // Se o pai de X for filho à direita (simétrico ao If):
            No* u = X->p->p->esq; // Tio de X é o filho à esquerda do avô

            // Caso 1: O tio de X é vermelho
            if (u != NULL && u->cor == RED) {
                X->p->cor = BLACK;    // Pai de X se torna preto
                u->cor = BLACK;       // Tio de X se torna preto
                X->p->p->cor = RED;   // Avô de X se torna vermelho
                X = X->p->p;          // Continua a verificação a partir do avô

            } else { // Caso 2: Tio de X é preto
                if (X == X->p->esq) {       // E X é filho à esquerda
                    X = X->p;               // X se torna igual ao seu pai
                    giraDireita(tree, X);   // Rotação à direita no pai
                }
                // Caso 3: Tio de X é preto e X é filho à direita
                X->p->cor = BLACK;
                X->p->p->cor = RED;
                giraEsquerda(tree, X->p->p);
            }
        }
    }
    // A raiz da árvore deve sempre ser preta
    tree->raiz->cor = BLACK;
}

// Função para inserir um novo nó
No* insere(RedBlackTree *tree, int valor) { // recebe um ponteiro para a árvore e o valor a ser inserido
    No *no = criaNo(valor);                 // cria um novo nó e armazena em 'no'
    if (tree->raiz == NULL) {               // se a raiz da árvore for nula,
        no->cor = BLACK;                    // O nó a ser inserido será preto,
        tree->raiz = no;                    // já que ele será a raiz da árvore

    } else {                                // se a raiz não for nula
        No *aux = tree->raiz;               // cria um ponteiro auxiliar que guarda a raiz da árvore para buscar a posição adequada onde o nó será inserido
        No *p = NULL;                       // ponteiro para ir armazenando a referência ao pai do novo nó

        while (aux != NULL) {               // Continua até que o ponteiro aux chegue a uma posição nula (local para inserir o novo nó)
            p = aux;                        // A cada iteração, p é atualizado para o nó atual em aux antes de aux ir para a esquerda ou direita
            if (no->valor < aux->valor) {   // se o valor do nó a ser inserido é menor que o valor do nó atual (aux),
                aux = aux->esq;             // continua buscando à esquerda
            } else {                        // se o valor do nó a ser inserido for maior ou igual ao valor do nó atual,
                aux = aux->dir;             // continua buscando à direita
            }
        }
        no->p = p;                          // o ponteiro 'p' é o pai do novo nó, então define 'p' como o pai do novo nó
        if (no->valor < p->valor) {         // se o valor do novo nó for menor que o valor de 'p'
            p->esq = no;                    // insere o novo nó como o filho à esquerda de 'p'
        } else {                            // caso contrário,
            p->dir = no;                    // insere o novo nó como o filho à direita de 'p'
        }
    
        // Corrigir a árvore após a inserção
        arrumar(tree, no);                  
    }
}

// Função para calcular a altura de um nó
int altura(No *no) {
    if (no == NULL) { // se um nó não existe,
        return -1;    // sua altura é -1  
    }
    
    int alturaEsq = altura(no->esq); // chama recursivamente a função 'altura' para calcular a altura da subárvore esquerda
    int alturaDir = altura(no->dir); // chama recursivamente a função 'altura' para calcular a altura da subárvore direita

    // utilizando um operador ternário para comparar as alturas calculadas, se alturaEsq for maior retorna alturaEsq + 1, 
    // caso contrário retorna alturaDir  +1
    // (+1 para contar o prórprio nó)
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

// Função para contar o número de nós vermelhos e pretos na árvore
void contaCor(No *no, int *contaVermelho, int *contaPreto) {
    if (no == NULL) {   // Se o nó é nulo, 
        return;         // só retorna já que não há nó para contar
    }

    if (no->cor == RED) {    // Se o nó é vermelho,
        (*contaVermelho)++;  // incrementa o contador de nós vermelhos
    } else {                 // Se o nó não é vermelho,
        (*contaPreto)++;     // incrementa o contador de nós pretos.
    }

    // Chama recursivamente a função para contar os nós nas subárvores esquerda e direita.
    contaCor(no->esq, contaVermelho, contaPreto);
    contaCor(no->dir, contaVermelho, contaPreto);
}

// Função para imprimir a árvore em ordem (esquerda, raiz, direita)
void emOrdem(No *raiz) {
    if (raiz != NULL) {                 // Se o nó não é nulo,
        emOrdem(raiz->esq);             // visita a subárvore esquerda primeiro (recursivamente),
        printf("%d" " ", raiz->valor);  // depois imprime o valor do nó atual (raiz),
        emOrdem(raiz->dir);             // por último visita a subárvore direita.
    }
}

int main() {
    RedBlackTree tree;  // Inicializa a árvore
    tree.raiz = NULL;   // Define que a árvore começa com a raiz nula (vazia)
    
    int n;
    // Loop para inserir os 13 valores na árvore
    for (int i = 0; i < 13; i++) {
        scanf("%d", &n);        // Lê um valor inteiro
        insere(&tree, n);       // Insere o valor na árvore
    }

    // Exibindo o percurso em ordem
    printf("Percurso em ordem: ");
    emOrdem(tree.raiz);  // Chama a função para imprimir a árvore em ordem
    printf("\n");

    // Exibindo o valor da raiz
    printf("Raiz: %d\n", tree.raiz->valor);  // Imprime o valor armazenado na raiz da árvore

    // Exibindo a altura da árvore
    printf("Altura: %d\n", altura(tree.raiz));  // Chama a função 'altura' e imprime a altura da árvore a partir da raiz

    int contaVermelho = 0, contaPreto = 0;  
    contaCor(tree.raiz, &contaVermelho, &contaPreto);               // Conta quantos nós vermelhos e pretos existem
    printf("Quantidade de nós vermelhos: %d\n", contaVermelho);     // Imprime o número de nós vermelhos
    printf("Quantidade de nós pretos: %d\n", contaPreto);           // Imprime o número de nós pretos

    return 0;
}
