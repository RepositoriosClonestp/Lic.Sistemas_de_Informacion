#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
	int codigo;
	int rubro;
	int cantidad;
	float precio;
	char nombre[30];
}tData;
typedef struct nodo{
	tData infoVenta;
	struct nodo *sig;
}pilaV;

pilaV *ventas;

void inicializarPila();
bool pilaVacia(pilaV *lista);
void apilar(tData); // Funcion insertar adelante
void desapilar(pilaVentas *); // Funcion eliminar adelante
void visualizar(pilaVentas *);
void mostrarCima(pilaVentas *);

int main(){
	
}

//Desarrollo de Funciones
bool listaVacia(pilaV *lista){
	return (lista == NULL);
}
