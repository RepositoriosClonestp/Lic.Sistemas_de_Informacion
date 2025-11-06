
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <stdbool.h> 


typedef char tFecha[9]; 

typedef struct {	    
    tFecha fecha; 
	int entrantes;
	int salientes;   
} tInventario;	 


void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unDia(); 
void finCorte();


FILE * inventario;
tInventario registro, registroAnterior;


int subtotalEntrantes, subtotalSalientes;


int totalDias;
int maxSalientes;
tFecha fechaMaxSalientes;



int main() {		
	inicializacion();	
	procesoCorte();		
	finalizacion();
	return 0; 
}


void inicializacion() {
		
	inventario = fopen("Inventario.dat", "rb");	
	
	if(inventario != NULL ) {
		fread(&registro, sizeof(tInventario), 1, inventario);	
	} else {
		printf("No se encuentra el archivo 'Inventario.dat'!\n");
		exit(EXIT_FAILURE);
	}
	
	///CLAVE!!!!!!
	registroAnterior = registro;
	

	totalDias = 0;
	maxSalientes = 0; 
	
	printf("%s", "\n*** Informe de Inventario por Día ***\n");
	
	printf("Fecha\t\tTotal de Entradas\tTotal de Salidas\n");
	printf("---------------------------------------------------\n");
}

void procesoCorte() {

	while (!feof(inventario)) { 
	
		principioCorte(); 
		

	    while(!feof(inventario) && strcmp(registro.fecha, registroAnterior.fecha) == 0) { 
			unDia();
			fread(&registro, sizeof(tInventario), 1, inventario);					
		} 
		
		finCorte();
	}

}

void principioCorte() {
		
	subtotalEntrantes = 0;
	subtotalSalientes = 0;	
}

void unDia() {

	subtotalEntrantes += registro.entrantes;
	subtotalSalientes += registro.salientes;
	
	
	
	
}

void finCorte(){      		
	

	printf("%s\t%d\t\t\t%d\n", registroAnterior.fecha, subtotalEntrantes, subtotalSalientes);
	

	totalDias++; 
	
	// 3. Buscar el mayor general
	if (subtotalSalientes > maxSalientes) {
		maxSalientes = subtotalSalientes;
		strcpy(fechaMaxSalientes, registroAnterior.fecha); 
	}
	
	// CLAVE!!!!!!
	registroAnterior = registro;
}

void finalizacion(){

	printf("----------------------------------------------------------------\n");
	printf("Total de días registrados en el mes: %d\n", totalDias);
	
	if (totalDias > 0) {
		printf("Día con más artículos salientes: %s (%d salidas)\n", fechaMaxSalientes, maxSalientes);
	} else {
		printf("No se procesaron registros.\n");
	}
	//clave!
	fclose(inventario);
}
