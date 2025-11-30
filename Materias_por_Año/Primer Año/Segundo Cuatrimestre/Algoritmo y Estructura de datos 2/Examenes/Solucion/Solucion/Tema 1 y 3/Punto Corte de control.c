#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char tString[50];

typedef struct{
	int codSocio;
	tString socio;
	int nroPrestamo; //	----No importa si no esta (por el enunciado)
	char fecha [10];
	tString titulo;
}tCliente;

void inicializar();
void procesoCorte();
void finalizar();

void principioCorte();
void finCorte();
void unPrestamo();

tCliente cliente, clienteAnterior;
int subTotalSocio;

int totalDeSocios;
int menorPrestamo;
tString clienteMayorNombre;

FILE * archivoClientes;

int main(){
	inicializar();
	procesoCorte();
	finalizar();
	
	return 0;
}

void inicializar(){
	archivoClientes = fopen("Prestamo.dat", "rb");
	if(archivoClientes != NULL ){
		fread(&cliente, sizeof(tCliente), 1, archivoClientes);	
	}else{
		printf("No se encuentra el archivo!\n");
		exit(EXIT_FAILURE);
	}
	
	clienteAnterior = cliente;

	
	printf("\n código. socio	Socio	Nro. préstamo	Fecha préstamo	Título libro\n");
	
	
	totalDeSocios=0;
	menorPrestamo=999999;
}

void procesoCorte(){
	while(!feof(archivoClientes)){
		principioCorte();
		
		while(!feof(archivoClientes) && cliente.codSocio == clienteAnterior.codSocio){
			//unPrestamo();
			
			subTotalSocio = subTotalSocio +1;
	        printf("\n%d %s %s %s", cliente.codSocio, cliente.socio, cliente.fecha, cliente.titulo );

			fread(&cliente, sizeof(tCliente), 1, archivoClientes);
		}
		finCorte();
	}
}

void principioCorte(){
	subTotalSocio = 0;
}

void unPrestamo(){
	subTotalSocio = subTotalSocio +1;
	printf("\n%d %s %s %s", cliente.codSocio, cliente.socio, cliente.fecha, cliente.titulo );
}

void finCorte(){
	
	totalDeSocios=totalDeSocios + 1;
	
	printf("\n-------------------------------------------------------------\n");
	printf("\nTotal prestado a %s\t %d\n", clienteAnterior.socio, subTotalSocio);
	printf("\n-------------------------------------------------------------\n");
	
	if(subTotalSocio < menorPrestamo){
		menorPrestamo=subTotalSocio;
		strcpy(clienteMayorNombre,clienteAnterior.socio);
	}
	
	clienteAnterior = cliente;
}

void finalizar(){
	
	printf("\n-------------------------------------------------------------\n");
	printf("\n**Total de socios %d\n", totalDeSocios );
	printf("\n**Socio con menor cantidad de libros prestados: %s\t %d\n", clienteMayorNombre, menorPrestamo);
	printf("\n-------------------------------------------------------------\n");
	
	fclose(archivoClientes);
}
