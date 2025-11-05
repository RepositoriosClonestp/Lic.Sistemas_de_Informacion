#include<stdio.h>
int dobleDe = 0;

float multiplicacion(int);
void mostrarResultado();

int main()
{
printf("Ingrese un numero: \n");
scanf("%d", &dobleDe);
printf("%f", multiplicacion(dobleDe));

}

float multiplicacion(int nro){/**/
float mostrarResultado;
printf("El doble del numero ingresado es: ");
mostrarResultado = (float)nro*2;
return mostrarResultado;
 }
