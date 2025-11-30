// Probar la función malloc en este ejercicio
// malloc reserva un espacio en memoria, el cual es posible acceder a su contenido mediante el uso del asterisco
// sin asterisco muestra la direccion de memoria de la variable puntero

#include <stdio.h>
#include <stdlib.h>

void itemB();
float real;
float *pf;

int main(){
	itemB();
	
	return 0;
}

void itemB(){
	real = 20.5;
	pf = &real;
	printf("\n Puntero hacia real: %.1f", *pf);
	printf("\n Direccion de memoria de la variable apuntada: %p", pf);
	printf("\n Direccion de memoria del puntero: %p ", &pf);
}
