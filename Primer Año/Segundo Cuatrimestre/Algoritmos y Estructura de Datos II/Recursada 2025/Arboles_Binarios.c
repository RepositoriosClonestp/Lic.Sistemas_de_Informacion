#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/* Declaración de tipos de datos personalizados */
typedef char tString [25];
 
 
 typedef struct {
	int idProyecto;
	tString nombreProyecto;
	int Cantidad;
} tDatos;
 
typedef struct nodoArbol {
	tDatos datos;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

tArbol * arbol;

/* Declaración de prototipos */
void crearArbolVacio( tArbol ** );
bool arbolVacio( tArbol * );

void insertarElemento( tArbol **, tDatos );

void recorrerEnPreorden( tArbol * );
void recorrerEnPostorden( tArbol * );
void recorrerEnInorden( tArbol * );
bool buscarElemento( tArbol *, int );


tArbol * buscarMin(tArbol *);

void eliminarElemento( tArbol * * , int );

tArbol * buscarMax(tArbol *);
void eliminarElementoOtraManera( tArbol **, int );

/* Declaración de variables */

/* Bloque principal */
int main() {
	tDatos dato;
	
	crearArbolVacio(&arbol);
	
	dato.idProyecto = 410;
	strcpy(dato.nombreProyecto, "Descripcion 410");	
	insertarElemento(&arbol, dato);
	
	dato.idProyecto = 314;
	strcpy(dato.nombreProyecto, "Descripcion 314");	
	insertarElemento(&arbol, dato);
	
	dato.idProyecto = 432;
	strcpy(dato.nombreProyecto, "Descripcion 432");	
	insertarElemento(&arbol, dato);
	
	
	dato.idProyecto = 537;
	strcpy(dato.nombreProyecto, "Descripcion 537");	
	insertarElemento(&arbol, dato);
	
	dato.idProyecto = 843;
	strcpy(dato.nombreProyecto, "Descripcion 843");	
	insertarElemento(&arbol, dato);
		
	dato.idProyecto = 51;
	strcpy(dato.nombreProyecto, "Descripcion 51");	
	insertarElemento(&arbol, dato);
		
	dato.idProyecto = 129;
	strcpy(dato.nombreProyecto, "Descripcion 129");	
	insertarElemento(&arbol, dato);
	
	printf("#########recorrerEnPreorden###############\n");
	recorrerEnPreorden(arbol); 
	
	printf("#########recorrerEnInorden###############\n");
	recorrerEnInorden(arbol); 
	
	printf("#########recorrerEnPostorden###############\n");
	recorrerEnPostorden(arbol); 
	//printf("########################\n");
	
	//eliminarElemento(&arbol, 80);
	//eliminarElementoOtraManera(&arbol, 80);
	
	//printf("########################\n");
	//recorrerEnPreorden(arbol); 
	
	return 0;
}

/* Implementación de funciones */
void crearArbolVacio( tArbol ** pArbol ) {	
	*pArbol = NULL;
	printf("Arbol vacio creado!\n");
}

bool arbolVacio( tArbol * pArbol ) {
	return pArbol == NULL;
}

void insertarElemento( tArbol ** pArbol, tDatos pDatos ) {
	if( arbolVacio(*pArbol) ) {
		/* Reservar memoria para el nodo y asignarle valores */
		(*pArbol) = (tArbol *) malloc(sizeof(tArbol));
	
		if( *pArbol == NULL ) {
			printf("No hay espacio disponible!\n");
		} else {
			/* Asignar valores al nodo */
			(*pArbol)->datos = pDatos;
			(*pArbol)->hijoIzquierdo = NULL;
			(*pArbol)->hijoDerecho = NULL;
		}
		
	}else {
		
		/* Definir para qué lado continuar recorriendo */
		if( pDatos.idProyecto > (*pArbol)->datos.idProyecto ) {
			insertarElemento( &(*pArbol)->hijoDerecho, pDatos);
		}else{
			if( pDatos.idProyecto < (*pArbol)->datos.idProyecto ) {
				insertarElemento( &(*pArbol)->hijoIzquierdo, pDatos);
			} else {
				/* El valor ya existe */
				printf("Elemento duplicado!\n");
			}	
		}		
	}
}


//################# Buscar
bool buscarElemento( tArbol * pArbol, int pidProyecto ) {
	if( arbolVacio(pArbol) ) {
		return false;		
	} else {
		if( pidProyecto > pArbol->datos.idProyecto ) {
			buscarElemento(pArbol->hijoDerecho, pidProyecto);
		}else{
			if( pidProyecto < pArbol->datos.idProyecto ) {
				buscarElemento(pArbol->hijoIzquierdo, pidProyecto);
			}else{
				return true;
			}
		}
	}
}


tDatos buscarElemento2( tArbol * pArbol, int pidProyecto ) {
	if( arbolVacio(pArbol) ) {
		tDatos aux;
		return aux;		
	} else {
		if( pidProyecto > pArbol->datos.idProyecto ) {
			buscarElemento(pArbol->hijoDerecho, pidProyecto);
		}else{
			if( pidProyecto < pArbol->datos.idProyecto ) {
				buscarElemento(pArbol->hijoIzquierdo, pidProyecto);
			}else{
				return pArbol->datos;
			}
		}
	}
}


//################# Recorrido
void recorrerEnPreorden( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) { // pArbol != NULL
		printf("%d - %s\n", pArbol->datos.idProyecto, pArbol->datos.nombreProyecto);
		recorrerEnPreorden(pArbol->hijoIzquierdo);
		recorrerEnPreorden(pArbol->hijoDerecho);
	}
}

