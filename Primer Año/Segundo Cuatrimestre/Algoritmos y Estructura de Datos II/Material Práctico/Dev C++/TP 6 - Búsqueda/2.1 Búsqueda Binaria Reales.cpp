#include<stdio.h>
#include<iostream>
#include<stdbool.h>
const int MAX = 6;
typedef float tArregloReal[MAX];

void cargarArreglo(tArregloReal);
bool busquedaBinaria(tArregloReal, float);
void visualizarArreglo(tArregloReal);

int main(){
	tArregloReal arreglo;
	float elem;
	bool busqueda;
	
	cargarArreglo(arreglo);
	
	printf(" Ingrese numero real a buscar: ");
	scanf("%f", &elem);
	
	visualizarArreglo(arreglo);
	
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
	
	while (inf <= sup){ // 0 <= 5
		mit = (inf + sup) / 2; //  5/2 = 2
		
		if (pArreglo[mit] == pElem){ // 2 == 2 true
			printf(" Elemento %.2f encontrado en la posicion %d\n", pElem, mit);
			return true;
			break;
		}
		
		if(pElem < pArreglo[mit]){ // 3 > 2 true
			sup = mit - 1; // sup = 6 - 1
			
			
		}
		
		if(pElem > pArreglo[mit] ){ // 6 < 7 true
			inf = mit + 1; // inf = 6 + 1
		}
	}
	
	return false;
}

void visualizarArreglo(tArregloReal pArreglo){
	int i;
	for(i=0; i<MAX; i++){
		printf(" %.2f \n", pArreglo[i]);
	}
}
