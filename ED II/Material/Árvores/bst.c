#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esq, *dir;
} No;


No* criaNo(int valor){
    /*
    
    sizeof(No) calcula a qtd de bytes que eu preciso considerando o tamanho dos campos 
    int valor e dos ponteiros esq e dir --> pedindo uma quantidade de memoria suficiente 
    pra alocar uma estrutura do tipo nó; o malloc retorna um ponteiro para o primeiro byte 
    desse bloco de memória que foi alocado; é necessário colocar (No*) pois isso garante 
    que o ponteiro devolvido pelo malloc seja convertido para o tipo correto [typecasting]
    
    */

    No* no = (No*)malloc(sizeof(No)); 
    no->valor = valor;
    no->dir = NULL;
    no->esq = NULL;

    return no;
}

No* insere(No* raiz, int valor){
    if (raiz == NULL){
        return criaNo(valor);
    }
    if (valor < raiz->valor){
        raiz->esq = insere(raiz->esq, valor);
    }
    
    else if(valor > raiz->valor){
        raiz->dir = insere(raiz->dir, valor);
    }
    
    return raiz;
}

No* buscaValor(No* raiz, int valor){
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor){
        return buscaValor(raiz->esq, valor);
    }

    return buscaValor(raiz->dir, valor);
}

int main(){
    No* raiz = NULL;

    /* Na primeira chamada da função insere a raiz da árvore ainda é NULL,
    portanto a função criaNo é chamada e um nó com valor 15 é chamado, se tornando a raiz
    */

    raiz = insere(raiz, 15); 
    insere(raiz, 10);
    insere(raiz, 12);
    insere(raiz, 9);

    No* x = buscaValor(raiz, 9);
    No* y = buscaValor(raiz, 20);

    if (x != NULL){
        printf("Valor encontrado \n");
    }
    else
        printf("Valor não encontrado \n");


    if(y != NULL){
        printf("Valor encontrado \n");
    }

    else
        printf("Valor não encontrado \n");

    return 0;
}