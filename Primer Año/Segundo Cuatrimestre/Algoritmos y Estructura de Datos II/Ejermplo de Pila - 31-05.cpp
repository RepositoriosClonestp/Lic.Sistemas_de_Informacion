/* Ejemplo de Pila con Vectores */
#include <stdio.h>
#include <stdbool.h>
#define MAX 5
typedef char tArrayChar[MAX];
typedef struct {
tArrayChar listaCaracteres;
int tope;
}tPilaCaracteres;
void crearPilaVacia();
bool pilaVacia( tPilaCaracteres );
bool pilaLlena( tPilaCaracteres );
void apilarCaracter( char );
void desapilarCaracter();
char cima( tPilaCaracteres );
void visualizarElementosApilados( 
tPilaCaracteres );
void menu();
tPilaCaracteres pila;

int main() { 
crearPilaVacia();
menu(); 
return 0;
}
void crearPilaVacia() {
pila.tope = -1;
printf("\nSe inicializo la pila!\n");
}
bool pilaVacia( tPilaCaracteres pPila ) { 
return ( pPila.tope == -1 ) ; 
}
bool pilaLlena( tPilaCaracteres pPila ) {
return ( pPila.tope == MAX-1 );
}
