#include <stdio.h>

/*Se declaran las variables globales*/
int sumando_a;
int sumando_b;
int resultado;

/*Se declara las funciones a utilizar*/
int suma(int, int);
int division(int, int);
int resta(int, int);
int multiplicacion(int, int);
void menu(int);
int calculadora(int);

void inicializarVariables();

int main(){
	/*Se inicializa las variables que se utilizaran*/
	inicializarVariables();
	/*Variable local con la opción seleccionada*/
	int opcionMenu = 0;
	
	/*Se ingresa el primer valor*/
		printf("Ingresar el valor del primer caracter: ");
	scanf("%d", &sumando_a);
	fflush(stdin);
	/*Se ingresa el segundo valor*/
	printf("Ingresar el valor del primer caracter: ");
	scanf("%d", &sumando_b);
	
	/*Menú para ejecutar una sola vez*/
	printf("Menú de opciones\n");
	printf("1- Sumar\n2- Restar\n3- Dividir\n4-Multiplicar\n5-Salir");
	printf("\nIngresar seleccion: ");
	scanf("%d", &opcionMenu);
	
	switch(opcionMenu){
		case 1: 
			resultado = suma(sumando_a, sumando_b );
			printf("El resultado de la suma es %d\n\n", resultado);
			menu(opcionMenu);
			break;
		case 2: 
			resultado = resta(sumando_a, sumando_b );
			printf("El resultado de la resta es %d\n\n", resultado);
			menu(opcionMenu);
			break;
		case 3: 
			/*Operador ternario --> Alternativa del if utilizado*/
			(sumando_b == 0) ? printf("El segundo valor debe ser distinto de 0\n\n") :
			 printf("El resultado de la division es %d\n\n", division(sumando_a, sumando_b));
			menu(opcionMenu);
			break;
		case 4: 
			resultado = multiplicacion(sumando_a, sumando_b );
			printf("El resultado de la multiplicacion es %d\n\n", resultado);
			menu(opcionMenu);
			break;
		case 5: 
			printf("Termino el programa!");
			return 0;
			break;
		default:
			printf("Opcion no valida");
			break;
	}
	
	return 0;
}

/*Función que inicializa las variables*/
void inicializarVariables(){
	sumando_a = 0;
	sumando_b = 0;
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

void menu(int y){
	printf("Menú de opciones\n");
	printf("1- Sumar\n2- Restar\n3- Dividir\n4-Multiplicar\n5-Salir");
	printf("\nIngresar seleccion: ");
	scanf("%d", &y);
	calculadora(y);
}

int calculadora(int x){
		switch(x){
		case 1: 
			resultado = suma(sumando_a, sumando_b );
			printf("El resultado de la suma es %d\n\n", resultado);
			menu(x);
			break;
		case 2: 
			resultado = resta(sumando_a, sumando_b );
			printf("El resultado de la resta es %d\n\n", resultado);
			menu(x);
			break;
		case 3: 
			/*Operador ternario --> Alternativa del if utilizado*/
			(sumando_b == 0) ? printf("El segundo valor debe ser distinto de 0\n\n") : printf("El resultado de la division es %d\n\n", division(sumando_a, sumando_b));
			menu(x);
			break;
		case 4: 
			resultado = multiplicacion(sumando_a, sumando_b );
			printf("El resultado de la multiplicacion es %d\n\n", resultado);
			menu(x);
			break;
		case 5:
			printf("Termino el programa!");
			return 0;
			break;
		default:
			printf("Opcion no valida");
			break;
	}
}

