#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int factorial(int);

int main(){
	int valor, r;
	printf(" Ingrese numero");
	scanf("%d", &valor);
	
	r = factorial(valor);
	printf("%d", r);
	return 0;
}

int factorial(int pValor){
	if(pValor == 0){
		return 1;
	}
	else{
		return pValor * factorial(pValor-1);
	}
}

