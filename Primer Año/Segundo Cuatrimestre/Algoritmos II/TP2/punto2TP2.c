// Lista enlazada
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definición del tipo de dato para el nodo de la lista
typedef struct NodoProducto {
    int codProducto;
    char descripcion[100];
    float precioUnitario;
    struct NodoProducto* siguiente;
} tNodoProducto;

// Función para crear un nuevo nodo con los datos ingresados
tNodoProducto* crearNodo(int codProducto, const char* descripcion, float precioUnitario) {
    tNodoProducto* nuevoNodo = (tNodoProducto*)malloc(sizeof(tNodoProducto));
    nuevoNodo->codProducto = codProducto;
    strcpy(nuevoNodo->descripcion, descripcion);
    nuevoNodo->precioUnitario = precioUnitario;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al principio de la lista
tNodoProducto* insertarAlPrincipio(tNodoProducto* lista, tNodoProducto* nuevoNodo) {
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

// Función para eliminar el primer nodo de la lista
tNodoProducto* eliminarPrimerNodo(tNodoProducto* lista) {
    if (lista == NULL) {
        printf("La lista está vacía.\n");
        return lista;
    }
    tNodoProducto* siguienteNodo = lista->siguiente;
    free(lista);
    return siguienteNodo;
}

// Función para visualizar todos los nodos de la lista
void mostrarLista(tNodoProducto* lista) {
    printf("Productos en la lista:\n");
    tNodoProducto* actual = lista;
    while (actual != NULL) {
        printf("Código de producto: %d\n", actual->codProducto);
        printf("Descripción: %s\n", actual->descripcion);
        printf("Precio unitario: %.2f\n\n", actual->precioUnitario);
        actual = actual->siguiente;
    }
}

int main() {
    tNodoProducto* lista = NULL;

    // Insertar el primer producto
    int cod;
    char desc[100];
    float precio;
    printf("Ingrese el código del primer producto: ");
    scanf("%d", &cod);
    printf("Ingrese la descripción del primer producto: ");
    scanf(" %[^\n]", desc);
    printf("Ingrese el precio unitario del primer producto: ");
    scanf("%f", &precio);
    lista = insertarAlPrincipio(lista, crearNodo(cod, desc, precio));

    // Mostrar los datos del primer producto
    printf("\nDatos del primer producto:\n");
    printf("Código de producto: %d\n", lista->codProducto);
    printf("Descripción: %s\n", lista->descripcion);
    printf("Precio unitario: %.2f\n\n", lista->precioUnitario);

    // Insertar otro producto al principio
    printf("Ingrese el código del producto a insertar al principio: ");
    scanf("%d", &cod);
    printf("Ingrese la descripción del producto a insertar al principio: ");
    scanf(" %[^\n]", desc);
    printf("Ingrese el precio unitario del producto a insertar al principio: ");
    scanf("%f", &precio);
    lista = insertarAlPrincipio(lista, crearNodo(cod, desc, precio));

    // Mostrar la lista completa
    mostrarLista(lista);

    // Eliminar el primer producto
    lista = eliminarPrimerNodo(lista);

    // Mostrar la lista después de la eliminación
    mostrarLista(lista);

    // Liberar memoria de la lista
    tNodoProducto* actual = lista;
    while (actual != NULL) {
        tNodoProducto* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    return 0;
}

