#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float * apuntFloat;

void itemB();
void itemB2();

int main(){
	itemB();
	
	return 0;
}

void itemB2(){
	apuntFloat = (float * ) malloc(sizeof(float)); //reserva direccion de memoria
	*apuntFloat = 20.5; //establece una direccion distinta de memoria para 20.5
	printf(" Direccion de memoria del puntero: %p", &apuntFloat);
	printf("\n Direccion de memoria del valor apuntado: %p", apuntFloat);
	printf("\n Valor asignado: %.1f", *apuntFloat);
}

void itemB(){
	float real = 20.5;
	apuntFloat = &real;
	printf(" direccion de memoria original: %p", &real); // & señala la posición de memoria
	printf("\n direccion de memoria asignado a la variable puntero: %p", apuntFloat); // esta variable guarda el valor de la posición de memoria anterior, por lo tantos son iguales
	printf("\n valor apuntado: %.1f", *apuntFloat); // * apunta al contenido de la variable apuntFloat, declarado anteriormente que es un real, por lo tanto es lo mismo que "real"
	printf("\n valor original: %.1f", real);
	printf(" \n posicion de memoria de variable puntero: %p", &apuntFloat);
}
