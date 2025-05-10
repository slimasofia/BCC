#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct {
    unsigned int origem, destino;
} Aresta;

typedef struct NoListaAdj {
    unsigned int destino;
    struct NoListaAdj* proximo;
} NoListaAdj;

typedef struct {
    NoListaAdj* inicio;
} ListaAdj;

NoListaAdj* criaNo(unsigned int destino) {
    NoListaAdj* novoNo = (NoListaAdj*)malloc(sizeof(NoListaAdj));
    novoNo->destino = destino;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionaArestaListaAdj(ListaAdj* listaAdj, unsigned int u, unsigned int v) {
    NoListaAdj* novoNo = criaNo(v);
    novoNo->proximo = listaAdj[u].inicio;
    listaAdj[u].inicio = novoNo;
    novoNo = criaNo(u);
    novoNo->proximo = listaAdj[v].inicio;
    listaAdj[v].inicio = novoNo;
}

void adicionaArestaMapaAdj(NoListaAdj* mapaAdj[N+1][N+1], unsigned int u, unsigned int v) {
    mapaAdj[u][v] = criaNo(v);
    mapaAdj[v][u] = criaNo(u);
}

void adicionaArestaMatrizAdj(unsigned int matrizAdj[N+1][N+1], unsigned int u, unsigned int v) {
    matrizAdj[u][v] = 1;
    matrizAdj[v][u] = 1;
}

void removeArestaListaAdj(ListaAdj* listaAdj, unsigned int u, unsigned int v) {
    NoListaAdj* atual = listaAdj[u].inicio;
    NoListaAdj* anterior = NULL;

    while (atual != NULL && atual->destino != v) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL)
            listaAdj[u].inicio = atual->proximo;
        else
            anterior->proximo = atual->proximo;
        free(atual);
    }

    atual = listaAdj[v].inicio;
    anterior = NULL;

    while (atual != NULL && atual->destino != u) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL)
            listaAdj[v].inicio = atual->proximo;
        else
            anterior->proximo = atual->proximo;
        free(atual);
    }
}

void removeArestaMapaAdj(NoListaAdj* mapaAdj[N+1][N+1], unsigned int u, unsigned int v) {
    free(mapaAdj[u][v]);
    free(mapaAdj[v][u]);
    mapaAdj[u][v] = NULL;
    mapaAdj[v][u] = NULL;
}

void removeArestaMatrizAdj(unsigned int matrizAdj[N+1][N+1], unsigned int u, unsigned int v) {
    matrizAdj[u][v] = 0;
    matrizAdj[v][u] = 0;
}

void imprimeListaArestas(Aresta arestas[], unsigned int numArestas) {
    printf("Lista de Arestas:\n");
    for (unsigned int i = 0; i < numArestas; i++)
        printf("(%u, %u)\n", arestas[i].origem, arestas[i].destino);
    printf("\n");
}

void imprimeListaAdj(ListaAdj listaAdj[N+1]) {
    printf("Lista de Adjacência:\n");
    for (unsigned int i = 1; i <= N; i++) {
        printf("Vértice %u:", i);
        NoListaAdj* atual = listaAdj[i].inicio;
        while (atual) {
            printf(" -> %u", atual->destino);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("\n");
}

void imprimeMapaAdj(NoListaAdj* mapaAdj[N+1][N+1]) {
    printf("Mapa de Adjacência:\n");
    for (unsigned int i = 1; i <= N; i++) {
        for (unsigned int j = 1; j <= N; j++)
            if (mapaAdj[i][j] != NULL)
                printf("(%u -> %u) ", i, j);
        printf("\n");
    }
    printf("\n");
}

void imprimeMatrizAdj(unsigned int matrizAdj[N+1][N+1]) {
    printf("Matriz de Adjacência:\n");
    for (unsigned int i = 1; i <= N; i++) {
        for (unsigned int j = 1; j <= N; j++)
            printf("%u ", matrizAdj[i][j]);
        printf("\n");
    }
    printf("\n");
}

unsigned int main() {
    Aresta arestas[] = { {1, 2}, {1, 3}, {2, 3} };
    ListaAdj listaAdj[N+1] = {0};
    NoListaAdj* mapaAdj[N+1][N+1] = {NULL};
    unsigned int matrizAdj[N+1][N+1] = {0};
    unsigned int numArestas = sizeof(arestas) / sizeof(arestas[0]);

    for (unsigned int i = 0; i < numArestas; i++) {
        unsigned int u = arestas[i].origem;
        unsigned int v = arestas[i].destino;
        adicionaArestaListaAdj(listaAdj, u, v);
        adicionaArestaMapaAdj(mapaAdj, u, v);
        adicionaArestaMatrizAdj(matrizAdj, u, v);
    }

    imprimeListaArestas(arestas, numArestas);
    imprimeListaAdj(listaAdj);
    imprimeMapaAdj(mapaAdj);
    imprimeMatrizAdj(matrizAdj);

    removeArestaListaAdj(listaAdj, 1, 2);
    removeArestaMapaAdj(mapaAdj, 1, 2);
    removeArestaMatrizAdj(matrizAdj, 1, 2);

    printf("Após remover a aresta (1, 2):\n");
    imprimeListaAdj(listaAdj);
    imprimeMapaAdj(mapaAdj);
    imprimeMatrizAdj(matrizAdj);

    return 0;
}