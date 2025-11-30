#include<stdio.h>

float valor = 0;
float resultado = 0;

float resta(float);
float suma(float);
float multiplicacion(float);
float division(float);

int main(){
	
	int opcionMenu = 1;
	printf("Ingrese un numero: ");
	scanf("%f",&valor);
	fflush(stdin);
	
while (opcionMenu == 1)
{


	printf("Que funcion desea conocer con el numero ingresado? \n\n");	
	printf(" 1) Su mitad\n 2) Su doble\n 3) Su triple\n 4) Su anterior\n 5) Su posterior\n 6) El posterior de su doble\n 7) Salir ");
	printf("\nSeleccione con un numero la funcion deseada: ");
	scanf("%d",&opcionMenu);
    	
switch (opcionMenu){
	
case 1:
       resultado = (float)valor/2;
       printf("La mitad del numero ingresado es: %f ",resultado);
       break;

case 2:
       resultado = (float)valor*2;
       printf("El doble del numero ingresado es: %f ",resultado);
       break;

case 3:
       resultado = (float)valor*3;
       printf("El triple del numero ingresado es: %f ",resultado);
       break;

case 4:
       resultado = (float)valor-1;
       printf("El anterior del numero ingresado es: %f ",resultado);
       break;


case 5:
       resultado = (float)valor+1;
       printf("El siguiente numero al ingresado es: %f ",resultado);
       break;

case 6:
       resultado = (float)valor*2+1;
       printf("El siguiente del doble del numero ingresado es: %f ",resultado);
       break;

case 7:
      	printf("Termino el programa!");
		return 0;
		break;

  }
  printf ("\n\nDesea conocer el resultado de otra funcion?\n");
  printf("\n1) SI\n2) NO");
  printf("\nIngrese 1 para si o 2 para no: " );
  scanf("%d",&opcionMenu);
  
 }

return 0;

}


