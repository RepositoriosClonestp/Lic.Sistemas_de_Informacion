#include <stdio.h>

char tipo_entrada;
char anticipada;
float subtotal;

void ingresarDatos ();
void imprimirTicket();

int main (){
	ingresarDatos();
	if(tipo_entrada == '1')  
	{
		subtotal = 750;
	}
	else if (tipo_entrada == '2') {
	 subtotal = 500;
	}
	else if (tipo_entrada == '3') {
	 subtotal = 400;
	}

	if (anticipada == 's' || anticipada == 'S')
	{
		subtotal = (float)subtotal * 0.8;
	}
	imprimirEntrada();	
	return 0;
}

void ingresarDatos(){
	printf ("Tipo de entrada\n 1: con consumision - 2: sin consumision - 3:con chicle \n");
	scanf("%c",&tipo_entrada);
	printf ("Venta anticipada?\n s: Si - n: NO \n");
	fflush(stdin);
	scanf("%c",&anticipada);
}
/*Porgrama del ejercicio2.2 del tp4*/
void imprimirEntrada(){
	printf("Tipo de entrada: %c \n",tipo_entrada);
	printf("Valor de la entrada: %.2f",subtotal);
}







