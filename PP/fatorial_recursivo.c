#include <stdio.h>

int calculaFatorial(int n){
    if (n == 0){
        return 1;
    
    } else{
        return n * calculaFatorial(n - 1);
    }
}

int main(){
    int n;

    printf("Digite um número: \n");
    scanf("%d", &n);

    if (n < 0){
        printf("Inválido. Digite um número positivo. \n");

    } else {
    int resultado = calculaFatorial(n);
    printf("O fatorial de %d é: %d\n", n, resultado);

 }
    return 0;
}