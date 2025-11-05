#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Declaración de tipos de datos personalizados */
/* Declaración de prototipos */
void ejPunteroFloatEstatico();
void ejPunteroFloatDinamico();
void ejPunteroIntEstatico();
void ejPunteroIntDinamico();
void ejPunteroCharEstatico();
void mostrarSeparador(const char* titulo);

/* Declaración de variables */
/* Bloque principal */
int main() {
    printf("PROGRAMA DE GESTION DE MEMORIA CON PUNTEROS\n");
    printf("==========================================\n");
    
    ejPunteroFloatEstatico();
    ejPunteroFloatDinamico();
    ejPunteroIntEstatico();
    ejPunteroIntDinamico();
    ejPunteroCharEstatico();
    
    return 0;
}

/* Implementación de funciones */
void mostrarSeparador(const char* titulo) {
    printf("\n=== %s ===\n", titulo);
}

void ejPunteroFloatEstatico() {
    mostrarSeparador("PUNTERO FLOAT - ASIGNACION ESTATICA");
    
    /* Asignación estática de memoria */
    float peso; /*Variable tipo float*/
    float * apPeso; /*puntero que almacena la dirección de una variable float*/
    
    printf("ANTES DE ASIGNAR EL PUNTERO:\n");
    printf("La direccion de la variable peso: %p\n", &peso);
    printf("El valor inicial de peso (basura): %.2f\n", peso);
    
    apPeso = &peso; /*&peso dirección de memoria donde está la variable peso*/
    
    printf("\nDESPUES DE ASIGNAR EL PUNTERO:\n");
    printf("La direccion de la variable peso: %p\n", &peso);
    printf("La direccion almacenada en apPeso: %p\n", apPeso);
    printf("La direccion del puntero apPeso: %p\n", &apPeso);
    
    printf("\nASIGNANDO VALORES:\n");
    peso = 50.0;
    printf("Despues de peso = 50.0:\n");
    printf("El valor de la variable peso: %.2f\n", peso);
    printf("El valor via puntero *apPeso: %.2f\n", *apPeso);
    
    *apPeso = 55.75;
    printf("\nDespues de *apPeso = 55.75:\n");
    printf("El valor de la variable peso: %.2f\n", peso);
    printf("El valor via puntero *apPeso: %.2f\n", *apPeso);
}

void ejPunteroFloatDinamico() {
    mostrarSeparador("PUNTERO FLOAT - ASIGNACION DINAMICA");
    
    /* Asignación dinámica */
    float * apFloat;
    
    printf("ANTES DE MALLOC:\n");
    printf("Direccion del puntero apFloat: %p\n", &apFloat);
    printf("Contenido inicial de apFloat (basura): %p\n", apFloat);
    
    /* Se reserva memoria para una variable de tipo float y 
       se asigna esa dirección de memoria al puntero */
    apFloat = ( float * ) malloc( sizeof(float) ); 
    
    printf("\nDESPUES DE MALLOC:\n");
    printf("Direccion del puntero apFloat: %p\n", &apFloat);
    printf("Contenido de apFloat (direccion asignada): %p\n", apFloat);
    
    *apFloat = 25.75;
    printf("\nDESPUES DE ASIGNAR VALOR 25.75:\n");
    printf("Contenido de apFloat: %p\n", apFloat);
    printf("Contenido de la variable referenciada por apFloat: %.2f\n", *apFloat);
    
    /* Modificando el valor */
    *apFloat = 3.14; /* Implementando el caso específico del punto c) */
    printf("\nDESPUES DE MODIFICAR A 3.14:\n");
    printf("Contenido de la variable referenciada por apFloat: %.2f\n", *apFloat);
    
    /* Cuando ya no se necesita la variable referenciada, hay que liberar la memoria */
    printf("\nLIBERANDO MEMORIA:\n");
    free(apFloat);
    printf("Memoria liberada\n");
    
    apFloat = NULL;
    printf("apFloat establecido a NULL: %p\n", apFloat);
    
    printf("\nREASIGNANDO MEMORIA DINAMICA:\n");
    apFloat = ( float * ) malloc( sizeof(float) ); 
    *apFloat = 50.75;
    
    printf("Nueva direccion de apFloat: %p\n", apFloat);
    printf("Nuevo valor en apFloat: %.2f\n", *apFloat);
    
    /* Liberando la segunda asignación */
    free(apFloat);
    apFloat = NULL;
    printf("Segunda memoria liberada y puntero establecido a NULL\n");
}

