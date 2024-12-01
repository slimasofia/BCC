#include <stdio.h>
#include <stdlib.h>

#define V 5
#define MAX_ARESTAS 10

typedef struct {
    int origem, destino, peso;
} Aresta;

typedef struct {
    int pai, rank;
} Subconjunto;

int compararArestas(const void* a, const void* b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int encontrarPai(Subconjunto subconjuntos[], int v) {
    if (subconjuntos[v].pai != v)
        subconjuntos[v].pai = encontrarPai(subconjuntos, subconjuntos[v].pai);
    return subconjuntos[v].pai;
}

void unir(Subconjunto subconjuntos[], int u, int v) {
    int raizU = encontrarPai(subconjuntos, u);
    int raizV = encontrarPai(subconjuntos, v);

    if (subconjuntos[raizU].rank < subconjuntos[raizV].rank)
        subconjuntos[raizU].pai = raizV;
    else if (subconjuntos[raizU].rank > subconjuntos[raizV].rank)
        subconjuntos[raizV].pai = raizU;
    else {
        subconjuntos[raizV].pai = raizU;
        subconjuntos[raizU].rank++;
    }
}

void kruskal(Aresta arestas[], int n) {
    qsort(arestas, n, sizeof(Aresta), compararArestas);

    Subconjunto subconjuntos[V];
    for (int v = 0; v < V; v++) {
        subconjuntos[v].pai = v;
        subconjuntos[v].rank = 0;
    }

    int custoTotal = 0;
    printf("Arestas da MST:\n");
    for (int i = 0, e = 0; e < V - 1 && i < n; i++) {
        int u = arestas[i].origem;
        int v = arestas[i].destino;

        int raizU = encontrarPai(subconjuntos, u);
        int raizV = encontrarPai(subconjuntos, v);

        if (raizU != raizV) {
            printf("%d - %d com custo %d\n", u, v, arestas[i].peso);
            custoTotal += arestas[i].peso;
            unir(subconjuntos, raizU, raizV);
            e++;
        }
    }
    printf("Custo total: %d\n", custoTotal);
}

int main() {
    Aresta arestas[MAX_ARESTAS] = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9} };
    int n = 7;

    kruskal(arestas, n);
    return 0;
}