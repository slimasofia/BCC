#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Número de vértices no grafo

// Função para encontrar o vértice com o menor valor de chave, que ainda não está na MST
unsigned int menorChave(unsigned int chave[], bool conjuntoMST[]) {
    unsigned int minimo = UINT_MAX, indiceMinimo;

    for (unsigned int v = 0; v < V; v++)
        if (!conjuntoMST[v] && chave[v] < minimo) {
            minimo = chave[v];
            indiceMinimo = v;
        }

    return indiceMinimo;
}

// Função para construir e exibir a MST usando o algoritmo de Prim
void prim(unsigned int grafo[V][V]) {
    unsigned int pai[V]; // Array para armazenar a árvore MST
    unsigned int chave[V]; // Valores chave para selecionar a aresta de menor peso
    bool conjuntoMST[V]; // conjuntoMST[v] será true se o vértice v está na MST

    // Inicializa todos os valores chave como infinito e conjuntoMST como falso
    for (unsigned int i = 0; i < V; i++) {
        chave[i] = UINT_MAX;
        conjuntoMST[i] = false;
    }

    // O primeiro vértice é sempre incluído na MST, então define sua chave como 0
    chave[0] = 0;
    pai[0] = -1;  // O primeiro nó é a raiz da MST

    // Construindo a MST
    for (unsigned int contador = 0; contador < V - 1; contador++) {
        unsigned int u = menorChave(chave, conjuntoMST);  // Seleciona o vértice com a menor chave
        conjuntoMST[u] = true;                            // Adiciona o vértice à MST

        // Atualiza o valor chave e o pai dos vértices adjacentes do vértice escolhido
        for (unsigned int v = 0; v < V; v++)
            if (grafo[u][v] && !conjuntoMST[v] && grafo[u][v] < chave[v]) {
                pai[v] = u;
                chave[v] = grafo[u][v];
            }
    }

    // Calcula e exibe as arestas da MST e o custo total
    unsigned int custo = 0;
    printf("Arestas da MST:\n");
    for (unsigned int i = 1; i < V; i++) {
        printf("%u - %u com custo %u\n", pai[i], i, grafo[i][pai[i]]);
        custo += grafo[i][pai[i]];
    }
    printf("Custo total: %u\n", custo);
}

int main() {
    // Grafo representado como uma matriz de adjacência
    unsigned int grafo[V][V] = { {0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0} };

    // Calcula a MST
    prim(grafo);

    return 0;
}