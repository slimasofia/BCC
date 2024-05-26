#include <stdio.h>

int main(){

int n1, n2, soma1 = 0, soma2 = 0;

    printf("Digite o primeiro número: \n");
    scanf("%d", &n1);

    printf("Digite o segundo número: \n");
    scanf("%d", &n2);

    for(int i = 1; i < n1; ++i){
        if (n1 % i == 0){
            soma1 += i; 
        }
    }

    for(int i = 1; i < n2; ++i){
        if (n2 % i == 0){
            soma2 += i; 
        } 
    }

    if (soma1 == n2 && soma2 == n1){
        printf("%d e %d são números amigos! \n", n1, n2);
    } else{
        printf("%d e %d não são números amigos! \n", n1, n2);
    }

    return 0;
}
