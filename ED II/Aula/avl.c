#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    int altura;
    struct No *esq, *dir;
} No;

No* criaNo(int valor) {
    No* no = (No*)malloc(sizeof(No)); 
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 0; // Inicialmente a altura é 0 (um nó folha)
    return no;
}

int alturaNo(No* no) {
    if (no == NULL)
        return -1;
    return no->altura;
}

// Atualizar a altura do nó
int max(int a, int b) {
    return (a > b) ? a : b;
}

// o fator de balanceamento é dado por: 
// se o nó não existir, o fb é -1; se o nó existir o fb é dado pela altura do filho à esquerda menos a altura do filho à direita
int fatorBalanceamento(No* no) {
    if (no == NULL)
        return -1;
    return alturaNo(no->esq) - alturaNo(no->dir);
}

// Rotação à direita
No* rotacaoDireita(No* y) {

    // y é o nó desbalanceado e que precisa ser rotacionado.
    // x é o filho esquerdo de y.
    // T1 é a subárvore esquerda de x.
    // T2 é a subárvore direita de x.

    No* x = y->esq; // 'x' se torna a nova raiz da subárvore que antes era a esquerda de 'y'
    No* T2 = x->dir; // 'T2' é a subárvore direita de 'x', que será movida para ser a subárvore esquerda de 'y' após a rotação

    // à direita de x agora teremos y e à esquerda de y teremos T2
    // Realiza a rotação: 'x' sobe, 'y' desce para a direita
    x->dir = y;  // A subárvore direita de 'x' agora será o próprio 'y'
    y->esq = T2; // A subárvore esquerda de 'y' agora será 'T2', que era a subárvore direita de 'x'

    // Atualiza as alturas dos nós 'y' e 'x' após a rotação
    y->altura = max(alturaNo(y->esq), alturaNo(y->dir)) + 1; 
    // A altura de 'y' agora é 1 mais a altura máxima entre suas subárvores esquerda e direita

    x->altura = max(alturaNo(x->esq), alturaNo(x->dir)) + 1;
    // A altura de 'x' agora é 1 mais a altura máxima entre suas subárvores esquerda e direita

    // Retorna 'x' como a nova raiz da subárvore rotacionada
    return x;
}

No* rotacaoEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = max(alturaNo(x->esq), alturaNo(x->dir)) + 1;
    y->altura = max(alturaNo(y->esq), alturaNo(y->dir)) + 1;

    // Retorna a nova raiz
    return y;
}

No* insere(No* raiz, int valor) {
    if (raiz == NULL)
        return criaNo(valor);

    if (valor < raiz->valor)
        raiz->esq = insere(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = insere(raiz->dir, valor);
    else
        return raiz; 

    //Atualiza a altura do nó atual
    raiz->altura = 1 + max(alturaNo(raiz->esq), alturaNo(raiz->dir));

    //Verifica o fator de balanceamento para ver se o nó ficou desbalanceado
    int balance = fatorBalanceamento(raiz);

    // Casos de desbalanceamento:

    // Caso 1: Rotação à direita (esquerda-esquerda)
    if (balance > 1 && valor < raiz->esq->valor)
        return rotacaoDireita(raiz);

    // Caso 2: Rotação à esquerda (direita-direita)
    if (balance < -1 && valor > raiz->dir->valor)
        return rotacaoEsquerda(raiz);

    // Caso 3: Rotação dupla (esquerda-direita)
    if (balance > 1 && valor > raiz->esq->valor) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    // Caso 4: Rotação dupla (direita-esquerda)
    if (balance < -1 && valor < raiz->dir->valor) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

No* buscaValor(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscaValor(raiz->esq, valor);

    return buscaValor(raiz->dir, valor);
}

int main() {
    No* raiz = NULL;

    raiz = insere(raiz, 15);
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 8);
    raiz = insere(raiz, 12);
    raiz = insere(raiz, 25);
    raiz = insere(raiz, 30);  // Vai desbalancear e ser corrigido

    // Exemplo de busca
    // No* x = buscaValor(raiz, 25);
    // No* y = buscaValor(raiz, 100);

    return 0;
}
