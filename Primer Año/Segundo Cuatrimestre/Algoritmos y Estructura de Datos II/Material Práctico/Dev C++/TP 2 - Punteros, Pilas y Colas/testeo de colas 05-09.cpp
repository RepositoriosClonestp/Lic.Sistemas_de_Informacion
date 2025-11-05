#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString [40];
typedef enum {VISA = 1, MASTERCARD
}tTarjeta;

typedef struct {
	int tipoTarjeta;
	long numTarjeta;
	long dni;
	tString nombre;
}tDatos;

typedef struct nodo {
	tDatos cliente;
	struct nodo *siguiente;
}tNodo;

typedef struct{
	tNodo *principio;
	tNodo *final;
}tCola;

// Prototipos Principales
void inicializar(tCola *pCola);
bool colaVacia(tCola pCola);


tCola colaClientes; // CUANDO LA VARiABLE NO ES TIPO PUNTERO UTILIZAR ., CUANDO ES UN TIPO PUNTERO USAR ->

// Función Principal
int main(){
	char visa[50];
	strcpy(visa, "Visa\n");
	printf("%s", visa);
	int p;
	inicializar(&colaClientes);
	p = colaVacia(colaClientes);
	printf("%d", p);
	return 0;
}

// Desarrollo de Funciones
void inicializar(tCola *pCola){
	pCola->principio = NULL;
	pCola->final = NULL;
}

bool colaVacia(tCola pCola){
	return (pCola.principio == NULL && pCola.final == NULL);
}
