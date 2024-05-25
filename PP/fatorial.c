#include <stdio.h>

int main(){
    int n;
    int fatorial = 1;

    printf("Digite um número: \n");
    scanf("%d", &n);

    if (n < 0){
        printf("Inválido. Digite um número positivo. \n");

    } else {
        for(int i = 1; i <= n; i++) {
            fatorial = fatorial * i;
        }
    printf("O fatoriral é: %d\n", fatorial);
    }
    
    return 0;
}
