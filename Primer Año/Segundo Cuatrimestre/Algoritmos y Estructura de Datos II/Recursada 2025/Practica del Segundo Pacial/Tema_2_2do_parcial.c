#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITULO "\n***Informe de Pedidos por Dia***\n\n"

typedef char tString[50];

typedef struct {
    char fecha[9];         /* AAAAMMDD + '\0'*/
    tString cliente;
    float importe;
} tPedido;

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unPedido();
void finCorte();

FILE *pedidos;
tPedido ped, pedAnt;

float totalGeneral;
float totalDia;
float maxImporteDia;
tString clienteMaxDia;
int contadorDias;

int main() {
    inicializacion();
    procesoCorte();
    finalizacion();
    return 0;
}

void inicializacion() {
    pedidos = fopen("Pedidos.dat", "rb");
    if (pedidos == NULL) {
        printf("No se encuentra el archivo!\n");
        exit(EXIT_FAILURE);
    }

    fread(&ped, sizeof(tPedido), 1, pedidos);
    pedAnt = ped;

    totalGeneral = 0;
    contadorDias = 0;

    printf("%s", TITULO);
    printf("Fecha\t\tCliente\t\t\tImporte Pedido\n");
    printf("------------------------------------------------------------\n");
}

void procesoCorte() {
    while (!feof(pedidos)) {
        principioCorte();

        /* Imprimimos fecha una sola vez por dia*/
        printf("%s\n", pedAnt.fecha);

        while (!feof(pedidos) && strcmp(ped.fecha, pedAnt.fecha) == 0) {
            unPedido();
            fread(&ped, sizeof(tPedido), 1, pedidos);
        }

        finCorte();
    }
}

void principioCorte() {
    totalDia = 0;
    maxImporteDia = 0;
    strcpy(clienteMaxDia, "");
}

void unPedido() {
    printf("\t%-15s\t$%.2f\n", ped.cliente, ped.importe);

    totalDia += ped.importe;

    if (ped.importe > maxImporteDia) {
        maxImporteDia = ped.importe;
        strcpy(clienteMaxDia, ped.cliente);
    }
}

void finCorte() {
    printf("\n* Cliente con mayor pedido del d�a: %s (Importe: $%.2f)\n\n",
           clienteMaxDia, maxImporteDia);

    totalGeneral += totalDia;
    contadorDias++;

    pedAnt = ped;
}

void finalizacion() {
    printf("------------------------------------------------------------\n");
    printf("Total de dias registrados: %d\n", contadorDias);
    printf("Total General de Pedidos: $%.2f\n", totalGeneral);

    fclose(pedidos);
}


