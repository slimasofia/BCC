#include <stdio.h>
#include <stdlib.h>

#define QUANT_VERTICES 10

unsigned int grafo[QUANT_VERTICES][QUANT_VERTICES];
unsigned int visitado[QUANT_VERTICES];

void dfs(unsigned int v) {
    visitado[v] = 1;
    for (unsigned int i = 0; i < QUANT_VERTICES; i++)
        if (grafo[v][i] && !visitado[i])
            dfs(i);
}

unsigned int grafoConexo() {
    unsigned int componentes = 0;
    for (unsigned int i = 0; i < QUANT_VERTICES; i++)
        visitado[i] = 0;

    dfs(0);

    for (unsigned int i = 0; i < QUANT_VERTICES; i++)
        if (!visitado[i])
            // O Grafo não é conexo
            return 0;
    // O Grafo é conexo
    return 1;
}

int main() {
    unsigned int e;
    printf("Digite a quantidade de arestas: ");
    scanf("%u", &e);
    
    for (unsigned int i = 0; i < e; i++) {
        unsigned int u, v;
        do {
            printf("Lembre-se: O seu grafo possui %u vértices.\nDigite a aresta (u v), com valores de 0 até %u: ", QUANT_VERTICES, QUANT_VERTICES - 1);
            scanf("%u %u", &u, &v);
        } while (u >= QUANT_VERTICES && v >= QUANT_VERTICES);
        grafo[u][v] = grafo[v][u] = 1;
    }

    if (grafoConexo())
        printf("O grafo é conexo.\n");
    else
        printf("O grafo não é conexo.\n");
    
    return 0;
}