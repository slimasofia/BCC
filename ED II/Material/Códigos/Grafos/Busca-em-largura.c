#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUANTIDADE_VERTICES 4

struct Fila {
    int itens[QUANTIDADE_VERTICES];
    int frente, traseira;
};

void inicializaFila(struct Fila *f) {
    f->frente = 0;
    f->traseira = -1;
}

bool filaVazia(struct Fila *f) {
    return f->frente > f->traseira;
}

void insereFila(struct Fila *f, int valor) {
    f->itens[++f->traseira] = valor;
}

int removeFila(struct Fila *f) {
    return f->itens[f->frente++];
}

void BFS(int grafo[QUANTIDADE_VERTICES][QUANTIDADE_VERTICES], int vertices, int inicio) {
    bool visitado[QUANTIDADE_VERTICES] = {false};
    struct Fila f;
    inicializaFila(&f);

    visitado[inicio] = true;
    insereFila(&f, inicio);

    while (!filaVazia(&f)) {
        int vertice = removeFila(&f);
        printf("Visitado %d\n", vertice);

        for (int i = 0; i < vertices; i++) {
            if (grafo[vertice][i] && !visitado[i]) {
                visitado[i] = true;
                insereFila(&f, i);
            }
        }
    }
}

int main() {
    int grafo[QUANTIDADE_VERTICES][QUANTIDADE_VERTICES] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}};
    int inicio = 1; // Altere!
    BFS(grafo, QUANTIDADE_VERTICES, inicio);

    return 0;
}