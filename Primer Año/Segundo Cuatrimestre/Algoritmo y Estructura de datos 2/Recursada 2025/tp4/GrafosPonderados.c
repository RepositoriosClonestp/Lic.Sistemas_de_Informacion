#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

/* Declaraci�n de tipos de datos personalizados */
typedef int tVertice;

typedef float tPeso;

// Arco definido por sus vertices de origen y destino y su peso
typedef struct {
	tVertice origen;
	tVertice destino;
	tPeso peso;
}tArco; 

// Grafo ponderado representado mediante conjuntos de vertices y matriz de adyacencia con pesos
typedef bool conjuntoVertices[N]; // Conjunto de vertices
typedef tPeso conjuntoArcos[N][N]; // Conjunto de arcos con pesos

// Definicion del TDA Grafo Ponderado
typedef struct{
	conjuntoVertices vertices;
	conjuntoArcos arcos;
}tGrafoPonderado;

/* Declaracion de los prototipos */
void inicializarGrafo( tGrafoPonderado * );
void agregarVertice( tGrafoPonderado *, tVertice ); 
void agregarArco( tGrafoPonderado *, tArco ); 
void borrarVertice( tGrafoPonderado *, tVertice ); 
void borrarArco( tGrafoPonderado *, tArco ); 

int maximoVertice( tGrafoPonderado );
void visualizarMatrizAdyacencia( tGrafoPonderado );
void visualizarMatrizPesos( tGrafoPonderado );
bool existeVertice( tGrafoPonderado, tVertice );

/* Declaracion de las variables globales */
tGrafoPonderado grafo;

// Programa Principal
int main() {
	tArco arco;
	
	inicializarGrafo( &grafo ); // Puntero al grafo

	agregarVertice( &grafo, 2 );
	agregarVertice( &grafo, 3 );
	agregarVertice( &grafo, 4);	
	
	arco.origen = 3;
	arco.destino = 2;
	arco.peso = 25.0;
	agregarArco( &grafo, arco );
	
	arco.origen = 2;
	arco.destino = 4;
	arco.peso = 7.5;
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;
	arco.peso = 33.75;
	agregarArco( &grafo, arco );

	visualizarMatrizAdyacencia( grafo );
	
	visualizarMatrizPesos( grafo );
	
	/*borrarVertice( &grafo, 2 );
	
	visualizarMatrizAdyacencia( grafo );
	visualizarMatrizPesos( grafo );*/
	
	borrarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo );
	visualizarMatrizPesos( grafo );
	
	return 0;
}

// Implementacion de las funciones
void inicializarGrafo( tGrafoPonderado * pGrafo ) {
	// Consiste en inicializar en cero el array de v�rtices y
	// la matriz de arcos 
	int x, y;
	for(x=0; x<N; x++){
		pGrafo->vertices[x] = 0;
		// (*pGrafo).vertices[x] = 0;
		for(y=0; y<N; y++){
			pGrafo->arcos[x][y] = 0;
		}
	}
	printf("Grafo inicializado!\n");
}
// Agrega un vértice al grafo
void agregarVertice( tGrafoPonderado * pGrafo, tVertice pVertice ) {
	// Consiste en marcar 1 en el v�rtice que se desea activar en
	// el array de v�rtices
	if(pVertice < N){
		pGrafo->vertices[pVertice] = true;
		printf("Vertice %d activado!\n", pVertice);
	}else{
		printf("Vertice invalido!\n");
	}
} 
// Agrega un arco al grafo
void agregarArco( tGrafoPonderado * pGrafo, tArco pArco )  {
	// Consiste en activar el arco en la matriz de arcos siempre que exista
	// el v�rtice activo
	if( pGrafo->vertices[pArco.origen] == true &&
		pGrafo->vertices[pArco.destino] == true ) {
		pGrafo->arcos[pArco.origen][pArco.destino] = pArco.peso;
		printf("Arco (%d, %d) activado!\n", pArco.origen, pArco.destino);
	}else{
		printf("Arco invalido!\n");
		// se podr�a mejorar la validaci�n
	}
}
// Borra un vértice del grafo
void borrarVertice( tGrafoPonderado * pGrafo, tVertice pVertice )  {
	// Consiste en desactivar el v�rtice del vector de v�rtices 
	// si est� activo
	bool existeV = existeVertice( *pGrafo, pVertice );
	
	if(existeV){
		pGrafo->vertices[pVertice] = false;
	}else{
		printf("No existe el vertice que se desea quitar!\n");	
	}	
}
// Borra un arco del grafo
void borrarArco( tGrafoPonderado * pGrafo, tArco pArco )  {
	// Consiste en borrar el arco si existe en la matriz de arcos
	if( pGrafo->arcos[pArco.origen][pArco.destino] != 0.0 ) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 0.0;
		printf("Arco (%d, %d) desactivado!\n", pArco.origen, pArco.destino);
	}else{
		printf("No existe el arco!\n");	
	}
} 
// Devuelve el mayor vértice activo
int maximoVertice( tGrafoPonderado pGrafo )  {
	// Consiste en obtener el valor de v�rtice activo m�s grande
	int x;
	int max = 0;
	
	for(x=0; x<N; x++) {
		if(pGrafo.vertices[x] == true){
			max = x;
		}
	}
	
	return max;	
}
// Muestra la matriz de adyacencia
void visualizarMatrizAdyacencia( tGrafoPonderado pGrafo )  {
	// Pre-condici�n: obtener el m�ximo v�rtice del grafo
	// Consiste en recorrer la matriz de arcos, e identificar si existe una arista 
	// y mostrar 1 en su lugar y 0 en caso contrario
	int x, y;
	int maxV = maximoVertice( pGrafo );
	bool existeArista = false;
	
	printf("\n*** MATRIZ DE ADYACENCIA ***\n");	
	
	for(x=0; x<=maxV; x++){	
		for(y=0; y<=maxV; y++){
			existeArista = 	( pGrafo.arcos[x][y] != 0.0 ) 
							&& existeVertice( pGrafo, x )
							&& existeVertice( pGrafo, y );
			
			if(existeArista == true){
				printf("1 | ");		
			}else {
				printf("0 | ");
			}
		}
		printf("\n");
	}	
}

// Muestra la matriz de pesos
void visualizarMatrizPesos( tGrafoPonderado pGrafo ) {
	// Pre-condici�n: obtener cantidad de v�rtices del grafo
	// Consiste en recorrer la matriz de arcos, e identificar si existe una arista 
	// y mostrar su contenido en su lugar y 0 en caso contrario
	
	int x, y;
	int maxV = maximoVertice( pGrafo );
	bool existeArista = false;
	
	printf("\n*** MATRIZ DE ADYACENCIA ***\n");	
	
	for(x=0; x<=maxV; x++){	
		for(y=0; y<=maxV; y++){
			existeArista = 	( pGrafo.arcos[x][y] != 0.0 )
							&& existeVertice( pGrafo, x )
							&& existeVertice( pGrafo, y );
			
			if(existeArista == true){
				printf("%.2f | ", pGrafo.arcos[x][y]);		
			}else {
				printf("00.00 | ");
			}
		}
		printf("\n");
	}
	
	
}
// Verifica si un vértice existe
bool existeVertice( tGrafoPonderado pGrafo, tVertice pVertice ) {
	// Consiste en identificar s iel v�rtice est� activo
	return pGrafo.vertices[pVertice] == true;
}

