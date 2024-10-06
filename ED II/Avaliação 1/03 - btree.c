#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ORDEM 2

typedef struct No {
    struct No **filhos;
    int *chaves;
    int nChaves;
    bool folha; // o nó é folha ou não
} No;

No* criaNo(int folha) {
    No* no = (No*)malloc(sizeof(No));
    no->chaves = (int*)malloc((2 * ORDEM - 1) * sizeof(int));
    no->filhos = (No**)malloc(2 * ORDEM * sizeof(No*));
    no->nChaves = 0;
    no->folha = folha;
    return no;
}

typedef struct BTree {
    struct No *raiz;
} BTree;

// Função para percorrer a árvore B
void percorrer(No* no) {
    int i;
    for (i = 0; i < no->nChaves; i++) {
        if (!no->folha) {
            percorrer(no->filhos[i]);
        }
        printf("%d ", no->chaves[i]);
    }
    if (!no->folha) {
        percorrer(no->filhos[i]);
    }
}

// Função para buscar uma chave na árvore B
bool buscar(No* no, int chave) {
    int i = 0;
    while (i < no->nChaves && chave > no->chaves[i]) {
        i++;
    }
    if (i < no->nChaves && chave == no->chaves[i]) {
        return true; // Valor encontrado
    }
    if (no->folha) {
        return false; // Valor não encontrado
    }
    return buscar(no->filhos[i], chave);
}

// Função para dividir um nó cheio
void dividirFilho(struct No* pai, int i, No* filhoCheio) {
    No* novoFilho = criaNo(filhoCheio->folha);
    novoFilho->nChaves = ORDEM - 1;

    // Copia as últimas (t-1) chaves de filhoCheio para novoFilho
    for (int j = 0; j < ORDEM - 1; j++) {
        novoFilho->chaves[j] = filhoCheio->chaves[j + ORDEM];
    }

    // Copia os últimos t filhos de filhoCheio para novoFilho
    if (!filhoCheio->folha) {
        for (int j = 0; j < ORDEM; j++) {
            novoFilho->filhos[j] = filhoCheio->filhos[j + ORDEM];
        }
    }

    filhoCheio->nChaves = ORDEM - 1;

    // Move os filhos do pai para abrir espaço para novoFilho
    for (int j = pai->nChaves; j >= i + 1; j--) {
        pai->filhos[j + 1] = pai->filhos[j];
    }

    pai->filhos[i + 1] = novoFilho;

    // Move as chaves do pai para abrir espaço para a chave do meio de filhoCheio
    for (int j = pai->nChaves - 1; j >= i; j--) {
        pai->chaves[j + 1] = pai->chaves[j];
    }

    // Copia a chave do meio de filhoCheio para o pai
    pai->chaves[i] = filhoCheio->chaves[ORDEM - 1];
    pai->nChaves++;
}

// Função para inserir uma chave em um nó que não está cheio
void inserirNaoCheio(struct No* no, int chave) {
    int i = no->nChaves - 1;

    if (no->folha) {
        // Move as chaves para encontrar o local adequado
        while (i >= 0 && chave < no->chaves[i]) {
            no->chaves[i + 1] = no->chaves[i];
            i--;
        }
        // Insere a nova chave
        no->chaves[i + 1] = chave;
        no->nChaves++;
    } else {
        // Encontra o filho adequado para a inserção
        while (i >= 0 && chave < no->chaves[i]) {
            i--;
        }
        i++;

        // Se o filho estiver cheio, divida-o
        if (no->filhos[i]->nChaves == 2 * ORDEM - 1) {
            dividirFilho(no, i, no->filhos[i]);

            // Após a divisão, a chave do meio sobe, então decidimos em qual metade inserir
            if (chave > no->chaves[i]) {
                i++;
            }
        }
        inserirNaoCheio(no->filhos[i], chave);
    }
}

// Função para inserir uma chave na árvore B
void inserir(struct BTree* arvore, int chave) {
    No* raiz = arvore->raiz;

    // Se a raiz estiver cheia, precisamos dividi-la
    if (raiz->nChaves == 2 * ORDEM - 1) {
        No* novaRaiz = criaNo(0);  // Nova raiz não será uma folha
        novaRaiz->filhos[0] = raiz;
        dividirFilho(novaRaiz, 0, raiz);
        inserirNaoCheio(novaRaiz, chave);
        arvore->raiz = novaRaiz;
    } else {
        inserirNaoCheio(raiz, chave);
    }
}

int main() {
    BTree* arvore = (BTree*)malloc(sizeof(BTree));
    arvore->raiz = criaNo(1);  // A raiz é inicialmente uma folha

    char comando[20];
    int valor;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "insere") == 0) {
            scanf("%d", &valor);
            inserir(arvore, valor);
        } else if (strcmp(comando, "percorre") == 0) {
            printf("Percurso da árvore B em ordem: ");
            percorrer(arvore->raiz);
            printf("\n");
        } else if (strcmp(comando, "busca") == 0) {
            scanf("%d", &valor);
            if (buscar(arvore->raiz, valor)) {
                printf("Valor %d encontrado!\n", valor);
            } else {
                printf("Valor %d não encontrado!\n", valor);
            }
        }
    }
    
    return 0;
}
