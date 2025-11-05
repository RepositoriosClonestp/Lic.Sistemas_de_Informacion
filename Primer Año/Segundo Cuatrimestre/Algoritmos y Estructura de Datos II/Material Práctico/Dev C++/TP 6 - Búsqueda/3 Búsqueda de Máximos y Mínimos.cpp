#include<stdio.h>
#include<iostream>
#include<stdbool.h>

const int MAX = 5;
typedef int tVector[MAX];

int valorMaximo(tVector, int);
int valorMinimo(tVector, int);
float mediaVector(tVector, int);
float semisumaVector(int, int);

int main(){
	tVector vector;
	int i, maximo, minimo;
	float media, semisuma;
	
	for(i=0; i<MAX; i++){
		printf(" Ingrese entero positivo: ");
		scanf("%d", &vector[i]);
	}
	
	maximo = valorMaximo(vector, MAX);
	minimo = valorMinimo(vector, MAX);
	media = mediaVector(vector, MAX);
	semisuma = semisumaVector(valorMaximo(vector, MAX), valorMinimo(vector, MAX));
	
	printf(" Valor Maximo: %d \n Valor Minimo: %d \n Media: %.2f \n Semisuma: %.2f", maximo, minimo, media, semisuma);
	
	return 0;
}

int valorMaximo(tVector pVector, int pDimension){
	int i, mayor;
	mayor = 0;
	
	for (i=0; i<pDimension; i++){
		if(pVector[i] > mayor){
			mayor = pVector[i];
		}
	}
	
	return mayor;
}

int valorMinimo(tVector pVector, int pDimension){
	int i, menor;
	menor = 100000;
	
	for(i=0; i<pDimension; i++){
		if(pVector[i] < menor){
			menor = pVector[i];
		}
	}
	
	return menor;
}

float mediaVector(tVector pVector, int pDimension){
	int i;
	float media = 0;
	
	for(i=0; i<pDimension; i++){
		media = media + pVector[i];
	}
	media = media / pDimension;
	
	return media;
}

float semisumaVector(int pMaximo, int pMinimo){
	float semisuma = 0;
	semisuma = (pMaximo + pMinimo) / 2;
	
	return semisuma;
}






