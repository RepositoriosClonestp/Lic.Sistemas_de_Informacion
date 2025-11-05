#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Nodo {
    int dato;                // El valor del nodo
    struct Nodo* siguiente;  // Puntero al siguiente nodo
};

// Declaración de la cabeza de la lista (variable global)
struct Nodo* cabeza = NULL;  // Inicializamos la lista como vacía

// Función para imprimir la lista
void imprimirLista() {
    struct Nodo* actual = cabeza;

    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void liberarLista() {
    struct Nodo* actual = cabeza;
    struct Nodo* siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    cabeza = NULL;  // Asegurarse de que la cabeza apunte a NULL después de liberar la lista
}

// Función para agregar un nodo al principio de la lista
void agregarAlPrincipio(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));  // Crear un nuevo nodo
    nuevoNodo->dato = valor;  // Asignar el valor al nuevo nodo
    nuevoNodo->siguiente = cabeza;  // Hacer que el nuevo nodo apunte al antiguo primer nodo

    cabeza = nuevoNodo;  // El nuevo nodo ahora es la cabeza de la lista
}

// Función para agregar un nodo al final de la lista
void agregarAlFinal(int valor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));  // Crear un nuevo nodo
    nuevoNodo->dato = valor;  // Asignar el valor al nuevo nodo
    nuevoNodo->siguiente = NULL;  // El nuevo nodo apunta al siguiente como NULL

    // Verificar si la lista está vacía
    if (cabeza == NULL) {
        cabeza = nuevoNodo;  // Si está vacía, el nuevo nodo es la cabeza
    } else {
        // Si la lista no está vacía, encontrar el último nodo y hacer que apunte al nuevo nodo
        struct Nodo* ultimo = cabeza;
        while (ultimo->siguiente != NULL) {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;
    }
}

// Función para agregar un nodo en la mitad de la lista
void agregarEnLaMitad(int valor, int posicion) {
    if (posicion <= 0) {
        printf("La posición debe ser un número positivo.\n");
        return;
    }

    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));  // Crear un nuevo nodo
    nuevoNodo->dato = valor;  // Asignar el valor al nuevo nodo

    // Caso especial: si la posición es 1, agregar al principio
    if (posicion == 1) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        return;
    }

    // Buscar el nodo en la posición anterior a la posición deseada
    struct Nodo* actual = cabeza;
    for (int i = 1; i < posicion - 1 && actual != NULL; i++) {
        actual = actual->siguiente;
    }

    // Verificar si la posición deseada es válida
    if (actual == NULL) {
        printf("La posición excede la longitud de la lista.\n");
        free(nuevoNodo);  // Liberar el nuevo nodo antes de salir
        return;
    }

    // Insertar el nuevo nodo en la posición deseada
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

int main() {
    // Agregar nodos a la lista
    agregarAlFinal(10);
    agregarAlFinal(20);
    agregarAlFinal(30);

    // Imprimir la lista
    printf("Lista inicial: ");
    imprimirLista();

    // Agregar al principio
    agregarAlPrincipio(5);
    printf("Después de agregar al principio: ");
    imprimirLista();

    // Agregar en la mitad (en la posición 2)
    agregarEnLaMitad(15, 2);
    printf("Después de agregar en la mitad: ");
    imprimirLista();

    // Liberar la memoria de la lista
    liberarLista();

    return 0;
}









