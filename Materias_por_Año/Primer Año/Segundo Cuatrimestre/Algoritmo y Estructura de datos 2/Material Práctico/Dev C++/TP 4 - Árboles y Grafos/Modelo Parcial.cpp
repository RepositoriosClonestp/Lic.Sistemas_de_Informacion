#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Declaración de tipos de datos personalizados */
typedef char tString [25];
 
typedef struct {
	int codigo;
	tString descripcion;
	float peso;
	float precio;
} tDatosCompra;

typedef struct nodoArbol {
	tDatosCompra datosCompra;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbolProductos;

tArbolProductos *arbol;

void inicializar(tArbolProductos **);
bool arbolVacio(tArbolProductos *);

void ingresarVenta(tArbolProductos **, tDatosCompra);
void recorrerPreorden(tArbolProductos *);
void inordenMostrarCondicion(tArbolProductos *);
void recorrerPostorden(tArbolProductos *);

tArbolProductos *buscarMin(tArbolProductos *);
void eliminarVenta(tArbolProductos **, int);

int main(){
	tDatosCompra info;
	inicializar(&arbol);
	
	
	info.codigo = 8;
	strcpy(info.descripcion, "Mouse");
	info.peso = 50;
	info.precio = 1001;
	ingresarVenta(&arbol, info);
	
	info.codigo = 3;
	strcpy(info.descripcion, "teclado");
	info.peso = 123;
	info.precio = 210;
	ingresarVenta(&arbol, info);
	
	info.codigo = 1;
	strcpy(info.descripcion, "webcam");
	info.peso = 200;
	info.precio = 1120;
	ingresarVenta(&arbol, info);
	
	inordenMostrarCondicion(arbol);
	eliminarVenta(&arbol, 3);
	printf("---------------\n");
	inordenMostrarCondicion(arbol);
	
	return 0;
}

void inicializar(tArbolProductos ** pArbol){
	*pArbol = NULL;
}

bool arbolVacio(tArbolProductos * pArbol){
	return (pArbol == NULL);
}

void ingresarVenta(tArbolProductos ** pArbol, tDatosCompra pDatos){
	if( arbolVacio(*pArbol) ) {
		/* Reservar memoria para el nodo y asignarle valores */
		(*pArbol) = (tArbolProductos *) malloc(sizeof(tArbolProductos));
	
		if( *pArbol == NULL ) {
			printf("No hay espacio disponible!\n");
		} else {
			/* Asignar valores al nodo */
			(*pArbol)->datosCompra = pDatos;
			(*pArbol)->hijoIzquierdo = NULL;
			(*pArbol)->hijoDerecho = NULL;
		}
	}
	else{
		if (pDatos.codigo > (*pArbol)->datosCompra.codigo){
			ingresarVenta(&(*pArbol)->hijoDerecho, pDatos);
		}
		else{
			if(pDatos.codigo < (*pArbol)->datosCompra.codigo){
				ingresarVenta(&(*pArbol)->hijoDerecho, pDatos);
			}
			else{
				printf(" Elemento duplicado.");
			}
		}
	}
}

tArbolProductos *buscarMin(tArbolProductos *pArbol) {
	if( arbolVacio(pArbol)) {
		return NULL;
	} else {
		if( !arbolVacio(pArbol->hijoIzquierdo)) {
			return buscarMin( pArbol->hijoIzquierdo );
		}else {
			return pArbol;
		}
	}	
}

void eliminarVenta( tArbolProductos ** pArbol, int pCodigo ) {
	tArbolProductos * aux;
	if(arbolVacio(*pArbol)) {
		printf("No existe el elemento que se desea eliminar\n");		
	}  
	else{		
		if( pCodigo < (*pArbol)->datosCompra.codigo ) {
			eliminarVenta( &((*pArbol)->hijoIzquierdo) , pCodigo);
		} else {
			if( pCodigo > (*pArbol)->datosCompra.codigo ) {
				eliminarVenta( &((*pArbol)->hijoDerecho) , pCodigo);
			} else {
				// Se encontró el nodo que se desea eliminar
				if( (*pArbol)->hijoIzquierdo == NULL) {
					/* Por acá se eliminaría si es una hoja o si tiene un hijo derecho */
					aux = *pArbol;
					*pArbol = (*pArbol)->hijoDerecho;
					free(aux);
				} else {
					if( (*pArbol)->hijoDerecho == NULL) {
						/* Por acá se eliminaría si tiene un hijo izquierdo */
						aux = *pArbol;
						*pArbol = (*pArbol)->hijoIzquierdo;
						free(aux);
					} else {
						// significa que el nodo por eliminar tiene 2 hijos
						aux = buscarMin( (*pArbol)->hijoDerecho  );
						(*pArbol)->datosCompra = aux->datosCompra;
						eliminarVenta( &((*pArbol)->hijoDerecho) , (*pArbol)->datosCompra.codigo );
					} 										
				}
			}
		}		
	}	
}

void inordenMostrarCondicion( tArbolProductos * pArbol ) {
	if( !(arbolVacio(pArbol)) ) { // pArbol != NULL	
		if ((pArbol->datosCompra.peso > 100) || (pArbol->datosCompra.precio > 1000)){
			printf("%d - %s - %.2f - %.2f\n", pArbol->datosCompra.codigo, pArbol->datosCompra.descripcion, pArbol->datosCompra.peso, pArbol->datosCompra.precio);
		}
		inordenMostrarCondicion(pArbol->hijoIzquierdo);
		inordenMostrarCondicion(pArbol->hijoDerecho);	
	}
}
