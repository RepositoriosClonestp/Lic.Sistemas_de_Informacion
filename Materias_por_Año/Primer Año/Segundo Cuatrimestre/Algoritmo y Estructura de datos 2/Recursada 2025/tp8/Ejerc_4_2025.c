#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char string[50];

typedef struct {
	int cuenta;
	string nombre;
} tDatosCliente;

void inicializar();
void copiarClientes();
void finalizar();

FILE * archivoOrigen;
FILE * archivoDestino;
int contClientes;

int main() {
	inicializar();
	copiarClientes();
	finalizar();
	return 0;
}

void inicializar() {
	contClientes = 0;

	/* Abrir archivos: uno para lectura y otro para escritura */
	archivoOrigen = fopen("clientes.txt", "r");
	archivoDestino = fopen("clientes_backup.txt", "w");

	if (archivoOrigen == NULL || archivoDestino == NULL) {
		printf("Error al abrir los archivos.\n");
	}
}

void copiarClientes() {
	tDatosCliente cliente;

	printf("\nCOPIAMOS LOS CLIENTES AL ARCHIVO BACKUP\n");

	/* Leer cada línea del archivo origen y escribirla en el destino */
	while (fscanf(archivoOrigen, "%d %s", &cliente.cuenta, cliente.nombre) == 2) {
		fprintf(archivoDestino, "%d %s\n", cliente.cuenta, cliente.nombre);
		contClientes++;
	}

	if (contClientes == 0) {
		printf("\nNo se encontraron registros en el archivo origen.\n");
	}
}

void finalizar() {
	/* Cerrar ambos archivos */
	fclose(archivoOrigen);
	fclose(archivoDestino);

	/* Mostrar cantidad de registros copiados */
	printf("\nCantidad de registros copiados: %d\n", contClientes);
}

