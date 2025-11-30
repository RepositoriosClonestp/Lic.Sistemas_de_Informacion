#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// --ESTRUCTURAS--

// Lista de libros (ID) que tiene cada usuario

typedef struct nodoLibro {
    int idLibro;
    struct nodoLibro* siguiente;
} tNodoLibro;

// Estructura del usuario

typedef struct {
    int idUsuario;
    char nombre[MAX];
    tNodoLibro* librosPrestados; // Lista enlazada de libros que tiene el suario
} tUsuario;

// Lista general de usuarios

typedef struct nodoUsuario {
    tUsuario usuario; //datos
    struct nodoUsuario* siguiente;
} tNodoUsuario;

// Estructura que tiene el libro

typedef struct {
    int idLibro;
    char titulo[MAX];
    char autor[MAX];
    int disponible; // 1 = Disponible, 0 = Prestado
} tLibro;

// Arbol Binario para mostrar libros (catalogo)

typedef struct nodoArbol {
    tLibro libro;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;
} tNodoArbol;

FILE* archivoPuntero;

// --PROTOTIPOS DE FUNCIONES--

//Libros prestados

void agregarLibroPrestado(tUsuario*, int);
int quitarLibroPrestado(tUsuario*, int);

//Catalogo

tNodoArbol* insertarLibro(tNodoArbol*, tLibro);
tNodoArbol* buscarLibro(tNodoArbol*, int);
void mostrarCatalogo(tNodoArbol*);

//Funciones de usuarios

tNodoUsuario* insertarUsuario(tNodoUsuario*, tUsuario);
tNodoUsuario* buscarUsuario(tNodoUsuario*, int);
void mostrarUsuarios(tNodoUsuario*);

//Logica de negocio

void prestarLibro(tNodoArbol*, tNodoUsuario*, int, int);
void devolverLibro(tNodoArbol*, tNodoUsuario*, int, int);

//Persistencia

void guardarTodo(tNodoArbol*, tNodoUsuario*);
void cargarTodo(tNodoArbol**, tNodoUsuario**);

// --IMPLEMENTACION DE FUNCIONES--

//Libros prestafos

void agregarLibroPrestado(tUsuario* usuario, int idLibro) { //agrega a un usuario el libro prestado(mete al inicio)
    tNodoLibro* nuevoNodo = (tNodoLibro*)malloc(sizeof(tNodoLibro));
    nuevoNodo->idLibro = idLibro;
    nuevoNodo->siguiente = usuario->librosPrestados; //apunta a donde apuntaba antes usuario
    usuario->librosPrestados = nuevoNodo; //nueva cabeza
}

int quitarLibroPrestado(tUsuario* usuario, int idLibro) {
    tNodoLibro* actual = usuario->librosPrestados; //primer libro(usuario->librosPrestados;)
    tNodoLibro* anterior = NULL;

    while (actual != NULL && actual->idLibro != idLibro) { //avanzan los vagones
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL){
        return 0; // No encontrado
    } 

    if (anterior == NULL){
        usuario->librosPrestados = actual->siguiente; // pasa al segundo nodo
    } else {
        anterior->siguiente = actual->siguiente; //hace puente
    } 

    free(actual);
    return 1;
}

//Catalogo

tNodoArbol* insertarLibro(tNodoArbol* raiz, tLibro pLibro) {
    if (raiz == NULL) {
        tNodoArbol* nuevoNodo = (tNodoArbol*)malloc(sizeof(tNodoArbol));
        nuevoNodo->libro = pLibro;
        nuevoNodo->izquierda = NULL;
        nuevoNodo->derecha = NULL;
        return nuevoNodo;
    }
    if (pLibro.idLibro < raiz->libro.idLibro){
        raiz->izquierda = insertarLibro(raiz->izquierda, pLibro);
    }else if (pLibro.idLibro > raiz->libro.idLibro){
        raiz->derecha = insertarLibro(raiz->derecha, pLibro);
    }
    return raiz;
}

