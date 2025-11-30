#include <stdio.h>
#include "libGrafoPonderado.h"

// Programa principal 
int main() {
	tArco arco;
	tGrafoPonderado grafo;					
					
	inicializarGrafo(&grafo );
	
	agregarVertice(&grafo, 2 );
	agregarVertice(&grafo, 3 );
	agregarVertice(&grafo, 4);
	
	arco.origen = 3;
	arco.destino = 2;	
	arco.peso.km= 2;	
	arco.peso.promedioPaciente = 2;
	
	agregarArco( &grafo, arco );
	

	arco.origen = 2;
	arco.destino = 4;
	arco.peso.km = 12;	
	arco.peso.promedioPaciente = 12;
	agregarArco( &grafo, arco );
	
	arco.origen = 3;
	arco.destino = 4;
	arco.peso.km = 22;	
	arco.peso.promedioPaciente = 22;
	agregarArco( &grafo, arco );
	
	visualizarMatrizPeso( grafo );
	
	arco.origen = 3;
	arco.destino = 4;
	arco.peso.km = 22;	
	arco.peso.promedioPaciente = 22;
	borrarArco( &grafo, arco );
	
	visualizarMatrizPeso( grafo );
	
	return 0;
}

