// Lista enlazada
#include <stdio.h>
#include <stdlib.h>

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

int main() {
    tNodoProducto* primerNodo = NULL; // Puntero al primer nodo de la lista

    // Ingreso de datos por teclado
    int cod;
    char desc[100];
    float precio;
    printf("Ingrese el código del producto: ");
    scanf("%d", &cod);
    printf("Ingrese la descripción del producto: ");
    scanf(" %[^\n]", desc); // %[^n] se usa para leer hasta que se ingrese un salto de línea
    printf("Ingrese el precio unitario del producto: ");
    scanf("%f", &precio);

    // Crear el primer nodo de la lista
    primerNodo = crearNodo(cod, desc, precio);

    // Mostrar los datos del primer nodo almacenado
    printf("\nDatos del primer nodo:\n");
    printf("Código de producto: %d\n", primerNodo->codProducto);
    printf("Descripción: %s\n", primerNodo->descripcion);
    printf("Precio unitario: %.2f\n", primerNodo->precioUnitario);

    // Liberar memoria del nodo
    free(primerNodo);

    return 0;
}

