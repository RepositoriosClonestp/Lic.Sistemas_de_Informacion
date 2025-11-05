#include<Dado.h>
int main(){
	tArray array;
	int opcion, caraActual;
	
	while(opcion!=4){
		printf("\n 1) Inicializar Valores de Dado\n 2) Lanzar Dado \n 3) Mostrar Valor Actual \n 4) Finalizar \nIngrese Opcion: ");
		scanf("%d", &opcion);
		switch (opcion){
			case 1: inicializarValores(array);
			break;
			case 2: caraActual = lanzarDado(array);
			break;
			case 3: valorActual(caraActual);
			break;
			case 4: opcion = 4;
			break;
			default: printf(" Error, opcion no valida\n");
		}
	}
	
	return 0;
}
