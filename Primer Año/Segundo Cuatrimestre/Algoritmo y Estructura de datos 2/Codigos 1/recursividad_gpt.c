#include <stdio.h>

// Función recursiva para calcular el factorial de un número
int factorial(int n) {
    // Caso base: cuando n es 0, el factorial es 1
    if (n == 0) {
        printf("Caso base alcanzado: factorial(0) = 1\n");
        return 1;
    } else {
        // Caso recursivo: n! = n * (n-1)!
        printf("Factorial(%d) = %d * Factorial(%d)\n", n, n, n - 1);
        return n * factorial(n - 1);
    }
}

int main() {
    // Ejemplo de uso de la función factorial
    int num = 5;
    printf("Calculando el factorial de %d:\n", num);
    int resultado = factorial(num);
    printf("El factorial de %d es: %d\n", num, resultado);

    return 0;
}
