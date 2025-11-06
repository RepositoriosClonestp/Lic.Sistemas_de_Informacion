#include "Calculadora.h"

int main(){
	float a = 5.0;
	float b = 2.25;
	printf("Suma de %.2f+%.2f = %.2f\n", 
			a, b,
			suma(a, b));
	printf("Resta de %.2f-%.2f = %.2f\n", 
			a, b,
			resta(a, b));	
	printf("Producto de %.2fx%.2f = %.2f\n", 
			a, b,
			producto(a, b));
	printf("Cociente de %.2f/%.2f = %.2f\n", 
			a, b,
			cociente(a, b));
	return 0;
}
