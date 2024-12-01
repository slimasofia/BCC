#include <iostream>
#include <vector>
#include <climits>
#include <string>

#define INF INT_MAX
#define V 5

using namespace std;

string cidades[V] = {"Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"};

struct Aresta {
    int vertice;
    int peso;
};

struct MinHeap {
    int tam;
    int capacidade;
    vector<Aresta> arestas;
};

MinHeap* criaMinHeap(int capacidade) {
    MinHeap* heap = new MinHeap();
    heap->tam = 0;
    heap->capacidade = capacidade;
    heap->arestas.reserve(capacidade);
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
        swap(heap->arestas[indice], heap->arestas[menor]);
        minHeapify(heap, menor);
    }
}

Aresta extraiMin(MinHeap *heap) {
    Aresta min = heap->arestas[0];
    heap->arestas[0] = heap->arestas[--heap->tam];
    minHeapify(heap, 0);
    return min;
}

void dijkstra(int grafo[V][V], const string& cidade) {
    unsigned int origem;
    for (unsigned int i = 0; i < V; i++)
        if (cidade == cidades[i]) {
            origem = i;
            break;
        }

    int dist[V];
    fill(dist, dist + V, INF);

    dist[origem] = 0;

    MinHeap* heap = criaMinHeap(V);
    insereMinHeap(heap, origem, 0);

    while (heap->tam > 0) {
        Aresta min = extraiMin(heap);
        int u = min.vertice;

        for (int v = 0; v < V; v++)
            if (grafo[u][v] && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
                insereMinHeap(heap, v, dist[v]);
            }
    }

    cout << "Vértice\t\tDistância da Origem (" << cidades[origem] << ")\n";
    for (int i = 0; i < V; i++)
        cout << cidades[i] << "\t\t" << dist[i] << "\n";
}

int main() {
    int grafo[V][V] = { {0, 15, 20, 0, 0}, {15, 0, 0, 40, 0}, {20, 0, 0, 12, 30}, {0, 40, 12, 0, 10}, {0, 0, 30, 10, 0} };
    dijkstra(grafo, "Blu");
    return 0;
}