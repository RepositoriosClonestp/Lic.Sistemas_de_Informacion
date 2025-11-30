#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdbool.h>

// definicion de constantes
const int N = 4; // constante de los arreglos, por conveniencia 4

//Definicion de tipos
typedef char tString[25];
typedef int tVectorInt[N];
typedef float tVectorFloat[N];
tString CAT[5] = {"", "Panaderia ", "Lacteos   ", "Perfumeria", "Limpieza  "}; // categorias

typedef struct{
	int nroTicket;
	int longitudArreglo;
	tVectorInt codProd;
	tString nombre[N];
	tVectorInt codCat; // codigo categoria
	tVectorInt cantVendido;
	tVectorFloat precio;
}tRegSup; // tipo registro supermercado


//Prototipos
bool escribirListado(tString);
bool leerListado(tString); // En esta funcion van a estar incluidas las dos de debajo, que serían los cortes de control
bool leerListadoPorCat(tString, int, int); // Corte de Control entre tickets, que muestra el total por Categorias
bool leerListadoTotal(tString); // Corte de Control al final del archivo, que muestra el total de ventas y la cantidad de tickets imprimidos

void inicializarListado(tString); 


// Función Principal
int main(){
	tString nombreArchivo;
	strcpy(nombreArchivo, "supermercado.dat");
	
	if(escribirListado(nombreArchivo) == false){
		printf("Error de escritura!");
	}
	if(leerListado(nombreArchivo) == false){
		printf("Error de lectura!");
	}
	return 0;
}


// Definición de Funciones
void inicializarListado(tString pNombreArchivo, int pCant){
	FILE *F;
	tRegSup regSup;
	
	F = fopen(pNombreArchivo, "wb");
	
	if(F == NULL){
		printf(" Error al abrir el archivo para escritura.\n");
	}
	else{
		int i;
		for(i=1; i<=pCant; i++){
			regSup.nroTicket = 0;
			int j;
			for(j=0; j<N; j++){
				regSup.codProd[j] = 0;
				regSup.codCat[j] = 0;
				strcpy(regSup.nombre[j], "");
				regSup.cantVendido[j] = 0;
				regSup.precio[j] = 0;
			}
			fwrite(&regSup, sizeof(tRegSup), 1, F);
		}
	}
		fclose(F);
}

bool escribirListado(tString pNombreArchivo){
	FILE *F;
	tRegSup regSup;
	
	F = fopen(pNombreArchivo, "wb");
	
	if(F == NULL){
		printf(" Error al abrir el archivo para escritura.\n");
		return false;
	}
	else{
		int cantTicket = 0;
		
		printf(" Ingrese cantidad de tickets a registrar: ");
		scanf("%d", &cantTicket);
		
		inicializarListado(pNombreArchivo, cantTicket);
		
		int i;
		for(i=1; i<=cantTicket; i++){
			regSup.nroTicket = i; // Asú queda ordenado el archivo por tickets
			int j;
			int cantProd = 0;
			
			printf(" Ingrese cantidad de productos por categoria a comprar (max 4): "); // Esto es para guardar la longitud de cada arreglo del registro (ya que todos tienen la misma longitud)
			scanf("%d", &regSup.longitudArreglo);										// Es muy importante para después recorrer e imprimir cada registro y sus arreglos
			
			for(j=0; j<regSup.longitudArreglo; j++){
				
				printf(" Ingrese Codigo Producto: ");
				scanf("%d", &regSup.codProd[j]);
				while (getchar() != '\n');
					
				printf(" Ingrese Nombre Producto: ");
				scanf("%[^\n]", &regSup.nombre[j]);
					
				printf(" Ingrese Categoria del Producto: ");
				scanf("%d", &regSup.codCat[j]);
					
				printf(" Ingrese Cantidad de Productos: ");
				scanf("%d", &regSup.cantVendido[j]);
					
				printf(" Ingrese Precio Producto: ");
				scanf("%f", &regSup.precio[j]);
				
				printf("\n");
			}
			fwrite(&regSup, sizeof(tRegSup), 1, F); 
		}
	}
		fclose(F);
		return true;
}