void ejPunteroIntEstatico() {
    mostrarSeparador("PUNTERO INT - ASIGNACION ESTATICA");
    
    /* Asignación estática de memoria */
    int numero; /*Variable tipo int*/
    int * apNumero; /*puntero que almacena la dirección de una variable int*/
    
    printf("ANTES DE ASIGNAR EL PUNTERO:\n");
    printf("La direccion de la variable numero: %p\n", &numero);
    
    apNumero = &numero;
    
    printf("\nDESPUES DE ASIGNAR EL PUNTERO:\n");
    printf("La direccion de la variable numero: %p\n", &numero);
    printf("La direccion almacenada en apNumero: %p\n", apNumero);
    printf("La direccion del puntero apNumero: %p\n", &apNumero);
    
    numero = 42;
    printf("\nDespues de numero = 42:\n");
    printf("El valor de la variable numero: %d\n", numero);
    printf("El valor via puntero *apNumero: %d\n", *apNumero);
    
    *apNumero = 100;
    printf("\nDespues de *apNumero = 100:\n");
    printf("El valor de la variable numero: %d\n", numero);
    printf("El valor via puntero *apNumero: %d\n", *apNumero);
}

void ejPunteroIntDinamico() {
    mostrarSeparador("PUNTERO INT - ASIGNACION DINAMICA");
    
    /* Asignación dinámica */
    int * apInt;
    
    printf("ANTES DE MALLOC:\n");
    printf("Direccion del puntero apInt: %p\n", &apInt);
    
    apInt = ( int * ) malloc( sizeof(int) );
    
    printf("\nDESPUES DE MALLOC:\n");
    printf("Direccion del puntero apInt: %p\n", &apInt);
    printf("Contenido de apInt (direccion asignada): %p\n", apInt);
    
    *apInt = 555;
    printf("\nDESPUES DE ASIGNAR VALOR 555:\n");
    printf("Contenido de apInt: %p\n", apInt);
    printf("Contenido de la variable referenciada por apInt: %d\n", *apInt);
    
    *apInt = 777;
    printf("\nDESPUES DE MODIFICAR A 777:\n");
    printf("Contenido de la variable referenciada por apInt: %d\n", *apInt);
    
    free(apInt);
    apInt = NULL;
    printf("\nMemoria liberada y puntero establecido a NULL\n");
}

void ejPunteroCharEstatico() {
    mostrarSeparador("PUNTERO CHAR - ASIGNACION ESTATICA");
    
    /* Asignación estática de memoria */
    char letra; /*Variable tipo char*/
    char * apLetra; /*puntero que almacena la dirección de una variable char*/
    
    printf("ANTES DE ASIGNAR EL PUNTERO:\n");
    printf("La direccion de la variable letra: %p\n", &letra);
    
    apLetra = &letra;
    
    printf("\nDESPUES DE ASIGNAR EL PUNTERO:\n");
    printf("La direccion de la variable letra: %p\n", &letra);
    printf("La direccion almacenada en apLetra: %p\n", apLetra);
    printf("La direccion del puntero apLetra: %p\n", &apLetra);
    
    letra = 'A';
    printf("\nDespues de letra = 'A':\n");
    printf("El valor de la variable letra: %c\n", letra);
    printf("El valor via puntero *apLetra: %c\n", *apLetra);
    
    *apLetra = 'Z';
    printf("\nDespues de *apLetra = 'Z':\n");
    printf("El valor de la variable letra: %c\n", letra);
    printf("El valor via puntero *apLetra: %c\n", *apLetra);
}
