/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Declaracion de tipos de datos personalizados */
typedef char tString[25];

typedef struct {
	int codigo;
	tString descripcion;	
} tElem;

typedef struct nodo {
	tElem info;
	struct nodo * siguiente;
} tLista;

/* 	Declaracion de prototipos de funciones 
	asociadas a las operaciones que se puede realizar 
	con la lista */
void inicializarLista();
bool listaVacia( tLista * );

void insertarPrimero( tElem );
void insertarAdelante( tElem );
void insertarElemento( tElem );

void eliminarPrimero();

void visualizarElementos( tLista * );

void insertarEnPos( int, tElem );

void eliminarEnPos( int );

int cantidadNodos( tLista * );

/* Declaracion de variables globales*/
tLista * lista;

/* Funci�n principal */
int main() {	
	tElem data;
	
	inicializarLista();
	
	printf("Esta vacia? %s\n", listaVacia(lista) == true ? "si" : "no" );
	
	data.codigo = 111;
	strcpy(data.descripcion, "Papas fritas");	
	insertarElemento(data);
	
	data.codigo = 222;
	strcpy(data.descripcion, "Hamburguesa");	
	insertarElemento(data);
	
	printf("Esta vacia? %s\n", listaVacia(lista) == true ? "si" : "no" );
	
	visualizarElementos(lista);
	
	/* eliminarPrimero(); */
	
	data.codigo = 333;
	strcpy(data.descripcion, "Milanesa");
	insertarElemento(data);
	
	data.codigo = 444;
	strcpy(data.descripcion, "Coca Cola");
	insertarElemento(data);
	visualizarElementos(lista);
	
	data.codigo = 555;
	strcpy(data.descripcion, "Alfajor");
	insertarEnPos(4, data);
	
	visualizarElementos(lista);
	
	data.codigo = 558;
	strcpy(data.descripcion, "Alikal");
	insertarEnPos(3, data);
	
	visualizarElementos(lista);
	
	eliminarEnPos(3);
	
	visualizarElementos(lista);
	
	eliminarEnPos(1);
	visualizarElementos(lista);
	
	return 0;
}

/* Implementacion de funciones */
void inicializarLista() {	
	lista = NULL;
	printf("Lista inicializada\n");
}

bool  listaVacia( tLista * pLista ) {
	return ( pLista == NULL );
}

void insertarPrimero( tElem pElem ) {
	/* 1. Se crea el nodo que se va a insertar */
	tLista * nuevoNodo;
	
	/* 2. Se asigna memoria al nodo */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = pElem;
	
	/* 4. Se indica que el primer nodo apunta a NULL */
	nuevoNodo->siguiente = NULL;
	
	/* 5. Se agrega el nodo a la lista la lista debe apuntar al nuevo nodo */
	lista = nuevoNodo;
	
	printf("Primer elemento insertado: %d-%s\n", pElem.codigo, pElem.descripcion);	
}

void insertarAdelante( tElem pElem ) {
	/* 1. 	Se crea el nodo que se va a insertar */
	tLista * nuevoNodo;
	
	/* 2. 	Se asigna memoria al nodo */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 3. 	Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = pElem;
	
	/* 4. 	Como la inserci�n es por la parte de adelante de la lista, 
			se indica que al nuevo nodo le sigue el resto de la lista */
	nuevoNodo->siguiente = lista;
			
	/* 5. 	Como en el nuevo nodo qued� la lista completa, nos queda indicar que la lista que se recibe 
			como par�metro es igual a nuevo nodo */
	lista = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", pElem.codigo, pElem.descripcion);	

}

void insertarElemento( tElem pElem ) {
	if ( listaVacia( lista ) ) {
		insertarPrimero( pElem );
	}else {
		insertarAdelante( pElem );
	}		
}

void eliminarPrimero() {
	if ( listaVacia( lista ) ) {
		printf("No hay elementos para quitar!\n");
	} else {
		/* 1. Se guarda en una variable auxiliar el primer nodo de la lista */
		tLista * nodoSuprimir = lista;
	
		/* 2. Se avanza el puntero una vez, es decir se pasa al siguiente nodo de la lista */
		lista = lista->siguiente;
		
		printf("Primer elemento eliminado: %d-%s\n", nodoSuprimir->info.codigo, nodoSuprimir->info.descripcion );	
	
		/* 3. Se libera la memoria del nodo a suprimir que conten�a el primer elemento de la lista */
		free(nodoSuprimir);
		
		/* 4. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
		nodoSuprimir = NULL;
	}
	
}

void visualizarElementos( tLista * pLista ) {
	tLista * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		/* Hay elementos para mostrar */
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("%d-%s\n", aux->info.codigo, aux->info.descripcion);
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}

void insertarEnPos( int pos, tElem nuevoDato ) {
	int i;
	tLista * aux, * nuevoNodo;
	
	/* 1.Se debe utilizar una lista auxiliar aux */
	aux = lista;
	
	/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1 */
	for(i=1; i<pos-1; i++ ) {
		aux = aux->siguiente;
	}
	
	/* 3. Reservar memoria para el nodo a insertar */
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	
	/* 4. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->info = nuevoDato;

	/* 5. Se actualizan los punteros */
	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", nuevoDato.codigo, nuevoDato.descripcion);	
}

void eliminarEnPos( int pos ) {
	int i, cantNodos;
	tLista * aux, * nodoSuprimir;
	
	/* 0. Validar posici�n */
	cantNodos = cantidadNodos( lista );
	
	if( pos <= cantNodos && pos > 0 ) {
		
		if( pos == 1 ) {
			eliminarPrimero();
		} else {
			/* 1. Se debe utilizar una lista auxiliar aux */
			aux = lista;
			
			/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1 */
			for(i=1; i<pos-1; i++ ) {
				aux = aux->siguiente;
			}
			
			/* 3. Se resguarda el nodo que se va a suprimir en una variable auxiliar */
			nodoSuprimir = aux->siguiente;
		
			/* 4. Se indica a qu� nodo tiene que apuntar aux: al siguiente del que se va a eliminar */
			aux->siguiente = nodoSuprimir->siguiente;
			
			printf("Elemento eliminado: %d-%s\n", nodoSuprimir->info.codigo, nodoSuprimir->info.descripcion );	
				
			/* 5. Se libera la memoria del nodo a suprimir que conten�a el elemento de la posici�n pos de la lista */
			free(nodoSuprimir);
				
			/* 6. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
			nodoSuprimir = NULL;
		}	
	} else {
		printf("\nPosicion invalida\n");
	}	
}

int cantidadNodos( tLista * pLista ) {
	tLista * aux;
	int contador = 0;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		while(aux != NULL) {
			contador++;
			aux = aux->siguiente;
		}		
	}
	return contador;
}

