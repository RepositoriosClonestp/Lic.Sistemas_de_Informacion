/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Declaración de tipos de datos personalizados */
typedef char tString[25];

typedef struct{
	int campo1;
	tString campo2;	
}tInfo;


typedef struct nodo {
	
	tInfo data;
	
	struct nodo * siguiente;
}tPila;

tPila * pila;


void inicializarPila();
bool pilaVacia(tPila *);
void apilar(tInfo);
void desapilar(tPila *);
void visualizar(tPila *);
void mostrarCima(tPila *);
tInfo cima(tPila *);

void menu();

void cargarDatosTInfo();

int opcion;

int main(){
	inicializarPila();
	menu();
	return 0;
}

void ingresarOpcion(){
	printf("ingrese una opcion \n");
	printf("1 - apilar \n");
	printf("2 - desapilar \n");
	printf("3 - mostrar Cima \n");	
	printf("4 - visualizar \n");	
	printf("5 - salir \n");
	scanf("%d",&opcion);
}

void menu(){
	ingresarOpcion();
	while(opcion !=5 ){
		
		switch(opcion){
			case 1: 
					break; 
			case 2: 
					break; 
			default : printf("\n opcion incorrecta!");
				break;
		}
		
		
		ingresarOpcion();
	}	
}




void inicializarPila(){
	
}

void cargarDatosTInfo(){

}
