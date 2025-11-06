#include <stdio.h>

int numero = 5; 
int calcularFactorial(int);

int main() {
    
    int resultado = calcularFactorial(numero);
    printf("El factorial de %d es: %d\n", numero, resultado);

    return 0;
}
/* Función que calcula factorial usando repetición (bucle for)*/
int calcularFactorial(int pNumero) {
    int i;
	int resultado = 1;

    for (i = 1; i <= pNumero; i++) {
        resultado *= i;  /* resultado = resultado * i*/
    }

    return resultado;
}


