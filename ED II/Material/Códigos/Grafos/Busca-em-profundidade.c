#include <stdio.h>
#include <stdbool.h>

#define QUANTIDADE_VERTICES 4

void DFS(int grafo[QUANTIDADE_VERTICES][QUANTIDADE_VERTICES], bool visitado[QUANTIDADE_VERTICES], int vertice, int vertices) {
    visitado[vertice] = true;
    printf("Visitado %d\n", vertice);

    for (int i = 0; i < vertices; i++)
        if (grafo[vertice][i] && !visitado[i])
            DFS(grafo, visitado, i, vertices);
}

int main() {
    int grafo[QUANTIDADE_VERTICES][QUANTIDADE_VERTICES] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}};
    bool visitado[QUANTIDADE_VERTICES] = {false};

    DFS(grafo, visitado, 1, QUANTIDADE_VERTICES); // Altere o terceiro parâmetro!

    return 0;
}