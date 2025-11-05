#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char letra;
} tDatos;

int main() {
    /* Declaración de punteros*/
    tDatos *pApunt1;
    tDatos *pApunt2;

    /* Reserva dinámica de memoria para la estructura*/
    pApunt1 = (tDatos*) malloc(sizeof(tDatos));
    

    /* Inicialización de valores*/
    pApunt1->numero = 42;
    pApunt1->letra = 'X';

    /* Mostrar información inicial*/
    printf("Direccion del puntero pApunt1: %p\n", &pApunt1);
    printf("Valores: numero=%d, letra=%c\n", pApunt1->numero, pApunt1->letra);

    /* Asignar el segundo puntero a la misma dirección*/
    pApunt2 = pApunt1;

    printf("\nDireccion del puntero pApunt2: %p\n", &pApunt2);
    printf("Valores a traves de pApunt2: numero=%d, letra=%c\n", pApunt2->numero, pApunt2->letra);

    /* Modificar uno de los campos desde pApunt2*/
    pApunt2->numero = 99;

    /* Mostrar nuevamente valores desde ambos punteros*/
    printf("\n--- Despues de modificar desde pApunt2 ---\n");
    printf("Valores desde pApunt1: numero=%d, letra=%c\n", pApunt1->numero, pApunt1->letra);
    printf("Valores desde pApunt2: numero=%d, letra=%c\n", pApunt2->numero, pApunt2->letra);

    /* Liberar memoria*/
    free(pApunt1);
    pApunt1 = NULL;
    pApunt2 = NULL;

    return 0;
}