void recorrerEnInorden( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) { // pArbol != NULL	
		recorrerEnInorden(pArbol->hijoIzquierdo);
		printf("%d - %s\n", pArbol->datos.idProyecto, pArbol->datos.nombreProyecto);
		recorrerEnInorden(pArbol->hijoDerecho);		
	}
}

void recorrerEnPostorden( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) { // pArbol != NULL	
		recorrerEnPostorden(pArbol->hijoIzquierdo);
		recorrerEnPostorden(pArbol->hijoDerecho);
		printf("%d - %s\n", pArbol->datos.idProyecto, pArbol->datos.nombreProyecto);
	}
}




//################# Eliminar
tArbol * buscarMin( tArbol * pArbol ) {
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

void eliminarElemento( tArbol ** pArbol, int pidProyecto ) {
	tArbol * aux;
	
	if( arbolVacio(*pArbol)) {
		// No existe el nodo que se quiere eliminar
		printf("No existe el elemento que se desea eliminar\n");		
	} else {		
		if( pidProyecto < (*pArbol)->datos.idProyecto ) {
			eliminarElemento( &((*pArbol)->hijoIzquierdo) , pidProyecto);
		} else {
			if( pidProyecto > (*pArbol)->datos.idProyecto ) {
				eliminarElemento( &((*pArbol)->hijoDerecho) , pidProyecto);
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
						(*pArbol)->datos = aux->datos;
						eliminarElemento( &((*pArbol)->hijoDerecho) , (*pArbol)->datos.idProyecto );
					} 										
				}
			}
		}		
	}	
}


//################# Eliminar2

tArbol * buscarMax (tArbol * pArbol ) {
	if( arbolVacio(pArbol)) {
		return NULL;
	} else {
		if( !arbolVacio(pArbol->hijoDerecho)) {
			return buscarMax( pArbol->hijoDerecho );
		}else {
			return pArbol;
		}
	}	
}
void eliminarElementoOtraManera( tArbol ** pArbol, int pidProyecto ) {
	tArbol * aux;
	
	if( arbolVacio(*pArbol)) {
		// No existe el nodo que se quiere eliminar
		printf("No existe el elemento que se desea eliminar\n");		
	} else {		
		if( pidProyecto < (*pArbol)->datos.idProyecto ) {
			eliminarElementoOtraManera( &((*pArbol)->hijoIzquierdo) , pidProyecto);
		} else {
			if( pidProyecto > (*pArbol)->datos.idProyecto ) {
				eliminarElementoOtraManera( &((*pArbol)->hijoDerecho) , pidProyecto);
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
						aux = buscarMax( (*pArbol)->hijoIzquierdo  );
						(*pArbol)->datos = aux->datos;
						eliminarElementoOtraManera( &((*pArbol)->hijoIzquierdo) , (*pArbol)->datos.idProyecto );
					} 										
				}
			}
		}		
	}	
}si
