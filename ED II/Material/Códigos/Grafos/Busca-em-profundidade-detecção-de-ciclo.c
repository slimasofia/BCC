#include <stdio.h>
#include <stdbool.h>

#define QUANT_VERTICES 5

bool dfsCiclo(int grafo[QUANT_VERTICES][QUANT_VERTICES], bool visitado[], int vertice, int pai) {
    visitado[vertice] = true;

    for (int i = 0; i < QUANT_VERTICES; i++) {
        if (grafo[vertice][i]) {
            if (!visitado[i])
                if (dfsCiclo(grafo, visitado, i, vertice))
                    return true;
            else if (i != pai)
                return true;
        }
    }
    return false;
}

bool temCiclo(int grafo[QUANT_VERTICES][QUANT_VERTICES]) {
    bool visitado[QUANT_VERTICES] = {false};

    for (int i = 0; i < QUANT_VERTICES; i++)
        if (!visitado[i])
            if (dfsCiclo(grafo, visitado, i, -1))
                return true;

    return false;
}

int main() {
    int grafo[QUANT_VERTICES][QUANT_VERTICES] = {
        {0, 1, 0, 0, 1}, // Mude para: {0, 1, 0, 0, 0}
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0} // Mude para: {0, 0, 0, 1, 0}
    };

    if (temCiclo(grafo))
        printf("O grafo tem um ciclo.\n");
    else
        printf("O grafo não tem ciclos.\n");

    return 0;
}