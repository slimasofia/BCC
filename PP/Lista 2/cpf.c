#include <stdio.h>
#include <string.h>

int main(){
    char cpf[12];
    char d_verificador[3];
    int soma = 0, soma2 = 0;
    int d1 = 0, d2 = 0;
    
    printf("Digite um cpf para ser verificado: ");
    scanf("%s", cpf);

    d_verificador[0] = cpf[9];
    d_verificador[1] = cpf[10];
    d_verificador[2] = '\0';

    cpf[9] = '\0';
    cpf[10] = '\0';

    for(int i = 0; i < 9; i++){
      soma += (cpf[8 - i] - '0') * (i + 2);
    }

    if((soma % 11) < 2){
        d1 = 0;
    } else {
        d1 = 11 - (soma % 11);
    }

    cpf[9] = d1 + '0';

    for(int i = 0; i < 10; i++){
      soma2 += (cpf[9 - i] - '0') * (i + 2);
    }

    if((soma2 % 11) < 2){
        d2 = 0;

    } else {
        d2 = 11 - (soma2 % 11);
    }

    if (d_verificador[0] == (d1 + '0') && d_verificador[1] == (d2 + '0')) {
        printf("O CPF é válido\n");
    } else {
        printf("O CPF não é válido\n");
    }
    
    return 0;
}