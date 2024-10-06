#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

// estrutura do nó da árvore
typedef struct No{
    int valor;
    struct No *esq, *dir, *p;
    int cor;

} No;

typedef struct RedBlackTree {
    No *raiz; // ponteiro pra raiz da árvore
  //No *NIL;  Nó sentinela
} RedBlackTree;

No* criaNo(int valor){

    No* no = (No*)malloc(sizeof(No)); 
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    no->p = NULL;
    no->cor = RED; // nó novo é sempre vermelho

    return no;
}

// inicializando a árvore
RedBlackTree* inicializar() {
    RedBlackTree *tree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    tree->raiz = NULL;
    return tree;
}


void giraEsquerda(RedBlackTree *tree, No* A){
    No *B = A->dir;
    A->dir = B->esq;
    if(B->esq != NULL){
        B->esq->p = A;
    }
    B->p = A->p;
    
    if(A->p == NULL){
        tree->raiz = B; // B é a nova raiz
    } else if (A == A->p->esq)
    {
        A->p->esq = B;
    }else {
        A->p->dir = B;
    }
    B->esq = A;
    A->p = B;
}

void giraDireita(RedBlackTree *tree, No* B){
    No *A = B->esq;
    B->esq = A->dir;
    if (A->dir != NULL) {
        A->dir->p = B;
    }
    A->p = B->p;
    if (B->p == NULL) {
        tree->raiz = A; // A é a nova raiz
    } else if (B == B->p->dir) {
        B->p->dir = A;
    } else {
        B->p->esq = A;
    }
    A->dir = B;
    B->p = A;
}

void arrumar(RedBlackTree* tree, No* k) {
    while (k != tree->raiz && k->p->cor == RED) { 
        
        if (k->p == k->p->p->esq) { // Se o pai de k é filho à esquerda:
            No* u = k->p->p->dir; // Então o tio de k é o filho à direita do avô

            // Caso 1: O tio de k é vermelho
            if (u != NULL && u->cor == RED) {
                k->p->cor = BLACK;    // Pai de k se torna preto
                u->cor = BLACK;       // Tio de k se torna preto
                k->p->p->cor = RED;   // Avô de k se torna vermelho
                k = k->p->p;          // Continuar a verificação a partir do avô
            } else { // Caso 2: Tio de k é preto
                if (k == k->p->dir) { // E k é filho à direita
                    k = k->p;
                    giraEsquerda(tree, k); // Rotação à esquerda no pai
                }
                // Caso 3: Tio de k é preto e k é filho à esquerda
                k->p->cor = BLACK;
                k->p->p->cor = RED;
                giraDireita(tree, k->p->p);
            }

        } else { // Caso simétrico: pai de k é filho à direita
            No* u = k->p->p->esq; // Tio de k é o filho à esquerda do avô

            // Caso 1: O tio de k é vermelho
            if (u != NULL && u->cor == RED) {
                k->p->cor = BLACK;    // Pai de k se torna preto
                u->cor = BLACK;       // Tio de k se torna preto
                k->p->p->cor = RED;   // Avô de k se torna vermelho
                k = k->p->p;          // Continuar a verificação a partir do avô
            } else { // Caso 2: Tio de k é preto
                if (k == k->p->esq) { // E k é filho à esquerda
                    k = k->p;
                    giraDireita(tree, k); // Rotação à direita no pai
                }
                // Caso 3: Tio de k é preto e k é filho à direita
                k->p->cor = BLACK;
                k->p->p->cor = RED;
                giraEsquerda(tree, k->p->p);
            }
        }
    }
    // A raiz da árvore deve sempre ser preta
    tree->raiz->cor = BLACK;
}

No* insere(RedBlackTree *tree, int valor) {
    No *no = criaNo(valor);
    if (tree->raiz == NULL) {
        no->cor = BLACK; // A raiz é sempre preta
        tree->raiz = no;
    } else {
        No *current = tree->raiz;
        No *p = NULL;

        while (current != NULL) {
            p = current;
            if (no->valor < current->valor) {
                current = current->esq;
            } else {
                current = current->dir;
            }
        }
        no->p = p;
        if (no->valor < p->valor) {
            p->esq = no;
        } else {
            p->dir = no;
        }
    
        // Corrigir a árvore após a inserção
        arrumar(tree, no);
    }
}

int altura(No *no) {
    if (no == NULL) {
        return -1;   
    }
    
    int alturaEsq = altura(no->esq);
    int alturaDir = altura(no->dir);

    //retorna 0 sem o +1 porque a raiz ta nula
    // Retorna a maior altura entre as duas subárvores, mais 1 para incluir o nó atual
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}


void contaCor(No *no, int *contaVermelho, int *contaPreto){
    if (no == NULL) {
        return;
    }
    if (no->cor == RED) {
        (*contaVermelho)++;
    } else {
        (*contaPreto)++;
    }

    contaCor(no->esq, contaVermelho, contaPreto);
    contaCor(no->dir, contaVermelho, contaPreto);
    
}


// Função para imprimir a árvore (em-ordem)
void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d" " ", raiz->valor);
        emOrdem(raiz->dir);
    }
}


int main(){
    RedBlackTree *tree = inicializar();
    //RedBlackTree tree;
    //tree.raiz = NULL;
    
    int n;
        for (int i = 0; i < 13; i++) {
            scanf("%d", &n);
            insere(tree, n);
    }

    printf("Percurso em ordem: ");
    emOrdem(tree->raiz);
    printf("\n");

    // Exibindo a raiz
    printf("Raiz: %d\n", tree->raiz->valor);

    // Exibindo a altura da árvore
    printf("Altura: %d\n", altura(tree->raiz));


    int contaVermelho = 0, contaPreto = 0;
    contaCor(tree->raiz, &contaVermelho, &contaPreto);
    printf("Quantidade de nós vermelhos: %d\n", contaVermelho);
    printf("Quantidade de nós pretos: %d\n", contaPreto);
    // Exibindo a quantidade de nós vermelhos
     
    return 0;
}




