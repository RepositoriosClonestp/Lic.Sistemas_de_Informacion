/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Declaración de tipos de datos personalizados */
typedef char tString [25];
 
typedef struct {
	int nroTurno;
	tString nombre;
	tString apellido;
	int tipoConsulta;
	tString hora;
} tDatos;

typedef struct nodo {
	tDatos turno;
	struct nodo * siguiente;
}tTurnos;

/* Declaración de variables globales*/
tTurnos * lista;


void inicializarLista();
bool listaVacia( tTurnos * );

void insertarPrimero( tDatos );
void insertarAdelante( tDatos );
void insertarElemento( tDatos );

void ingresarDatosProduto();

void eliminarPrimero();

void visualizarElementos( tTurnos * );
void visualizarSegunTipo( tTurnos *, int  ) ;
void insertarEnPos( int, tDatos );

void eliminarEnPos( int );

int cantidadNodos( tTurnos * );

/* Declaración de variables globales*/
tTurnos * lista;

tDatos turno;
	
tString vectorNombre [4]={"","haberes ","Maternidad ","Obra Social"};
/* Función principal */
int main() {	
	
	inicializarLista();
	
	turno.nroTurno = 1111;	
	turno.tipoConsulta = 1;
	strcpy(turno.nombre, "nombre 1");
	insertarElemento(turno);
		
	turno.nroTurno = 3333;
	turno.tipoConsulta = 2;
	strcpy(turno.nombre, "nombre 3");	
	insertarElemento(turno);
	
	turno.nroTurno = 4444;
	turno.tipoConsulta = 3;
	strcpy(turno.nombre, "nombre 4");
	insertarElemento(turno);
	
		
	turno.nroTurno = 55555;
	turno.tipoConsulta = 1;
	strcpy(turno.nombre, "nombre 5");
	insertarElemento(turno);

	
	turno.nroTurno = 2222;
	turno.tipoConsulta = 1;
	strcpy(turno.nombre, "nombre 2");
	insertarEnPos( 4, turno ) ;
	
	visualizarElementos(lista);

	visualizarSegunTipo(lista, 1);
	
	return 0;
}

void ingresarDatosProduto(){
	printf("\ningrese el nroTurno del producto :");
	scanf("%d",&turno.nroTurno);
	printf("\ningrese la nombre del producto :");
	scanf("%s",&turno.nombre);
}

/* Implementación de funciones */
void inicializarLista() {	
	lista = NULL;
	printf("Lista inicializada\n");
}

bool  listaVacia( tTurnos * pLista ) {
	return ( pLista == NULL );
}

void insertarPrimero( tDatos pElem ) {
	/* 1. Se crea el nodo que se va a insertar */
	tTurnos * nuevoNodo;
	
	/* 2. Se asigna memoria al nodo */
	nuevoNodo = ( tTurnos * ) malloc(sizeof(tTurnos));
	
	/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->turno = pElem;
	
	/* 4. Se indica que el primer nodo apunta a NULL */
	nuevoNodo->siguiente = NULL;
	
	/* 5. Se agrega el nodo a la lista la lista debe apuntar al nuevo nodo */
	lista = nuevoNodo;
	
	printf("Primer elemento insertado: %d-%s-%d\n", pElem.nroTurno, pElem.nombre, pElem.tipoConsulta);	
}

void insertarAdelante( tDatos pElem ) {
	/* 1. 	Se crea el nodo que se va a insertar */
	tTurnos * nuevoNodo;
	
	/* 2. 	Se asigna memoria al nodo */
	nuevoNodo = ( tTurnos * ) malloc(sizeof(tTurnos));
	
	/* 3. 	Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->turno = pElem;
	
	/* 4. 	Como la inserción es por la parte de adelante de la lista, 
			se indica que al nuevo nodo le sigue el resto de la lista */
	nuevoNodo->siguiente = lista;
			
	/* 5. 	Como en el nuevo nodo quedó la lista completa, nos queda indicar que la lista que se recibe 
			como parámetro es igual a nuevo nodo */
	lista = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", pElem.nroTurno, pElem.nombre);	

}

void insertarElemento( tDatos pElem ) {
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
		tTurnos * nodoSuprimir = lista;
	
		/* 2. Se avanza el puntero una vez, es decir se pasa al siguiente nodo de la lista */
		lista = lista->siguiente;
		
		printf("Primer elemento eliminado: %d-%s\n", nodoSuprimir->turno.nroTurno, nodoSuprimir->turno.nombre );	
	
		/* 3. Se libera la memoria del nodo a suprimir que contenía el primer elemento de la lista */
		free(nodoSuprimir);
		
		/* 4. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
		nodoSuprimir = NULL;
	}
	
}

void visualizarElementos( tTurnos * pLista ) {
	tTurnos * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		/* Hay elementos para mostrar */
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("%d-%s-%d\n", aux->turno.nroTurno, aux->turno.nombre, aux->turno.tipoConsulta);
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}

void insertarEnPos( int pos, tDatos nuevoDato ) {
	int i;
	tTurnos * aux, * nuevoNodo;
	
	aux = lista;
	
	for(i=1; i<pos-1; i++ ) {
		aux = aux->siguiente;
	}
	
	nuevoNodo = ( tTurnos * ) malloc(sizeof(tTurnos));
	
	nuevoNodo->turno = nuevoDato;

	nuevoNodo->siguiente = aux->siguiente;
	aux->siguiente = nuevoNodo;
	
	printf("Elemento insertado: %d-%s\n", nuevoDato.nroTurno, nuevoDato.nombre);	
}

void eliminarEnPos( int pos ) {
	int i, cantNodos;
	tTurnos * aux, * nodoSuprimir;
	
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
		
			/* 4. Se indica a qué nodo tiene que apuntar aux: al siguiente del que se va a eliminar */
			aux->siguiente = nodoSuprimir->siguiente;
			
			printf("Elemento eliminado: %d-%s\n", nodoSuprimir->turno.nroTurno, nodoSuprimir->turno.nombre );	
				
			/* 5. Se libera la memoria del nodo a suprimir que contenía el elemento de la posición pos de la lista */
			free(nodoSuprimir);
				
			/* 6. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
			nodoSuprimir = NULL;
		}	
}



void visualizarSegunTipo( tTurnos * pLista, int pTipoConsulta ) {
	tTurnos * aux;
	aux = pLista;
	int cantidad=0;
	
	if( !listaVacia(aux) ) {
		/* Hay elementos para mostrar */
		printf("\n*** Elementos en la lista segun tipo %s***\n",vectorNombre[pTipoConsulta]);
		while(aux != NULL) {
			if(aux->turno.tipoConsulta==pTipoConsulta){
				printf("%d-%s\n", aux->turno.nroTurno, aux->turno.nombre);
				
				cantidad= cantidad+1;
			}
			
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
		printf("Total: %d\n",cantidad);
}
