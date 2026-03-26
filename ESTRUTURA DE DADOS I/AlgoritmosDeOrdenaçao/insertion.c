#include <stdio.h>

void insertionSort(int vector[], int len) {
    // assume-se que o primeiro elemento já está ordenado
    for(int i = 1; i < len; i++) {
        // escolhe um elemento para ser a chave
        int key = vector[i];
        // define j como o elemento anteiror a chave
        int j = i - 1;
        // se o elemento anterior for  
        while(j >= 0 && vector[j] > key) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }
       vector[j + 1] = key;
    }
}


int main() {

    int vector[] = {23, 4, 1, 12, 6, 9};
    int len = sizeof(vector) / sizeof(vector[0]);

    insertionSort(vector, len);
    for(int i = 0; i < len; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
