#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void imprimirLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void liberarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    struct Nodo* siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

void agregarAlPrincipio(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void agregarAlFinal(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo* ultimo = *cabeza;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;
    }
}

void agregarEnLaMitad(struct Nodo* nodoAnterior, int valor) {
    if (nodoAnterior == NULL) {
        printf("Error: El nodo anterior no puede ser NULL.\n");
        return;
    }

    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nodoAnterior->siguiente;
    nodoAnterior->siguiente = nuevoNodo;
}

int main() {
    struct Nodo* cabeza = NULL;

    agregarAlFinal(&cabeza, 1);
    agregarAlFinal(&cabeza, 2);
    agregarAlFinal(&cabeza, 3);

    printf("Lista inicial: ");
    imprimirLista(cabeza);

    agregarAlPrincipio(&cabeza, 0);
    printf("Lista después de agregar al principio: ");
    imprimirLista(cabeza);

    // Agregar nodo en cualquier parte de la lista (después del primer nodo)
    agregarEnLaMitad(cabeza, 5);
    printf("Lista después de agregar en la mitad: ");
    imprimirLista(cabeza);

    // Liberar la memoria de la lista
    liberarLista(cabeza);

    return 0;
}


