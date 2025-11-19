#include <stdio.h>
#include <stdlib.h>
//#include <stbool.h>
#include <string.h>

/* Parte TAD */

//Cola 
typedef struct NodoCola {
    int idUsuario; //
    struct NodoCola* siguiente;
}tNodoCola;

typedef struct {
    NodoCola *frente, *final;
}tCola;

//Libros
typedef struct {
    long long code;
    char titulo[100];
    char autor[100];
    int disponible; // 1 = disponible, 0 = prestado
    Cola* listaEspera; // Cola de IDs de usuarios esperando por este libro
}tLibro;

// Estructura del nodo del árbol AVL para libros
typedef struct NodoArbol {
    Libro libro;
    struct NodoArbol *izquierda;
    struct NodoArbol *derecha;
    int altura;
} NodoArbol;

// Variable global para la raíz del árbol
NodoArbol *raizLibros = NULL;

// Funciones auxiliares para el árbol AVL
int max(int a, int b) {
    return (a > b) ? a : b;
}

int obtenerAltura(NodoArbol *nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

int obtenerBalance(NodoArbol *nodo) {
    if (nodo == NULL)
        return 0;
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

// Rotación simple a la derecha
NodoArbol *rotacionDerecha(NodoArbol *y) {
    NodoArbol *x = y->izquierda;
    NodoArbol *T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    return x;
}

// Rotación simple a la izquierda
NodoArbol *rotacionIzquierda(NodoArbol *x) {
    NodoArbol *y = x->derecha;
    NodoArbol *T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    return y;
}

// Crear un nuevo nodo del árbol
NodoArbol *crearNodoArbol(Libro libro) {
    NodoArbol *nodo = (NodoArbol *)malloc(sizeof(NodoArbol));
    if (nodo == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        return NULL;
    }
    nodo->libro = libro;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    nodo->altura = 1;
    return nodo;
}

// Insertar un libro en el árbol AVL
NodoArbol *insertarEnArbol(NodoArbol *nodo, Libro libro) {
    // Inserción normal de BST
    if (nodo == NULL)
        return crearNodoArbol(libro);

    if (libro.id < nodo->libro.id)
        nodo->izquierda = insertarEnArbol(nodo->izquierda, libro);
    else if (libro.id > nodo->libro.id)
        nodo->derecha = insertarEnArbol(nodo->derecha, libro);
    else
        return nodo; // IDs duplicados no permitidos

    // Actualizar altura
    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

    // Obtener balance
    int balance = obtenerBalance(nodo);

    // Caso Izquierda-Izquierda
    if (balance > 1 && libro.id < nodo->izquierda->libro.id)
        return rotacionDerecha(nodo);

    // Caso Derecha-Derecha
    if (balance < -1 && libro.id > nodo->derecha->libro.id)
        return rotacionIzquierda(nodo);

    // Caso Izquierda-Derecha
    if (balance > 1 && libro.id > nodo->izquierda->libro.id) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    // Caso Derecha-Izquierda
    if (balance < -1 && libro.id < nodo->derecha->libro.id) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

// Buscar un libro por ID en el árbol
NodoArbol *buscarEnArbol(NodoArbol *nodo, int id) {
    if (nodo == NULL || nodo->libro.id == id)
        return nodo;

    if (id < nodo->libro.id)
        return buscarEnArbol(nodo->izquierda, id);

    return buscarEnArbol(nodo->derecha, id);
}

// Recorrido inorden del árbol (para listar libros ordenados)
void recorridoInorden(NodoArbol *nodo) {
    if (nodo != NULL) {
        recorridoInorden(nodo->izquierda);
        printf("ID: %d | Título: %s | Autor: %s | Año: %d | Estado: %s\n",
               nodo->libro.id, nodo->libro.titulo, nodo->libro.autor,
               nodo->libro.anio, nodo->libro.estado);
        recorridoInorden(nodo->derecha);
    }
}

// Encontrar el nodo con el valor mínimo
NodoArbol *nodoMinimo(NodoArbol *nodo) {
    NodoArbol *actual = nodo;
    while (actual->izquierda != NULL)
        actual = actual->izquierda;
    return actual;
}

// Eliminar un libro del árbol AVL
NodoArbol *eliminarDeArbol(NodoArbol *raiz, int id) {
    if (raiz == NULL)
        return raiz;

    if (id < raiz->libro.id)
        raiz->izquierda = eliminarDeArbol(raiz->izquierda, id);
    else if (id > raiz->libro.id)
        raiz->derecha = eliminarDeArbol(raiz->derecha, id);
    else {
        // Nodo con un hijo o sin hijos
        if ((raiz->izquierda == NULL) || (raiz->derecha == NULL)) {
            NodoArbol *temp = raiz->izquierda ? raiz->izquierda : raiz->derecha;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;
            free(temp);
        } else {
            // Nodo con dos hijos
            NodoArbol *temp = nodoMinimo(raiz->derecha);
            raiz->libro = temp->libro;
            raiz->derecha = eliminarDeArbol(raiz->derecha, temp->libro.id);
        }
    }

    if (raiz == NULL)
        return raiz;

    // Actualizar altura
    raiz->altura = 1 + max(obtenerAltura(raiz->izquierda), obtenerAltura(raiz->derecha));

    // Balancear el árbol
    int balance = obtenerBalance(raiz);

    // Caso Izquierda-Izquierda
    if (balance > 1 && obtenerBalance(raiz->izquierda) >= 0)
        return rotacionDerecha(raiz);

    // Caso Izquierda-Derecha
    if (balance > 1 && obtenerBalance(raiz->izquierda) < 0) {
        raiz->izquierda = rotacionIzquierda(raiz->izquierda);
        return rotacionDerecha(raiz);
    }

    // Caso Derecha-Derecha
    if (balance < -1 && obtenerBalance(raiz->derecha) <= 0)
        return rotacionIzquierda(raiz);

    // Caso Derecha-Izquierda
    if (balance < -1 && obtenerBalance(raiz->derecha) > 0) {
        raiz->derecha = rotacionDerecha(raiz->derecha);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

// Liberar memoria del árbol
void liberarArbol(NodoArbol *nodo) {
    if (nodo != NULL) {
        liberarArbol(nodo->izquierda);
        liberarArbol(nodo->derecha);
        free(nodo);
    }
}