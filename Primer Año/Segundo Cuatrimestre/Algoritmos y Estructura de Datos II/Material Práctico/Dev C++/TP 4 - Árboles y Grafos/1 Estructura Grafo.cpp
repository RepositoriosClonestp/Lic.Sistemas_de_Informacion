#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

const int N = 5;

typedef int tVector[N];
typedef int tMatriz[N][N];

typedef struct{
	tVector vertices;
	tMatriz arcos;
}tGrafoNP;

typedef struct{
	int origen;
	int destino;
}tArco;

tGrafoNP grafo;
tArco arco;

void inicializarGrafo(tGrafoNP *);
void agregarVertice(tGrafoNP *, int);
void agregarArco(tGrafoNP *, tArco);
void eliminarVertice(tGrafoNP *, int);
void eliminarArco(tGrafoNP *, tArco);
void visualizarMatriz(tGrafoNP);
// Funcion que diga si vector a, esta conectado con algun vector b, o si a no tiene conexion con otros vectores

int main(){
	inicializarGrafo(&grafo);
	
	agregarVertice(&grafo, 0);
	agregarVertice(&grafo, 1);
	agregarVertice(&grafo, 2);
	
	arco.origen = 2;
	arco.destino = 1;
	agregarArco(&grafo, arco);
	arco.origen = 0;
	arco.destino = 1;
	agregarArco(&grafo, arco);
	visualizarMatriz(grafo);
	
	return 0;
}

void inicializarGrafo(tGrafoNP *pGrafo){
	int i, j;
	for(i=0; i<N; i++){
		pGrafo->vertices[i] = 0;
		for(j=0; i<N; i++){
			pGrafo->arcos[i][j]= 0;
		}
	}
}

void agregarVertice(tGrafoNP *pGrafo, int pVertice){
	pGrafo->vertices[pVertice] = 1;
}

void agregarArco(tGrafoNP *pGrafo, tArco pArco){
	if( (pGrafo->vertices[pArco.origen] == 1) && (pGrafo->vertices[pArco.destino] == 1) ){
		pGrafo->arcos[pArco.origen][pArco.destino] = 1;
	}
	else{
		printf("\n No se puede crear arco. Vertices: %d o %d o ambos no existen \n", pArco.origen, pArco.destino);
	}
}

void eliminarVertice(tGrafoNP *pGrafo, int pVertice){
	if(pGrafo->vertices[pVertice] == 1){
		pGrafo->vertices[pVertice] = 0;
		printf("\n Vertice %d eliminado.\n", pVertice);
	}
	else{
		printf("\n No existe vertice a eliminar. \n");
	}
}

void eliminarArco(tGrafoNP *pGrafo, tArco pArco){
	if(pGrafo->arcos[pArco.origen][pArco.destino] == 1){
		pGrafo->arcos[pArco.origen][pArco.destino] = 0;
		printf("\n Arco %d, %d eliminado. \n", pArco.origen, pArco.destino);
	}
	else{
		printf("\n No existe arco a eliminar. \n");
	}
}

void visualizarMatriz(tGrafoNP pGrafo){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if( (pGrafo.vertices[i] == 1) && (pGrafo.vertices[j] == 1) && (pGrafo.arcos[i][j] == 1) ){
				printf("1 ");
			}
			else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}


















