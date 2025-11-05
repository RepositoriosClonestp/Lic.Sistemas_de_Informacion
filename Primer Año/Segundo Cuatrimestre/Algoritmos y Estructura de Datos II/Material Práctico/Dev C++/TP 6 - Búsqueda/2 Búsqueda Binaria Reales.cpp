#include<stdio.h>
#include<iostream>
#include<stdbool.h>
const int MAX = 6;
typedef float tArregloReal[MAX];

void cargarArreglo(tArregloReal);
bool busquedaBinaria(tArregloReal, float);

int main(){
	tArregloReal arreglo;
	float elem;
	bool busqueda;
	
	cargarArreglo(arreglo);
	
	printf(" Ingrese numero real a buscar: ");
	scanf("%f", &elem);
	
	busqueda = busquedaBinaria(arreglo, elem);
	if(busqueda == false){
		printf(" Elemento no encontrado");
	}
	
	return 0;
}

void cargarArreglo(tArregloReal pArreglo){
	int i;
	for(i=0; i<MAX; i++){
		printf(" Cargue un numero real de menor a mayor: ");
		scanf("%f", &pArreglo[i]);
	}
}

bool busquedaBinaria(tArregloReal pArreglo, float pElem){
	int inf, sup, mit;
	inf = 0;
	sup = MAX;
	
	while (inf < sup){
		mit = (inf + sup) / 2;
		
		if (pArreglo[mit] == pElem){ 
			printf(" Elemento %.2f encontrado en la posicion %d\n", pElem, mit);
			return true;
			break;
		}
		
		if(pArreglo[mit] > pElem){
			sup = mit;
			mit = (inf + sup) / 2;
			
			
		}
		
		if(pArreglo[mit] < pElem){
			inf = mit;
			mit = (inf + sup) / 2;
			
			if(inf == MAX-1){
				return false;
				break;
			}
		}
		
		printf(" -%d %d- \n ", inf, sup);
	}
}



