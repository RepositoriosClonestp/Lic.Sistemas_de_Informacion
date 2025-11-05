#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 100

struct Cola {
    int datos[MAX_TAM];
    int frente, fin;
};

// Función para inicializar una cola
void inicializarCola(struct Cola* cola) {
    cola->frente = cola->fin = -1;
}

// Función para verificar si la cola está vacía
int estaVacia(struct Cola* cola) {
    return cola->frente == -1;
}

// Función para verificar si la cola está llena
int estaLlena(struct Cola* cola) {
    return (cola->fin + 1) % MAX_TAM == cola->frente;
}

// Función para agregar un elemento a la cola
void encolar(struct Cola* cola, int elemento) {
    if (estaLlena(cola)) {
        printf("Error: la cola está llena.\n");
    } else {
        if (estaVacia(cola)) {
            cola->frente = 0;
        }
        cola->fin = (cola->fin + 1) % MAX_TAM;
        cola->datos[cola->fin] = elemento;
    }
}

// Función para quitar un elemento de la cola
int desencolar(struct Cola* cola) {
    if (estaVacia(cola)) {
        printf("Error: la cola está vacía.\n");
        return -1; // Valor especial para indicar error
    } else {
        int elemento = cola->datos[cola->frente];
        if (cola->frente == cola->fin) {
            inicializarCola(cola);
        } else {
            cola->frente = (cola->frente + 1) % MAX_TAM;
        }
        return elemento;
    }
}

int main() {
    struct Cola miCola;
    inicializarCola(&miCola);

    encolar(&miCola, 10);
    encolar(&miCola, 20);
    encolar(&miCola, 30);

    printf("Elementos de la cola: %d, %d, %d\n", desencolar(&miCola), desencolar(&miCola), desencolar(&miCola));

    return 0;
}
