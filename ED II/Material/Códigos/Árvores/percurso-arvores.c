#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int val;
    struct No* esq;
    struct No* dir;
} No;

No* novoNo(int val) {
    No* no = (No*)malloc(sizeof(No));
    no->val = val;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->val);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->val);
        emOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->val);
    }
}

int main() {
    
    No* raiz = novoNo(1);
    raiz->esq = novoNo(2);
    raiz->dir = novoNo(3);
    raiz->esq->esq = novoNo(4);
    raiz->esq->dir = novoNo(5);

    printf("Travessia pré-ordem: ");
    preOrdem(raiz);
    printf("\n");
 
    printf("Travessia em-ordem: ");
    emOrdem(raiz);
    printf("\n");
 
    printf("Travessia pós-ordem: ");
    posOrdem(raiz);
    printf("\n");
    return 0;
}