tNodoArbol* buscarLibro(tNodoArbol* raiz, int id) {
    if (raiz == NULL || raiz->libro.idLibro == id){
        return raiz;
    }    
    if (id < raiz->libro.idLibro){
        return buscarLibro(raiz->izquierda, id);
    }else {
        return buscarLibro(raiz->derecha, id);
    }
}

void mostrarCatalogo(tNodoArbol* raiz) {
    if (raiz != NULL) {
        mostrarCatalogo(raiz->izquierda);
        printf("ID: %-4d | Titulo: %-20s | Estado: %s\n", 
               raiz->libro.idLibro, 
               raiz->libro.titulo, 
               raiz->libro.disponible ? "DISPONIBLE" : "PRESTADO");
        mostrarCatalogo(raiz->derecha);
    }
}

//Funciones de usuarios

tNodoUsuario* insertarUsuario(tNodoUsuario* cabeza, tUsuario pUsuario) {
    tNodoUsuario* nuevoNodo = (tNodoUsuario*)malloc(sizeof(tNodoUsuario));
    nuevoNodo->usuario = pUsuario;
    nuevoNodo->usuario.librosPrestados = NULL; // Empieza sin libros
    nuevoNodo->siguiente = cabeza;//cabeza es primer usuarioi
    return nuevoNodo;
}

tNodoUsuario* buscarUsuario(tNodoUsuario* cabeza, int id) {
    while (cabeza != NULL) {
        if (cabeza->usuario.idUsuario == id){
            return cabeza;
        }
        cabeza = cabeza->siguiente;
    }
    return NULL;
}

void mostrarUsuarios(tNodoUsuario* cabeza) {
    if (cabeza == NULL){
        printf("(No hay usuarios registrados)\n");
    }
    while (cabeza != NULL) {
        printf("ID: %d | Nombre: %s\n", cabeza->usuario.idUsuario, cabeza->usuario.nombre);
        printf("   -> Libros Prestados (IDs): ");
        
        tNodoLibro* aux = cabeza->usuario.librosPrestados;
        if (aux == NULL){
            printf("Ninguno");
        }
        while(aux != NULL) {
            printf("[%d] ", aux->idLibro);
            aux = aux->siguiente;
        }
        printf("\n--------------------------------\n");
        cabeza = cabeza->siguiente;
    }
}

//Logica de negocio

void prestarLibro(tNodoArbol* raizLibros, tNodoUsuario* cabezaUsuarios, int idLibro, int idUsuario) {
    tNodoArbol* nodoLibro = buscarLibro(raizLibros, idLibro);
    tNodoUsuario* nodoUsuario = buscarUsuario(cabezaUsuarios, idUsuario);

    if (nodoLibro == NULL) { 
        printf("ERROR: El libro no existe.\n");
        return;
    }
    if (nodoUsuario == NULL) { 
        printf("ERROR: El usuario no existe.\n");
        return;
    }

    if (nodoLibro->libro.disponible == 1) {
        // Esta disponible se presta
        nodoLibro->libro.disponible = 0;
        agregarLibroPrestado(&(nodoUsuario->usuario), idLibro);
        printf("Libro '%s' prestado a %s.\n", nodoLibro->libro.titulo, nodoUsuario->usuario.nombre);
    } else {
        // No esta disponible
        printf("El libro '%s' ya esta prestado.\n", nodoLibro->libro.titulo);
    }
}

void devolverLibro(tNodoArbol* raizLibros, tNodoUsuario* cabezaUsuarios, int idLibro, int idUsuario) {
    tNodoArbol* nodoLibro = buscarLibro(raizLibros, idLibro);
    tNodoUsuario* nodoUsuario = buscarUsuario(cabezaUsuarios, idUsuario);

    if (!nodoLibro || !nodoUsuario) {
        printf("ERROR: Datos incorrectos.\n"); 
        return;
    }

    if (quitarLibroPrestado(&(nodoUsuario->usuario), idLibro)) {
        nodoLibro->libro.disponible = 1;
        printf("Libro '%s' devuelto correctamente.\n", nodoLibro->libro.titulo);
    } else {
        printf("ERROR: El usuario %s no tiene prestado el libro %d.\n", nodoUsuario->usuario.nombre, idLibro);
    }
}

