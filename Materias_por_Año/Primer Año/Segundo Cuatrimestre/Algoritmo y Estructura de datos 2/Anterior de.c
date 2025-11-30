#include<stdio.h>

int anteriorDe = 0;

float resta(int);
void mostrarResultado();

int main()
{

printf("Ingrese un numero: \n");/*Ingreso el valor al q deseo aplicar una funcion*/
scanf("%d",&anteriorDe);/*escaneamos el valor ingresado*/
printf("%f", resta(anteriorDe));
	
}

float resta(int nro){
float mostrarResultado;
printf("El numero anterior al ingresado es: ");
mostrarResultado = (float)nro-1;
return mostrarResultado;
}

