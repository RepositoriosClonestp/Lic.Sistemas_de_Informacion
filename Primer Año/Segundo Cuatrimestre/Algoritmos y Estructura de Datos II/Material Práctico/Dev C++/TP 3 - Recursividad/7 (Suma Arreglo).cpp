#include <stdio.h>
#include <iostream>
#include <string.h>
typedef int tArray[10];

int sumarVec(tArray, int);

int main() {
	int i, nro;
	tArray arreglo;
	int resultado;
	
	for (i=0; i<10; i++){
		arreglo[i] = 3;
	}
	
	printf(" Ingrese numero menor a 11: ");
	scanf("%d", &nro);
	
	resultado = sumarVec(arreglo, nro);
	printf(" %d", resultado);
	
	return 0;
}

int sumarVec(tArray pArreglo, int pNro) {
		if (pNro == 0){
			return 0;
		}
		else{
			return sumarVec(pArreglo, pNro - 1) + pArreglo[pNro];
		}
}
