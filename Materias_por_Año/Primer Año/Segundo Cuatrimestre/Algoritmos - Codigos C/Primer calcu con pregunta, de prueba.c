#include <stdio.h>

int sumando_a = 0;
int sumando_b = 0;
int resultado = 0; 
int continuar = 0;

int suma (int a, int b){
	return a+b;
}



int main(){
	printf("Mi primer calcu\n");
	printf("Ingrese el primer valor\n");
	scanf("%d",&sumando_a);
	scanf("%d",&sumando_b);
	resultado = suma(sumando_a, sumando_b);
	printf ("El resultado de la suma %d+%d es: %d\n",sumando_a,sumando_b,resultado); 
	printf("Desea continuar sumando? (1-si / 2-no)");
	scanf("%d", &continuar);
	return 100;
}
