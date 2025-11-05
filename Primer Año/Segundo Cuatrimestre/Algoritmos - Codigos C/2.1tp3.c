#include <stdio.h>
/*Variables globales*/
float lado1;
float lado2;

/*Funciones*/
float perimetroCaja(float,float);
float cintaCaja(float,float);

/*Prototipo*/
void mostrarResultado();

int main (){
	printf("Para conocer el perimetro de una caja ingrese los siguientes valores por favor \n \n");
	printf("Ingrese ancho de la caja en cm:  \n");
	scanf("%f",&lado1);
	fflush(stdin);
	printf("Ingrese alto de la caja en cm: \n");
	scanf("%f",&lado2);
	printf("%f cm\n",perimetroCaja(lado1,lado2));
	printf("%f mts",cintaCaja(lado1,lado2));
	
	
	
}
float perimetroCaja( float lad1, float lad2){
	float mostrarResultado;
	printf("\nEl perimetro en centimetros de la caja es: ");
		mostrarResultado = 2 * (lad1 + lad2);
		return mostrarResultado;
}

float cintaCaja( float lad1, float lad2){
	float mostrarResultado;
	printf("Los metros de cinta por caja son: ");
		mostrarResultado = (2 * (lad1 + lad2))/100;
		return mostrarResultado;
}



