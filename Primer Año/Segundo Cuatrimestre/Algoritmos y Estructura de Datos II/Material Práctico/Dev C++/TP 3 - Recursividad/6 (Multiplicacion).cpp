#include <stdio.h>
#include <iostream>
#include <string.h>

void multiplicar(int, int, int);

int main() {
	int multiplicando, multiplicador, producto, aux;
	producto = 0;
	
	printf(" Ingrese entero: ");
	scanf("%d", &multiplicando);
	printf(" Ingrese por cuanto multiplicar: ");
	scanf("%d", &multiplicador);
	
	multiplicar(multiplicando, multiplicador, producto);
	
	return 0;
}

void multiplicar(int pMultiplicando, int pMultiplicador, int pProducto) {
		int resultado;
		resultado = pMultiplicando * pMultiplicador;
		
		if (resultado == pProducto){
			printf(" Resultado: %d", pProducto);
		}
		else{
			if (pMultiplicador > 0){
				pProducto = pProducto + pMultiplicando;
				multiplicar(pMultiplicando, pMultiplicador, pProducto);
			}
			if (pMultiplicador < 0){
				pProducto = pProducto - pMultiplicando;
				multiplicar(pMultiplicando, pMultiplicador, pProducto);
			}
		}
}
