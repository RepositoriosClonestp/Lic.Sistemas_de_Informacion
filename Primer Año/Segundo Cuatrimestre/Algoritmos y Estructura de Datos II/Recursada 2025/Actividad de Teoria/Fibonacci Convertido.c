#include <stdio.h>

// Funcion iterativa para calcular Fibonacci
int fibonacci_iterativo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0;
    int b = 1;
    int c;
    int i;  // declaracion de la i

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n;

    printf("Ingrese la posicion de la serie de Fibonacci: ");
    scanf("%d", &n);

    printf("El termino en la posicion %d es: %d\n", n, fibonacci_iterativo(n));

    return 0;
}
