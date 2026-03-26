#include <stdio.h>

void bubbleSort(int vector[], int len) {
     for(int i = 0; i < len; i++) {
        for(int j = 0; j < (len - 1 - i); j ++) {
            if(vector[j] > vector[j + 1]) {
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

int main() {

    int vector[] = {23, 4, 1, 12, 6, 9};
    int len = sizeof(vector) / sizeof(vector[0]);

    bubbleSort(vector, len);
    for(int i = 0; i < len; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}

