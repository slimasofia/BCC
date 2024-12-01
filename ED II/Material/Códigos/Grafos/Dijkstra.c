#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX
#define V 5

char *cidades[V] = {"Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"};

typedef struct {
    int vertice;
    int peso;
} Aresta;

typedef struct {
    int tam;
    int capacidade;
    Aresta *arestas;
} MinHeap;

MinHeap* criaMinHeap(int capacidade) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->tam = 0;
    heap->capacidade = capacidade;
    heap->arestas = (Aresta*)malloc(capacidade * sizeof(Aresta));
    return heap;
}

void insereMinHeap(MinHeap *heap, int vertice, int peso) {
    int i = heap->tam++;
    while (i && peso < heap->arestas[(i - 1) / 2].peso) {
        heap->arestas[i] = heap->arestas[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->arestas[i].vertice = vertice;
    heap->arestas[i].peso = peso;
}

void minHeapify(MinHeap *heap, int indice) {
    int menor = indice;
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;

    if (esq < heap->tam && heap->arestas[esq].peso < heap->arestas[menor].peso)
        menor = esq;
    if (dir < heap->tam && heap->arestas[dir].peso < heap->arestas[menor].peso)
        menor = dir;
    if (menor != indice) {
        Aresta temp = heap->arestas[indice];
        heap->arestas[indice] = heap->arestas[menor];
        heap->arestas[menor] = temp;
        minHeapify(heap, menor);
    }
}

Aresta extraiMin(MinHeap *heap) {
    Aresta min = heap->arestas[0];
    heap->arestas[0] = heap->arestas[--heap->tam];
    minHeapify(heap, 0);
    return min;
}

void dijkstra(int grafo[V][V], char *cidade) {
    unsigned int origem;
    for (unsigned int i = 0; i < V; i++)
        if (!strcmp(cidade, cidades[i])) {
            origem = i;
            break;
        }

    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[origem] = 0;

    MinHeap* heap = criaMinHeap(V);
    insereMinHeap(heap, origem, 0);

    while (heap->tam) {
        Aresta min = extraiMin(heap);
        int u = min.vertice;

        for (int v = 0; v < V; v++)
            if (grafo[u][v] && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
                insereMinHeap(heap, v, dist[v]);
            }
    }

    printf("Vértice\t\tDistância da Origem (%s)\n", cidades[origem]);
    for (int i = 0; i < V; i++)
        printf("%s\t\t%d\n", cidades[i], dist[i]);
}

int main() {
    int grafo[V][V] = { {0, 15, 20, 0, 0}, {15, 0, 0, 40, 0}, {20, 0, 0, 12, 30}, {0, 40, 12, 0, 10}, {0, 0, 30, 10, 0} };
    dijkstra(grafo, "Blu");
    return 0;
}