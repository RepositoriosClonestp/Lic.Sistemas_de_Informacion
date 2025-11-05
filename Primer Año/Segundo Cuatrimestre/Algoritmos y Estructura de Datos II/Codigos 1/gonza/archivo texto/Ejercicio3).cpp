#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char nombreArchivo[100];
    char dni[20], nombre[100];

    archivo = fopen("Ejercicio2)", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("Registros en el archivo:\n");

    while (fscanf(archivo, "%s %99[^\n]\n", dni, nombre) != EOF) {
        printf("DNI: %s, Nombre: %s\n", dni, nombre);
    }

    fclose(archivo);

    return 0;
}

