#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tipos de datos personalizados */
typedef struct {    
    int nroCaja;
    long nroVenta;
    float importe;
    int codTipoPago;
    char fecha[11]; // formato: DD/MM/AAAA
    char hora[6];   // formato: HH:MM
} tRegistro;

/* Declaración de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unaVenta();
void finCorte();

/* Declaración de variables */
float totalCaja, totalGeneral, totalEfectivo, totalTarjeta;
tRegistro reg, regAnterior;
FILE *archivo;

/* Bloque principal */
int main() {        
    inicializacion();    
    procesoCorte();        
    finalizacion();
}

/* Implementación de funciones */
void inicializacion() {
    archivo = fopen("ventasSupermercado.dat", "rb");
    if (archivo != NULL) {
        fread(&reg, sizeof(tRegistro), 1, archivo);    
    } else {
        printf("No se encuentra el archivo!\n");
        exit(EXIT_FAILURE);
    }
    regAnterior = reg;
    totalGeneral = 0.0;
    totalEfectivo = 0.0;
    totalTarjeta = 0.0;
    printf("\t\t *** SUPERMERCADO ASDF *** \n\n");
}

void procesoCorte() {
    while (!feof(archivo)) { 
        principioCorte(); 
        
        while (!feof(archivo) && reg.nroCaja == regAnterior.nroCaja) { 
            unaVenta();
            fread(&reg, sizeof(tRegistro), 1, archivo);    
        } 
        
        finCorte();
    }
}

void principioCorte() {
    printf("Caja N° %d\n", reg.nroCaja);
    printf("Nro Venta   |  Importe  |  Tipo Pago       |  Fecha - Hora\n");
    printf("-----------------------------------------------------------\n");
    totalCaja = 0.0;        
}

void unaVenta() {
    const char *tipoPago = (reg.codTipoPago == 1) ? "1 - Efectivo" : "2 - Tarjeta";
    printf("%-12ld | $%-9.2f | %-16s | %s   %s\n",
           reg.nroVenta,
           reg.importe,
           tipoPago,
           reg.fecha,
           reg.hora);
    
    totalCaja += reg.importe;
    if (reg.codTipoPago == 1) {
        totalEfectivo += reg.importe;
    } else if (reg.codTipoPago == 2) {
        totalTarjeta += reg.importe;
    }
}

void finCorte() {              
    printf("-----------------------------------------------------------\n");
    printf("Total caja: $%.2f\n\n", totalCaja);
    totalGeneral += totalCaja;
    regAnterior = reg;
}

void finalizacion() {
    printf("\n===========================================================\n");
    printf("Total final: $%.2f\n", totalGeneral);
    printf("Total 1 - Efectivo: $%.2f\n", totalEfectivo);
    printf("Total 2 - Tarjeta: $%.2f\n", totalTarjeta);
    fclose(archivo);
}

