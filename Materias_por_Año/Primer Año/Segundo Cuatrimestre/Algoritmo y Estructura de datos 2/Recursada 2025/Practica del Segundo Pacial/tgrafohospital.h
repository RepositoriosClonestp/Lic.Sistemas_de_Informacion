#include <stdio.h>
#include <stdbool.h>
#define N 120  // Maximo numero de vertices

/* Declaracion de tipos de datos personalizados */
typedef int tVertice;
typedef struct {
    float distanciaMtrs;
    float tiempoMin;
} tArcoData;

// Arco ponderado
typedef struct {
	tVertice origen;
	tVertice destino;	
	tArcoData peso;	// peso del arco
} tArco;

typedef bool conjuntoVertices[N]; // Vector de vertices activos o no activos
typedef tArcoData conjuntoArcos[N][N]; // Matriz de adyacencia ponderada

// Grafo ponderado
typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
} tGrafoHospital;

//INTERFAZ 

void borrarVertice( tGrafoHospital *, tVertice ); 
void borrarArco( tGrafoHospital *, tArco ); 



void agregarArco( tGrafoHospital *, tArco ); 
void inicializarGrafo( tGrafoHospital * );
void agregarVertice( tGrafoHospital *, tVertice ); 
int maximoVertice( tGrafoHospital );
bool existeVertice( tGrafoHospital, tVertice );
void visualizarMatrizPeso( tGrafoHospital );

/* * IMPLEMENTACIÓN DE FUNCIONES
 */

void inicializarGrafo(tGrafoHospital * pGrafo) {
    // Inicializa el array de vértices en falso
    // e inicializa la matriz de arcos (usamos -1.0 para indicar "sin conexión")
    int x, y;
    tArcoData dataNula = {-1.0, -1.0}; // -1 indica que no hay arco
    
    for(x=0; x<N; x++){
        pGrafo->vertices[x] = false;
        for(y=0; y<N; y++){
            pGrafo->arcos[x][y] = dataNula;
        }
    }
    printf("Grafo de Hospital inicializado!\n\n");
}

void agregarVertice(tGrafoHospital * pGrafo, tVertice pVertice) {
    // Activa un vértice (área) en el array de vértices
    if(pVertice < N){
        pGrafo->vertices[pVertice] = true;
        printf("Área (Vértice) %d activada!\n", pVertice);
    } else {
        printf("Vértice inválido!\n");
    }
} 

/*
 * Codificar una función para agregar un arco en el grafo definido [cite: 33]
 */
void agregarArco(tGrafoHospital * pGrafo, tVertice pOrigen, tVertice pDestino, tArcoData pData) {
    // Verifica que ambas áreas (vértices) existan
    if(existeVertice(*pGrafo, pOrigen) && existeVertice(*pGrafo, pDestino)) {
        
        pGrafo->arcos[pOrigen][pDestino] = pData;
        
        // Como es un grafo NO DIRIGIDO, agregamos la conexión en ambos sentidos 
        pGrafo->arcos[pDestino][pOrigen] = pData; 
        
        printf("Conexión (Arco) (%d <-> %d) agregada!\n", pOrigen, pDestino);
    } else {
        printf("Arco inválido (una o ambas áreas no existen)!\n");
    }
}

/*
 * Codificar una función para visualizar la matriz de pesos 
 */
void visualizarMatriz(tGrafoHospital pGrafo) {
    int x, y;
    int maxV = maximoVertice(pGrafo); // Obtenemos el vértice más alto para no imprimir 120x120

    printf("\n*** Matriz de Conexiones del Hospital ***\n");

    // Imprimir cabeceras de columnas
    printf("\t\t");
    for(x=0; x<=maxV; x++){
        printf("[%d]\t\t\t", x);
    }
    printf("\n");

    for(x=0; x<=maxV; x++){
        printf("[%d]\t", x); // Imprimir cabecera de fila
        
        // Solo mostrar si el vértice (fila) está activo
        if (existeVertice(pGrafo, x)) {
            for(y=0; y<=maxV; y++){
                
                tArcoData data = pGrafo.arcos[x][y];
                
                // Si la distancia es -1.0, no hay conexión
                if (data.distanciaMtrs == -1.0) {
                    printf("(--- mtrs | --- min)\t");
                } else {
                    // Muestra la información con el formato solicitado 
                    printf("(%.2f mtrs | %.2f min)\t", data.distanciaMtrs, data.tiempoMin);
                }
            }
        }
        printf("\n");
    }
}

// --- Funciones auxiliares (adaptadas de tu plantilla) ---

int maximoVertice(tGrafoHospital pGrafo) {
    // Obtiene el valor de vértice activo más grande
    int x;
    int max = 0;
    for(x=0; x<N; x++) {
        if(pGrafo.vertices[x] == true){
            max = x;
        }
    }
    return max;
}

bool existeVertice(tGrafoHospital pGrafo, tVertice pVertice) {
    // Identifica si el vértice está activo
    if (pVertice >= N || pVertice < 0) return false;
    return pGrafo.vertices[pVertice] == true;
}