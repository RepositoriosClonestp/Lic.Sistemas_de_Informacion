#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tstring [25]; 

void itemA (); 

tstring * apuntCadena; 

int main () {
	itemA (); 
	return 0;
}

void itemA () {
	/*Asignacion dinamica*/
	apuntCandena = (tstring *) malloc(sizeof (tstring)); 
	strcpy ((*apuntCadena), "Maria Acosta"); 
	printf ("\nEl contenido de la apuntada es: %s\n", *apuntCadena);
	printf ("\nLa direccion de la variaable apuntada es: %p\n", apuntCadena); 
	printf ("\nLa direccion de la variable puntero es: %p", &apuntCadena); 
	
}
