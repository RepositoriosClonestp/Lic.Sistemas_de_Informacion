/*
Una concesionaria necesita llevar un registro anual de las ventas realizadas durante los últimos 3 años. Se requiere un programa en lenguaje 
C para determinar la cantidad promedio de ventas por año. Para ello: 
	-Almacene en una matriz ingresando por teclado la información correspondiente a la cantidad de vehículos vendidos por mes de los últimos 
	3 años. Cada fila representa un año y cada columna representa un mes.
	-Recorra la matriz para generar un vector que registre el promedio de ventas realizadas por año. Es decir, cada posición del vector 
	representara un año y almacenara la cantidad promedio de ventas realizadas durante ese año. 
	-Incluya una función para mostrar los datos ingresados en la matriz, así como los valores promedios almacenados en el vector.

*/


#include <stdio.h>
#include <string.h>

typedef char tString[60];
typedef int tMatrizVentas[3][3];
typedef float tVectorPromedio[3];

tString titulo;

void ingresarDatosMatriz(tMatrizVentas);
void generarVector(tMatrizVentas, tVectorPromedio);
void mostrarDatos(tMatrizVentas, tVectorPromedio);
void validarTitulo();

int main(){
	tMatrizVentas matriz;
	tVectorPromedio vector;
	
	ingresarDatosMatriz(matriz);
	generarVector(matriz, vector);
	validarTitulo();
	mostrarDatos(matriz, vector);

	return 0;
}

void ingresarDatosMatriz(tMatrizVentas pMatrizVentas){
	int i, j;
	
	for(i=0; i<3; i++){
		printf("-- Año %d --\n", i+1);
		for(j=0; j<3; j++){
			printf("Mes %d - Cantidad de ventas: ", j+1);
			scanf("%d", &pMatrizVentas[i][j]);
			fflush(stdin);
		}
	}
}

void generarVector(tMatrizVentas pMatrizVentas, tVectorPromedio pVectorPromedio){
	int i, j;
	int sumaVentas = 0;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			sumaVentas = sumaVentas + pMatrizVentas[i][j];
		}
		pVectorPromedio[i] = (float)sumaVentas/12;
		sumaVentas = 0;
	}
}

void mostrarDatos(tMatrizVentas pMatrizVentas, tVectorPromedio pVectorPromedio){
	int i, j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf(" %d | ", pMatrizVentas[i][j]);
		}
		printf("\t %.2f | \n", pVectorPromedio[i]);
	}
}

void validarTitulo(){
	int longitud;
	
	printf("Ingrese el titulo del informe: ");
	scanf("%[^\n]s", &titulo);
	fflush(stdin);
	
	longitud = strlen(titulo);
	
	if(longitud > 50){
		printf("El titulo supera los 50 caracteres. \n");
	}
	else{
		printf("El titulo no supera los 50 caracteres. \n");
	}
}
