#include <stdio.h>
#include <stdbool.h>
#define N 15

/* Declaracion de tipos de datos personalizados */
typedef int tVertice;
typedef struct {
	float km;
	float promedioPaciente;
}tPeso;

typedef struct {
	tVertice origen;
	tVertice destino;	
	tPeso peso;	
} tArco;

typedef bool conjuntoVertices[N];
typedef tPeso conjuntoArcos[N][N];

typedef struct {
	conjuntoVertices vertices;
	conjuntoArcos arcos;
} tGrafoPonderado;

//INTERFAZ

void borrarVertice( tGrafoPonderado *, tVertice ); 
void borrarArco( tGrafoPonderado *, tArco ); 



void agregarArco( tGrafoPonderado *, tArco ); 
void inicializarGrafo( tGrafoPonderado * );
void agregarVertice( tGrafoPonderado *, tVertice ); 
int maximoVertice( tGrafoPonderado );
bool existeVertice( tGrafoPonderado, tVertice );
void visualizarMatrizPeso( tGrafoPonderado );

//Implementacion

void borrarVertice( tGrafoPonderado * pGrafo, tVertice pVertice )  {
	if( pGrafo->vertices[pVertice] =! 0 ) {
		pGrafo->vertices[pVertice] = 0;
		printf( "Se desactivo el vertice %d\n", pVertice );
	} else {
		printf( "El vertice no se encuentra \n" );
	}
}

void borrarArco( tGrafoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->arcos[pArco.origen][pArco.destino].km != 0 ) {
		pGrafo->arcos[pArco.origen][pArco.destino].km = 0;		
		pGrafo->arcos[pArco.origen][pArco.destino].promedioPaciente = 0;
		
		printf( "Se desactivo el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "El arco no se encuentra \n" );
	}	
	
} 

void visualizarMatrizPeso( tGrafoPonderado pGrafo )  {
	int x, y, maxVer;
	bool existeArista = false;
	
	maxVer= maximoVertice( pGrafo );
	
	printf( "\n MATRIZ DE Peso (Km) \n" );
	for( x=1; x<=maxVer; x++ ) {
		for( y=1; y<=maxVer; y++ ) {
			existeArista = ( pGrafo.arcos[x][y].km != 0 ) && existeVertice( pGrafo, x ) && existeVertice( pGrafo, y );
			if( existeArista ) {
				printf("%.2f ",pGrafo.arcos[x][y].km);
			} else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}


void inicializarGrafo( tGrafoPonderado * pGrafo ) {
	int x, y;
	
	for( x=0; x<=N; x++ ) {
		pGrafo->vertices[x] = 0;		
		// ( *pGrafo ).vertices[x] = 0;				
		for( y=0; y<=N; y++ ) {
			pGrafo->arcos[x][y].km = 0;
			pGrafo->arcos[x][y].promedioPaciente = 0;
		}
	}
}

void agregarVertice( tGrafoPonderado * pGrafo, tVertice pVertice ) {
	// ( *pGrafo ).vertices[pVertice] = 1;
	pGrafo->vertices[pVertice] = 1;
	printf( "Se agrego el vertice %d\n", pVertice );
} 

void agregarArco( tGrafoPonderado * pGrafo, tArco pArco )  {
	if( pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1 ) {
	pGrafo->arcos[pArco.origen][pArco.destino]= pArco.peso;
		printf( "Se agrego el arco [%d, %d]\n", pArco.origen, pArco.destino );
	} else {
		printf( "No se pudo agregar - Alguno de los vertices no se encuentra activo\n" );
	}		
}

int maximoVertice( tGrafoPonderado pGrafo )  {
	int x, max;
	max = 0;

	for( x=0; x<N; x++ ) {
		if( pGrafo.vertices[x] == 1) {
			max = x;
		}
	}	
	return max;
}

bool existeVertice( tGrafoPonderado pGrafo, tVertice pVertice ) {
	return pGrafo.vertices[pVertice] == 1;
}
 
