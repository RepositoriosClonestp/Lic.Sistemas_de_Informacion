#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char nombreArchivo[100];
    char continuar;
    char dni[20], nombre[100];

    printf("Ingrese el nombre del archivo de texto: ");
    scanf("%s", nombreArchivo);

    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    do {
        printf("Ingrese el DNI del alumno: ");
        scanf("%s", dni);

        printf("Ingrese el nombre del alumno: ");
        scanf(" %99[^\n]", nombre); // Lee el nombre del alumno, evitando desbordar el buffer

        fprintf(archivo, "%s %s\n", dni, nombre);

        printf("¿Desea continuar ingresando datos? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    fclose(archivo);

    // Reabrir el archivo para lectura
    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    int cantidadRegistros = 0;
    while (fscanf(archivo, "%s %99[^\n]\n", dni, nombre) != EOF) {
        printf("DNI: %s, Nombre: %s\n", dni, nombre);
        cantidadRegistros++;
    }

    fclose(archivo);

    printf("Cantidad de registros grabados: %d\n", cantidadRegistros);

    return 0;
}




