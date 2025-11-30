#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int insertarPrimero (lista *lista, tElem *dato);
void inicializacion (lista *lista);

typedef struct tElem {
	int codProducto;
	char descrip[50];
	float precio;
};

typedef struct nodo {
	tElem *dato;
	struct elementoLista *siguiente;
}elementos;

typedef struct listaIdentificar {
	elemento *inicio;
	elemento *fin;
	int tamanio;
}lista;

int main (){
}

void inicializacion (lista *lista){
	lista->inicio = NULL;
	lista->fin = NULL;
	tamanio = 0;
}
int insertarPrimero (lista *lista, char *dato){
	elemento *nuevo_elemento;
	if ((nuevo_elemento = (elemento *) malloc (sizeof(elemento))) == NULL)
	return -1;
	if ((nuevo_elemento->dato = (char*) malloc (50 * sizeof(char))) == NULL)
	return -1;
	
	strcpy (nuevo_elemento->dato, dato);
	
	nuevo_elemento->siguiente = NULL;
	lista->inicio = nuevo_elemento;
	lista->fin = nuevo_elemento;
	lista->tamanio++;
	return 0;
}
