#include<stdio.h>
#include<iostream>
const int MAX = 10;
typedef float tVector[MAX];

void ordenarBurbuja(tVector, int);
void ordenarSeleccion(tVector, int);
void ordenarInsersion(tVector, int);
void visualizarVector(tVector, int);

int main(){
	tVector burbuja = {3.2, 4.5, 1.2, 7, 21, 2.3, 9.3, 8.8, 11, 1.1};
	tVector seleccion = {3.2, 4.5, 1.2, 7, 21, 2.3, 9.3, 8.8, 11, 1.1};
	tVector insersion = {3.2, 4.5, 1.2, 7, 21, 2.3, 9.3, 8.8, 11, 1.1};
	
	ordenarBurbuja(burbuja, MAX);
	ordenarSeleccion(seleccion, MAX);
	ordenarInsersion(insersion, MAX);
	
	printf("\n Burbuja: ");
	visualizarVector(burbuja, MAX);
	printf("\n Seleccion: ");
	visualizarVector(seleccion, MAX);
	printf("\n Insersion: ");
	visualizarVector(insersion, MAX);
	
	return 0;
}

void ordenarBurbuja(tVector pVector, int pDimension){
	float aux;
	int i, j;
	for(i=1; i<pDimension; i++){
		for(j=0; j<pDimension-i; j++){
			if(pVector[j] > pVector[j+1]){
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
			}
		}
	}
}

void ordenarSeleccion(tVector pVector, int pDimension){
	float aux;
	int i, j, menor;
	
	for(i=0; i<pDimension-1; i++){
		menor = i;
		
		for(j=i+1; j<pDimension; j++){
			if(pVector[j] < pVector[menor]){
				menor = j;
			}
		}
		if(menor != i){
			aux = pVector[i];
			pVector[i] = pVector[menor];
			pVector[menor] = aux;
		}
	}
}

void ordenarInsersion(tVector pVector, int pDimension){
	int i, j;
	float aux;
	
	for(i=1; i<pDimension; i++){
		j = i;
		aux = pVector[i];
		
		while(j>0 && aux<pVector[j-1]){
			pVector[j] = pVector[j-1];
			j--;
		}
		pVector[j] = aux;
	}
}


void visualizarVector(tVector pVector, int pDimension){
	int i;
	for(i=0; i<pDimension; i++){
		printf(" %.2f - ", pVector[i]);
	}
}















