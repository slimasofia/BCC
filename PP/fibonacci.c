#include <stdio.h>

int fibonacci(int n) {
    int t1 = 0, t2 = 1, prox;
    if (n == 0) {
        return t1;
    }
    for (int i = 2; i <= n; ++i) {
        prox = t1 + t2;
        t1 = t2;
        t2 = prox; 
    }
    return t2;
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    printf("O termo %d da sequência de Fibonacci é: %d\n", n, fibonacci(n));

    return 0;
}
