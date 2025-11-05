/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
///tipos
typedef char tString[25];

typedef struct{
	int codProducto;
	tString descripcion;
	float precio;	
} tProducto;

typedef struct nodo{
	tProducto producto;
	struct nodo * siguiente;
} tListaProductos;
////Prototipos
void inicializarLista();
void ingresarProducto();
void mostrarProducto();
void visualizarElementos( tListaProductos * );


bool listaVacia( tListaProductos * );
void insertarPrimero( tProducto );
void insertarAdelante( tProducto );
void insertarElemento( tProducto );
//variables
tListaProductos * lista;
tProducto producto;

int main()
{
	//inicializar lista
	inicializarLista();
	

	//ingresar datos por teclado
	ingresarProducto();
	//mostrarProducto();
	//insertar producto a la lista
	insertarElemento(producto);
	/////lista esta vacia
		////si es primero
	////mostrar lista
		ingresarProducto();
		insertarElemento(producto);
	visualizarElementos(lista);
	
	
	
	return 0;
}

void inicializarLista() {	
	lista = NULL;
	printf("Lista inicializada\n");
}

void ingresarProducto()
{
	printf("Ingrese codigo de producto \n");
	scanf("%d",&producto.codProducto);
	fflush(stdin);
	
	printf("Ingrese Descripcion \n");
	scanf("%[^\n]s",&producto.descripcion);

	printf("Ingrese Precio \n");
	scanf("%f",&producto.precio);
}

void mostrarProducto()
{
	printf("%d %s %.2f",producto.codProducto,producto.descripcion,producto.precio);
}


void insertarAdelante( tProducto pElem ) {
	/* 1. 	Se crea el nodo que se va a insertar */
	tListaProductos * nuevoNodo;
	/* 2. 	Se asigna memoria al nodo */
	nuevoNodo = ( tListaProductos * ) malloc(sizeof(tListaProductos));
	/* 3. 	Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->producto = pElem;
	/* 4. 	Como la inserción es por la parte de adelante de la lista, 
			se indica que al nuevo nodo le sigue el resto de la lista */
	nuevoNodo->siguiente = lista;		
	/* 5. 	Como en el nuevo nodo quedó la lista completa, nos queda indicar que la lista que se recibe 
			como parámetro es igual a nuevo nodo */
	lista = nuevoNodo;
	printf("Elemento insertado");	

}

void insertarElemento( tProducto pElem ) {
	if ( listaVacia( lista ) ) {
		insertarPrimero( pElem );
	}else {
		insertarAdelante( pElem );
	}		
}

bool  listaVacia( tListaProductos * pLista ) {
	return ( pLista == NULL );
}

void insertarPrimero( tProducto pElem ) {
	/* 1. Se crea el nodo que se va a insertar */
	tListaProductos * nuevoNodo;
	
	/* 2. Se asigna memoria al nodo */
	nuevoNodo = ( tListaProductos * ) malloc(sizeof(tListaProductos));
	
	/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo->producto = pElem;
	
	/* 4. Se indica que el primer nodo apunta a NULL */
	nuevoNodo->siguiente = NULL;
	
	/* 5. Se agrega el nodo a la lista la lista debe apuntar al nuevo nodo */
	lista = nuevoNodo;
	
	printf("Primer elemento insertado");	
}

void visualizarElementos( tListaProductos * pLista ) {
	tListaProductos * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		/* Hay elementos para mostrar */
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("%d %s %.2f \n", aux->producto.codProducto, aux->producto.descripcion, aux->producto.precio);
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}
