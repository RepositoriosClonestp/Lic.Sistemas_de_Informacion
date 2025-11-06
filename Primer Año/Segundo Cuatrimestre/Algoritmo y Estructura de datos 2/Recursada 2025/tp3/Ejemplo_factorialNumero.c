#include <stdio.h>

int numero=5;
int calcularFactorial(int);

int main() {
    int numero = 5; 
    int resultado = calcularFactorial(numero);

    printf("El factorial de %d es: %d\n", numero, resultado);

    return 0;
}

int calcularFactorial(int pNumero) {
    if (pNumero == 0 || pNumero == 1) {
        return 1;  /* Caso base: 0! = 1 y 1! = 1*/
    }
    return pNumero * calcularFactorial(pNumero - 1);  /* Llamada recursiva*/
}
