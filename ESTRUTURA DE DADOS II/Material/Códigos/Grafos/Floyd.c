#include <stdio.h>
#include <limits.h>

#define V 5
#define INF INT_MAX

char *cidades[V] = {"Blu", "Indaial", "Gaspar", "Ilhota", "Itajaí"};

void floydWarshall(int grafo[V][V]) {
    int dist[V][V];

    // Inicializa a matriz de distâncias com os valores do grafo
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            if (grafo[i][j] == 0 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = grafo[i][j];
        }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("\t");
    for (unsigned int i = 0; i < V; i++)
        printf("%s\t", cidades[i]);
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%s\t", cidades[i]);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grafo[V][V] = { {0, 15, 20, 0, 0}, {15, 0, 0, 40, 0}, {20, 0, 0, 12, 30}, {0, 40, 12, 0, 10}, {0, 0, 30, 10, 0} };
    floydWarshall(grafo);
    return 0;
}