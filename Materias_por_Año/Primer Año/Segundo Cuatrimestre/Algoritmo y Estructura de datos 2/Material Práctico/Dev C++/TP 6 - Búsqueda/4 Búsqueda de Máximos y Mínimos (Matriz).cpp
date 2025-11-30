#include<stdio.h>
#include<iostream>

const int FILAS = 5, COLUMNAS = 4;
typedef int tMatriz[FILAS][COLUMNAS];

int valorMaximo(tMatriz, int, int);
int valorMinimo(tMatriz, int, int);

int main(){
	tMatriz matriz;
	int maximo, minimo;
	
	int i, j;
	for(i=0; i<FILAS; i++){
		for(j=0; j<COLUMNAS; j++){
			printf(" Ingrese entero positivo en\n i=%d - j=%d: ", i+1, j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
	
	maximo = valorMaximo(matriz, FILAS, COLUMNAS);
	minimo = valorMinimo(matriz, FILAS, COLUMNAS);
	
	printf(" Valor Maximo: %d \n Valor Minimo: %d\n", maximo, minimo);
	
	return 0;
}

int valorMaximo(tMatriz pMatriz, int pFilas, int pColumnas){
	int i, j;
	int mayor = 0;
	int posicionFila = -1;
	int posicionColumna = -1;
	
	for(i=0; i<pFilas; i++){
		for(j=0; j<pColumnas; j++){
			if(pMatriz[i][j] > mayor){
				mayor = pMatriz[i][j];
				posicionFila = i;
				posicionColumna = j;
			}
		}
	}
	printf(" Valor Maximo en Fila: %d - Columna: %d\n", posicionFila+1, posicionColumna+1);
	
	return mayor;
}

int valorMinimo(tMatriz pMatriz, int pFilas, int pColumnas){
	int i, j;
	int menor = 100000;
	int posicionFila = -1;
	int posicionColumna = -1;
	
	for(i=0; i<pFilas; i++){
		for(j=0; j<pColumnas; j++){
			if(pMatriz[i][j] < menor){
				menor = pMatriz[i][j];
				posicionFila = i;
				posicionColumna = j;
			}
		}
	}
	printf(" Valor Minimo en Fila: %d - Columna: %d\n", posicionFila+1, posicionColumna+1);
	
	return menor;
}
