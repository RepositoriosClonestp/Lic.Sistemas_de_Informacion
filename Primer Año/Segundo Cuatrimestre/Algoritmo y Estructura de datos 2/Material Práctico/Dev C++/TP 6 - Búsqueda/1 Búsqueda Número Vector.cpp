#include<stdio.h>
#include<iostream>
#include<stdbool.h>
typedef int tVector[5];

void cargar(tVector );
void visualizar(tVector);
void inicializar(tVector);
bool buscador(tVector, int);

tVector vector;

int main(){
	int busqueda, elemBuscar;
	inicializar(vector);
	cargar(vector);
	visualizar(vector);
	printf("\n Ingrese numero a buscar: ");
	scanf("%D", &elemBuscar);
	busqueda = buscador(vector, elemBuscar);
	if(busqueda == true){
		printf("\n Elemento encontrado");
	}
	else{
		printf("\n Elemento no encontrado");
	}
	
	return 0;
}

void inicializar(tVector pVector){
	int i;
	for(i=0; i<5; i++){
		pVector = 0;
	}
}

void cargar(tVector pVector){
	int i;
	for(i=0; i<5; i++){
		printf(" Cargue un valor: ");
		scanf("%d", &pVector[i]);
		
	}
}

void visualizar(tVector pVector){
	int i;
	for(i=0; i<5; i++){
		printf("\n Valor %d: %d", i+1, pVector[i]);
	}
}

bool buscador(tVector pVector, int pNum){
	int i;
	for (i=0; i<5; i++){
		if(pNum == pVector[i]){
			return true;
		}
	}
}
