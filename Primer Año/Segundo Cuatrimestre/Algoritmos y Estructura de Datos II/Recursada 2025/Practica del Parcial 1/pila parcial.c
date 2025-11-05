#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Estructuras

typedef struct {
    char titulo[50];
    char autor[50];
    char ultimaModificacion[30];
    bool cerradoConErrores;
} tDocumento;

typedef struct nodo {
    tDocumento doc;
    struct nodo *siguiente;
} tNodo;

typedef struct {
    tNodo *pila;
} tPila;

//   Prototipos de funciones

void inicializarPila(tPila *p);
bool pilaVacia(tPila *p);
tDocumento restaurarDocumento(tPila *p);
void visualizarDocumentos(tPila *p);


//   Implementación

// Inicializar pila

void inicializarPila(tPila *p) {
    p->pila = NULL;
}

// Verificar si la pila está vacía
bool pilaVacia(tPila *p) {
    return (p->pila == NULL);
}

// Restaurar (desapilar) documento


tDocumento restaurarDocumento(tPila *p) {
    tDocumento d;
    strcpy(d.titulo, "");
    strcpy(d.autor, "");
    strcpy(d.ultimaModificacion, "");
    d.cerradoConErrores = false;

    if (pilaVacia(p)) {
        printf("No existen documentos en la pila para restaurar.\n");
        return d;
    }

    tNodo *aux = p->pila;
    d = aux->doc;
    p->pila = aux->siguiente;
    free(aux);

    printf("Documento '%s' restaurado.\n", d.titulo);
    return d;
}

// Visualizar todos los documentos cerrados


void visualizarDocumentos(tPila *p) {
    if (pilaVacia(p)) {
        printf("No hay documentos para mostrar.\n");
        return;
    }

    tNodo *aux = p->pila;
    int total = 0, conErrores = 0, sinErrores = 0;

    printf("\n--- Documentos recientemente cerrados ---\n");
    while(aux != NULL) {
        printf("Titulo: %s | Autor: %s | Ultima Modificacion: %s | Cerrado con errores: %s\n",
               aux->doc.titulo,
               aux->doc.autor,
               aux->doc.ultimaModificacion,
               aux->doc.cerradoConErrores ? "Si" : "No");
        total++;
        if(aux->doc.cerradoConErrores) conErrores++;
        else sinErrores++;
        aux = aux->siguiente;
    }
    printf("----------------------------------------\n");
    printf("Total de documentos en pila: %d\n", total);
    printf("Total de documentos sin errores: %d\n", sinErrores);
    printf("Total de documentos con errores: %d\n", conErrores);
}
