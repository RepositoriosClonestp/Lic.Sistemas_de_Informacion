#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

// --- ARCHIVOS DE PERSISTENCIA ---
#define ARCHIVO_LIBROS "libros.dat"
#define ARCHIVO_USUARIOS "usuarios.dat"
#define ARCHIVO_COLAS "colas_espera.dat"


// --- IMPLEMENTACIÓN DE FUNCIONES ---

Cola* crearCola() {
    Cola* q = (Cola*)malloc(sizeof(Cola));
    if (!q) {
        printf("Error de memoria creando cola.\n");
        exit(1);
    }
    q->frente = q->final = NULL;
    return q;
}

int estaVaciaCola(Cola* q) {
    return (q->frente == NULL);
}

void encolar(Cola* q, int idUsuario) {
    NodoCola* temp = (NodoCola*)malloc(sizeof(NodoCola));
    if (!temp) {
        printf("Error de memoria encolando.\n");
        return;
    }
    temp->idUsuario = idUsuario;
    temp->siguiente = NULL;
    
    if (q->final == NULL) {
        q->frente = q->final = temp;
        return;
    }
    q->final->siguiente = temp;
    q->final = temp;
}

int desencolar(Cola* q) {
    if (estaVaciaCola(q)) {
        return -1; // Cola vacía
    }
    NodoCola* temp = q->frente;
    int idUsuario = temp->idUsuario;
    q->frente = q->frente->siguiente;
    
    if (q->frente == NULL) {
        q->final = NULL;
    }
    free(temp);
    return idUsuario;
}

// NUEVA: Contar elementos en la cola
int contarCola(Cola* q) {
    int count = 0;
    NodoCola* temp = q->frente;
    while (temp != NULL) {
        count++;
        temp = temp->siguiente;
    }
    return count;
}

// NUEVA: Verificar si un usuario está en la cola
int estaEnCola(Cola* q, int idUsuario) {
    NodoCola* temp = q->frente;
    while (temp != NULL) {
        if (temp->idUsuario == idUsuario) {
            return 1;
        }
        temp = temp->siguiente;
    }
    return 0;
}


// --- 3. OPERACIONES DE LA LISTA ENLAZADA (Libros del Usuario) ---

void insertarLibroUsuario(NodoLibroUsuario** cabeza, int idLibro) {
    NodoLibroUsuario* nuevo = (NodoLibroUsuario*)malloc(sizeof(NodoLibroUsuario));
    if (!nuevo) {
        printf("Error de memoria (lista usuario).\n");
        return;
    }
    nuevo->idLibro = idLibro;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Retorna 1 si tuvo éxito, 0 si no encontró el libro
int eliminarLibroUsuario(NodoLibroUsuario** cabeza, int idLibro) {
    NodoLibroUsuario* temp = *cabeza;
    NodoLibroUsuario* prev = NULL;
    
    while (temp != NULL && temp->idLibro != idLibro) {
        prev = temp;
        temp = temp->siguiente;
    }
    
    if (temp == NULL) return 0; // No encontrado
    
    if (prev == NULL) { // Es la cabeza
        *cabeza = temp->siguiente;
    } else {
        prev->siguiente = temp->siguiente;
    }
    free(temp);
    return 1; // Encontrado y eliminado
}

void mostrarLibrosUsuario(NodoLibroUsuario* cabeza) {
    NodoLibroUsuario* temp = cabeza;
    if (temp == NULL) {
        printf("  (Ninguno)\n");
        return;
    }
    while (temp != NULL) {
        printf("  - ID Libro: %d\n", temp->idLibro);
        temp = temp->siguiente;
    }
}

int contarLibrosUsuario(NodoLibroUsuario* cabeza) {
    int count = 0;
    NodoLibroUsuario* temp = cabeza;
    while(temp != NULL) {
        count++;
        temp = temp->siguiente;
    }
    return count;
}


// ========================================
// OPERACIONES DE LISTA ENLAZADA (Libros por Usuario)
// ========================================

}


// ========================================
// OPERACIONES DEL ÁRBOL AVL (Catálogo)
// ========================================

// Funciones auxiliares AVL
int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int obtenerAltura(NodoArbol* nodo) {
    if (nodo == NULL) return 0;
    return nodo->altura;
}

int obtenerBalance(NodoArbol* nodo) {
    if (nodo == NULL) return 0;
    return obtenerAltura(nodo->izq) - obtenerAltura(nodo->der);
}

