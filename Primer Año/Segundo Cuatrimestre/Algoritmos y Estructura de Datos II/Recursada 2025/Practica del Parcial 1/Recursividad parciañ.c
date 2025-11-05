#include <stdio.h>

// Prototipos
void cuentaRegresiva(int n);
int factorial(int n);
int sumaHastaN(int n);

// Implementación

// Cuenta regresiva desde n hasta 1
void cuentaRegresiva(int n) {
    if (n == 0) {
        printf("¡Despegue!\n");
    } else {
        printf("%d\n", n);
        cuentaRegresiva(n - 1);  // Llamada recursiva
    }
}

// Factorial de un número (n! = n * (n-1) * ... * 1)
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;   // Caso base
    }
    return n * factorial(n - 1); // Llamada recursiva
}

// Suma de números desde 1 hasta n
int sumaHastaN(int n) {
    if (n == 0) {
        return 0;   // Caso base
    }
    return n + sumaHastaN(n - 1); // Llamada recursiva
}

