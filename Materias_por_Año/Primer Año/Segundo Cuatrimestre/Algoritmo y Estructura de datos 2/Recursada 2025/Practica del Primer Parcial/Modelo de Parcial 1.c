#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char tString[20];

// Estructura para el proceso
typedef struct {
    char idProceso[10];
    int tamanioMemoria;
    int tipoProceso; // 1 = sistema, 2 = usuario
} tProcesoEnEspera;

// Nodo de la cola
typedef struct nodo {
    tProcesoEnEspera proceso;
    struct nodo *siguiente;
} tNodo;

// Cola con punteros a frente y final
typedef struct {
    tNodo *frente;
    tNodo *final;
} tCola;

/* Inicializar la cola */
void inicializarCola(tCola *cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

/* Verificar si está vacía */
int colaVacia(tCola *cola) {
    return (cola->frente == NULL);
}

/* Encolar un proceso */
void encolar(tCola *cola, tProcesoEnEspera proceso) {
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    nuevo->proceso = proceso;
    nuevo->siguiente = NULL;

    if (cola->final == NULL) {
        cola->frente = nuevo;
    } else {
        cola->final->siguiente = nuevo;
    }
    cola->final = nuevo;
}

/* Asignar memoria al primer proceso (desencolar) */
void asignarMemoria(tCola *cola) {
    if (colaVacia(cola)) {
        printf("No hay procesos en espera.\n");
        return;
    }

    tNodo *aux = cola->frente;
    tProcesoEnEspera p = aux->proceso;

    printf("\n*** Asignando Memoria ***\n");
    printf("ID Proceso: %s\n", p.idProceso);
    printf("Tamaño de Memoria: %d MB\n", p.tamanioMemoria);
    printf("Tipo de Proceso: %s\n", (p.tipoProceso == 1) ? "Sistema" : "Usuario");

    cola->frente = cola->frente->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    free(aux);
}

/* Mostrar todos los procesos en la cola */
void mostrarCola(tCola *cola) {
    if (colaVacia(cola)) {
        printf("No hay procesos en espera.\n");
        return;
    }

    printf("\n*** Procesos en espera ***\n");
    tNodo *aux = cola->frente;
    int contador = 0;
    while (aux != NULL) {
        printf("ID: %s | Memoria: %d MB | Tipo: %s\n",
               aux->proceso.idProceso,
               aux->proceso.tamanioMemoria,
               (aux->proceso.tipoProceso == 1) ? "Sistema" : "Usuario");
        aux = aux->siguiente;
        contador++;
    }
    printf("Total de procesos en espera: %d\n", contador);
}

/* Programa principal */
int main() {
    tCola cola;
    inicializarCola(&cola);

    tProcesoEnEspera p1 = {"P001", 1024, 1};
    tProcesoEnEspera p2 = {"P002", 2048, 2};

    encolar(&cola, p1);
    encolar(&cola, p2);

    mostrarCola(&cola);

    asignarMemoria(&cola);

    mostrarCola(&cola);

    return 0;
}

