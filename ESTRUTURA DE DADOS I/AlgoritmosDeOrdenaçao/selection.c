#include <stdio.h>

void selectionSort(int vector[], int len) {
    for(int i = 0; i < len; i++) {
        int min = i;
        for(int j = i + 1; j < len; j++) {
            if(vector[j] < vector[min]) {
                min = j;
            }
        }
        // depois de encontrar o menor elemento, realizar a troca
        int aux = vector[i];
        vector[i] = vector[min];
        vector[min] = aux;
    }
}

int main() {

    int vector[] = {23, 4, 1, 12, 6, 9};
    int len = sizeof(vector) / sizeof(vector[0]);

    selectionSort(vector, len);
    for(int i = 0; i < len; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
