#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 100

struct Pila {
    int datos[MAX_TAM];
    int tope;
};

// Función para inicializar una pila
void inicializarPila(struct Pila* pila) {
    pila->tope = -1;
}

// Función para verificar si la pila está vacía
int estaVacia(struct Pila* pila) {
    return pila->tope == -1;
}

// Función para verificar si la pila está llena
int estaLlena(struct Pila* pila) {
    return pila->tope == MAX_TAM - 1;
}

// Función para agregar un elemento a la pila
void push(struct Pila* pila, int elemento) {
    if (estaLlena(pila)) {
        printf("Error: la pila está llena.\n");
    } else {
        pila->datos[++(pila->tope)] = elemento;
    }
}

// Función para quitar un elemento de la pila
int pop(struct Pila* pila) {
    if (estaVacia(pila)) {
        printf("Error: la pila está vacía.\n");
        return -1; // Valor especial para indicar error
    } else {
        return pila->datos[(pila->tope)--];
    }
}

int main() {
    struct Pila miPila;
    inicializarPila(&miPila);

    push(&miPila, 10);
    push(&miPila, 20);
    push(&miPila, 30);

    printf("Elementos de la pila: %d, %d, %d\n", pop(&miPila), pop(&miPila), pop(&miPila));

    return 0;
}
