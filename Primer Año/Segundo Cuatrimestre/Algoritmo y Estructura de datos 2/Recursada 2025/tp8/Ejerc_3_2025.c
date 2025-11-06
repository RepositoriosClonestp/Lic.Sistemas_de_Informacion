#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char string[50];

typedef struct {
	int dni;
	string nombre;
	string apellido;
} tDatosPersona;

void inicializar();
void leerPersonas();
void finalizar();

FILE * archivoTexto;
int contPersonas;

int main() {
	inicializar();
	leerPersonas();
	finalizar();
	return 0;
}

void inicializar() {
	contPersonas = 0;

	/* abrir archivo en modo lectura */
	archivoTexto = fopen("Personas.txt", "r");

	if (archivoTexto == NULL) {
		printf("No se pudo abrir el archivo para lectura.\n");
	}
}

void leerPersonas() {
	tDatosPersona persona;

	printf("\n LISTADO DE PERSONAS REGISTRADAS \n\n");

	/* leer línea por línea hasta fin de archivo */
	while (fscanf(archivoTexto, "%d %s %s", &persona.dni, persona.nombre, persona.apellido) == 3) {
		printf("DNI: %d\tNombre: %s\tApellido: %s\n", persona.dni, persona.nombre, persona.apellido);
		contPersonas++;
	}

	if (contPersonas == 0) {
		printf("\nNo se encontraron registros en el archivo.\n");
	}
}

void finalizar() {
	fclose(archivoTexto);
	printf("\nCantidad de registros leidos: %d\n", contPersonas);
}

