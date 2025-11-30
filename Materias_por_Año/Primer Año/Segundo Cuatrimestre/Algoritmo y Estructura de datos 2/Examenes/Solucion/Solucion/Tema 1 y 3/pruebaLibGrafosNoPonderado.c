#include <stdio.h>
#include "libGrafo.h"
#define N 10 


int main() {
	tArco arco;
	tGrafoNoPonderado grafo;					
					
	inicializarGrafo(&grafo );
	
	agregarVertice(&grafo, 2 );
	agregarVertice(&grafo, 3 );
	agregarVertice(&grafo, 4);
	
	arco.origen = 3;
	arco.destino = 2;
	agregarArco( &grafo, arco );
	

	arco.origen = 2;
	arco.destino = 4;
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;
	agregarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo );
		
	visualizarMatrizAdyacencia( grafo );
	
	arco.origen = 3;
	arco.destino = 4;
	borrarArco( &grafo, arco );
	
	visualizarMatrizAdyacencia( grafo );
	
	return 0;
}

