#include <stdio.h>

int sumando_a = 0;
int sumando_b = 0;
int resultado = 0; 

int suma (int a, int b){
	return a+b;
}

int main(){
	printf("Mi primer calcu");
	printf("Ingrese el primer valor");
	scanf("%d",&sumando_a);
	scanf("%d",&sumando_b);
	resultado = suma(sumando_a, sumando_b);
	printf ("El resultado de la suma %d+%d es: %d",sumando_a,sumando_b,resultado); 
	return 100;
}

