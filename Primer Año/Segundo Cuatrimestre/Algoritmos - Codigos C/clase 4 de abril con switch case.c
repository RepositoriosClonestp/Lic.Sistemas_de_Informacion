#include <stdio.h>

/*se declaran las variables globales*/

int sumando_a;
int sumando_b;
int resultado;

/*se declaran las funciones*/
int suma(int, int);
int resta(int, int);
int multiplicacion(int, int);
int division(int, int);
void inicializarVariables();



int main(){
inicializarVariables()	;/*se inicializan las variables que se inicializaran*/
int opcionMenu = 0; /*Variable local con la opcion seleccionada*/

/*Se ingresa el primer valor*/
printf("Ingresa el valor del primer caracter: ");
scanf("%d",&sumando_a);
fflush(stdin);

/*Se ingresa el segundo valor*/
printf("Ingresar el valor del primer caracter: ");
scanf("%d",&sumando_b);

/*Menu para ejecutar una sola vez*/
printf("Menu de opciones\n");
printf("1-Sumar\n2-Restar\n3-Dividir\n4-Multiplicar");
printf("\nIngresar seleccion: ");
scanf("%d",&opcionMenu);

switch(opcionMenu){
	case 1:
		resultado = suma(sumando_a, sumando_b);
printf("El resultado de la suma es %d", resultado);
break;

case 2:
		resultado = resta(sumando_a, sumando_b);
printf("El resultado de la resta es %d", resultado);
break;

case 3:
	/*Operador ternario-->Alternativa del if utilizado (sumando_b == 0)?*/
printf("El segundo valor debe ser distinto distinto de 0");
printf("El resultado de la division es %d",division(sumando_a, sumando_b));
break;

case 4:
	resultado = multiplicacion(sumando_a, sumando_b);
printf("El resultado de la division es %d", resultado);
break;
default:
	printf("Opcion no valida");
break;

}
return 0;

}
/*Funcion que inicializa las variables*/
void inicializarVariables(){
int sumando_a = 0;
int sumando_b = 0;
int resultado = 0; 
}

int suma (int a, int b){
	return a+b;
}

int resta(int a, int b){
	return a-b;
}

int multiplicacion(int a, int b){
	return a*b;
}

int division (int a, int b){
	return a/b;	
}
