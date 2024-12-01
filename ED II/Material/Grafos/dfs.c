#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;       
typedef int TIPOPESO;   // Tipo de dado para o peso das arestas 

// para rastreamento de vértices durante a busca em profundidade
#define BRANCO 0    // ainda não visitado
#define AMARELO 1   // visitado, mas ainda não finalizado
#define VERMELHO 2  // finalizado

// Estrutura que representa uma aresta na lista de adjacência
typedef struct adjacencia {
    int vertice;                // Vértice de destino da aresta
    TIPOPESO peso;              // Peso da aresta
    struct adjacencia *prox;    // Ponteiro para a próxima aresta
} ADJACENCIA;

// Estrutura que representa um vértice no grafo
typedef struct vertice {
    ADJACENCIA *cab;            // Cabeça da lista de adjacência (arestas conectadas a este vértice)
} VERTICE;

// Estrutura que representa o grafo
typedef struct grafo {
    int vertices;               // Número de vértices no grafo
    int arestas;                // Número de arestas no grafo
    VERTICE *adj;               // Vetor de vértices (lista de adjacências)
} GRAFO;


GRAFO* criaGrafo(int vertices) {
    GRAFO *g = malloc(sizeof(GRAFO));        // Aloca memória para o grafo
    g->vertices = vertices;                 // Define o número de vértices
    g->arestas = 0;                         // Inicializa o número de arestas como 0
    g->adj = malloc(vertices * sizeof(VERTICE)); // Aloca memória para o vetor de vértices

    // Inicializa a lista de adjacência de cada vértice como vazia (NULL)
    for (int i = 0; i < vertices; i++)
        g->adj[i].cab = NULL;

    return g;  // Retorna o ponteiro para o grafo criado
}

// Função para adicionar uma aresta ao grafo
void adicionaAresta(GRAFO *g, int u, int v, TIPOPESO peso) {
    ADJACENCIA *nova = malloc(sizeof(ADJACENCIA)); // Cria uma nova aresta
    nova->vertice = v;                             // Define o vértice de destino
    nova->peso = peso;                             // Define o peso da aresta
    nova->prox = g->adj[u].cab;                    // Insere a nova aresta na lista de adjacência de u
    g->adj[u].cab = nova;
    g->arestas++;                                  // Incrementa o número de arestas do grafo
}

// Função recursiva para visitar os vértices durante a DFS
void visitaP(GRAFO *g, int u, int *cor) {
    printf("Visitando vertice %d\n", u); // Exibe o vértice que está sendo visitado
    cor[u] = AMARELO;                   // Marca o vértice como visitado (AMARELO)

    ADJACENCIA *v = g->adj[u].cab;      // Obtém a lista de adjacência do vértice u
    while (v) {                         // Percorre os vértices adjacentes
        if (cor[v->vertice] == BRANCO)  // Se o vértice adjacente ainda não foi visitado
            visitaP(g, v->vertice, cor); // Chama a função recursivamente para o vértice adjacente
        v = v->prox;                    // Move para a próxima aresta na lista de adjacência
    }

    cor[u] = VERMELHO;                  // Marca o vértice como finalizado (VERMELHO)
}

// Função principal para realizar a busca em profundidade (DFS) no grafo
void profundidade(GRAFO *g) {
    if (g == NULL || g->adj == NULL) {  // Verifica se o grafo foi inicializado
        printf("Grafo nao inicializado.\n");
        return;
    }

    int cor[g->vertices];               // Array para rastrear o estado de cada vértice (BRANCO, AMARELO, VERMELHO)

    // Inicializa todos os vértices como não visitados (BRANCO)
    for (int u = 0; u < g->vertices; u++)
        cor[u] = BRANCO;

    // Percorre todos os vértices do grafo
    for (int u = 0; u < g->vertices; u++) {
        if (cor[u] == BRANCO)           // Se o vértice ainda não foi visitado
            visitaP(g, u, cor);         // Inicia a DFS a partir desse vértice
    }
}

// Função para liberar a memória alocada pelo grafo
void liberaGrafo(GRAFO *g) {
    // Percorre cada vértice do grafo
    for (int i = 0; i < g->vertices; i++) {
        ADJACENCIA *temp = g->adj[i].cab; // Obtém a lista de adjacência do vértice
        while (temp) {                    // Percorre a lista de adjacência
            ADJACENCIA *prox = temp->prox; // Guarda o próximo elemento
            free(temp);                    // Libera o elemento atual
            temp = prox;                   // Avança para o próximo
        }
    }

    free(g->adj); // Libera o vetor de vértices
    free(g);      // Libera o grafo
}

// Função principal
int main() {
    GRAFO *g = criaGrafo(5);  // Cria um grafo com 5 vértices

    // Adiciona arestas ao grafo
    adicionaAresta(g, 0, 1, 0);
    adicionaAresta(g, 0, 2, 0);
    adicionaAresta(g, 1, 3, 0);
    adicionaAresta(g, 1, 4, 0);

    // Realiza a DFS no grafo
    printf("DFS:\n");
    profundidade(g);

    liberaGrafo(g);

    return 0; 
}
