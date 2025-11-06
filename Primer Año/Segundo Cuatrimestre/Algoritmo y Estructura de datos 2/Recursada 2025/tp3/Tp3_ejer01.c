#include<stdio.h>


int numero;
void cuentaRegresiva(int);

int main() {
	printf( "escriba un numero para la cuenta regresiva :");
	scanf("%d", &numero);
	cuentaRegresiva(numero);
	return 0;
}

void cuentaRegresiva(int pNumero){
	
	if (pNumero == 0 ){ /*si pNumero es 0, imprime el mensaje y termina la función (al salir del if, 
	                     no hay más instrucciones en ese bloque y la función retorna implícitamente*/
		printf("tiempo finalizado");
	}
	else{
		printf("\n el numero es :%d", pNumero);/*imprime el número actual y llama a la función con pNumero - 1*/
		cuentaRegresiva(pNumero -1);
	}
}	



