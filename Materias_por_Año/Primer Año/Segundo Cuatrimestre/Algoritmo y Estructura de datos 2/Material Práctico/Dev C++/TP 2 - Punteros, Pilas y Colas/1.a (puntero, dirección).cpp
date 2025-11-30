#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char tstring[25];

void itemA();

tstring * apuntCadena;

int main(){
	itemA();
	
	return 0;
}

void itemA(){
	// asignación dinámica
	apuntCadena = (tstring *) malloc(sizeof(tstring));
	strcpy((*apuntCadena), "Maria Acosta");
	printf("\n Contenido de la variable apuntada: %s ", *apuntCadena);
	printf("\n Direccion de la variable apuntada: %p ", apuntCadena);
	printf("\n Direccion de la variable puntero: %p ", &apuntCadena);
}
