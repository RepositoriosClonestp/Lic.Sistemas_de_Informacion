#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODOS 150 // Capacidad máxima de instituciones (vértices)
#define VALOR_NULO -1.0 // Usado para indicar que no hay arco (conexión)

// --- Definición de Tipos ---

/**
 * @struct tPesoArco
 * @brief Almacena la ponderación (pesos) de una conexión entre dos nodos.
 */
typedef struct {
    float distanciaKm;
    int estudiantesPromedio;
} tPesoArco;

/**
 * @struct tVertice
 * @brief Representa un nodo (institución) en el grafo.
 */
typedef struct {
    char nombreInstitucion[20]; // Nombre o identificador del vértice
    bool existe; // Indica si la posición del array está ocupada por un vértice
} tVertice;

/**
 * @struct tGrafoInstituciones
 * @brief TDA para un grafo ponderado (no dirigido) de instituciones.
 * Implementado con matriz de adyacencia (arrays).
 */
typedef struct {
    tVertice vertices[MAX_NODOS];
    tPesoArco arcos[MAX_NODOS][MAX_NODOS]; // Matriz de Adyacencia Ponderada
    int cantVertices; // Contador de vértices actualmente en el grafo
} tGrafoInstituciones;

/* --- Prototipos de Funciones del TDA --- */

/**
 * @brief Inicializa la estructura del grafo, limpiando vértices y arcos.
 * @param g Puntero al grafo a inicializar.
 */
void inicializarGrafo(tGrafoInstituciones *g);

/**
 * @brief Agrega un nuevo vértice (institución) al grafo.
 * @param g Puntero al grafo.
 * @param nombre Nombre de la institución a agregar.
 * @return true si se agregó correctamente, false si el grafo estaba lleno.
 */
bool agregarVertice(tGrafoInstituciones *g, const char *nombre);

/**
 * @brief Busca el índice (posición) de un vértice dado su nombre.
 * @param g Puntero al grafo.
 * @param nombre Nombre del vértice a buscar.
 * @return El índice (0 a MAX_NODOS-1) si se encuentra, o -1 si no existe.
 */
int buscarIndiceVertice(tGrafoInstituciones *g, const char *nombre);

/**
 * @brief Quita un vértice del grafo, eliminando también todos sus arcos asociados.
 * @param g Puntero al grafo.
 * @param nombre Nombre de la institución a quitar.
 * @return true si se eliminó correctamente, false si no se encontró el vértice.
 */
bool quitarVertice(tGrafoInstituciones *g, const char *nombre);

/**
 * @brief Agrega un arco (conexión) ponderado entre dos vértices.
 * @param g Puntero al grafo.
 * @param origen Nombre de la institución de origen.
 * @param destino Nombre de la institución de destino.
 * @param distancia Distancia en KM para el arco.
 * @param estudiantes Promedio de estudiantes para el arco.
 */
void agregarArco(tGrafoInstituciones *g, const char *origen, const char *destino, float distancia, int estudiantes);


/* --- Implementación de Funciones --- */

void inicializarGrafo(tGrafoInstituciones *g) {
    int i, j;
    g->cantVertices = 0;
    
    // Inicializa la matriz de adyacencia con VALOR_NULO
    for (i = 0; i < MAX_NODOS; i++) {
        g->vertices[i].existe = false;
        for (j = 0; j < MAX_NODOS; j++) {
            g->arcos[i][j].distanciaKm = VALOR_NULO;
            g->arcos[i][j].estudiantesPromedio = (int)VALOR_NULO;
        }
    }
}

bool agregarVertice(tGrafoInstituciones *g, const char *nombre) {
    if (g->cantVertices >= MAX_NODOS) {
        printf("Error: El grafo está lleno (máx. %d vértices).\n", MAX_NODOS);
        return false;
    }
    
    // Buscar la primera posición libre
    int i = 0;
    while (i < MAX_NODOS && g->vertices[i].existe) {
        i++;
    }
    
    // Asegurar que encontramos un espacio libre
    if (i < MAX_NODOS) {
        strcpy(g->vertices[i].nombreInstitucion, nombre);
        g->vertices[i].existe = true;
        g->cantVertices++;
        printf("-> Vértice '%s' agregado en la posición [%d].\n", nombre, i);
        return true;
    }
    return false; // No debería ocurrir si cantVertices se maneja bien
}

