/* Pila implementada con punteros ( utilizando listas enlazadas ) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Tipos de datos personalizados */

typedef char tString [25];

typedef struct {
	int codigo;
	tString descripcion;
	float precio;
}tData;

typedef struct node {
	tData data;
	struct node * siguiente; /*siguiente*/
}tPila; /* Define la estructura para un nodo de la Pila*/

/* Declaración de prototipos */

void inicializarPila(); /*inicializar pila*/
bool emptyStack( tPila * ); /* pila vacia*/
void insertarNodo( tData ); /*apilar*/
void eliminarNodo(); /*desapilatr*/
void mostrarDatos( tPila * ); /* mostrar elementos */
tData topNode( tPila * ); /* Retorna el elemento en la cima de la pila*/
tPila * topNode2( tPila * ); /* Retorna un puntero al nodo en la cima*/

/* Declaración de variables */

tPila * pila; /* es un puntero que apunta al nodo en la cima de la pila.*/
tData emptyData; /* es una variable que representa un nodo vacío.*/

/* Bloque principal */

int main() {
	tData data;
	
	emptyData.codigo = 0;
	strcpy(emptyData.descripcion, " ");
	emptyData.precio = 0.0;
	
	inicializarPila();
	
	data.codigo = 100;
	strcpy(data.descripcion, "Palta");
	data.precio = 237.50;	
	insertarNodo(data);
	
	data.codigo = 101;
	strcpy(data.descripcion, "Rucula");
	data.precio = 125.75;	
	insertarNodo(data);
	
	data.codigo = 102;
	strcpy(data.descripcion, "Tomates cherry");
	data.precio= 650.25;	
	insertarNodo(data);
	
	mostrarDatos(pila); /*Se muestra el contenido actual de la pila*/
	
	eliminarNodo();
	
	mostrarDatos(pila);	
	
	printf("\nTop node: %s \n", topNode(pila).descripcion);
	printf("Top node(version 2): %s \n", topNode2(pila)->data.descripcion);
	
	return 0;
}

/* Implementación de funciones */
void inicializarPila() {
	pila = NULL;
	printf("Pila inicializada ... \n"); /* Pila inicializada*/
}

bool emptyStack( tPila * pPila ) {
	return pPila == NULL;
}

void insertarNodo( tData pData ) {
	/* 1. Crear el nodo que se va a insertar */
	tPila * nuevoNodo;
	
	/* 2. Reservar y asignar memoria al nuevo nodo */
	nuevoNodo = (tPila * ) malloc(sizeof( tPila ));
	
	/* 3. Asignar el dato al campo del contenido */
	nuevoNodo->data = pData;
	/* 	(*newNode).data = pData;*/
	
	/* 4. Asignar un valor al campo siguiente (al puntero)  para que apunte al nodo actual en la cima de la pila.*/
	nuevoNodo->siguiente = pila;
	
	/* 5. Asignar la memoria del nuevo nodo a la cima de la pila. */
	pila = nuevoNodo;
	
	printf("Se ha insertado un nuevo nodo!\n"); 	
}



void eliminarNodo() {
	if( !emptyStack(pila) ) {
		/* 1. Guardar el nodo que vamos a eliminar en una variable auxiliar*/
		tPila * suprimirNodo; /* nodo a suprimir */
		suprimirNodo = pila;
		
		/* 2. Pasar al siguiente nodo de la lista, es decir romper el enlace 
		      (Desplaza la cima al siguiente nodo.)*/
		pila = pila->siguiente;
		
		printf("Nodo eliminado: %s\n", suprimirNodo->data.descripcion);
		
		/* 3. Liberar la memoria del nodo eliminado */
		free(suprimirNodo);
		
		/* 4. Asignar NULL a la variable puntero auxiliar utilizada para eliminar */
		suprimirNodo = NULL;
	} else {
		printf("Pila vacía!\n"); 
	}
}

void mostrarDatos( tPila * pPila ) {	
	if(emptyStack(pPila)) {
		printf("Pila Vacía!\n"); /* Pila vacía*/
	} else {
		tPila * aux = pPila;
		/* Hay elementos para visualizar */
		printf("\nInformacion\n");
		printf("-----------\n");
		printf("Codigo | Descripcion | Precio\n");
		while(aux != NULL) {
			printf("%d | %s | $ %.2f\n", 
					aux->data.codigo, 
					aux->data.descripcion, 
					aux->data.precio );
			aux = aux->siguiente; /* Pasamos al siguiente nodo*/
		}
	}
}

tData topNode( tPila * pPila ) { 

	/* if(emptyStack(pPila) == true) {
		return emptyData;
	} else {
		return pPila->data;
	} */

	return emptyStack(pPila) == true ? emptyData : pPila->data;
}

tPila * topNode2( tPila * pPila ) {
	/* if(emptyStack(pPila) == true) {
		return NULL;
	} else {
		return pSPila;
	}*/

	return emptyStack(pPila) == true ? NULL : pPila;
}



