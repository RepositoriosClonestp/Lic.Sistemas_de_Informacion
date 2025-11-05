#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Tipos de datos personalizados */

typedef struct {	    
    int nroCaja;
    long nroVenta;
    float importe;
    int codTipoPago;
    char fecha[11]; // formato: DD/MM/AAAA
    char hora[6];   // formato: HH:MM
    
}tRegistro;	 



/* Declaración de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unaVenta();
void finCorte();

/* Declaración de variables */
float totalCaja, totalGeneral;
tRegistro reg, regAnterior;
FILE * archivo;

int  codCampoControlAnt;

/* Bloque principal */
int main() {		
	inicializacion();	
	procesoCorte();		
	finalizacion();
}

/* Implementación de funciones */

void inicializacion() {
	/*	Actividades al inicio del programa:	
		1. Abrir archivo en modo lectura
		2. Leer el primer registro
		3. Guardar campo de control anterior
		4. Inicializar contadores/acumuladores generales/totales 
		5. Escribir titulos */
	archivo = fopen("ventasASDF.dat", "rb");
	if(archivo != NULL ){
		fread(&reg, sizeof(tRegistro), 1, archivo);	
	}else{
		printf("No se encuentra el archivo!\n");
		exit(EXIT_FAILURE);
	}
    regAnterior = reg;
    totalGeneral=0;
	printf("\t \t ***SUPERMERCADO ASDF*** \n\n");
    printf("Nro Venta   |  Importe  |  Tpo Pago         |  Fecha - Hora\n");
    printf("-----------------------------------------------------------\n");
		
	
}

void procesoCorte() {
	/* Recorrer el archivo hasta el final (feof) */
	while (!feof(archivo)) { 
	
		principioCorte(); 
		
		/* Con este while trabajamos con cada grupo  */
	    while(!feof(archivo) && reg.nroCaja == regAnterior.nroCaja) { 
			unaVenta();
			//leer otro registro
			fread(&reg, sizeof(tRegistro), 1, archivo);	
			
						
		} 
		/* Cuando termina este while significa que terminó un grupo entonces realizamos las actividades del corte */
		
		finCorte();
	}
	/* Cuando termina este while significa que se terminó de recorrer el archivo */
}

void principioCorte() {
	/* 	Actividades antes de recorrer los grupos:
			1. Inicializar los contadores/acumuladores parciales */			
	printf("Caja Nro: %d\n", reg.nroCaja);
    printf("-----------------------------------------------------------\n");
	totalCaja=0.0;		
}

void unaVenta() {
	/* Actividades por grupo
			1. Actualizar contadores/acumuladores parciales
			2. Mostrar la línea del detalle en el caso que sea necesario
			3. Buscar el mayor/menor del grupo (parcial) en el caso que sea necesario
			4. Leer otro registro (leerRegistro) */
	printf("%-12ld | $%-9.2f | %-16s | %s - %s\n",
               reg.nroVenta,
               reg.importe,
               reg.codTipoPago == 1 ? "Efectivo" : "Tarjeta",
               reg.fecha,
               reg.hora);

	totalCaja += reg.importe;
					
}

void finCorte(){      		
	/* 	Actividades por fin de corte de control
			1. Mostrar subtotales (línea de totales del grupo en el caso que el ejercicio lo solicite)
			2. Guardar la clave anterior(campo de control), en este caso codCarrera 		
			3. Calcular promedios/porcentajes parciales en el caso que el problema lo requiera
			4. Actualizar contadores/acumuladores generales			
			5. Buscar el mayor/menor (general) en el caso que el problema lo requiera */ 		
	printf("-----------------------------------------------------------\n");
    printf("Total Caja %d: $%.2f\n\n", regAnterior.nroCaja, totalCaja);
    totalGeneral += totalCaja;
	regAnterior = reg;
}

void finalizacion(){
	/* 	Actividades al finalizar
			1. Mostrar totales
			2. Calcular promedios/porcentajes generales en el caso que el problema lo requiera
			3. Cerrar el archivo */
	printf("\n===========================================================\n");
    printf("Total final: $%.2f\n", totalGeneral);
	
}
