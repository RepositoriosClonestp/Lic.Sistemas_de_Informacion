#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

typedef char tString[MAX];

typedef struct{
	int codSocio;
	tString socio;
	int nroPrestamo; //	----No importa si no esta (por el enunciado)
	char fecha [10];
	tString titulo;
}tPedidosClientes;


// Declaración de funciones
void iniciarProceso();
void procesoCorte();
void finalizarProceso();
void unaCuenta();

FILE *archivoClientes; // Archivo para guardar los datos de los pedidos

// Variables globales
tPedidosClientes cliente, clienteAnterior;

int main() {
    iniciarProceso();    // Inicia el proceso y abre el archivo
    procesoCorte();      // Procesa el archivo y genera el reporte
    finalizarProceso();  // Cierra el archivo y finaliza el programa
    return 0;
}

void iniciarProceso() {
    archivoClientes = fopen("prestamo.dat", "rb");  // Abre el archivo en modo lectura binaria
    
    if (archivoClientes == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("\nArchivo abierto exitosamente.\n");
    }

}

void procesoCorte() {
	fread(&cliente, sizeof(tPedidosClientes), 1, archivoClientes);

    while (!feof(archivoClientes)) {
      
            unaCuenta(); // Procesa cada pedido y acumula los importes
            fread(&cliente, sizeof(tPedidosClientes), 1, archivoClientes);
    }

}


void unaCuenta() {
    printf("%d\tCliente:%s\t%s\n", cliente.codSocio, cliente.socio, cliente.titulo);
    
}

void finalizarProceso() {
  
    fclose(archivoClientes); 
}

