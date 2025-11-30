#include<iostream>
#include<operacionesConDosValores.h>

int main(){
	int num, num2, opcion;
	printf(" Ingrese primer valor: ");
	scanf("%d", &num);
	printf(" Ingrese segundo valor: ");
	scanf("%d", &num2);
	printf(" \n1- Ver Mayor \n2- Ver Menor \n3- Ver Iguales \n4- Intercambiar   \nIngrese opcion: ");
	scanf("%d", &opcion);
	switch(opcion){
		case 1: calcularMayor(num, num2);
		break;
		case 2: calcularMenor(num, num2);
		break;
		case 3: calcularIguales(num, num2);
		break;
		case 4: intercambiarValores(&num, &num2);
		break;
		default: printf(" No valido.");
	}
	return 0;
}
