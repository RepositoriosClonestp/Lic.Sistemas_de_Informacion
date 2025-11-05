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


	if (anticipada == 's' || anticipada == 'S')
	{
		subtotal = (float)subtotal * 0.8;
	}
	imprimirEntrada();	
	return 0;
}

void ingresarDatos(){
	
	printf ("Tipo de entrada\n 1: con consumision - 2: sin consumision ");
	scanf("%c",&tipo_entrada);
	printf ("Venta anticipada?\n s: Si - n: NO \n");
	fflush(stdin);
	scanf("%c",&anticipada);
}

void imprimirEntrada(){
	switch (tipo_entrada){
		
    case '1':
	printf ("Tipo de entrada:con consumision \n");
	break;
	case '2':
	printf ("Tipo de entrada: sin consumision");
	break;
	default:
	printf ("No se seleciono un tipo valido\n");/*si ingressa otro valor que no es valido*/
}
	printf("Valor de la entrada: %.2f",subtotal);
}

