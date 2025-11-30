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
void grabarPersonas();
void finalizar();

FILE * archivoTexto;
int contPersonas;

int main() {
	inicializar();
	grabarPersonas();
	finalizar();
	return 0;
}

void inicializar() {
	contPersonas = 0;
	
	/* abrir archivo en modo escritura */
	archivoTexto = fopen("Personas.txt", "w");
	
	if (archivoTexto == NULL) {
		printf("No se pudo abrir el archivo.\n");
	}
}

void grabarPersonas() {		
	tDatosPersona persona;	
	char opcion = 's';
	
	while (opcion == 's') {
		contPersonas++;
		
		printf("\nIngresar DNI: ");
		scanf("%d", &persona.dni);
		
		printf("Ingresar nombre: ");
		fflush(stdin);
		gets(persona.nombre);
		
		printf("Ingresar apellido: ");
		fflush(stdin);
		gets(persona.apellido);
		
		/* insertar, escribir o grabar una línea con formato */
		fprintf(archivoTexto, "%d %s %s\n", persona.dni, persona.nombre, persona.apellido);	
		
		printf("¿Ingresar otro? (s/n): ");
		fflush(stdin);
		scanf("%c", &opcion);
		
		opcion = tolower(opcion);		
	}
}

void finalizar() {
	/* Cerrar el archivo */
	fclose(archivoTexto);
	
	/* Mostrar la cantidad de registros grabados */
	printf("\nCantidad de registros grabados: %d\n", contPersonas);
}