int buscarIndiceVertice(tGrafoInstituciones *g, const char *nombre) {
    for (int i = 0; i < MAX_NODOS; i++) {
        if (g->vertices[i].existe && strcmp(g->vertices[i].nombreInstitucion, nombre) == 0) {
            return i;
        }
    }
    return -1; // No encontrado
}

bool quitarVertice(tGrafoInstituciones *g, const char *nombre) {
    int indice = buscarIndiceVertice(g, nombre);
    
    if (indice == -1) {
        printf("Error: Vértice '%s' no encontrado para eliminar.\n", nombre);
        return false;
    }
    
    // 1. Marcar como inexistente
    g->vertices[indice].existe = false;
    g->cantVertices--;
    
    // 2. Eliminar todos los arcos relacionados (fila y columna)
    for (int i = 0; i < MAX_NODOS; i++) {
        // Eliminar fila (salientes)
        g->arcos[indice][i].distanciaKm = VALOR_NULO;
        g->arcos[indice][i].estudiantesPromedio = (int)VALOR_NULO;
        
        // Eliminar columna (entrantes)
        g->arcos[i][indice].distanciaKm = VALOR_NULO;
        g->arcos[i][indice].estudiantesPromedio = (int)VALOR_NULO;
    }
    
    printf("-> Vértice '%s' y sus arcos eliminados.\n", nombre);
    return true;
}

void agregarArco(tGrafoInstituciones *g, const char *origen, const char *destino, float distancia, int estudiantes) {
    int i = buscarIndiceVertice(g, origen);
    int j = buscarIndiceVertice(g, destino);
    
    if (i != -1 && j != -1) {
        g->arcos[i][j].distanciaKm = distancia;
        g->arcos[i][j].estudiantesPromedio = estudiantes;
        
        // Asumimos un grafo NO dirigido (simétrico)
        g->arcos[j][i] = g->arcos[i][j];
        
        printf("-> Arco entre %s y %s añadido (Dist: %.1f km, Est: %d).\n", origen, destino, distancia, estudiantes);
    } else {
        printf("Error al añadir arco: Uno o ambos vértices no existen.\n");
    }
}


/* --- Programa Principal (Uso del TDA) --- */

int main() {
    // 1. Declarar una variable del tipo tGrafoInstituciones
    tGrafoInstituciones redAcademica;
    
    printf("--- GESTIÓN DE RED ACADÉMICA ---\n");
    
    // 2. Inicializar la variable del TDA
    inicializarGrafo(&redAcademica);
    printf("Grafo inicializado. Capacidad máxima: %d nodos.\n\n", MAX_NODOS);
    
    // 3. Agregar Vértices (Instituciones)
    printf("--- Agregando Instituciones ---\n");
    agregarVertice(&redAcademica, "UTN-FRC");
    agregarVertice(&redAcademica, "UNC-FA");
    agregarVertice(&redAcademica, "UCC-FC");
    agregarVertice(&redAcademica, "IES-SM");
    
    // 4. Agregar Arcos (Conexiones)
    printf("\n--- Conectando Instituciones ---\n");
    agregarArco(&redAcademica, "UTN-FRC", "UNC-FA", 5.2, 1500);
    agregarArco(&redAcademica, "UNC-FA", "UCC-FC", 2.8, 800);
    agregarArco(&redAcademica, "IES-SM", "UTN-FRC", 12.0, 300);
    
    // 5. Quitar un Vértice
    printf("\n--- Eliminando una Institución ---\n");
    quitarVertice(&redAcademica, "UCC-FC");
    
    // 6. Intentar agregar otra para verificar que el espacio se liberó
    printf("\n--- Agregando nueva Institución ---\n");
    agregarVertice(&redAcademica, "UADE-CC");
    
    // 7. Verificar el estado final (simulado)
    printf("\n--- Estado Final del Grafo ---\n");
    printf("Total de Vértices activos: %d\n", redAcademica.cantVertices);
    
    int idxUNC = buscarIndiceVertice(&redAcademica, "UNC-FA");
    int idxUCC = buscarIndiceVertice(&redAcademica, "UCC-FC"); // Devolverá -1
    
    printf("Índice de 'UCC-FC' (debe ser -1): %d\n", idxUCC);
    
    if (idxUNC != -1 && idxUCC != -1) {
        // Esta línea ya no se ejecutará por la comprobación del if
        printf("Conexión 'UNC-FA' a 'UCC-FC': %.1f km\n", 
               redAcademica.arcos[idxUNC][idxUCC].distanciaKm);
    } else {
        printf("La conexión 'UNC-FA' a 'UCC-FC' ya no existe.\n");
    }

    return 0;
}