#include <stdio.h>

int array[] = {1, 70, 95, 100};
int tamanho = sizeof(array) / sizeof(array[0]);
int n;

int pertence(int n){
    for (int i = 0; i < tamanho; ++i) {
        if (array[i] == n) {
            return 1;
        }     
    }
    return 0;
}

int main(){
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    if (pertence(n)){
        printf("%d pertence ao array!\n", n);   
    } else {
        printf("%d não pertence ao array!\n", n);
    }

    return 0;
}