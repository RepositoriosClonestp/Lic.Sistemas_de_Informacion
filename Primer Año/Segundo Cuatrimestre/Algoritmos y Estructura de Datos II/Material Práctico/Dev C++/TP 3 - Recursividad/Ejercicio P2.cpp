#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[25];

int cantVocales(tString, int);

int main(){
	int i, r;
	tString palabra;
	printf(" Ingrese palabra: ");
	gets(palabra);
	
	r = cantVocales(palabra, strlen(palabra));
	printf("%d", r);
}

int cantVocales(tString pPalabra, int pDimension){
	if (pDimension == 0){
		return 0;
	}
	else{
		if((pPalabra[pDimension-1] == 'a') || (pPalabra[pDimension-1] == 'e') || (pPalabra[pDimension-1] == 'i') || (pPalabra[pDimension-1] == 'o') || (pPalabra[pDimension-1] == 'u')){
			return cantVocales(pPalabra, pDimension-1) + 1;
		}
		else{
			return cantVocales(pPalabra, pDimension -1);
		}
	}
}
