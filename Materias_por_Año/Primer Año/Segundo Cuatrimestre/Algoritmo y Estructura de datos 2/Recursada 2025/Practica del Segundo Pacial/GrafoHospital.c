#include <stdio.h>
#include "tgrafohospital.h"

// Programa principal 
int main() {
	tArcoData arco;
	tGrafoHospital grafo;					
					
	inicializarGrafo(&grafo );
	
    // Agregar vertices
    // 0 = Urgencias, 1 = Quirófanos, 2 = Laboratorios, 3 = Habitaciones
    agregarVertice(&grafo, 0 );
    agregarVertice(&grafo, 1 );
	agregarVertice(&grafo, 2 );
	agregarVertice(&grafo, 3 );
	
// Conectar Urgencias (0) <-> Quirófanos (1)
    dataArco.distanciaMtrs = 10.5;
    dataArco.tiempoMin = 1.0;
    agregarArco(&grafo, 0, 1, dataArco);
    
    // Conectar Urgencias (0) <-> Laboratorios (2)
    dataArco.distanciaMtrs = 30.0;
    dataArco.tiempoMin = 2.5;
    agregarArco(&grafo, 0, 2, dataArco);

    // Conectar Quirófanos (1) <-> Habitaciones (3)
    dataArco.distanciaMtrs = 5.0;
    dataArco.tiempoMin = 0.5;
    agregarArco(&grafo, 1, 3, dataArco);

    // Conectar Laboratorios (2) <-> Habitaciones (3)
    dataArco.distanciaMtrs = 15.2;
    dataArco.tiempoMin = 1.2;
    agregarArco(&grafo, 2, 3, dataArco);

    // Visualizar la matriz resultante
    visualizarMatriz(grafo);
    
    return 0;
}

