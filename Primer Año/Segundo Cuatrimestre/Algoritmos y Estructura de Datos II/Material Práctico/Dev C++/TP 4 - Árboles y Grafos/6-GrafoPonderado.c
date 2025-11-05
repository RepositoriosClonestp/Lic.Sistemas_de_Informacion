/*
6. Escribe en lenguaje c, la declaración de un tipo de dato tGrafoPonderado para un grafo ponderado de
hasta 10 vértices, donde el peso corresponde a kg. Utilizar la implementación de grafos con arrays.
Además, escribir las funciones para:
a) iniciar el grafo
b) agregar un vértice al grafo
c) agregar un arco al grafo
d) visualizar la matriz de pesos
*/

#include <stdio.h>
#include <stdbool.h>

#define VERTICES 10

typedef int tVertice;

typedef struct {
	tVertice origen;
	tVertice destino;
	float peso;
} tArista;

typedef int conjuntoVertices[VERTICES];
typedef float conjuntoAristas [VERTICES] [VERTICES];

typedef struct {
	conjuntoVertices vertices;
	conjuntoAristas aristas;
} tGrafoPonderado;

tGrafoPonderado grafo;
tArista arista;

void inicializarGrafo(tGrafoPonderado *);

void agregarVertice(tGrafoPonderado *, tVertice);
void agregarArista(tGrafoPonderado *, tArista);
void borrarArista(tGrafoPonderado *, tArista);
void borrarVertice(tGrafoPonderado *, tVertice);

void visualizarMatrizGrafo(tGrafoPonderado);
int maxVertices(tGrafoPonderado);
bool existeVertice(tGrafoPonderado, int);

void menu();

int main() {
	inicializarGrafo(&grafo);
	menu();
	
	return 0;
}

void inicializarGrafo(tGrafoPonderado *pGrafo) {
	int i, j;
	
	for (i = 0; i < VERTICES; i++) {
		pGrafo->vertices[i] = 0;
		
		for (j = 0; j < VERTICES; j++) {
			pGrafo->aristas[i] [j] = 0.0;
		}
	}
}

void agregarVertice(tGrafoPonderado *pGrafo, tVertice pVertice) {
	if (existeVertice(*pGrafo, pVertice) == false) {
		pGrafo->vertices[pVertice] = pVertice;		
		printf("\n***Vertice Agregado***\n\n");
	}
	else {
		printf("\n***Vertice Ya Existente***\n\n");
	}
}

void agregarArista(tGrafoPonderado *pGrafo, tArista pArista) {
	if (existeVertice(*pGrafo, pArista.origen) == true && existeVertice(*pGrafo, pArista.destino) == true) {
		pGrafo->aristas[pArista.origen] [pArista.destino] = pArista.peso;
		printf("\n***Arista Agregada***\n\n");
	}
	else {
		if (existeVertice(*pGrafo, pArista.origen) == false) {
			printf("\n***Vertice Origen Inexistente***\n\n");
		}
		else {
			printf("\n***Vertice Destino Inexistente***\n\n");
		}
	}
}

void borrarArista(tGrafoPonderado *pGrafo, tArista pArista) {
	if (pGrafo->aristas[pArista.origen] [pArista.destino] != 0) {
		pGrafo->aristas[pArista.origen] [pArista.destino] = 0.0;	
		printf("\n***Arista Eliminada***\n\n");		
	}
	else {
		printf("\n***Arista Inexistente***\n\n");
	}
}

void borrarVertice(tGrafoPonderado *pGrafo, tVertice pVertice) {
	if (existeVertice(*pGrafo, pVertice) == true) {
		pGrafo->vertices[pVertice] = 0;	
		printf("\n***Vertice Eliminado***\n\n");
	}
	else {
		printf("\n***Vertice Inexistente***\n\n");
	}
}

void visualizarMatrizGrafo(tGrafoPonderado pGrafo) {
	int i, j, maxVer;
	maxVer = 0;
	maxVer = maxVertices(pGrafo);
	
	if (maxVer > 0) {
		printf("\n");
		printf("  ");
		for (i = 1; i <= maxVer; i++) {
			printf(" %d  ", i);
		}
	
		printf("\n");
	
		for (i = 1; i <= maxVer; i++) {
			printf("%d ", i);
			for (j = 1; j <= maxVer; j++) {
				if (pGrafo.aristas[i] [j] > 0 && existeVertice(pGrafo, i) == true && existeVertice(pGrafo, j) == true) {
					printf("%.1f ", pGrafo.aristas[i] [j]);	
				}
				else {
					printf("0.0 ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	else {
		printf("\n***Matriz Inexistente***\n\n");
	}
}

int maxVertices(tGrafoPonderado pGrafo) {
	int i, max = 0;

	for (i = 0; i < VERTICES; i++) {
		if (pGrafo.vertices[i] != 0) {
			max = i;
		}
	}
	
	return max;
}

bool existeVertice(tGrafoPonderado pGrafo, tVertice pVertice) {
	return pGrafo.vertices[pVertice] != 0;
}

void menu() {
	int option;
	tVertice numVer;
	tArista numArista;
	
	printf("Ingrese (1-Agregar Vertice, 2-Agregar Arista, 3-Borrar Vertice, 4-Borrar Arista, 5-Visualizar Matriz): ");
	scanf("%d", &option);
	
	switch (option) {
		case 1:
			printf("\n---Cargar Vertice (Entre 1 y %d): ", VERTICES);
			scanf("%d", &numVer);
			
			agregarVertice(&grafo, numVer);
			menu();
			break;
			
		case 2:
			printf("\n***Cargar Arista***\n");
			
			printf("\tVertice Origen: ", VERTICES);
			scanf("%d", &numArista.origen);
			
			printf("\tVertice Destino: ", VERTICES);
			scanf("%d", &numArista.destino);
			
			printf("\tPeso de la Arista: ");
			scanf("%f", &numArista.peso);
			
			agregarArista(&grafo, numArista);
			menu();
			break;
			
		case 3:
			printf("\n---Vertice a Borrar: ", VERTICES);
			scanf("%d", &numVer);
			
			borrarVertice(&grafo, numVer);
			menu();
			break;
			
		case 4:
			printf("\n***Arista a Borrar***\n");
			
			printf("\tVertice Origen (Entre 1-%d): ", VERTICES);
			scanf("%d", &numArista.origen);
			
			printf("\tVertice Destino (Entre 1-%d): ", VERTICES);
			scanf("%d", &numArista.destino);
			
			borrarArista(&grafo, numArista);
			menu();
			break;
			
		case 5:
			visualizarMatrizGrafo(grafo);
			menu();
			break;
		
		default:
			printf("\nERROR\n");
	}
}

