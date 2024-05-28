#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);

    printf("O termo %d da sequência de Fibonacci é: %d\n", n, fibonacci(n));

    return 0;
}
