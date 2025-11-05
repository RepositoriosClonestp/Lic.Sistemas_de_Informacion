#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <stdlib.h>

/*definiciones*/
#define N 4


/*tipo de datos*/
typedef tvector[N];
typedef tmatriz[N][N];

typedef struct{
	tmatriz arco;
	tvector vertice;
}tgrafo;

typedef struct{
	int origen;
	int destino;
	
}tarco;

/*variables*/
tgrafo grafo;
tarco arco;

/*prototipos*/
void inicializar_grafo(tgrafo *);
void agregar_vertice(tgrafo *, int);
void agregar_arco(tgrafo *, tarco);
void eliminar_vertice(tgrafo *, int);
void eliminar_arco(tgrafo *, tarco);

void visualizar_matriz(tgrafo);

/*bloque primcipal*/
int main(){
	
	inicializar_grafo( &grafo );
	
	agregar_vertice( &grafo, 0 );
	agregar_vertice( &grafo, 1 );
	agregar_vertice( &grafo, 2 );
	
	arco.origen = 0;
	arco.destino = 1;
	agregar_arco(&grafo, arco);
	
	arco.origen = 2;
	arco.destino = 3;
	agregar_arco(&grafo, arco);
	
	visualizar_matriz(grafo);
	
	return 0;
}

/*funciones*/
void inicializar_grafo(tgrafo * pgrafo){
	int i, j;
	
	for(i = 0; i < N; i++){
		
		pgrafo->vertice[i] = 0;
		
		for(j = 0; j < N; j++){
			
			
			pgrafo -> arco[i][j] = 0;
			
			
		}
		
	}
	
}



void agregar_vertice(tgrafo * pgrafo, int pvertice){
	
	pgrafo -> vertice[pvertice] = 1;
	
	printf("vertice añadido %d \n", pvertice);
	
}



void agregar_arco(tgrafo * pgrafo, tarco parco){
	
	if( pgrafo -> vertice[parco.origen] == 1 && pgrafo -> vertice[parco.destino] == 1 ){
		
		pgrafo -> arco[parco.origen] [parco.destino];
		
	}
	else{
		
		printf("algun vertice no esta activo \n");
		
	}
	
}



void eliminar_vertice(tgrafo * pgrafo, int pvertice){
	
	if( pgrafo -> vertice[pvertice] != 0 ){
		
		pgrafo -> vertice[pvertice] = 0;
		
		printf("se desactivo el vertice \n");
		
	}
	else{
		
		printf("el vertice no esta activo \n");
		
	}
	
}



void eliminar_arco( tgrafo * pgrafo, tarco parco ){
	
	if( pgrafo -> arco[parco.origen] [parco.destino] != 0 ){
		
		pgrafo -> arco[parco.origen] [parco.destino] = 0;
		
		printf("arco borrado \n");
		
	}
	else{
		
		printf("el arco que desea borrar no existe \n");
		
	}
	
}



void visualizar_matriz( tgrafo pgrafo ){
	
	int i, j;
	
	for( i = 0; i < N; i++ ){
		
		
		
		for( j = 0; j < N; j++ ){
			
			if ( pgrafo.arco[i][j] < 1 && pgrafo.vertice[i] == 1 && pgrafo.vertice[j] == 1 ){
				
				printf("| 1 |");
				
			}
			else{
				
				printf("| 0 |");
				
			}
			
		}
		
		printf("\n");
		
	}
	
	
	
}


