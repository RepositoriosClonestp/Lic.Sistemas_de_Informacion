#include <stdio.h>
/*con el if anidado  y else es el metodo mas largo*/
int sumando_a = 0;
int sumando_b = 0;
int resultado1 = 0; 
int resultado2 = 0;
int resultado3= 0;
int resultado4 = 0;
int continuar = 0;
int opcion = 0;
int suma(int, int);
int resta(int, int);
int multiplicacion(int, int);
int division(int, int);




int main(){
	printf("Mi primer calcu\n");
	printf("Ingrese el primer valor\n");
	scanf("%d",&sumando_a);
	
	printf("Ingrese el segundo valor\n");
	scanf("%d",&sumando_b);	

	

	printf("--Menu de Opciones--\n");
	printf("1- Suma\n");
	printf("2- Resta\n");
	printf("3- Multiplicacion\n");
	printf("4- Division\n");
	printf("Que desea realizar? - Ingrese una opcion:  ");
	scanf("%d", &opcion);
	
	if(opcion == 1){
		resultado1 = suma(sumando_a, sumando_b);
		printf ("El resultado de la suma %d+%d es: %d\n",sumando_a,sumando_b,resultado1);
			
	}
	else if(opcion == 2){
			resultado2 = resta(sumando_a, sumando_b);
		printf ("El resultado de la resta %d-%d es: %d\n",sumando_a,sumando_b,resultado2);
		
	}
	else if(opcion == 3){
			resultado3 = multiplicacion(sumando_a, sumando_b);
		printf ("El resultado de la multiplicacion %d*%d es: %d\n",sumando_a,sumando_b,resultado3);
		
	}
	else if(opcion == 4){
		if(sumando_b==0){
		printf (" No se puede dividir");
		}
			resultado4 = division(sumando_a, sumando_b);
		printf ("El resultado de la division %d/%d es: %d\n",sumando_a,sumando_b,resultado4);
		
	}
	
	else {
		return 0;
	}
	return 0;
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
