#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef int tArreglo[5];

int multiplicacion(tArreglo, int);

int main(){
	int i, r;
	tArreglo arreglo;
	for (i=0; i<5; i++){
		printf(" Ingrese valor: ");
		scanf("%d", &arreglo[i]);
	}
	r = multiplicacion(arreglo, 5);
	printf("%d", r);
}

int multiplicacion(tArreglo pArreglo, int pDimension){
	if (pDimension == 0){
		return 1;
	}
	else{
		return pArreglo[pDimension-1] * multiplicacion(pArreglo, pDimension-1);
	}
}
