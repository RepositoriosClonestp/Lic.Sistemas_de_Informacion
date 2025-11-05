#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definición de la estructura del nodo */
typedef struct Nodo {
    int numeroEstudio;
    char dni[10];
    char nombreApellido[50];
    char codigoLocalidad[3];
    struct Nodo* siguiente;
} Nodo;

/* Definición de la estructura de la cola */
typedef struct Cola {
    Nodo* frente;
    Nodo* fondo;
} Cola;

/* Prototipos de funciones */
Cola* crearCola();
void incorporarEstudio(Cola* cola, int numeroEstudio, char* dni, char* nombreApellido, char* codigoLocalidad);
int contabilizarEstudiosCapital(Cola* cola);
void visualizarEstudiosCapital(Cola* cola);
void liberarCola(Cola* cola);

int main() {
    Cola* colaEstudios = crearCola();
    char continuar;
    
    do {
        int numeroEstudio;
        char dni[10], nombreApellido[50], codigoLocalidad[3];

        printf("Ingrese el número de estudio: \n");
        scanf("%d", &numeroEstudio);
        
        printf("Ingrese el DNI del paciente: \n");
        scanf("%s", dni);
        
        printf("Ingrese el nombre y apellido del paciente: \n");
        scanf(" %[^\n]", nombreApellido); // Leer hasta el salto de línea
        
        printf("Ingrese el código de la localidad: \n");
        scanf("%s", codigoLocalidad);
        
        incorporarEstudio(colaEstudios, numeroEstudio, dni, nombreApellido, codigoLocalidad);
        
        printf("¿Desea cargar más datos? (S-SI, N-NO): \n");
        scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');
    
    int estudiosCapital = contabilizarEstudiosCapital(colaEstudios);
    printf("Total de estudios que faltan realizar de la localidad Capital: %d\n", estudiosCapital);
    
    visualizarEstudiosCapital(colaEstudios);
    
    liberarCola(colaEstudios);
    
    return 0;
}

Cola* crearCola() {
    Cola* nuevaCola = (Cola*)malloc(sizeof(Cola));
    nuevaCola->frente = NULL;
    nuevaCola->fondo = NULL;
    return nuevaCola;
}

void incorporarEstudio(Cola* cola, int numeroEstudio, char* dni, char* nombreApellido, char* codigoLocalidad) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->numeroEstudio = numeroEstudio;
    strcpy(nuevoNodo->dni, dni);
    strcpy(nuevoNodo->nombreApellido, nombreApellido);
    strcpy(nuevoNodo->codigoLocalidad, codigoLocalidad);
    nuevoNodo->siguiente = NULL;

    if (cola->fondo == NULL) {
        cola->frente = nuevoNodo;
        cola->fondo = nuevoNodo;
    } else {
        cola->fondo->siguiente = nuevoNodo;
        cola->fondo = nuevoNodo;
    }
}

int contabilizarEstudiosCapital(Cola* cola) {
    int contador = 0;
    Nodo* actual = cola->frente;

    while (actual != NULL) {
        if (strcmp(actual->codigoLocalidad, "01") == 0) {
            contador++;
        }
        actual = actual->siguiente;
    }
    return contador;
}

void visualizarEstudiosCapital(Cola* cola) {
    Nodo* actual = cola->frente;
    int contador = 0;

    printf("Estudios que faltan realizar de la localidad Capital:\n");
    while (actual != NULL) {
        if (strcmp(actual->codigoLocalidad, "01") == 0) {
            printf("Número de estudio: %d, DNI: %s, Nombre y Apellido: %s\n", 
                   actual->numeroEstudio, actual->dni, actual->nombreApellido);
            contador++;
        }
        actual = actual->siguiente;
    }
    printf("Total de estudios que faltan realizar de la localidad Capital: %d\n", contador);
}

void liberarCola(Cola* cola) {
    Nodo* actual = cola->frente;
    Nodo* siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(cola);
}
