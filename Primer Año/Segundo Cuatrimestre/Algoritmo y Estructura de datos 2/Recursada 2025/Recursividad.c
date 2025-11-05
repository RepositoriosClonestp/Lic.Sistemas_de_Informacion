#include<stdio.h> //Bilioteca Estandar


typedef int tVector [5];  //Arreglo de 5 enteros

int multiplicarImpares( tVector , int ); //nomenclatura para avisar

tVector vector = {1,3,4,3,2}; // Crear 5 vectores de arreglo
	
int main(){
	
	printf("%d", multiplicarImpares(  vector,  5-1));
	
	return 0;
} // Funcion Principal


int multiplicarImpares( tVector pVector, int pLongitud) {
    if (pLongitud < 0) {
        return 1; 
    }else{
    		if( pVector[pLongitud] %2!=0 ){
    			 return pVector[pLongitud] * multiplicarImpares(pVector, pLongitud-1);
    		}else{
    			 return multiplicarImpares(pVector , pLongitud-1);
    		}
    }
}