//Persistencia

void guardarLibrosRec(tNodoArbol* raiz) {
    if (raiz != NULL) {
        fwrite(&(raiz->libro), sizeof(tLibro), 1, archivoPuntero);
        guardarLibrosRec(raiz->izquierda);
        guardarLibrosRec(raiz->derecha);
    }
}

void guardarTodo(tNodoArbol* raiz, tNodoUsuario* lista) {
    // 1. GUARDAR LIBROS (arbol -> Archivo)
    archivoPuntero = fopen("libros.dat", "wb");
    if (archivoPuntero != NULL) {
        guardarLibrosRec(raiz);
        fclose(archivoPuntero);
        printf("- Libros guardados en %s\n", "libros.dat");
    } else {
        printf("Error al abrir archivo de libros.\n");
    }

    // 2. GUARDAR USUARIOS (Lista -> Archivo)
    archivoPuntero = fopen("usuarios.dat", "wb");
    if (archivoPuntero != NULL) {
        while(lista != NULL) {
            // Guardamos la estructura base del usuario
            fwrite(&(lista->usuario), sizeof(tUsuario), 1, archivoPuntero);
            
            // Contamos cuantos libros tiene para saber cuantos guardar
            int cant = 0;
            tNodoLibro* aux = lista->usuario.librosPrestados;
            while(aux) { 
                cant++; 
                aux = aux->siguiente;
            }
            fwrite(&cant, sizeof(int), 1, archivoPuntero); // Escribimos la cantidad
            
            // Guardamos los IDs de los libros prestados
            aux = lista->usuario.librosPrestados;
            while(aux) {
                fwrite(&(aux->idLibro), sizeof(int), 1, archivoPuntero);
                aux = aux->siguiente;
            }
            lista = lista->siguiente;
        }
        fclose(archivoPuntero);
        printf("- Usuarios guardados en %s\n", "usuarios.dat");
    } else {
        printf("Error al abrir archivo de usuarios.\n");
    }
}

void cargarTodo(tNodoArbol** raiz, tNodoUsuario** lista) {
    // 1. CARGAR LIBROS
    archivoPuntero = fopen("libros.dat", "rb");
    if (archivoPuntero != NULL) {
        tLibro libro;
        while(fread(&libro, sizeof(tLibro), 1, archivoPuntero) == 1) {
            *raiz = insertarLibro(*raiz, libro);
        }
        fclose(archivoPuntero);
        printf("Datos de libros cargados.\n");
    } else {
        printf("No se encontro archivo de libros (iniciando vacio).\n");
    }

    // 2. CARGAR USUARIOS 
    archivoPuntero = fopen("usuarios.dat", "rb");
    if (archivoPuntero != NULL) {
        tUsuario usuario;
        while(fread(&usuario, sizeof(tUsuario), 1, archivoPuntero) == 1) {
            usuario.librosPrestados = NULL; // Inicializar puntero
            int cant, idLibro, i;
            fread(&cant, sizeof(int), 1, archivoPuntero); // Leer cantidad
            
            for(i=0; i<cant; i++) {
                fread(&idLibro, sizeof(int), 1, archivoPuntero); // Leer cada ID
                agregarLibroPrestado(&usuario, idLibro);
            }
            *lista = insertarUsuario(*lista, usuario);
        }
        fclose(archivoPuntero);
        printf("Datos de usuarios cargados.\n");
    } else {
        printf("No se encontro archivo de usuarios (iniciando vacio).\n");
    }
}
