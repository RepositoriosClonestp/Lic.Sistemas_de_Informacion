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
void grabarArchivo();
void finalizarProceso();

FILE *archivoClientes; // Archivo de datos de los pedidos
tPedidosClientes * pedidosclientes;



int main() {
    iniciarProceso();    // Inicia el proceso y abre el archivo
    grabarArchivo();     // Permite ingresar datos y grabarlos en el archivo
    finalizarProceso();  // Cierra el archivo y finaliza el programa
    return 0;
}

void iniciarProceso() {
    
    archivoClientes = fopen("Prestamo.dat", "ab");  // Abre el archivo en modo de escritura binaria
    
    if (archivoClientes == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("\nArchivo creado correctamente.\n");
    }
}

void grabarArchivo() {
    char respuesta;
    
    printf("¿Desea ingresar datos? Responda s o n: ");
    fflush(stdin);
    scanf(" %c", &respuesta);
    
    while (respuesta == 's' || respuesta == 'S') {
        tPedidosClientes auxinfo;
		
		  
        printf("Ingrese el código del cliente: ");
        fflush(stdin);
        scanf("%d", &auxinfo.codSocio);
        
        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%s", &auxinfo.socio);
        
        printf("Ingrese la fecha del pedido en 'AAAA/MM/DD': ");
        scanf("%s", auxinfo.fecha);
        
        printf("Ingrese el nro prestamo: ");
        fflush(stdin);
        scanf("%d", &auxinfo.nroPrestamo);
        
        printf("ingrese el titulo ");
          fflush(stdin);
        scanf("%s", &auxinfo.titulo);
        printf("\n");

        // Escribe en el archivo
        fwrite(&auxinfo, sizeof(tPedidosClientes), 1, archivoClientes);

        printf("¿Desea ingresar datos? Responda s o n: ");
        fflush(stdin);
        scanf(" %c", &respuesta);
    }
}

void finalizarProceso() {
    fclose(archivoClientes); // Cierra el archivo
    printf("Archivo cerrado...\n");
}

