#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

No* novoNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);

    return buscar(raiz->direita, valor);
}

int main() {

    No* raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    No* pesquisa1 = buscar(raiz, 40);
    No* pesquisa2 = buscar(raiz, 45);

    if (pesquisa1 != NULL)
        printf("Valor encontrado!\n");
    else
        printf("\nValor não encontrado!\n");

    if (pesquisa2 != NULL)
        printf("Valor encontrado!\n");
    else
        printf("Valor não encontrado!\n");

    return 0;
}