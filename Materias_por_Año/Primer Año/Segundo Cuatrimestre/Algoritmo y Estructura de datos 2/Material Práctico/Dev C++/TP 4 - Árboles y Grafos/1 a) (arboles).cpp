#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int codigo;
}tDatos;

typedef struct nodoArbol{
	tDatos datos;
	struct nodoArbol *hijoIzquierdo;
	struct nodoArbol *hijoDerecho;
}tArbol;

void inicializar(tArbol **);
bool arbolVacio(tArbol *);

void ingresar(tArbol **, tDatos);
void recorrerPreorden(tArbol *);
void recorrerInorden(tArbol *);
void recorrerPostorden(tArbol *);

tArbol buscarMin(tArbol *);
void elimiar(tArbol **, int);

int main(){
	tDatos info, info2;
	tArbol *arbol;
	
	info.codigo = 54;
	info2.codigo = -72;
	
	inicializar(&arbol);
	ingresar(&arbol, info);
	ingresar(&arbol, info2);
	recorrerPreorden(arbol);
	
	return 0;
}

void inicializar(tArbol ** pArbol){
	*pArbol = NULL;
}

bool arbolVacio(tArbol * pArbol){
	return pArbol == NULL;
}

void ingresar(tArbol ** pArbol, tDatos pDatos){
	if (arbolVacio(*pArbol)){
		(*pArbol) = (tArbol *) malloc(sizeof(tArbol));
		
		(*pArbol)->datos = pDatos;
		(*pArbol)->hijoIzquierdo = NULL;
		(*pArbol)->hijoDerecho = NULL;
	}
	else{
		if (pDatos.codigo > (*pArbol)->datos.codigo){
			ingresar(&(*pArbol)->hijoDerecho, pDatos);
		}
		else{
			if(pDatos.codigo < (*pArbol)->datos.codigo){
				ingresar(&(*pArbol)->hijoDerecho, pDatos);
			}
			else{
				printf(" Elemento duplicado.");
			}
		}
	}
}

void recorrerPreorden( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) { // pArbol != NULL
		printf("%d \n", pArbol->datos.codigo);
		recorrerPreorden(pArbol->hijoIzquierdo);
		recorrerPreorden(pArbol->hijoDerecho);
	}
}





















