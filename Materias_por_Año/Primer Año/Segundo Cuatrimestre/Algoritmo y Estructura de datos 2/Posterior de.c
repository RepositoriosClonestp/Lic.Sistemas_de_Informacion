#include<stdio.h>
/*Declaro variables globales*/
float posteriorDe = 0;

/*Declaro parametros*/
float suma(float);/*Tipo de caracter, operacion y tipo de caracter del resultado*/
void mostrarResultado (float);

int main(){
	
	printf("Ingrese un numero: \n");
	scanf("%f",&posteriorDe);
    printf("%f",suma(posteriorDe));
}
/*Declaramos la funcion */
float suma (float nro){ /*Funcion, especificacndo el tipo de caracter y nombrando variables local*/
float (mostrarResultado);/*Variables local indica el resultado d ela operacion*/
printf("El numero posterior al ingresado es: ");
mostrarResultado = (float)nro+1; /*Resultado de la funcion especificando el tipo de caracter, utilizando la simbologia de la funcion y nombres d evariables locales*/
return mostrarResultado;/*Devuelve resultado*/
}
