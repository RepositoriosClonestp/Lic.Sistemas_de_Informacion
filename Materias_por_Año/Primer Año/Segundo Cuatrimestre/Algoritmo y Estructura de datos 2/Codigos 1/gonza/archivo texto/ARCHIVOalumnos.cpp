#include <stdio.h>

int main() {
    FILE *archivo;
    archivo = fopen("ArchivosAlumnos.txt", "r+"); // Abre el archivo para escritura

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    char continuar;
    int registros = 0;
    do {
        char dni[15];
        char nombre[50];

        printf("Ingrese el DNI del alumno: ");
        scanf("%s", dni);
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);

        // Escribe los datos en el archivo
        fprintf(archivo, "%s  %s\n", dni, nombre);

        registros++;

        printf("¿Desea continuar ingresando datos? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    fclose(archivo); // Cierra el archivo

    printf("Se han grabado %d registros en el archivo 'alumnos.txt'.\n", registros);

    return 0;
}
