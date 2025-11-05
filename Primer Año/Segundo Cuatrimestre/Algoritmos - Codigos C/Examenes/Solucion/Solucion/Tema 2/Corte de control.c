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

int totalGeneral;
int maximoPrestamo;
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
	
	
	totalGeneral=0;
	maximoPrestamo=0;
}

void procesoCorte(){
	while(!feof(archivoClientes)){
		principioCorte();
		
		while(!feof(archivoClientes) && cliente.codSocio == clienteAnterior.codSocio){
			unPrestamo();
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
	
	totalGeneral=totalGeneral + subTotalSocio;
	
	printf("\n-------------------------------------------------------------\n");
	printf("\nTotal prestado a %s\t %d\n", clienteAnterior.socio, subTotalSocio);
	printf("\n-------------------------------------------------------------\n");
	
	if(subTotalSocio >  maximoPrestamo){
		maximoPrestamo=subTotalSocio;
		strcpy(clienteMayorNombre,clienteAnterior.socio);
	}
	
	clienteAnterior = cliente;
}

void finalizar(){
	
	printf("\n-------------------------------------------------------------\n");
	printf("\n**Total de libros prestados %d\n", totalGeneral );
	printf("\n**Socio con mayor cantidad de libros prestados: %s\t %d\n", clienteMayorNombre, maximoPrestamo);
	printf("\n-------------------------------------------------------------\n");
	
	fclose(archivoClientes);
}
