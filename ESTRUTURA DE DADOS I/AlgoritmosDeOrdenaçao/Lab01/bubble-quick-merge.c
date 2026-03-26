#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// -------------- QUESTÃO 1 - BUBBLE SORT ------------------
void bubbleSort(int vector[], int len) {
     for(int i = 0; i < len; i++) {
        for(int j = 0; j < (len - 1 - i); j++) {
            if(vector[j] > vector[j + 1]) {
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

// -------------- QUESTÃO 1 - QUICK SORT ------------------

// organiza o array para que todos os elementos maiores que 
// o pivô fiquem a direita e todos os menores fiquem a esuqerda 
int partition(int vector[], int low, int high) {
    int pivot = vector[low];

    while(low < high) {
        while(vector[low] < pivot) {
            low++;
        }
        while(vector[high] > pivot){
            high--;
        }
        
        int aux = vector[low];
        vector[low] = vector[high];
        vector[high] = aux;
    }
    return low;
}

void quickSort(int vector[], int low, int high) {
    if(low < high) {
        int pivot = partition(vector, low, high);
        quickSort(vector, low, (pivot - 1));
        quickSort(vector, (pivot + 1), high);
    }
}

// -------------- QUESTÃO 1 - MERGE SORT ------------------

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
    // se o vetor right ainda tiver elementos:
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

// ---------- QUESTÃO 2 - GERAR VETOR ALEATÓRIO ------------

// gera um vetor de n números sem repetições
void generateRandomVector(int n, int vector[]) {

    for(int i = 0; i < n; i++) {
        vector[i] = i;
    }

    // percorre o vetor do último elemento até o primeiro
    for(int j = n - 1; j >= 0; j--) {
        // sorteia um número entre 0 e j
        int k = rand() % (j + 1);
        // troca o elemento da posição j com o da posição k
        int aux = vector[j];
        vector[j] = vector[k];
        vector[k] = aux;
    }
}

// função auxiliar para restaurar a cópia
void copyVector(int n, int *source, int *dest) {
    for(int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {

// ------------------ QUESTÃO 3 e 4 ----------------------
    srand(time(NULL));

    // tamanhos exigidos: 10^1, 10^2, 10^3, 10^4
    int sizes[] = {10, 100, 1000, 10000};
    int num_sizes = 4;

    printf("Resultados de Tempo de Execução:\n");
    printf("%-10s | %-15s | %-15s | %-15s\n", "Tamanho", "BubbleSort (s)", "QuickSort (s)", "MergeSort (s)");
    printf("------------------------------------------------------------------\n");

    for(int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        
        // aloca os vetores pro tamanho 'n' atual
        int *original_vector = (int *) malloc(n * sizeof(int));
        int *copy_vector = (int *) malloc(n * sizeof(int));

        generateRandomVector(n, original_vector);

        // variáveis para medir o tempo
        clock_t start, end;
        double time_bubble, time_quick, time_merge;

        // --- EXECUÇÃO DO BUBBLE SORT ---
        copyVector(n, original_vector, copy_vector); // usa uma cópia idêntica
        start = clock();
        bubbleSort(copy_vector, n);
        end = clock();
        time_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;

        // --- EXECUÇÃO DO QUICK SORT ---
        copyVector(n, original_vector, copy_vector); // restaura a cópia
        start = clock();
        quickSort(copy_vector, 0, n - 1);
        end = clock();
        time_quick = ((double)(end - start)) / CLOCKS_PER_SEC;

        // --- EXECUÇÃO DO MERGE SORT ---
        copyVector(n, original_vector, copy_vector); // restaura a cópia
        start = clock();
        mergeSort(copy_vector, 0, n - 1);
        end = clock();
        time_merge = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%-10d | %-15.6f | %-15.6f | %-15.6f\n", n, time_bubble, time_quick, time_merge);

        // libera a memória antes de ir para o próximo tamanho
        free(original_vector);
        free(copy_vector);
    }

    return 0;
}
