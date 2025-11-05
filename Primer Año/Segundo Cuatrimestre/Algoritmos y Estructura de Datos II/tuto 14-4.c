#include<stdio.h>


char caracter;
int nroReal;
double doble;



int main(){
	
    printf("Ingrese por teclado un caracter: \n ");
		scanf("%c",&caracter);		
	printf("El caracter ingresado es: %c ",caracter);
	printf("\nIngrese por teclado un numero Real: ");
	scanf("%d",&nroReal);

	printf("\nIngrese por teclado un double: ");
	scanf("%lf",&doble);
	

	
return 0;

}


/* Bibliotecas y valores pre-definidos */
#include <stdio.h> 
#define PI 3.141592
/* prototipos de funciones */
void ingresarDatos();
void totalSuperficie();
/*el area se calcula PI * r2 */
/*variables globales*/
float radio, area;
int figuras;
/* Programa Principal */
int main() {
	ingresarDatos();
	while(radio !=0) {
		totalSuperficie();
		ingresarDatos();
	}
	return 0;
}
/* implementacion de funciones */ 
void ingresarDatos() {
	printf("\nIngrese cantidad de figuras: ");
		scanf("%d", &figura
