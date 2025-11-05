#include <stdio.h>

void cargarPila();
void listarPesoDiscos();
void quitarDisco();
void detectarTope();
void mostrarDiscosApilados();
void calcularPromedio();

float pila[12];

int main(){
	cargarPila();
	quitarDisco();
	listarPesoDiscos();
	
	return 0;
}

void cargarPila(){
	int i;
	for (i=0; i<12; i++){
		printf(" Ingrese peso del disco por apilar: ");
		scanf("%f", &pila[i]);
	}
}

void listarPesoDiscos(){
	int i;
	printf(" Lista de peso de los discos: ");
	for (i=0; i<12; i++){
		printf(" %.2f \n", pila[i]);
	}
}

void quitarDisco(){
	int i, k;
	






