#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void valorBinario(int);

int main(){
	int valor;
	printf(" Ingrese valor para ver en binario: ");
	scanf("%d", &valor);
	
	valorBinario(valor);
	
	return 0;
	
}

void valorBinario(int pValor){
	if (pValor >= 1){
		valorBinario(pValor/2);
		if(pValor % 2 != 0){
			printf("1");
		}
		else{
			printf("0");
		}
	}
}
