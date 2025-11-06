 #include <stdio.h>
#include <stdbool.h>
#define N 10

/* Declaración de tipos de datos personalizados */
typedef int tVertice;

// Arco definido por sus vértices de origen y destino
typedef struct {
	tVertice origen; 
	tVertice destino;	
} tArco;
 
// Grafo no ponderado representado mediante conjuntos de vértices y matriz de adyacencia
typedef bool conjuntoVertices[N];
typedef bool conjuntoArcos[N][N];

// Definición del TDA Grafo No Ponderado
typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
} tGrafoNoPonderado;

/* Declaración de los prototipos */
void inicializarGrafo( tGrafoNoPonderado * ); // Puntero a grafo
void agregarVertice( tGrafoNoPonderado *, tVertice ); // Puntero a grafo y vértice a agregar
void agregarArco( tGrafoNoPonderado *, tArco ); // Puntero a grafo y arco a agregar
void borrarVertice( tGrafoNoPonderado *, tVertice ); // Puntero a grafo y vértice a borrar
void borrarArco( tGrafoNoPonderado *, tArco );  // Puntero a grafo y arco a borrar

// Funciones de visualización y utilidad
int maximoVertice( tGrafoNoPonderado ); // Devuelve el mayor vértice activo
void visualizarMatrizAdyacencia( tGrafoNoPonderado ); // Muestra la matriz de adyacencia
bool existeVertice( tGrafoNoPonderado, tVertice ); // Verifica si un vértice existe

/* Declaración de las variables globales */
tGrafoNoPonderado grafo;

int main() { // Programa Principal
	tArco arco;
					
	inicializarGrafo( &grafo ); // Puntero al grafo
	agregarVertice( &grafo, 2 ); // Puntero al grafo y vértice a agregar
	agregarVertice( &grafo, 3 ); // Puntero al grafo y vértice a agregar
	agregarVertice( &grafo, 4); // Puntero al grafo y vértice a agregar
	
	arco.origen = 3;				
	arco.destino = 2;				
	agregarArco( &grafo, arco );	
	
	arco.origen = 2;
	arco.destino = 4;
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;
	agregarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo ); // Paso por valor
	
	borrarVertice( &grafo, 2 ); // Puntero al grafo y vértice a borrar
	
	visualizarMatrizAdyacencia( grafo ); // Paso por valor
	
	borrarArco( &grafo, arco ); // Puntero al grafo y arco a borrar
	
	visualizarMatrizAdyacencia( grafo ); // Paso por valor
	
	return 0;
}

// Implementación de las funciones
void inicializarGrafo( tGrafoNoPonderado * pGrafo ) {
	int x, y;
	
	for( x=0; x<=N; x++ ) { 
		pGrafo->vertices[x] = 0;		
		/* ( *pGrafo ).vertices[x] = 0;	*/			
		for( y=0; y<=N; y++ ) {
			pGrafo->arcos[x][y] = 0;
		}
	}
}

// Agrega un vértice al grafo
void agregarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice ) {
	/* ( *pGrafo ).vertices[pVertice] = 1;*/
	pGrafo->vertices[pVertice] = 1;
	printf( "Se agrego el vertice %d\n", pVertice );
} 

// Agrega un arco al grafo
void agregarArco( tGrafoNoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1 ) {
		( *pGrafo ).arcos[pArco.origen][pArco.destino] = 1;
		printf( "Se agrego el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "No se pudo agregar - Alguno de los vertices no se encuentra activo\n" );
	}		
}

// Borra un vértice del grafo
void borrarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice )  {
	if( pGrafo->vertices[pVertice] =! 0 ) {
		pGrafo->vertices[pVertice] = 0;
		printf( "Se desactivo el vertice %d\n", pVertice );
	} else {
		printf( "El vertice no se encuentra \n" );
	}

}

// Borra un arco del grafo
void borrarArco( tGrafoNoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->arcos[pArco.origen][pArco.destino] != 0 ) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 0;
		printf( "Se desactivo el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "El arco no se encuentra \n" );
	}	
	
} 

// Devuelve el mayor vértice activo
int maximoVertice( tGrafoNoPonderado pGrafo )  {
	int x, max;
	max = 0;

	for( x=0; x<N; x++ ) {
		if( pGrafo.vertices[x] == 1) {
			max = x;
		}
	}	
	return max;
}

// Muestra la matriz de adyacencia
void visualizarMatrizAdyacencia( tGrafoNoPonderado pGrafo )  {
	int x, y, maxVer;
	bool existeArista = false;
	
	maxVer= maximoVertice( pGrafo );
	
	
	printf( "\n MATRIZ DE ADYACENCIA \n" );
	for( x=1; x<=maxVer; x++ ) {
		for( y=1; y<=maxVer; y++ ) {
			existeArista = ( pGrafo.arcos[x][y] == true ) && existeVertice( pGrafo, x ) && existeVertice( pGrafo, y );// Verifica si existe arco entre x e y
			if( existeArista ) {
				printf("1 ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

// Verifica si un vértice existe
bool existeVertice( tGrafoNoPonderado pGrafo, tVertice pVertice ) {
	return pGrafo.vertices[pVertice] == 1;
}
 
