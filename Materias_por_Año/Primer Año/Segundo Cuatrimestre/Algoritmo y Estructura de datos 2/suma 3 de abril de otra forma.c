#include <stdio.h>

int sumando_a = 12;
int sumando_b = 32;
int resultado = 0; 

int suma (int a, int b){
	return a+b;
}

int main(){
	resultado = suma(sumando_a, sumando_b);
	printf ("El resultado de la suma %d+%d es: %d",sumando_a,sumando_b,resultado); 
	return 100;
}

