#include <stdio.h>

/*Se declaran las variables globales*/
int x;
int y;
int resultado;

/*Se declara las funciones a utilizar*/
int suma(int, int);
int division(int, int);
int resta(int, int);
int multiplicacion(int, int);
void menu();
void ingresarDatos();
void inicializarVariables();

int main(){
	/*Se inicializa las variables que se utilizaran*/
	inicializarVariables();
	/*Variable local con la opción seleccionada*/
	int opcionMenu = 0;
	
	do {	
		menu();	
		scanf("%d", &opcionMenu);
			
		switch(opcionMenu){
			case 1: 
				ingresarDatos();
				resultado = suma(x, y);
				printf("El resultado de la suma es %d\n\n", resultado);

				break;
			case 2:
				ingresarDatos(); 
				resultado = resta(x, y);
				printf("El resultado de la resta es %d\n\n", resultado);

				break;
			case 3: 
				ingresarDatos();
				/*Operador ternario --> Alternativa del if utilizado*/
				(y == 0) ? printf("El segundo valor debe ser distinto de 0\n\n") : printf("El resultado de la division es %d\n\n", division(x, y));

				break;
			case 4: 
				ingresarDatos();
				resultado = multiplicacion(x,y);
				printf("El resultado de la multiplicacion es %d\n\n", resultado);

				break;
			case 5: 
				printf("Termino el programa!");
				return 0;
				
				break;
			default:
				printf("Opcion no valida!");
				
				break;
		}
	} while(opcionMenu > 0 && opcionMenu < 6);

	return 0;
}

/*Función que inicializa las variables*/
void inicializarVariables(){
	x = 0;
	y = 0;
	resultado = 0;
}

int suma(int a, int b){
	return a + b;
}

int resta(int a, int b){
	return a - b;
}

int multiplicacion(int a, int b){
	return a * b;
}

int division(int a, int b){
	return a / b;
}

void menu(){
	printf("--- Calculadora ---\n");
	printf("1- Sumar\n2- Restar\n3- Dividir\n4-Multiplicar\n5-Salir");
	
	printf("\nIngresar seleccion: ");

}

void ingresarDatos(){
	/*Se ingresa el primer valor*/
	printf("Ingresar el primer valor: ");
	scanf("%d", &x);
	fflush(stdin);
	
	/*Se ingresa el segundo valor*/
	printf("Ingresar el segundo valor: ");
	scanf("%d", &y);
}
