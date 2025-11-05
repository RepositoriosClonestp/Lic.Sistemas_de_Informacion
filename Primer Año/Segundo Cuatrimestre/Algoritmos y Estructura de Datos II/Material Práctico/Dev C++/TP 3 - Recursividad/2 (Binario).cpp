#include <stdio.h>
#include <iostream>

void verEnBinario(int);

int main() {
	int nro;
	printf(" Ingrese numero entero: ");
	scanf("%d", &nro);
	printf(" %d en forma binaria: ", nro);
	verEnBinario(nro);
	return 0;
}

void verEnBinario( int pNro ) {	
	if (pNro >= 1){
		verEnBinario(pNro/2);
		if (pNro % 2){
			printf("1");
		}
		else{
			printf("0");
		}
	}		
}

