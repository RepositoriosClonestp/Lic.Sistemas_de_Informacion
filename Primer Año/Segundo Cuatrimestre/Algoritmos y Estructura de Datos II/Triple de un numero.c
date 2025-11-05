#include<stdio.h>

int tripleDe = 0;

int multiplicacion(int);
void mostrarResultado ();

int main ()
{
	
	printf("Ingrese un numero: \n");
	scanf("%d",&tripleDe);
	printf("%d",multiplicacion(tripleDe));
	
}

int multiplicacion(int triple)
{
int mostrarResultado;
printf("El triple del numero ingresado es: ");
mostrarResultado = triple*3;
return mostrarResultado;
}