bool leerListado(tString pNombreArchivo){
	FILE *F;
	tRegSup regSup;
	
	F = fopen(pNombreArchivo, "rb");
	
	if(F == NULL){
		printf(" Error al abrir el archivo para lectura.");
		return false;
	}
	else{
		printf("\n Ticket | Cod Prod | Name | Categ | Cantidad | Precio Unitario \n");
		
		while(fread(&regSup, sizeof(tRegSup), 1, F) == 1){
		printf(" %d 	 ", regSup.nroTicket); 
		
		int i;
		for(i=0; i<regSup.longitudArreglo; i++){
			printf("-   %d 	- %s 	- %s 	- %d 	- %.2f", regSup.codProd[i], regSup.nombre[i], CAT[regSup.codCat[i]], regSup.cantVendido[i], regSup.precio[i]);
			printf("\n	");	
		}
		int j;
		for(j=1; j<5; j++){ /* La función de abajo imprime una sola categoría, este for es para recorrer todas las categorias, incluso si no se vendió nada, para que imprima 0 */
			if(leerListadoPorCat(pNombreArchivo, j, regSup.nroTicket) == false){ // Se le tiene que pasar como parámetro: La categoria que tiene que imprimir (j), y también el nro ticket
				printf(" Error al leer listado por categoria!");				 // para que imprima solamente el total de categorias de un solo ticket por vez
			}
		}
		printf("\n");
		printf(" --------------------------------------------------------------\n");
	}
	if(leerListadoTotal(pNombreArchivo) == false){ 
		printf(" Error al leer listado total!");
	}
	fclose(F);
	return true;
	}	
}

bool leerListadoPorCat(tString pNombreArchivo, int pCodCat, int pTicket){
	FILE *F;
	tRegSup regSup;
	
	F = fopen(pNombreArchivo, "rb");
	
	if(F == NULL){
		printf(" Error al abrir el archivo para lectura.");
		return false;
	}
	else{
		printf("\n");
		
		while(fread(&regSup, sizeof(tRegSup), 1, F) == 1){
		float impCat = 0; // Importe por Categoria
		int i;
		
		for(i=0; i<regSup.longitudArreglo; i++){
			if(regSup.nroTicket == pTicket && regSup.codCat[i] == pCodCat){
				
				impCat = impCat + (regSup.precio[i] * regSup.cantVendido[i]);
			}
		}
		if(regSup.nroTicket == pTicket){
			printf("%s: %.2f ", CAT[pCodCat], impCat); // Después del for, la variable ya tiene el total por categoria de ese ticket, se imprime la constante de string de categorias
		}											   // y el importe por categoria
		}
			
		fclose(F);
		return true;
	}	
}

bool leerListadoTotal(tString pNombreArchivo){
	FILE *F;
	tRegSup regSup;
	
	F = fopen(pNombreArchivo, "rb");
	
	if(F == NULL){
		printf(" Error al abrir el archivo para lectura.");
		return false;
	}
	else{
		printf("\n");
		float impTotal = 0; // Importe total
		int cantTicket = 0; // Cantidad de tickets en total
		
		while(fread(&regSup, sizeof(tRegSup), 1, F) == 1){
		int i;
		for(i=0; i<regSup.longitudArreglo; i++){ // For para calcular el importe total con los elementos que están dentro de los arreglos
			impTotal = impTotal + (regSup.cantVendido[i] * regSup.precio[i]);
		}
		cantTicket++; // Y fuera del for, sumar un ticket por cada recorrido del while
		}
		// Fuera del while imprimir los totales
		printf("\n Total Recaudado: %.2f", impTotal);
		printf("\n Cantidad de Tickets imprimidos: %d", cantTicket);
			
		fclose(F);
		return true;
	}
}













