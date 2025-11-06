/* 1.	Crear un tipo de dato tListaVideojuegos para un nodo que permita almacenar 
		los siguientes datos de un videojuego: 
		idJuego (entero), titulo (cadena de 50 caracteres), anioLanzamiento (entero), 
		precio (flotante).
		Luego, declarar un puntero a una variable de ese tipo, crear el primer nodo 
		de la lista a partir del ingreso de datos por teclado, y mostrar todos los 
		datos del nodo almacenado. 
		Importante: Implementar también la liberación correcta de la memoria asignada. */
		
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

typedef char tString50[MAX];

typedef struct{
	int idJuego;
	tString50 titulo;
	int anioLanzamiento;
	float precio;
}tDatosVideojuego;

typedef struct nodo{
	tDatosVideojuego videojuego;
	struct nodo* siguiente;
}tListaVideojuegos;

/*Definición de funciones*/
tListaVideojuegos* crearNodo(); /*función que devuelve un puntero a un nodo recién creado.*/
void mostrarDatosNodo(tListaVideojuegos*); /*función que recibe un nodo y muestra sus datos.*/
void liberarMemoria(tListaVideojuegos**); /*función que recibe un doble puntero y libera la memoria del nodo.*/

int main() {
	tListaVideojuegos* primerNodo = crearNodo();
	
	if(primerNodo != NULL){
	    mostrarDatosNodo(primerNodo);
	    liberarMemoria(&primerNodo);
	}else{
		printf("No hay memoria disponible!");
		exit(1);
	}
	
	/*verificar que la memoria se liberó*/
	if(primerNodo == NULL) {
		printf("La memoria del nodo se libero exitosamente!");
	}
	
	return 0;
}

tListaVideojuegos* crearNodo(){
	tListaVideojuegos* nodo = NULL; 
    
    /* Asignar memoria para el primer nodo*/
    nodo = (tListaVideojuegos*) malloc(sizeof(tListaVideojuegos));
    
    if (nodo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL;
    }
    
    /* Ingresar datos*/
    printf("\n ## CREAR PRIMER VIDEOJUEGO ##\n");
    printf("\tID del juego: ");
    scanf("%d", &nodo->videojuego.idJuego);
    
    printf("\tTitulo: ");
    scanf(" %49[^\n]", nodo->videojuego.titulo);
    
    printf("\tAnio de lanzamiento: ");
    scanf("%d", &nodo->videojuego.anioLanzamiento);
    
    printf("\tPrecio: ");
    scanf("%f", &nodo->videojuego.precio);
    
        
    nodo->siguiente = NULL;
    
    return nodo;
}


void mostrarDatosNodo(tListaVideojuegos* nodo) {
	printf("\n--------------------------------\n");
    printf("## DATOS DEL VIDEOJUEGO ##\n");
    printf("ID del juego        : %d\n", nodo->videojuego.idJuego);
    printf("Titulo              : %s\n", nodo->videojuego.titulo);
    printf("Anio de lanzamiento : %d\n", nodo->videojuego.anioLanzamiento);
    printf("Precio              : $%.2f\n", nodo->videojuego.precio);
    printf("--------------------------------\n");
}

/* Recordar que es necesario doble asterisco para modificar el nodo original*/
void liberarMemoria(tListaVideojuegos** nodo) {
	/* Liberar memoria*/
    free(*nodo);
    *nodo = NULL;
    
    printf("\nMemoria liberada correctamente.\n");
}


