#include<stdio.h>

float valor = 0;
float resultado = 0;

float resta(float);
float suma(float);
float multiplicacion(float);
float division(float);

int main(){
	
	int opcionMenu = 0;

	printf("Ingrese un numero: ");
	scanf("%f",&valor);
	fflush(stdin);
	printf("Que funcion desea conocer con el numero ingresado? \n\n");	
	printf(" 1) Su mitad\n 2) Su doble\n 3) Su triple\n 4) Su anterior\n 5) Su posterior\n 6) El posterior de su doble ");
	printf("\n\nIngrese su eleccion: ");
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
       resultado = (float)valor*3;
       printf("El triple del numero ingresado es: %f ",resultado);
break;


case 5:
       resultado = (float)valor+1;
       printf("El siguiente numero al ingresado es: %f ",resultado);
break;

case 6:
       resultado = (float)valor*2+1;
       printf("El siguiente del doble del numero ingresado es: %f ",resultado);
break;



}
return 0;
}



















/*int valor;
int resultado;

int suma (int);
int resta (int);
int multiplicacion (int);
int division (int);
void mostrarResultado();
void inicializarVariables();

int main(){
	
	int opcionMenu = 0;
	inicializarVariables()	;
	printf("Ingrese un valor: ");
	scanf("%d",&valor);
	fflush(stdin);
	printf("Que funcion desea realizar con el numero ingresado? \n");	
	printf(" 5 Anterior\n");
	scanf("%f",&opcionMenu);
	
	switch (opcionMenu){
		case 5: 
	resultado = resta(valor, );
	printf("El resultado de la resta es %d", resultado);
	break;
	
}
return 0;
}


void inicializarVariables(){
int valor = 0;
int resultado = 0;
}
int resta(int nro){
int mostrarResultado;
mostrarResultado = (int)nro-1;
return mostrarResultado;
}*/
