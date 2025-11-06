#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITULO "\n*** Informe de Inventario por Dia ***\n\n"

typedef char tString[10];

typedef struct {
    char fecha[9];     
	int entradas;
    int salidas;
} tInventario;

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unRegistro();
void finCorte();

FILE *inventario;
tInventario reg, regAnt;

int totalEntradasDia, totalSalidasDia;
int totalDias;
int diaMayorSalidas;
int maxSalidas;

int main() {
    inicializacion();
    procesoCorte();
    finalizacion();
    return 0;
}

void inicializacion() {
    inventario = fopen("Inventario.dat", "rb");
    if (inventario == NULL) {
        printf("No se encuentra el archivo!\n");
        exit(EXIT_FAILURE);
    }

    fread(&reg, sizeof(tInventario), 1, inventario);
    regAnt = reg;

    totalDias = 0;
    maxSalidas = 0;

    printf("%s", TITULO);
    printf("Fecha\t\tTotal de Entradas\tTotal de Salidas\n");
    printf("--------------------------------------------------------\n");
}

void procesoCorte() {
    while (!feof(inventario)) {
        principioCorte();

        /* Imprimimos la fecha una sola vez por día*/
        printf("%s\t", regAnt.fecha);

        while (!feof(inventario) && strcmp(reg.fecha, regAnt.fecha) == 0) {
            unRegistro();
            fread(&reg, sizeof(tInventario), 1, inventario);
        }

        finCorte();
    }
}

void principioCorte() {
    totalEntradasDia = 0;
    totalSalidasDia = 0;
}

void unRegistro() {
    totalEntradasDia += reg.entradas;
    totalSalidasDia += reg.salidas;
}

void finCorte() {
    printf("%10d\t\t%10d\n", totalEntradasDia, totalSalidasDia);

    totalDias++;

    if (totalSalidasDia > maxSalidas) {
        maxSalidas = totalSalidasDia;
        diaMayorSalidas = atoi(regAnt.fecha);
    }

    regAnt = reg;
}

void finalizacion() {
    printf("--------------------------------------------------------\n");
    printf("Total de dias registrados en el mes: %d\n", totalDias);
    printf("Dia con mas articulos salientes: %d (%d salidas)\n", diaMayorSalidas, maxSalidas);

    fclose(inventario);
}

