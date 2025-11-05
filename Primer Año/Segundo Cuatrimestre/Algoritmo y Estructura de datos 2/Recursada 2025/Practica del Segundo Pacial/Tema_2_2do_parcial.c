#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITULO "\n***Informe de Pedidos por Dia***\n\n"

typedef char tString[50]; // Definición de tipo para cadenas de texto
// Estructura de datos para un pedido
typedef struct {
    char fecha[9];         /* AAAAMMDD + '\0'*/
    tString cliente;
    float importe;
} tPedido;
// Prototipos de funciones
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unPedido();
void finCorte();
// Variables globales
FILE *pedidos;
tPedido ped, pedAnt;
// Variables de control y acumuladores
float totalGeneral;
float totalDia;
float maxImporteDia;
tString clienteMaxDia;
int contadorDias;
// Función principal
int main() {
    inicializacion();
    procesoCorte();
    finalizacion();
    return 0;
}
// Definición de funciones
void inicializacion() {
    pedidos = fopen("Pedidos.dat", "rb"); // Abrir archivo de pedidos
    if (pedidos == NULL) {
        printf("No se encuentra el archivo!\n"); 
        exit(EXIT_FAILURE); // Salir si no se puede abrir el archivo
    }

    fread(&ped, sizeof(tPedido), 1, pedidos); // Leer el primer pedido
    pedAnt = ped;

    totalGeneral = 0; // Inicializar acumulador general
    contadorDias = 0; // Inicializar contador de dias

    printf("%s", TITULO);
    printf("Fecha\t\tCliente\t\t\tImporte Pedido\n");
    printf("------------------------------------------------------------\n");
}
// Procesamiento por cortes 
void procesoCorte() {
    while (!feof(pedidos)) { // Mientras no sea fin de archivo
        principioCorte();

        /* Imprimimos fecha una sola vez por dia*/
        printf("%s\n", pedAnt.fecha);

        while (!feof(pedidos) && strcmp(ped.fecha, pedAnt.fecha) == 0) { // Mismo dia
            unPedido();
            fread(&ped, sizeof(tPedido), 1, pedidos); // Leer siguiente pedido
        }

        finCorte();
    }
}
// Procesamiento por un dia
void principioCorte() {
    totalDia = 0; // Inicializar acumulador del dia
    maxImporteDia = 0; // Inicializar maximo del dia
    strcpy(clienteMaxDia, ""); // Inicializar cliente con maximo
}
// Procesamiento de un pedido
void unPedido() {
    printf("\t%-15s\t$%.2f\n", ped.cliente, ped.importe); // Imprimir pedido

    totalDia += ped.importe; // Acumular importe del dia

    if (ped.importe > maxImporteDia) { // Actualizar maximo del dia
        maxImporteDia = ped.importe; 
        strcpy(clienteMaxDia, ped.cliente); // Actualizar cliente con maximo
    }
}
// Finalización del procesamiento por un dia
void finCorte() {
    printf("\n* Cliente con mayor pedido del dia: %s (Importe: $%.2f)\n\n",
           clienteMaxDia, maxImporteDia); // Imprimir cliente con maximo del dia

    totalGeneral += totalDia; // Acumular al total general
    contadorDias++; // Incrementar contador de dias

    pedAnt = ped; // Actualizar pedido anterior
}
 // Finalización del procesamiento
void finalizacion() {
    printf("------------------------------------------------------------\n");
    printf("Total de dias registrados: %d\n", contadorDias); // Imprimir total de dias
    printf("Total General de Pedidos: $%.2f\n", totalGeneral); // Imprimir total general

    fclose(pedidos); // Cerrar archivo
}


