#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>


typedef char tString[30];
typedef struct {
	int codigo;
	tString descripcion;
	float precio;
}tDatos;

typedef struct nodo{
	tDatos datosProducto;
	struct nodo *siguiente;
}tListaProd;

tListaProd *listaProductos;

//Prototipos
void visualizar(tListaProd *);
void inicializar(tListaProd **);
bool listaVacia(tListaProd *);

void insertarPrimer(tListaProd **);
void insertarPrimero(tListaProd **);
void insertarEn(int, tListaProd **);
void eliminarPrimero(tListaProd **);
void eliminarEn(int, tListaProd **);

//----------------------------------------------------------------------------

int main(){
	inicializar(&listaProductos);
	insertarPrimer(&listaProductos);
	insertarPrimer(&listaProductos);
	eliminarEn(2, &listaProductos);
	visualizar(listaProductos);
	
	return 0;
} 

//----------------------------------------------------------------------------

void visualizar(tListaProd * pLista){
	tListaProd *aux;
	aux = pLista;
	int contador = 0;
	while(aux != NULL){
		printf("\n Codigo: %d", aux->datosProducto.codigo);
		printf(" Descripcion: %s", aux->datosProducto.descripcion);
		printf(" Precio: %.2f \n", aux->datosProducto.precio);
		aux = aux->siguiente;
		contador++;
	}
	printf(" Cantidad de ventas: %d", contador);
}

void inicializar(tListaProd ** pLista){
	*pLista = NULL;
}

bool listaVacia (tListaProd *pLista){
	return pLista == NULL;
}

void insertarPrimer (tListaProd ** pLista){
	tListaProd *nuevoProducto;
	int codigo;
	tString descripcion;
	float precio;
	nuevoProducto = (tListaProd *) malloc(sizeof(tListaProd));
	
	printf(" Ingrese codigo producto: ");
	scanf("%d", &codigo);
	fflush(stdin);
	printf(" Ingrese descripcion producto: ");
	gets(descripcion);
	printf(" Ingrese precio producto: ");
	scanf("%f", &precio);
	
	nuevoProducto->datosProducto.codigo = codigo;
	strcpy(nuevoProducto->datosProducto.descripcion, descripcion);
	nuevoProducto->datosProducto.precio = precio;
	nuevoProducto->siguiente = NULL;
	
	if (*pLista == NULL){
		*pLista = nuevoProducto;
	}
	else{
		tListaProd *aux;
		aux = (*pLista);
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevoProducto;
	}

}

void insertarPrimero(tListaProd ** pLista){
	tListaProd *nuevoProducto;
	int codigo;
	tString descripcion;
	float precio;
	nuevoProducto = (tListaProd *) malloc(sizeof(tListaProd));
	
	printf(" Ingrese codigo producto: ");
	scanf("%d", &codigo);
	fflush(stdin);
	printf(" Ingrese descripcion producto: ");
	gets(descripcion);
	printf(" Ingrese precio: ");
	scanf("%f", &precio);
	
	nuevoProducto->datosProducto.codigo = codigo;
	strcpy(nuevoProducto->datosProducto.descripcion, descripcion);
	nuevoProducto->datosProducto.precio = precio;
	nuevoProducto->siguiente = *pLista;
	*pLista = nuevoProducto;
}

void insertarEn(int posicion, tListaProd ** pLista){
	tListaProd *nuevoProducto;
	tListaProd *aux;
	aux = *pLista;
	if(*pLista == NULL){
		printf(" Posicion inexistente a colocar. ");
	}
	else{
		int codigo;
		tString descripcion;
		float precio;
		int i;
	    for (i=1; i<posicion-1; i++){
		aux = aux->siguiente;
		}
		nuevoProducto = (tListaProd *) malloc(sizeof(tListaProd));
		printf(" Ingrese codigo producto");
		scanf("%d", &codigo);
		fflush(stdin);
		printf(" Ingrese descripcion producto");
		gets(descripcion);
		printf(" Ingrese precio producto");
		scanf("%f", &precio);
		
		nuevoProducto->datosProducto.codigo = codigo;
		strcpy(nuevoProducto->datosProducto.descripcion, descripcion);
		nuevoProducto->datosProducto.precio = precio;
		nuevoProducto->siguiente = aux->siguiente;
		aux->siguiente = nuevoProducto;
	}
}

void eliminarPrimero(tListaProd **pLista){
	if(*pLista == NULL){
		// nada que eliminar
	}
	else{
		tListaProd *nodoSuprimir;
		nodoSuprimir = *pLista;
		*pLista = (*pLista)->siguiente;
		free(nodoSuprimir);
		nodoSuprimir = NULL;
	}
	
}

void eliminarEn(int lugar, tListaProd **pLista){
	if(*pLista == NULL){
		//nada que eliminar
	}
	else{
		tListaProd *nodoSuprimir;
		tListaProd *aux;
		aux = *pLista;
		int i;
		for (i=1; i<lugar-1; i++){
			aux = aux->siguiente;
		}
		nodoSuprimir = aux->siguiente;
		aux->siguiente = nodoSuprimir->siguiente;
		free(nodoSuprimir);
		nodoSuprimir = NULL;
	}
}