// Rotación simple a la derecha
NodoArbol* rotacionDerecha(NodoArbol* y) {
    NodoArbol* x = y->izq;
    NodoArbol* T2 = x->der;
    
    x->der = y;
    y->izq = T2;
    
    y->altura = maximo(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = maximo(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    
    return x;
}

// Rotación simple a la izquierda
NodoArbol* rotacionIzquierda(NodoArbol* x) {
    NodoArbol* y = x->der;
    NodoArbol* T2 = y->izq;
    
    y->izq = x;
    x->der = T2;
    
    x->altura = maximo(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = maximo(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    
    return y;
}

NodoArbol* crearNodoArbol(Libro libro) {
    NodoArbol* nuevo = (NodoArbol*)malloc(sizeof(NodoArbol));
    if (!nuevo) {
        printf("Error de memoria (nodo arbol).\n");
        exit(1);
    }
    nuevo->libro = libro;
    nuevo->libro.listaEspera = crearCola();
    nuevo->izq = nuevo->der = NULL;
    nuevo->altura = 1;
    return nuevo;
}

// Insertar libro con balanceo AVL - retorna código de error
NodoArbol* insertarLibroAVL(NodoArbol* nodo, Libro libro, int* codigo) {
    // Inserción normal BST
    if (nodo == NULL) {
        *codigo = 0; // Éxito
        return crearNodoArbol(libro);
    }
    
    if (libro.idLibro < nodo->libro.idLibro) {
        nodo->izq = insertarLibroAVL(nodo->izq, libro, codigo);
    } else if (libro.idLibro > nodo->libro.idLibro) {
        nodo->der = insertarLibroAVL(nodo->der, libro, codigo);
    } else {
        *codigo = 1; // ID duplicado
        return nodo;
    }
    
    // Actualizar altura
    nodo->altura = 1 + maximo(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));
    
    // Obtener balance
    int balance = obtenerBalance(nodo);
    
    // Caso Izquierda-Izquierda
    if (balance > 1 && libro.idLibro < nodo->izq->libro.idLibro)
        return rotacionDerecha(nodo);
    
    // Caso Derecha-Derecha
    if (balance < -1 && libro.idLibro > nodo->der->libro.idLibro)
        return rotacionIzquierda(nodo);
    
    // Caso Izquierda-Derecha
    if (balance > 1 && libro.idLibro > nodo->izq->libro.idLibro) {
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }
    
    // Caso Derecha-Izquierda
    if (balance < -1 && libro.idLibro < nodo->der->libro.idLibro) {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }
    
    return nodo;
}

// Buscar libro por ID
NodoArbol* buscarLibro(NodoArbol* raiz, int idLibro) {
    if (raiz == NULL || raiz->libro.idLibro == idLibro) {
        return raiz;
    }
    if (idLibro < raiz->libro.idLibro) {
        return buscarLibro(raiz->izq, idLibro);
    } else {
        return buscarLibro(raiz->der, idLibro);
    }
}

// NUEVA: Encontrar el nodo con valor mínimo (para eliminación)
NodoArbol* nodoMinimo(NodoArbol* nodo) {
    NodoArbol* actual = nodo;
    while (actual && actual->izq != NULL)
        actual = actual->izq;
    return actual;
}

// NUEVA: Eliminar libro del árbol AVL
NodoArbol* eliminarLibroAVL(NodoArbol* raiz, int idLibro, int* codigo) {
    if (raiz == NULL) {
        *codigo = 1; // No encontrado
        return raiz;
    }
    
    if (idLibro < raiz->libro.idLibro) {
        raiz->izq = eliminarLibroAVL(raiz->izq, idLibro, codigo);
    } else if (idLibro > raiz->libro.idLibro) {
        raiz->der = eliminarLibroAVL(raiz->der, idLibro, codigo);
    } else {
        // Nodo encontrado
        *codigo = 0; // Éxito
        
        // Nodo con un hijo o sin hijos
        if ((raiz->izq == NULL) || (raiz->der == NULL)) {
            NodoArbol* temp = raiz->izq ? raiz->izq : raiz->der;
            
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                // Copiar el contenido del hijo no vacío
                freeCola(raiz->libro.listaEspera); // Liberar cola del nodo eliminado
                *raiz = *temp;
            }
            free(temp);
        } else {
            // Nodo con dos hijos: obtener el sucesor inorden
            NodoArbol* temp = nodoMinimo(raiz->der);
            
            // Liberar la cola del nodo actual antes de sobrescribir
            freeCola(raiz->libro.listaEspera);
            
            // Copiar el contenido del sucesor
            raiz->libro = temp->libro;
            raiz->libro.listaEspera = crearCola(); // Nueva cola
            
            // Eliminar el sucesor
            raiz->der = eliminarLibroAVL(raiz->der, temp->libro.idLibro, codigo);
        }
    }
    
    if (raiz == NULL) return raiz;
    
    // Actualizar altura
    raiz->altura = 1 + maximo(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));
    
    // Balancear el árbol
    int balance = obtenerBalance(raiz);
    
    // Caso Izquierda-Izquierda
    if (balance > 1 && obtenerBalance(raiz->izq) >= 0)
        return rotacionDerecha(raiz);
    
    // Caso Izquierda-Derecha
    if (balance > 1 && obtenerBalance(raiz->izq) < 0) {
        raiz->izq = rotacionIzquierda(raiz->izq);
        return rotacionDerecha(raiz);
    }
    
    // Caso Derecha-Derecha
    if (balance < -1 && obtenerBalance(raiz->der) <= 0)
        return rotacionIzquierda(raiz);
    
    // Caso Derecha-Izquierda
    if (balance < -1 && obtenerBalance(raiz->der) > 0) {
        raiz->der = rotacionDerecha(raiz->der);
        return rotacionIzquierda(raiz);
    }
    
    return raiz;
}

// Recorrido Inorden para mostrar catálogo
void mostrarCatalogo(NodoArbol* raiz) {
    if (raiz != NULL) {
        mostrarCatalogo(raiz->izq);
        printf("----------------------------------------\n");
        printf("ID Libro: %d\n", raiz->libro.idLibro);
        printf("Titulo:   %s\n", raiz->libro.titulo);
        printf("Autor:    %s\n", raiz->libro.autor);
        printf("Estado:   %s\n", raiz->libro.disponible ? "Disponible" : "Prestado");
        int enEspera = contarCola(raiz->libro.listaEspera);
        if (enEspera > 0) {
            printf("En lista de espera: %d usuario(s)\n", enEspera);
        }
        mostrarCatalogo(raiz->der);
    }
}

// NUEVA: Contar total de libros
int contarLibros(NodoArbol* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarLibros(raiz->izq) + contarLibros(raiz->der);
}

// NUEVA: Actualizar información de un libro
int actualizarLibro(NodoArbol* raiz, int idLibro, const char* nuevoTitulo, const char* nuevoAutor) {
    NodoArbol* nodo = buscarLibro(raiz, idLibro);
    if (nodo == NULL) {
        return 1; // No encontrado
    }
    
    if (nuevoTitulo != NULL && strlen(nuevoTitulo) > 0) {
        strncpy(nodo->libro.titulo, nuevoTitulo, MAX_TITULO - 1);
        nodo->libro.titulo[MAX_TITULO - 1] = '\0';
    }
    
    if (nuevoAutor != NULL && strlen(nuevoAutor) > 0) {
        strncpy(nodo->libro.autor, nuevoAutor, MAX_AUTOR - 1);
        nodo->libro.autor[MAX_AUTOR - 1] = '\0';
    }
    
    return 0; // Éxito
}


// ========================================
// OPERACIONES DE LISTA DE USUARIOS
// ========================================

void agregarUsuarioLista(NodoUsuario** cabeza, Usuario usuario) {
    NodoUsuario* nuevo = (NodoUsuario*)malloc(sizeof(NodoUsuario));
    if (!nuevo) {
        printf("Error de memoria (lista usuarios).\n");
        return;
    }
    nuevo->usuario = usuario;
    nuevo->usuario.librosPrestados = NULL;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

NodoUsuario* buscarUsuario(NodoUsuario* cabeza, int idUsuario) {
    NodoUsuario* temp = cabeza;
    while (temp != NULL) {
        if (temp->usuario.idUsuario == idUsuario) {
            return temp;
        }
        temp = temp->siguiente;
    }
    return NULL;
}

// NUEVA: Eliminar usuario de la lista
int eliminarUsuario(NodoUsuario** cabeza, int idUsuario) {
    NodoUsuario* temp = *cabeza;
    NodoUsuario* prev = NULL;
    
    while (temp != NULL && temp->usuario.idUsuario != idUsuario) {
        prev = temp;
        temp = temp->siguiente;
    }
    
    if (temp == NULL) return 1; // No encontrado
    
    // Verificar si tiene libros prestados
    if (temp->usuario.librosPrestados != NULL) {
        return 2; // Tiene libros prestados, no se puede eliminar
    }
    
    if (prev == NULL) {
        *cabeza = temp->siguiente;
    } else {
        prev->siguiente = temp->siguiente;
    }
    
    free(temp);
    return 0; // Éxito
}

void mostrarUsuarios(NodoUsuario* cabeza) {
    NodoUsuario* temp = cabeza;
    if (temp == NULL) {
        printf("No hay usuarios registrados.\n");
        return;
    }
    while (temp != NULL) {
        printf("----------------------------------------\n");
        printf("ID Usuario: %d\n", temp->usuario.idUsuario);
        printf("Nombre:     %s\n", temp->usuario.nombre);
        int numPrestados = contarLibrosUsuario(temp->usuario.librosPrestados);
        printf("Libros Prestados (%d/%d):\n", numPrestados, MAX_PRESTAMOS_POR_USUARIO);
        mostrarLibrosUsuario(temp->usuario.librosPrestados);
        temp = temp->siguiente;
    }
}

// NUEVA: Contar total de usuarios
int contarUsuarios(NodoUsuario* cabeza) {
    int count = 0;
    NodoUsuario* temp = cabeza;
    while (temp != NULL) {
        count++;
        temp = temp->siguiente;
    }
    return count;
}


// ========================================
// LÓGICA PRINCIPAL DE BIBLIOTECA
// ========================================

// MEJORADA: Préstamo con límite de libros
int prestarLibro(NodoArbol* raizArbol, NodoUsuario* listaUsuarios, int idLibro, int idUsuario) {
    NodoArbol* nodoLibro = buscarLibro(raizArbol, idLibro);
    if (nodoLibro == NULL) {
        printf("Error: Libro con ID %d no encontrado.\n", idLibro);
        return 1;
    }
    
    NodoUsuario* nodoUsuario = buscarUsuario(listaUsuarios, idUsuario);
    if (nodoUsuario == NULL) {
        printf("Error: Usuario con ID %d no encontrado.\n", idUsuario);
        return 2;
    }
    
    // MEJORA: Verificar límite de préstamos
    int numPrestados = contarLibrosUsuario(nodoUsuario->usuario.librosPrestados);
    if (numPrestados >= MAX_PRESTAMOS_POR_USUARIO) {
        printf("Error: El usuario '%s' ya tiene %d libros prestados (limite alcanzado).\n", 
               nodoUsuario->usuario.nombre, MAX_PRESTAMOS_POR_USUARIO);
        return 3;
    }
    
    // Verificar si el usuario ya está en lista de espera
    if (estaEnCola(nodoLibro->libro.listaEspera, idUsuario)) {
        printf("Info: El usuario '%s' ya esta en la lista de espera de este libro.\n",
               nodoUsuario->usuario.nombre);
        return 4;
    }
    
    if (nodoLibro->libro.disponible) {
        // El libro está disponible
        nodoLibro->libro.disponible = 0;
        insertarLibroUsuario(&(nodoUsuario->usuario.librosPrestados), idLibro);
        printf("Exito: Libro '%s' prestado al usuario '%s'.\n", 
               nodoLibro->libro.titulo, nodoUsuario->usuario.nombre);
        return 0;
    } else {
        // El libro está prestado, añadir a lista de espera
        encolar(nodoLibro->libro.listaEspera, idUsuario);
        printf("Info: El libro '%s' esta prestado. Se ha anadido al usuario '%s' a la lista de espera.\n", 
               nodoLibro->libro.titulo, nodoUsuario->usuario.nombre);
        return 0;
    }
}

int devolverLibro(NodoArbol* raizArbol, NodoUsuario* listaUsuarios, int idLibro, int idUsuario) {
    NodoArbol* nodoLibro = buscarLibro(raizArbol, idLibro);
    if (nodoLibro == NULL) {
        printf("Error: Libro con ID %d no encontrado.\n", idLibro);
        return 1;
    }
    
    NodoUsuario* nodoUsuarioDevuelve = buscarUsuario(listaUsuarios, idUsuario);
    if (nodoUsuarioDevuelve == NULL) {
        printf("Error: Usuario con ID %d no encontrado.\n", idUsuario);
        return 2;
    }

    // Intentar quitar el libro de la lista del usuario
    if (!eliminarLibroUsuario(&(nodoUsuarioDevuelve->usuario.librosPrestados), idLibro)) {
        printf("Error: El usuario %s no tiene prestado el libro con ID %d.\n", 
               nodoUsuarioDevuelve->usuario.nombre, idLibro);
        return 3;
    }
    
    // Revisar la lista de espera del libro
    if (!estaVaciaCola(nodoLibro->libro.listaEspera)) {
        // Hay alguien esperando
        int idSiguienteUsuario = desencolar(nodoLibro->libro.listaEspera);
        NodoUsuario* nodoSiguienteUsuario = buscarUsuario(listaUsuarios, idSiguienteUsuario);
        
        if (nodoSiguienteUsuario != NULL) {
            // Verificar límite del siguiente usuario
            int numPrestados = contarLibrosUsuario(nodoSiguienteUsuario->usuario.librosPrestados);
            if (numPrestados >= MAX_PRESTAMOS_POR_USUARIO) {
                printf("Info: El siguiente usuario en espera (%s) alcanzo el limite de prestamos.\n",
                       nodoSiguienteUsuario->usuario.nombre);
                printf("      El libro '%s' queda disponible.\n", nodoLibro->libro.titulo);
                nodoLibro->libro.disponible = 1;
            } else {
                // Asignar el libro al siguiente usuario
                insertarLibroUsuario(&(nodoSiguienteUsuario->usuario.librosPrestados), idLibro);
                printf("Exito: Libro devuelto por %s y asignado automaticamente a %s (ID: %d) de la lista de espera.\n",
                       nodoUsuarioDevuelve->usuario.nombre, nodoSiguienteUsuario->usuario.nombre, idSiguienteUsuario);
            }
        } else {
            printf("Advertencia: El siguiente usuario en espera (ID %d) no fue encontrado. El libro queda disponible.\n", 
                   idSiguienteUsuario);
            nodoLibro->libro.disponible = 1;
        }
    } else {
        // Nadie está esperando, el libro queda disponible
        nodoLibro->libro.disponible = 1;
        printf("Exito: Libro '%s' devuelto por %s. El libro esta ahora disponible.\n", 
               nodoLibro->libro.titulo, nodoUsuarioDevuelve->usuario.nombre);
    }
    
    return 0;
}


// --- PERSISTENCIA DE DATOS ---

// --- Guardado de Libros (recorrido preorden) ---
void guardarLibrosRecursivo(NodoArbol* raiz, FILE* f) {
    if (raiz != NULL) {
        fwrite(&(raiz->libro), sizeof(Libro), 1, f);
        guardarLibrosRecursivo(raiz->izq, f);
        guardarLibrosRecursivo(raiz->der, f);
    }
}

void guardarLibros(NodoArbol* raiz) {
    FILE* f = fopen(ARCHIVO_LIBROS, "wb");
    if (f == NULL) {
        printf("Error: No se pudo abrir %s para escritura.\n", ARCHIVO_LIBROS);
        return;
    }
    guardarLibrosRecursivo(raiz, f);
    fclose(f);
    printf("Catalogo de libros guardado en %s.\n", ARCHIVO_LIBROS);
}

// NUEVA: Guardar colas de espera
void guardarColasRecursivo(NodoArbol* raiz, FILE* f) {
    if (raiz != NULL) {
        guardarColasRecursivo(raiz->izq, f);
        
        // Escribir ID del libro
        fwrite(&(raiz->libro.idLibro), sizeof(int), 1, f);
        
        // Contar y escribir cuántos usuarios en espera
        int numEnEspera = contarCola(raiz->libro.listaEspera);
        fwrite(&numEnEspera, sizeof(int), 1, f);
        
        // Escribir los IDs de usuarios en espera
        NodoCola* temp = raiz->libro.listaEspera->frente;
        while (temp != NULL) {
            fwrite(&(temp->idUsuario), sizeof(int), 1, f);
            temp = temp->siguiente;
        }
        
        guardarColasRecursivo(raiz->der, f);
    }
}

void guardarColas(NodoArbol* raiz) {
    FILE* f = fopen(ARCHIVO_COLAS, "wb");
    if (f == NULL) {
        printf("Advertencia: No se pudo abrir %s para escritura.\n", ARCHIVO_COLAS);
        return;
    }
    
    // Contar total de libros con cola
    int totalLibros = contarLibros(raiz);
    fwrite(&totalLibros, sizeof(int), 1, f);
    
    guardarColasRecursivo(raiz, f);
    fclose(f);
    printf("Listas de espera guardadas en %s.\n", ARCHIVO_COLAS);
}

// --- Carga de Libros ---
void cargarLibros(NodoArbol** raiz) {
    FILE* f = fopen(ARCHIVO_LIBROS, "rb");
    if (f == NULL) {
        printf("Info: No se encontro %s. Se iniciara con un catalogo vacio.\n", ARCHIVO_LIBROS);
        return;
    }
    
    Libro libroLeido;
    int codigo;
    while (fread(&libroLeido, sizeof(Libro), 1, f) == 1) {
        libroLeido.listaEspera = crearCola();
        *raiz = insertarLibroAVL(*raiz, libroLeido, &codigo);
    }
    
    fclose(f);
    printf("Catalogo de libros cargado desde %s.\n", ARCHIVO_LIBROS);
}

// NUEVA: Cargar colas de espera
void cargarColas(NodoArbol* raiz) {
    FILE* f = fopen(ARCHIVO_COLAS, "rb");
    if (f == NULL) {
        printf("Info: No se encontro %s. Las listas de espera estaran vacias.\n", ARCHIVO_COLAS);
        return;
    }
    
    int totalLibros;
    if (fread(&totalLibros, sizeof(int), 1, f) != 1) {
        fclose(f);
        return;
    }
    
    for (int i = 0; i < totalLibros; i++) {
        int idLibro;
        int numEnEspera;
        
        if (fread(&idLibro, sizeof(int), 1, f) != 1) break;
        if (fread(&numEnEspera, sizeof(int), 1, f) != 1) break;
        
        NodoArbol* nodoLibro = buscarLibro(raiz, idLibro);
        if (nodoLibro != NULL) {
            for (int j = 0; j < numEnEspera; j++) {
                int idUsuario;
                if (fread(&idUsuario, sizeof(int), 1, f) != 1) break;
                encolar(nodoLibro->libro.listaEspera, idUsuario);
            }
        } else {
            // Libro no encontrado, saltar los IDs
            for (int j = 0; j < numEnEspera; j++) {
                int dummy;
                fread(&dummy, sizeof(int), 1, f);
            }
        }
    }
    
    fclose(f);
    printf("Listas de espera cargadas desde %s.\n", ARCHIVO_COLAS);
}

// --- Guardado de Usuarios ---
void guardarUsuarios(NodoUsuario* cabeza) {
    FILE* f = fopen(ARCHIVO_USUARIOS, "wb");
    if (f == NULL) {
        printf("Error: No se pudo abrir %s para escritura.\n", ARCHIVO_USUARIOS);
        return;
    }
    
    NodoUsuario* temp = cabeza;
    while (temp != NULL) {
        fwrite(&(temp->usuario), sizeof(Usuario), 1, f);
        
        int numLibros = contarLibrosUsuario(temp->usuario.librosPrestados);
        fwrite(&numLibros, sizeof(int), 1, f);
        
        NodoLibroUsuario* libroTemp = temp->usuario.librosPrestados;
        while(libroTemp != NULL) {
            fwrite(&(libroTemp->idLibro), sizeof(int), 1, f);
            libroTemp = libroTemp->siguiente;
        }
        
        temp = temp->siguiente;
    }
    fclose(f);
    printf("Lista de usuarios guardada en %s.\n", ARCHIVO_USUARIOS);
}

// --- Carga de Usuarios ---
void cargarUsuarios(NodoUsuario** cabeza) {
    FILE* f = fopen(ARCHIVO_USUARIOS, "rb");
    if (f == NULL) {
        printf("Info: No se encontro %s. Se iniciara sin usuarios.\n", ARCHIVO_USUARIOS);
        return;
    }
    
    Usuario usuarioLeido;
    while (fread(&usuarioLeido, sizeof(Usuario), 1, f) == 1) {
        usuarioLeido.librosPrestados = NULL;
        
        int numLibros;
        fread(&numLibros, sizeof(int), 1, f);
        
        for (int i = 0; i < numLibros; i++) {
            int idLibroLeido;
            fread(&idLibroLeido, sizeof(int), 1, f);
            insertarLibroUsuario(&(usuarioLeido.librosPrestados), idLibroLeido);
        }
        
        agregarUsuarioLista(cabeza, usuarioLeido);
    }
    
    fclose(f);
    printf("Lista de usuarios cargada desde %s.\n", ARCHIVO_USUARIOS);
}


// --- LIBERACIÓN DE MEMORIA ---

void freeListaLibrosUsuario(NodoLibroUsuario* cabeza) {
    NodoLibroUsuario *temp;
    while(cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

void freeCola(Cola* q) {
    if (q == NULL) return;
    NodoCola* temp;
    while(q->frente != NULL) {
        temp = q->frente;
        q->frente = q->frente->siguiente;
        free(temp);
    }
    free(q);
}

void freeArbol(NodoArbol* raiz) {
    if (raiz != NULL) {
        freeArbol(raiz->izq);
        freeArbol(raiz->der);
        freeCola(raiz->libro.listaEspera);
        free(raiz);
    }
}

void freeUsuarios(NodoUsuario* cabeza) {
    NodoUsuario* temp;
    while(cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        freeListaLibrosUsuario(temp->usuario.librosPrestados);
        free(temp);
    }
}


// --- FUNCIONES AUXILIARES ---

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void leerCadena(char* buffer, int maxLen, const char* prompt) {
    printf("%s", prompt);
    if (fgets(buffer, maxLen, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

// Función auxiliar para contar estado de libros
void contarEstadoLibrosRecursivo(NodoArbol* nodo, int* disponibles, int* prestados) {
    if (nodo != NULL) {
        contarEstadoLibrosRecursivo(nodo->izq, disponibles, prestados);
        if (nodo->libro.disponible) {
            (*disponibles)++;
        } else {
            (*prestados)++;
        }
        contarEstadoLibrosRecursivo(nodo->der, disponibles, prestados);
    }
}

// NUEVA: Mostrar estadísticas del sistema
void mostrarEstadisticas(NodoArbol* catalogoLibros, NodoUsuario* listaUsuarios) {
    printf("\n========================================\n");
    printf("      ESTADISTICAS DEL SISTEMA\n");
    printf("========================================\n");
    
    int totalLibros = contarLibros(catalogoLibros);
    int totalUsuarios = contarUsuarios(listaUsuarios);
    
    printf("Total de libros en catalogo: %d\n", totalLibros);
    printf("Total de usuarios registrados: %d\n", totalUsuarios);
    
    // Contar libros prestados y disponibles
    int librosDisponibles = 0;
    int librosPrestados = 0;
    
    contarEstadoLibrosRecursivo(catalogoLibros, &librosDisponibles, &librosPrestados);
    
    printf("Libros disponibles: %d\n", librosDisponibles);
    printf("Libros prestados: %d\n", librosPrestados);
    printf("Limite de prestamos por usuario: %d\n", MAX_PRESTAMOS_POR_USUARIO);
    printf("========================================\n");
}


// --- FUNCIÓN PRINCIPAL (MAIN) ---

int main() {
    NodoArbol* catalogoLibros = NULL;
    NodoUsuario* listaUsuarios = NULL;
    
    printf("===========================================\n");
    printf("  SISTEMA DE GESTION DE BIBLIOTECA v2.0\n");
    printf("===========================================\n\n");
    
    // Cargar datos al iniciar
    cargarLibros(&catalogoLibros);
    cargarUsuarios(&listaUsuarios);
    cargarColas(catalogoLibros);
    
    int opcion;
    int idLibro;
    int idUsuario;
    
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1.  Agregar nuevo libro al catalogo\n");
        printf("2.  Buscar libro por ID\n");
        printf("3.  Actualizar informacion de libro\n");
        printf("4.  Eliminar libro del catalogo\n");
        printf("5.  Mostrar catalogo completo\n");
        printf("6.  Agregar nuevo usuario\n");
        printf("7.  Eliminar usuario\n");
        printf("8.  Mostrar lista de usuarios\n");
        printf("9.  Prestar libro\n");
        printf("10. Devolver libro\n");
        printf("11. Mostrar estadisticas\n");
        printf("12. Guardar y Salir\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            limpiarBuffer();
            opcion = 0;
        }
        limpiarBuffer();
        
        switch (opcion) {
            case 1: {
                Libro nuevoLibro;
                nuevoLibro.disponible = 1;
                
                printf("Ingrese ID del Libro: ");
                scanf("%d", &nuevoLibro.idLibro);
                limpiarBuffer();
                
                leerCadena(nuevoLibro.titulo, MAX_TITULO, "Ingrese Titulo: ");
                leerCadena(nuevoLibro.autor, MAX_AUTOR, "Ingrese Autor: ");
                
                int codigo;
                catalogoLibros = insertarLibroAVL(catalogoLibros, nuevoLibro, &codigo);
                
                if (codigo == 0) {
                    printf("Exito: Libro agregado al catalogo.\n");
                } else {
                    printf("Error: Ya existe un libro con ID %d.\n", nuevoLibro.idLibro);
                }
                break;
            }
            
            case 2: {
                printf("Ingrese ID del libro a buscar: ");
                scanf("%d", &idLibro);
                limpiarBuffer();
                
                NodoArbol* encontrado = buscarLibro(catalogoLibros, idLibro);
                if (encontrado != NULL) {
                    printf("\n--- LIBRO ENCONTRADO ---\n");
                    printf("ID Libro: %d\n", encontrado->libro.idLibro);
                    printf("Titulo:   %s\n", encontrado->libro.titulo);
                    printf("Autor:    %s\n", encontrado->libro.autor);
                    printf("Estado:   %s\n", encontrado->libro.disponible ? "Disponible" : "Prestado");
                    int enEspera = contarCola(encontrado->libro.listaEspera);
                    if (enEspera > 0) {
                        printf("Usuarios en espera: %d\n", enEspera);
                    }
                } else {
                    printf("No se encontro un libro con ID %d.\n", idLibro);
                }
                break;
            }
            
            case 3: {
                printf("Ingrese ID del libro a actualizar: ");
                scanf("%d", &idLibro);
                limpiarBuffer();
                
                char nuevoTitulo[MAX_TITULO];
                char nuevoAutor[MAX_AUTOR];
                
                printf("Nuevo titulo (Enter para mantener): ");
                fgets(nuevoTitulo, MAX_TITULO, stdin);
                nuevoTitulo[strcspn(nuevoTitulo, "\n")] = '\0';
                
                printf("Nuevo autor (Enter para mantener): ");
                fgets(nuevoAutor, MAX_AUTOR, stdin);
                nuevoAutor[strcspn(nuevoAutor, "\n")] = '\0';
                
                int resultado = actualizarLibro(catalogoLibros, idLibro, 
                    strlen(nuevoTitulo) > 0 ? nuevoTitulo : NULL,
                    strlen(nuevoAutor) > 0 ? nuevoAutor : NULL);
                
                if (resultado == 0) {
                    printf("Exito: Libro actualizado.\n");
                } else {
                    printf("Error: No se encontro el libro con ID %d.\n", idLibro);
                }
                break;
            }
            
            case 4: {
                printf("Ingrese ID del libro a eliminar: ");
                scanf("%d", &idLibro);
                limpiarBuffer();
                
                // Verificar si el libro existe y su estado
                NodoArbol* libro = buscarLibro(catalogoLibros, idLibro);
                if (libro == NULL) {
                    printf("Error: No existe un libro con ID %d.\n", idLibro);
                    break;
                }
                
                if (!libro->libro.disponible) {
                    printf("Error: El libro '%s' esta prestado. No se puede eliminar.\n", 
                           libro->libro.titulo);
                    break;
                }
                
                if (!estaVaciaCola(libro->libro.listaEspera)) {
                    printf("Error: El libro '%s' tiene usuarios en lista de espera. No se puede eliminar.\n",
                           libro->libro.titulo);
                    break;
                }
                
                printf("¿Esta seguro de eliminar '%s'? (S/N): ", libro->libro.titulo);
                char confirmacion;
                scanf("%c", &confirmacion);
                limpiarBuffer();
                
                if (confirmacion == 'S' || confirmacion == 's') {
                    int codigo;
                    catalogoLibros = eliminarLibroAVL(catalogoLibros, idLibro, &codigo);
                    if (codigo == 0) {
                        printf("Exito: Libro eliminado del catalogo.\n");
                    }
                } else {
                    printf("Operacion cancelada.\n");
                }
                break;
            }
            
            case 5:
                printf("\n--- CATALOGO COMPLETO DE LIBROS ---\n");
                if (catalogoLibros == NULL) {
                    printf("(Catalogo vacio)\n");
                } else {
                    mostrarCatalogo(catalogoLibros);
                    printf("----------------------------------------\n");
                    printf("Total de libros: %d\n", contarLibros(catalogoLibros));
                }
                break;
            
            case 6: {
                Usuario nuevoUsuario;
                printf("Ingrese ID del nuevo usuario (numerico): ");
                scanf("%d", &nuevoUsuario.idUsuario);
                limpiarBuffer();
                
                if (buscarUsuario(listaUsuarios, nuevoUsuario.idUsuario) != NULL) {
                    printf("Error: Ya existe un usuario con ID %d.\n", nuevoUsuario.idUsuario);
                    break;
                }
                
                leerCadena(nuevoUsuario.nombre, MAX_NOMBRE_USUARIO, "Ingrese Nombre del usuario: ");
                
                agregarUsuarioLista(&listaUsuarios, nuevoUsuario);
                printf("Exito: Usuario agregado al sistema.\n");
                break;
            }
            
            case 7: {
                printf("Ingrese ID del usuario a eliminar: ");
                scanf("%d", &idUsuario);
                limpiarBuffer();
                
                NodoUsuario* usuario = buscarUsuario(listaUsuarios, idUsuario);
                if (usuario == NULL) {
                    printf("Error: No existe un usuario con ID %d.\n", idUsuario);
                    break;
                }
                
                int numPrestados = contarLibrosUsuario(usuario->usuario.librosPrestados);
                if (numPrestados > 0) {
                    printf("Error: El usuario '%s' tiene %d libro(s) prestado(s). Debe devolverlos primero.\n",
                           usuario->usuario.nombre, numPrestados);
                    break;
                }
                
                printf("¿Esta seguro de eliminar al usuario '%s'? (S/N): ", usuario->usuario.nombre);
                char confirmacion;
                scanf("%c", &confirmacion);
                limpiarBuffer();
                
                if (confirmacion == 'S' || confirmacion == 's') {
                    int resultado = eliminarUsuario(&listaUsuarios, idUsuario);
                    if (resultado == 0) {
                        printf("Exito: Usuario eliminado del sistema.\n");
                    }
                } else {
                    printf("Operacion cancelada.\n");
                }
                break;
            }
            
            case 8:
                printf("\n--- LISTA DE USUARIOS ---\n");
                mostrarUsuarios(listaUsuarios);
                printf("----------------------------------------\n");
                printf("Total de usuarios: %d\n", contarUsuarios(listaUsuarios));
                break;
            
            case 9:
                printf("Ingrese ID del usuario: ");
                scanf("%d", &idUsuario);
                printf("Ingrese ID del libro a prestar: ");
                scanf("%d", &idLibro);
                limpiarBuffer();
                prestarLibro(catalogoLibros, listaUsuarios, idLibro, idUsuario);
                break;
            
            case 10:
                printf("Ingrese ID del usuario que devuelve: ");
                scanf("%d", &idUsuario);
                printf("Ingrese ID del libro a devolver: ");
                scanf("%d", &idLibro);
                limpiarBuffer();
                devolverLibro(catalogoLibros, listaUsuarios, idLibro, idUsuario);
                break;
            
            case 11:
                mostrarEstadisticas(catalogoLibros, listaUsuarios);
                break;
            
            case 12:
                printf("Guardando datos...\n");
                guardarLibros(catalogoLibros);
                guardarUsuarios(listaUsuarios);
                guardarColas(catalogoLibros);
                printf("\n¡Gracias por usar el Sistema de Gestion de Biblioteca!\n");
                printf("Saliendo...\n");
                break;
            
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
        
    } while (opcion != 12);
    
    // Liberar toda la memoria
    freeArbol(catalogoLibros);
    freeUsuarios(listaUsuarios);
    
    return 0;
}
