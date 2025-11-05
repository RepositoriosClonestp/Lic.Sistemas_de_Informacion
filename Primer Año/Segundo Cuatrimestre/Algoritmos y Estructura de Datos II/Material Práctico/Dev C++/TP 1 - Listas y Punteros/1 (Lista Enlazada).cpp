#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int tElem;
typedef struct nodo{
	tElem elem;
	struct nodo *siguiente;
}tLista;

tLista *lista;

void inicializarLista();
bool listaVacia (tLista * );
void insertarPrimero(tElem);
void insertarAdelante(tElem);
void insertarElemento(tElem);
void eliminarPrimero();
void visualizarElementos(tLista * );
void insertarK(int k, tElem);
void eliminarK(int k );
void menu();

int main(){
	inicializarLista();
	printf("Lista vacia? %s\n", listaVacia(lista) ? "si" : "no");
	insertarElemento(1);
	printf("Lista vacia? %s\n", listaVacia(lista) ? "si" : "no");
	insertarElemento(2);
	insertarElemento(3);
	visualizarElementos(lista);
	insertarK(3,5);
	visualizarElementos(lista);
	insertarK(2,10);
	visualizarElementos(lista);
	eliminarPrimero();
	visualizarElementos(lista);
	eliminarK(2);
	visualizarElementos(lista);
	
	return 0;
	
	return 0;
}

void inicializarLista(){
	lista = NULL;
}

bool listaVacia( tLista *pLista){
	return (pLista == NULL);
}

void insertarElemento(tElem pElem){
	if (lista == NULL)
	 insertarPrimero(pElem);
	else
	 insertarAdelante(pElem);
}

void insertarPrimero(tElem pElem){
	tLista *nuevoNodo;
	nuevoNodo = (tLista * ) malloc (sizeof(tLista));
	
	nuevoNodo->elem = pElem;
	nuevoNodo->siguiente = NULL;
	
	printf(" Primer nodo insertado \n");
}

void insertarAdelante(tElem pElem) {
	tLista *nuevoNodo;
	nuevoNodo = (tLista * ) malloc (sizeof(tLista));
	
	nuevoNodo->elem = pElem;
	nuevoNodo->siguiente = lista;
	lista = nuevoNodo;
	
	printf("Elemento insertado \n");
}

void eliminarPrimero(){
	tLista *nodoSuprimir;
	
	nodoSuprimir = lista;
	lista = lista->siguiente;
	free(nodoSuprimir);
	nodoSuprimir = NULL;
	
	printf("Primer elemento eliminado\n");
}

void visualizarElementos(tLista *pLista){
	tLista *aux;
	aux = pLista;
	
	if (!listaVacia(pLista)){
		printf("\n Detalle de elementos en la lista \n");
		while (aux != NULL){
			printf("%d", aux->elem);
			aux = aux->siguiente;
		}
	} else {
		printf ("\n La lista esta vacia \n");
	}
	printf("\n\n");
}

void insertarK (int k, tElem nuevoDato){
	tLista *nuevoNodo, *aux;
	int i;
	aux = lista;
	
	for (i=1; i<k-1; i++){
		aux = aux->siguiente;
	}
	
	nuevoNodo = (tLista * ) malloc(sizeof(tLista));
	nuevoNodo->elem = nuevoDato;
	nuevoNodo->siguiente = aux->siguiente;
	
	printf("Elemento insertado en la posicion %d\n", k);
}

void eliminarK(int k) {
	tLista *nodoSuprimir, *aux;
	int i;
	aux = lista;
	
	for (i=1; i<k-1; i++){
		aux = aux->siguiente;
	}
	
	nodoSuprimir = aux->siguiente;
	aux->siguiente = nodoSuprimir->siguiente;
	free(nodoSuprimir);
	
	nodoSuprimir = NULL;
	
	printf(" Elemento de la posicion %d eliminado\n", k);
	
}





























































