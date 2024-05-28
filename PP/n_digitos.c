#include <stdio.h>

int contaDigito(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + contaDigito(n / 10);
}

int main() {
    int n;
    int q;

    printf("Digite um número inteiro: \n");
    scanf("%d", &n);

    if (n == 0) {
        q = 1;
    } else {
        q = contaDigito(n);
    }

    printf("O número %d tem %d dígito(s)\n", n, q);
    return 0;
}
