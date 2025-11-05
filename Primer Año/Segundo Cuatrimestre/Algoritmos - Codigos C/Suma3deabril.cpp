#include <stdio.h>

int resultado = 0;//declaramos el tipo entero
int suma (int a, int b){
	return a+b;
}

int main(){
	resultado = suma(12,32);
	printf ("El resultado de la suma 12+32 es: %d",resultado);//%d especificador de la variable entera
	return 1;//declaramos que devuelva un valor de tipo entero
}


