#include <stdio.h>

// função auxiliar para juntar
void merge(int vector[], int p, int mid, int r) {
    // tamanho das metades:
    int n1 = mid - p + 1;
    int n2 = r - mid;

    // vetores auxiliares:
    int left[n1];
    int right[n2];

    // copiar os elementos do vetor original para os auxiliares
    for(int i = 0; i < n1; i++) {
        left[i] = vector[p + i];
    }

    for(int j = 0; j < n2; j++) {
        right[j] = vector[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;
    while(i < n1 && j < n2) {
        if(left[i] < right[j]) {
            vector[k] = left[i];
            i++;
            k++;
        } else {
            vector[k] = right[j];
            j++;
            k++;
        }

    }

    // se o vetor left ainda tiver elementos:
    while (i < n1) {
        vector[k] = left[i];
        i = i + 1;
        k++;
    }

    while(j < n2) {
        vector[k] = right[j];
        j = j + 1;
        k++;
    }
}

// função para dividir
void mergeSort(int vector[], int p, int r) {
    // condição de parada: 
    // se o início for igual ao fim (1 elemento)
    // ou a lista for vazia
    if(p >= r) {
        return;
    }

    int mid = (p + r) / 2;
    mergeSort(vector, p, mid);
    mergeSort(vector, mid + 1, r);
    merge(vector, p, mid, r);
        
}


int main() {

    int vector[] = {23, 4, 1, 12, 6, 9};
    int len = sizeof(vector) / sizeof(vector[0]);

    mergeSort(vector, 0, len - 1);
    for(int i = 0; i < len; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");


    return 0;
}
