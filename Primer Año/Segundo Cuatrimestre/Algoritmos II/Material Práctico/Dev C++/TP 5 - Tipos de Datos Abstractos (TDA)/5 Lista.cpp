#include<Lista.h>
#include<iostream>

lista *listaDin;

int main(){
	int opcion;
	while(opcion != 4){
		printf("\n 1) Inicializar\n 2) Cargar\n 3) Mostrar \n 4) Finalizar\n Ingrese Opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: inicializarLista(&listaDin);
			break;
			case 2: cargarLista(&listaDin);
			break;
			case 3: mostrarLista(listaDin);
			break;
			case 4: opcion = 4;
			break;
			default: printf(" Opcion No Valida\n");
		}
	}
	
	return 0;
}
