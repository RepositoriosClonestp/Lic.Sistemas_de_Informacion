#include<stdio.h>

typedef int tArray[4];
tArray arreglo;

int multiplicarImpares(int, int);
int resultado = 1;
int main(){
	int result;
	arreglo[0] = 2;
	arreglo[1] = 3;
	arreglo[2] = 4;
	arreglo[3] = 5;
	
	result = multiplicarImpares(arreglo[0], 4);
	printf("%d", result);
	
	return 0;
}

int multiplicarImpares(int pArray, int pDim){
	if(pArray == pDim - 1){
		return resultado;
	}
	else{
		if(!(pArray % 2)){
			resultado = pDim * resultado;
		}
	}
	multiplicarImpares(pArray[+1], pDim);
}
