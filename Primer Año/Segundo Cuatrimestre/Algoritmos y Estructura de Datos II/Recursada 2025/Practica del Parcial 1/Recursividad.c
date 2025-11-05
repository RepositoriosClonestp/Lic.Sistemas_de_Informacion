#include <stdio.h>

void mostrarMultiplos(int numero, int limite, int i) {
    if (i > limite) { // Caso base: si ya supero el limite, termina
        return;
    }
    printf("%d * %d = %d\n", numero, i, numero * i);
    mostrarMultiplos(numero, limite, i + 1); // Llamada recursiva
}

int main() {
    int numero, limite;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    printf("Ingrese el limite: ");
    scanf("%d", &limite);

    mostrarMultiplos(numero, limite, 0);

    return 0;
}

