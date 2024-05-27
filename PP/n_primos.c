#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificaPrimo(int n){
    if(n < 2){
        return 0;
    }

    for (int i = 2; i <= n/2; ++i){
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(){
   int n_gerados = 0;
    
    int c = 0;
    srand(time(NULL));

    while (c < 25){
        int n = rand() % 100;

        if (verificaPrimo(n)){
            c++;
        }
    n_gerados++;
    }
    printf("Quantidade de números gerados até encontrar 25 números primos: %d\n", n_gerados);

    return 0;
}