#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void alReves(int);

int main(){
	int valor;
	printf(" Ingrese valor para ver en binario: ");
	scanf("%d", &valor);
	
	alReves(valor);
	
	return 0;
	
}

void alReves(int pValor){
	if(pValor>0){
		printf("%d", pValor % 10);
		alReves(pValor/10);
	}
}
