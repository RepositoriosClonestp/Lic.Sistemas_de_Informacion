#include <stdio.h>

char tipo_producto;
char tipo;
float subtotal;

void ingresarDatos ();
void imprimirTicket();

int main (){

	ingresarDatos();
	if(tipo_producto == 'P') {
		subtotal == 50*0.95;
	}
	else if (tipo_producto == 'F') {
	 subtotal == 100*0.9;
	}
   else if (tipo_producto == 'L') {
	 subtotal == 150*0.85;
	}
	imprimirTicket();	
	return 0;
}

void ingresarDatos(){
	
	printf ("Tipo de producto\n P: Perfumeria - F: Farmacia - L: Limpieza\n  ");
	scanf("%c",&tipo);
}

void imprimirTicket(){
	
	switch (tipo_producto){
		
		case 'F':
			printf("El importe a pagar es: ",subtotal);
			subtotal == 100*0.9;
			printf("La bonificacion es del 5% ");
	}
	
}
