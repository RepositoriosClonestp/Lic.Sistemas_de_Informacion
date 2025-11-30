#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Declaración de tipos de datos personalizados */

/* Declaración de prototipos */
void ejPunteroFloatEstatico();
void ejPunteroFloatDinamico();

/* Declaración de variables */

/* Bloque principal */
int main() {
	ejPunteroFloatEstatico();
	ejPunteroFloatDinamico();
	return 0;
}

/* Implementación de funciones */
void ejPunteroFloatEstatico() {
	/* Asignación estática de memoria */
	float peso; /*Variable tipo float*/
	float * apPeso; /*puntero que almacena la dirección de una variable float*/
	apPeso = &peso; /*&peso dirección de memoria donde está la variable peso*/
	
	printf("La direccion de la variable peso: %p\n", &peso);
	printf("La direccion de la variable peso: %p\n", apPeso);
	
	peso = 50.0;
	*apPeso = 55.75;
	
	printf("El valor de la variable peso: %.2f\n", peso);
	printf("El valor de la variable peso: %.2f\n", *apPeso);	
	
}

void ejPunteroFloatDinamico() {
	/* Asignación dinámica */
	float * apFloat;
	
	/* 	Se reserva memoria para una variable de tipo float y 
		se asigna esa dirección de memoria al puntero */
	apFloat = ( float * ) malloc( sizeof(float) ); 
	*apFloat = 25.75;
	
	printf("Contenido de apFloat: %p\n", apFloat);
	printf("Contenido de la variable referenciada por apFloat: %.2f\n", *apFloat);
	
	/* Cuando ya no se necesita la variable referenciada, hay que liberar la memoria */
	free(apFloat);
	
	apFloat = NULL;
	
	apFloat = ( float * ) malloc( sizeof(float) ); 
	*apFloat = 50.75;
	
	printf("Contenido de apFloat: %p\n", apFloat);
	printf("Contenido de la variable referenciada por apFloat: %.2f\n", *apFloat);
}
