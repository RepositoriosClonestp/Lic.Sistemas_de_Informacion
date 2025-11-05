#include<stdio.h>
#include<string.h>
#define N 4

typedef int tVector[N];
typedef int tMatriz[N][N];

typedef struct{
	tVector vertice;
	tMatriz arco;
}tGrafoNoPonderado;

typedef struct{
	int origen;
	int destino;
	int peso;
}tArco;

tGrafoNoPonderado grafo;
tArco arco1;

void inicializarGrafo(tGrafoNoPonderado *);
void agregarVertice(tGrafoNoPonderado *, int);
void agregarArco(tGrafoNoPonderado *, tArco);
void eliminarVertice(tGrafoNoPonderado *, int);
void eliminarArco(tGrafoNoPonderado *, tArco);
void visualizarMatriz(tGrafoNoPonderado);
void visualizarMatrizPeso(tGrafoNoPonderado);

int main (){
	
	inicializarGrafo(&grafo);
	
	agregarVertice(&grafo, 0);	
	agregarVertice(&grafo, 1);
	agregarVertice(&grafo, 2);
	
	arco1.origen=0;
	arco1.destino=1;
	arco1.peso=2;
	agregarArco(&grafo,arco1);
	
	
	arco1.origen=2;
	arco1.destino=3;
	agregarArco(&grafo,arco1);
	
	 visualizarMatrizPeso(grafo);
	
	return 0;
}

void inicializarGrafo(tGrafoNoPonderado * p_Grafo){
	int i,j;
	for(i=0;i<N;i++){
		p_Grafo->vertice[i]= 0;
		for(j=0;j<N;j++){
			
			p_Grafo->arco[i][j]= 0;
		}	
	}
	
	
}

void agregarVertice(tGrafoNoPonderado * pGrafo, int pVertice){
	pGrafo->vertice[pVertice] = 1;
	printf("vertice añadido %d\n", pVertice);
}

void agregarArco(tGrafoNoPonderado * pGrafo, tArco pArco){
	if (pGrafo->vertice [pArco.origen]==1 && pGrafo-> vertice [pArco.destino]==1){
		pGrafo-> arco[pArco.origen] [pArco.destino] = pArco.peso;
		printf("arco agregado\n");
	}
     else{
     	printf("algun vertice no esta activo\n");
     }
}
void eliminarVertice (tGrafoNoPonderado * pGrafo, int pVertice){
	if (pGrafo->vertice [pVertice]!=0){
		pGrafo->vertice [pVertice]=0;
		printf("Se desactivo el Vertice\n");
		
	}else{
		printf("El vertice no esta activo");
	}
}
void eliminarArco(tGrafoNoPonderado * pGrafo, tArco pArco){
	 if	(pGrafo->arco [pArco.origen][pArco.destino]!=0){
	 	pGrafo->arco [pArco.origen][pArco.destino]=0;
		 }else{
		 	printf("El arco que desea borrar no existe");
	}
}
void visualizarMatriz(tGrafoNoPonderado pGrafo){
	int i,j;
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++){
		if (pGrafo.arco[i][j]==1 && pGrafo.vertice[i]==1 &&  pGrafo.vertice[j]==1 ){
			printf("1 ");
			
		}else{
		 	printf("0 ");
		}
	}
	printf("\n");
		
}
}

void visualizarMatrizPeso(tGrafoNoPonderado pGrafo){
	int i,j;
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++){
		if (pGrafo.arco[i][j]>0 && pGrafo.vertice[i]==1 &&  pGrafo.vertice[j]==1 ){
			printf("%d ",pGrafo.arco[i][j]);
			
		}else{
		 	printf("0 ");
		}
	}
	printf("\n");
		
}
}





