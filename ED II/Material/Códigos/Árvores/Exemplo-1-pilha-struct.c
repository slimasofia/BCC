#include <stdio.h>
#define MAX 100

struct Pilha {
    int dado[MAX];
    int tamanho;
};

typedef struct Pilha Pilha;

void init(Pilha *S) {
    S->tamanho = 0;
}

int top(Pilha *S) {
    if (S->tamanho == 0) {
        fprintf(stderr, "Erro: pilha vazia.\n");
        return -1;
    } 
    return S->dado[S->tamanho-1];
}

void push(Pilha *S, int d) {
    if (S->tamanho < MAX)
        S->dado[S->tamanho++] = d;
    else
        fprintf(stderr, "Erro: pilha cheia.\n");
}

void pop(Pilha *S) {
    if (S->tamanho == 0)
        fprintf(stderr, "Erro: pilha vazia.\n");
    else
        S->tamanho--;
}

int size(Pilha *S) {
    return S->tamanho;
}

int empty(Pilha *S) {
    return S->tamanho == 0;
}

int main(int argc, char const *argv[]) {
    Pilha minhaPilha;
    init(&minhaPilha);
    
    if (empty(&minhaPilha))
        printf("Pilha está vazia.\n");
    
    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    
    printf("Tamanho da pilha: %d\n", size(&minhaPilha));   
    printf("Topo da pilha: %d\n", top(&minhaPilha));
    pop(&minhaPilha);
    printf("Topo da pilha após uma operação pop: %d\n", top(&minhaPilha));
    
    if (empty(&minhaPilha))
        printf("Pilha está vazia.\n");
    else
        printf("Pilha não está vazia.\n");
    return 0;
}