#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>

// definicion de estructuras
typedef char tString[25];
typedef struct {
	int codigo;
	tString descripcion;
}tDatos;

typedef struct nodoCola{
	tDatos datosCola;
	struct nodoCola *siguiente;
}tNodoCola;

typedef struct {
	tNodoCola *principio;
	tNodoCola *final;
}tCola;

tCola cola;

//prototipos
void inicializar(tCola *);
bool colaVacia(tCola );
void visualizar(tCola );

void agregar(tCola *);
void eliminar(tCola *);

int main(){
	inicializar(&cola);
	agregar(&cola);
	agregar(&cola);
	eliminar(&cola);
	visualizar(cola);
	
	return 0;
}

void inicializar(tCola *pCola){
	pCola->principio = NULL;
	pCola->final = NULL;
}

bool colaVacia(tCola pCola){
	return ((pCola.principio == NULL) && (pCola.final == NULL));
}

void visualizar(tCola pCola){
	tNodoCola *aux;
	aux = pCola.principio;
	while (aux != NULL){
		printf("cod: %d", aux->datosCola.codigo);
		printf("descrp: %s", aux->datosCola.descripcion);
		aux = aux->siguiente;
	}
	
}

void agregar(tCola *pCola){
	tNodoCola *nuevoNodo;
	int codigo;
	tString descripcion;
	nuevoNodo = (tNodoCola *) malloc (sizeof(tNodoCola));
	
	printf(" Ingrese codigo: ");
	scanf("%d", &codigo);
	fflush(stdin);
	printf(" Ingrese descripcion: ");
	gets(descripcion);
	nuevoNodo->datosCola.codigo = codigo;
	strcpy(nuevoNodo->datosCola.descripcion, descripcion);
	nuevoNodo->siguiente = NULL;
	
	if(pCola->principio == NULL){
		pCola->principio = nuevoNodo;
		pCola->final = nuevoNodo;
	}
	else{
		pCola->final->siguiente = nuevoNodo;
		pCola->final = nuevoNodo;
	}
}

void eliminar(tCola *pCola){
	if(pCola == NULL){
		//nada que eliminar
	}
	else{
		tNodoCola *nodoSuprimir;
		nodoSuprimir = pCola->principio;
		if(pCola->final == pCola->principio){
			inicializar(pCola);
		}
		else{
			pCola->principio = nodoSuprimir->siguiente;
			free(nodoSuprimir);
			nodoSuprimir = NULL;
		}
	}
}




















