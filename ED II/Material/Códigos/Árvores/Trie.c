#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO_ALFABETO 26

typedef struct NoTrie {
    struct NoTrie *filhos[TAMANHO_ALFABETO];
    bool fimDePalavra;
} NoTrie;

NoTrie* criarNo() {
    NoTrie *no = (NoTrie*)malloc(sizeof(NoTrie));
    no->fimDePalavra = false;
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        no->filhos[i] = NULL;
    }
    return no;
}

void inserir(NoTrie *raiz, const char *palavra) {
    NoTrie *atual = raiz;
    while (*palavra) {
        int indice = *palavra - 'a';
        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        atual = atual->filhos[indice];
        palavra++;
    }
    atual->fimDePalavra = true;
}

bool buscar(NoTrie *raiz, const char *palavra) {
    NoTrie *atual = raiz;
    while (*palavra) {
        int indice = *palavra - 'a';
        if (atual->filhos[indice] == NULL) {
            return false;
        }
        atual = atual->filhos[indice];
        palavra++;
    }
    return atual->fimDePalavra;
}

void deletarTrie(NoTrie *raiz) {
    for (int i = 0; i < TAMANHO_ALFABETO; i++) {
        if (raiz->filhos[i] != NULL) {
            deletarTrie(raiz->filhos[i]);
        }
    }
    free(raiz);
}

int main() {
    NoTrie *raiz = criarNo();
    
    inserir(raiz, "ola");
    inserir(raiz, "olamundo");
    inserir(raiz, "ola");
    inserir(raiz, "mundo");
    
    printf("Buscando 'ola': %s\n", buscar(raiz, "ola") ? "Encontrado" : "Não Encontrado");
    printf("Buscando 'mundo': %s\n", buscar(raiz, "mundo") ? "Encontrado" : "Não Encontrado");
    printf("Buscando 'imundo': %s\n", buscar(raiz, "imundo") ? "Encontrado" : "Não Encontrado");

    deletarTrie(raiz);

    return 0;
}