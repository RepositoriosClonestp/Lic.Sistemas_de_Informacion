// Lista enlazada
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoAlumno {
    int numLibreta;
    char nombre[100];
    struct NodoAlumno* siguiente;
} tNodoAlumno;

tNodoAlumno* crearNodo(int numLibreta, const char* nombre) {
    tNodoAlumno* nuevoNodo = (tNodoAlumno*)malloc(sizeof(tNodoAlumno));
    nuevoNodo->numLibreta = numLibreta;
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

tNodoAlumno* insertarAlPrincipio(tNodoAlumno* lista, tNodoAlumno* nuevoNodo) {
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

tNodoAlumno* eliminarPrimerNodo(tNodoAlumno* lista) {
    if (lista == NULL) {
        printf("La lista está vacía.\n");
        return lista;
    }
    tNodoAlumno* siguienteNodo = lista->siguiente;
    free(lista);
    return siguienteNodo;
}

tNodoAlumno* insertarEnPosicion(tNodoAlumno* lista, tNodoAlumno* nuevoNodo, int posicion) {
    if (posicion <= 1) {
        nuevoNodo->siguiente = lista;
        return nuevoNodo;
    }
    tNodoAlumno* actual = lista;
    for (int i = 1; i < posicion - 1 && actual != NULL; i++) {
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        printf("Posición inválida.\n");
        return lista;
    }
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
    return lista;
}

tNodoAlumno* eliminarEnPosicion(tNodoAlumno* lista, int posicion) {
    if (posicion <= 1) {
        tNodoAlumno* siguienteNodo = lista->siguiente;
        free(lista);
        return siguienteNodo;
    }
    tNodoAlumno* actual = lista;
    for (int i = 1; i < posicion - 1 && actual != NULL; i++) {
        actual = actual->siguiente;
    }
    if (actual == NULL || actual->siguiente == NULL) {
        printf("Posición inválida.\n");
        return lista;
    }
    tNodoAlumno* nodoAEliminar = actual->siguiente;
    actual->siguiente = nodoAEliminar->siguiente;
    free(nodoAEliminar);
    return lista;
}

void mostrarLista(tNodoAlumno* lista) {
    printf("Alumnos en la lista:\n");
    tNodoAlumno* actual = lista;
    while (actual != NULL) {
        printf("Número de libreta: %d\n", actual->numLibreta);
        printf("Nombre: %s\n\n", actual->nombre);
        actual = actual->siguiente;
    }
}

int contarAlumnos(tNodoAlumno* lista) {
    int contador = 0;
    tNodoAlumno* actual = lista;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void liberarLista(tNodoAlumno* lista) {
    tNodoAlumno* actual = lista;
    while (actual != NULL) {
        tNodoAlumno* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    tNodoAlumno* lista = NULL;
    int opcion;
    int numLibreta;
    char nombre[100];
    int posicion;

    do {
        printf("\nMenú Principal:\n");
        printf("1. Insertar primer alumno\n");
        printf("2. Insertar alumno al principio\n");
        printf("3. Eliminar primer alumno\n");
        printf("4. Insertar alumno en posición\n");
        printf("5. Eliminar alumno en posición\n");
        printf("6. Mostrar lista de alumnos\n");
        printf("7. Cantidad de alumnos en la lista\n");
        printf("8. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el número de libreta: ");
                scanf("%d", &numLibreta);
                printf("Ingrese el nombre del alumno: ");
                scanf(" %[^\n]", nombre);
                lista = insertarAlPrincipio(lista, crearNodo(numLibreta, nombre));
                break;

            case 2:
                printf("Ingrese el número de libreta: ");
                scanf("%d", &numLibreta);
                printf("Ingrese el nombre del alumno: ");
                scanf(" %[^\n]", nombre);
                lista = insertarAlPrincipio(lista, crearNodo(numLibreta, nombre));
                break;

            case 3:
                lista = eliminarPrimerNodo(lista);
                break;

            case 4:
                printf("Ingrese el número de libreta: ");
                scanf("%d", &numLibreta);
                printf("Ingrese el nombre del alumno: ");
                scanf(" %[^\n]", nombre);
                printf("Ingrese la posición: ");
                scanf("%d", &posicion);
                lista = insertarEnPosicion(lista, crearNodo(numLibreta, nombre), posicion);
                break;

            case 5:
                printf("Ingrese la posición: ");
                scanf("%d", &posicion);
                lista = eliminarEnPosicion(lista, posicion);
                break;

            case 6:
                mostrarLista(lista);
                break;

            case 7:
                printf("Cantidad de alumnos en la lista: %d\n", contarAlumnos(lista));
                break;

            case 8:
                liberarLista(lista);
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 8);

    return 0;
}

