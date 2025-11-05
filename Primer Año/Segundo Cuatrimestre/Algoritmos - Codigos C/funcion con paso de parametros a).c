#include<stdio.h>
int entero = 0;

float division(int);
void mostrarResultado();

int main()
{
printf("Ingrese un numero: \n");
scanf("%d", &entero);
printf("%f", division(entero));

}

float division(int nro){
float mostrarResultado;
printf("La mitad del numero ingresado es: ");
mostrarResultado = (float)nro/2;
return mostrarResultado;
 }
