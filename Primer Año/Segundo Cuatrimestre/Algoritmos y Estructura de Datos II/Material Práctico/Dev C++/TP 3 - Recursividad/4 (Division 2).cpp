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
	int resultado;
	resultado = pDivisor*pCociente + pResto;
	
	if (pDividendo == resultado){
		printf("\n %d cabe %d veces en %d", pDivisor, pCociente, pDividendo);
	}
	if (pDividendo >= pAux){
		pCociente = pCociente + 1;
		pAux = pAux + pDivisor;
		dividir(pDividendo, pDivisor, pCociente, pResto, pAux);
	}
}
