#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// --- CONFIGURACIÓN DEL SISTEMA ---
#define MAX_PRESTAMOS_POR_USUARIO 5
#define MAX_TITULO 100
#define MAX_AUTOR 100
#define MAX_NOMBRE_USUARIO 100

// --- ESTRUCTURAS DE DATOS (TADs) ---

// Cola (para lista de espera)
typedef struct NodoCola {
    int idUsuario;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct {
    NodoCola *frente, *final;
} Cola;

// Libro
typedef struct {
    int idLibro;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int disponible;
    Cola* listaEspera;
} Libro;

// Árbol AVL
typedef struct NodoArbol {
    Libro libro;
    struct NodoArbol *izq, *der;
    int altura;
} NodoArbol;

// Lista de libros por usuario
typedef struct NodoLibroUsuario {
    int idLibro;
    struct NodoLibroUsuario* siguiente;
} NodoLibroUsuario;

// Usuario
typedef struct {
    int idUsuario;
    char nombre[MAX_NOMBRE_USUARIO];
    NodoLibroUsuario* librosPrestados;
} Usuario;

// Lista de usuarios
typedef struct NodoUsuario {
    Usuario usuario;
    struct NodoUsuario* siguiente;
} NodoUsuario;

// --- PROTOTIPOS DE FUNCIONES (Interfaz Pública) ---

// Operaciones de Cola
Cola* crearCola();
int estaVaciaCola(Cola* q);
void encolar(Cola* q, int idUsuario);
int desencolar(Cola* q);
int contarCola(Cola* q);
int estaEnCola(Cola* q, int idUsuario);
void freeCola(Cola* q);

// Operaciones de Lista de Libros de Usuario
void insertarLibroUsuario(NodoLibroUsuario** cabeza, int idLibro);
int eliminarLibroUsuario(NodoLibroUsuario** cabeza, int idLibro);
void mostrarLibrosUsuario(NodoLibroUsuario* cabeza);
int contarLibrosUsuario(NodoLibroUsuario* cabeza);
void freeListaLibrosUsuario(NodoLibroUsuario* cabeza);

// Operaciones del Árbol AVL
NodoArbol* crearNodoArbol(Libro libro);
NodoArbol* insertarLibroAVL(NodoArbol* nodo, Libro libro, int* codigo);
NodoArbol* buscarLibro(NodoArbol* raiz, int idLibro);
NodoArbol* eliminarLibroAVL(NodoArbol* raiz, int idLibro, int* codigo);
void mostrarCatalogo(NodoArbol* raiz);
int contarLibros(NodoArbol* raiz);
int actualizarLibro(NodoArbol* raiz, int idLibro, const char* nuevoTitulo, const char* nuevoAutor);
void freeArbol(NodoArbol* raiz);

// Operaciones de Lista de Usuarios
void agregarUsuarioLista(NodoUsuario** cabeza, Usuario usuario);
NodoUsuario* buscarUsuario(NodoUsuario* cabeza, int idUsuario);
int eliminarUsuario(NodoUsuario** cabeza, int idUsuario);
void mostrarUsuarios(NodoUsuario* cabeza);
int contarUsuarios(NodoUsuario* cabeza);
void freeUsuarios(NodoUsuario* cabeza);

// Lógica de Biblioteca
int prestarLibro(NodoArbol* raizArbol, NodoUsuario* listaUsuarios, int idLibro, int idUsuario);
int devolverLibro(NodoArbol* raizArbol, NodoUsuario* listaUsuarios, int idLibro, int idUsuario);

// Persistencia
void guardarLibros(NodoArbol* raiz);
void cargarLibros(NodoArbol** raiz);
void guardarColas(NodoArbol* raiz);
void cargarColas(NodoArbol* raiz);
void guardarUsuarios(NodoUsuario* cabeza);
void cargarUsuarios(NodoUsuario** cabeza);

// Utilidades
void limpiarBuffer();
void leerCadena(char* buffer, int maxLen, const char* prompt);
void mostrarEstadisticas(NodoArbol* catalogoLibros, NodoUsuario* listaUsuarios);

#endif // BIBLIOTECA_H
