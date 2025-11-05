#include <stdio.h>
#include <iostream>
#include <string.h>

void dividir(int, int, int, int, int);

	
int main() {
	int aux;
	int dividendo;
	int divisor;
	int cociente;
	int resto;
	
	printf(" Ingrese numero a dividir: ");
	scanf("%d", &dividendo);
	printf(" Ingrese numero que dividira a %d: ", dividendo);
	scanf("%d", &divisor);
	
	resto = dividendo % divisor;
	cociente = 0;
	aux = divisor;
	
	dividir(dividendo, divisor, cociente, resto, aux);
	return 0;
}


void dividir(int pDividendo, int pDivisor, int pCociente, int pResto, int pAux) {
	int resultado = pAux*pCociente + pResto;
	
	if (pDividendo == resultado){
		printf(" %d cabe %d veces en %d", pAux, pCociente, pDividendo);
	}
	if (pDividendo >= pDivisor){
		pCociente = pCociente + 1;
		pDivisor = pDivisor + pAux;
		dividir(pDividendo, pDivisor, pCociente, pResto, pAux);
	}
}
