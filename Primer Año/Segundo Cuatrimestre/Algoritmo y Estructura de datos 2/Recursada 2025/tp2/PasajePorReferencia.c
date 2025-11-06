#include <stdio.h>
#include <stdlib.h>

/* Variables tradicionales*/
void intercambiarPorValor(int, int);
void ejecutarIntercambiarPorValor();

void intercambiarPorRef(int *, int *);
void ejecutarIntercambiarPorRef();

/* Variables que son punteros*/
void cambiarMemoriaPunteroPorValor(int * punteroInt);
void ejecutarCambiarMemoriaPunteroPorValor();

void cambiarMemoriaPunteroPorRef(int ** punteroInt);
void ejecutarCambiarMemoriaPunteroPorRef();

int main(){
	printf("EJEMPLOS PARA CAMBIAR VALORES DE UNA VARIABLE TRADICIONAL\n");
	printf("----------------------------------------------------------\n");
	ejecutarIntercambiarPorValor();
	ejecutarIntercambiarPorRef();
	
	printf("\nEJEMPLOS PARA CAMBIAR VALORES DE UN PUNTERO\n");
	printf("----------------------------------------------------------\n");
	ejecutarCambiarMemoriaPunteroPorValor();
	ejecutarCambiarMemoriaPunteroPorRef();
	return 0;
}

void intercambiarPorValor(int a, int b){
	/* 	El propósito de esta función es demostrar que si no utilizamos 
		pasaje por referencia no cambia el valor de la variable original */
		int aux = a;
		a = b;
		b = aux;
}

void ejecutarIntercambiarPorValor(){
	int nroA = 10;
	int nroB = 20;
	
	printf("Antes de ejecutar(intercambiarPorValor):\n");
	printf("\tValor de A: %d\n", nroA);
	printf("\tValor de B: %d\n\n", nroB);
	
	intercambiarPorValor(nroA, nroB);
	
	printf("Despues de ejecutar(intercambiarPorValor):\n");
	printf("\tValor de A: %d\n", nroA);
	printf("\tValor de B: %d\n\n", nroB);
	
	printf("*** Se visualiza que los valores de las variables originales NO CAMBIARON ***\n");
	printf("-----------------------------------------------------------------------------\n");
}

void intercambiarPorRef(int * a, int * b){
	/* 	El propósito de esta función es demostrar que si utilizamos 
		pasaje por referencia cambia el valor de la variable original */
		int aux = *a;
		*a = *b;
		*b = aux;	
}

void ejecutarIntercambiarPorRef(){
	int nroA = 10;
	int nroB = 20;
	
	printf("Antes de ejecutar(intercambiarPorRef):\n");
	printf("\tValor de A: %d\n", nroA);
	printf("\tValor de B: %d\n\n", nroB);
	
	intercambiarPorRef(&nroA, &nroB);
	
	printf("Despues de ejecutar(intercambiarPorRef):\n");
	printf("\tValor de A: %d\n", nroA);
	printf("\tValor de B: %d\n\n", nroB);
	
	printf("*** Se visualiza que los valores de las variables originales CAMBIARON ***\n");
	printf("-----------------------------------------------------------------------------\n");
}

/* 	Ahora probemos qué pasaría si necesito modificar la memoria del puntero
	(esto es lo que vamos a necesitar hacer cuando manejemos listas enlazadas) */
void cambiarMemoriaPunteroPorValor(int * punteroInt){
	int * nuevaMemoria = (int*) malloc(sizeof(int));
	punteroInt = nuevaMemoria;
}

void ejecutarCambiarMemoriaPunteroPorValor(){
	int * pNro = (int*) malloc(sizeof(int));
	
	printf("Antes de ejecutar(cambiarMemoriaPunteroPorValor):\n");
	printf("\tLa direccion que contiene pNro: %p\n\n", pNro);
	
	cambiarMemoriaPunteroPorValor(pNro);
	
	printf("Despues de ejecutar(cambiarMemoriaPunteroPorValor):\n");
	printf("\tLa direccion que contiene pNro: %p\n\n", pNro);
	
	printf("*** Se visualiza que la direccion que contiene NO CAMBIO ***\n");
	printf("-----------------------------------------------------------------------------\n");	
}

void cambiarMemoriaPunteroPorRef(int ** punteroInt){
	int * nuevaMemoria = (int*) malloc(sizeof(int));
	*punteroInt = nuevaMemoria;
}

void ejecutarCambiarMemoriaPunteroPorRef(){
	int * pNro = (int*) malloc(sizeof(int));
	
	printf("Antes de ejecutar(cambiarMemoriaPunteroPorRef):\n");
	printf("\tLa direccion que contiene pNro: %p\n\n", pNro);
	
	cambiarMemoriaPunteroPorRef(&pNro);
	
	printf("Despues de ejecutar(cambiarMemoriaPunteroPorRef):\n");
	printf("\tLa direccion que contiene pNro: %p\n\n", pNro);
	
	printf("*** Se visualiza que la direccion que contiene CAMBIO ***\n");
	printf("-----------------------------------------------------------------------------\n");	
}

