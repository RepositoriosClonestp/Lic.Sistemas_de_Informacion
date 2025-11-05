#include <stdio.h>
#include <stdbool.h>
#define N 10

/* Declaracionn de tipos de datos personalizados */
typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;	
} tArco;

typedef bool conjuntoVertices[N];
typedef bool conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
	
} tGrafoNoPonderado;

//INTERFAZ
void agregarArco( tGrafoNoPonderado *, tArco ); 
void borrarArco( tGrafoNoPonderado *, tArco ); 
void visualizarMatrizAdyacencia( tGrafoNoPonderado );


void borrarVertice( tGrafoNoPonderado *, tVertice ); 
void inicializarGrafo( tGrafoNoPonderado * );
void agregarVertice( tGrafoNoPonderado *, tVertice ); 
int maximoVertice( tGrafoNoPonderado );
bool existeVertice( tGrafoNoPonderado, tVertice );


//IMPLEMENTACION
void agregarArco( tGrafoNoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1 ) {
		pGrafo->arcos[pArco.origen][pArco.destino]=1;
		printf( "Se agrego el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "No se pudo agregar - Alguno de los vertices no se encuentra activo\n" );
	}		
}

void borrarArco( tGrafoNoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->arcos[pArco.origen][pArco.destino] != 0 ) {
		pGrafo->arcos[pArco.origen][pArco.destino] = 0;
		printf( "Se desactivo el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "El arco no se encuentra \n" );
	}	
	
} 


void visualizarMatrizAdyacencia( tGrafoNoPonderado pGrafo )  {
	int x, y, maxVer;
	bool existeArista = false;
	
	maxVer= maximoVertice( pGrafo );	
	
	printf( "\n MATRIZ DE ADYACENCIA \n" );
	for( x=1; x<=maxVer; x++ ) {
		for( y=1; y<=maxVer; y++ ) {
			existeArista = ( pGrafo.arcos[x][y] == true ) && pGrafo.vertices[x] == 1&& pGrafo.vertices[y] ;
			if( existeArista ) {
				printf("1 ");
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}


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


bool existeVertice( tGrafoNoPonderado pGrafo, tVertice pVertice ) {
	return pGrafo.vertices[pVertice] == 1;
}
 


void inicializarGrafo( tGrafoNoPonderado * pGrafo ) {
	int x, y;
	
	for( x=0; x<=N; x++ ) {
		pGrafo->vertices[x] = 0;		
		// ( *pGrafo ).vertices[x] = 0;				
		for( y=0; y<=N; y++ ) {
			pGrafo->arcos[x][y] = 0;
		}
	}
}

void agregarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice ) {
	// ( *pGrafo ).vertices[pVertice] = 1;
	pGrafo->vertices[pVertice] = 1;
	printf( "Se agrego el vertice %d\n", pVertice );
} 


void borrarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice )  {
	if( pGrafo->vertices[pVertice] =! 0 ) {
		pGrafo->vertices[pVertice] = 0;
		printf( "Se desactivo el vertice %d\n", pVertice );
	} else {
		printf( "El vertice no se encuentra \n" );
	}

}





