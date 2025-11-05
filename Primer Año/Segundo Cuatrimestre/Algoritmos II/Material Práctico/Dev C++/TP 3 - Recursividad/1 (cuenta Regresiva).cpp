#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void cuentaRegresiva(int);

int main(){
	int valor;
	printf(" Ingrese valor: ");
	scanf("%d", &valor);
	
	cuentaRegresiva(valor);
	
	return 0;
	
}

void cuentaRegresiva(int pValor){
	if (pValor == 0){
		printf("%d fin", pValor);
	}
	else{
		printf("%d \n", pValor);
		cuentaRegresiva(pValor - 1);
	}
}
