#include <stdio.h>

int mult(int a, int b) {
 
    if (b == 0) {
        return 0;
    }
    return a + mult(a, b - 1);
}

int main() {
    int a = 5;
    int b = 15;
    int r = mult(a, b);
    printf("%d", r);
    return 0;
}
