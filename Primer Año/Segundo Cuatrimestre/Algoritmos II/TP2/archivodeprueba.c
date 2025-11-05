/*2. Modificar el ejercicio 1 para que se puedan realizar todas las operaciones básicas para el manejo de una
lista enlazada:
a) Generar o inicializar la lista.
b) Función para determinar si una lista está vacía.
c) Insertar el primer producto (nodo) de la lista.
d) Insertar un producto al principio de la lista.
e) Eliminar el primer producto de la lista.
f) Insertar un producto en una determinada posición dentro de la lista.
g) Eliminar un producto de una determinada posición de la lista.
h) Visualizar todos los datos de los productos que están en la lista.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



/* Declaración de tipos de datos personalizados */
typedef char tString[50];
typedef struct {
	int codProducto;
	tString descripcion;
	float pUnit;	
} tProducto;

/*ESTRUCTURA (LISTA) AUTOREFERENCIADA NODO*/
typedef struct nodo {
	tProducto producto;
	struct nodo * siguiente;/* siguiente es un campoPUNTERO AL TIPO DE DATO QUE ESTOY CREANDO*/
} tListaProductos;



tListaProductos * lista;
tProducto producto;


void inicializarLista();
void ingresarProduc();
void insertarElemento(tProducto);
void insertarPrimero(tProducto);
void insertarAdelante(tProducto);

void eliminarPrimero();
void insertarK();
void eliminarK();

void visualizar(tListaProductos * );
bool listaVacia(tListaProductos); 

int contNodos( tListaProductos * );


int main(){

		inicializarLista();
		
	
		ingresarProduc();
		insertarElemento(producto);
		
	ingresarProduc();
		insertarElemento(producto);

		eliminarPrimero();
		insertarK();
				ingresarProduc();
		insertarElemento(producto);
	    
		insertarK();
		eliminarK();
				
		visualizar(lista);
		
		
   return 0;
}

/*  A) INICIALIZAR LISTA*/
void inicializarLista() {
	lista = NULL;
	printf("Lista inicializada\n");
}


void ingresarProduc(){/* &producto. con esto paso como info del nodo*/
	
	printf("Codigo del producto: ");
	scanf("%d",&producto.codProducto);
	fflush(stdin);
	
	printf("\nDescripcion del producto: ");
	scanf("%[^\n]s",&producto.descripcion);
	fflush(stdin);
	
	printf("\nPrecio unitario del producto: ");
	scanf("%f",&producto.pUnit);

}

/*  B) DETERMINAMOS SI LA FUNCION ESTA VACIA*/
bool listaVacia(tListaProductos  pListaProductos){
	return (pListaProductos = NULL);
}


void insertarElemento(tProducto pProd){
	
	if(listaVacia(lista)){/*Si la lista esta vacia se carga el el primer elemento.*/
		insertarPrimero(pProd);
	}
	else{
		(insertarAdelante( pProd));/Si hay elementos en la lista se ingresan delantes de ellos/
	}
}

/*  C) INSERTAR PRIMERO*/
void insertarPrimero(tProducto pProd){/*Lista vacia por lo tanto inserto primer nodo el cual apunta a vacio.
Pasando el argumento com vsriable y creando una variable slocal*/
		/* 1. Se crea el nodo que se va a insertar */
		tListaProductos  * nuevoNodo;
	
	/* 2. Se asigna memoria al nodo */
	 nuevoNodo = (tListaProductos  ) malloc(sizeof(tListaProductos ));/*Mediante el puntero apunto a donde apunta nuvoNodo el cual tiene tipo de dato de tListaProducto/
	
	/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
	nuevoNodo -> producto = pProd;/*producto: ES LA INFO DEL NUEVO NODO. Luego esto es igual a la nueva info con la misma estructura */
	
	/* 4. Se indica que el primer nodo apunta a NULL. 
	Ahora el nuevo nodo seria el ultimo por lo tanto apunta a NULL */
	nuevoNodo -> siguiente = NULL;
	
	/* 5. Se agrega el nodo a la lista, la lista debe apuntar al nuevo nodo */
	lista = nuevoNodo;
	printf("\nPrimer nodo almacenado\n");

}

/*  D) INSERTAR PRODUCTO AL PRINCIPIO DE LA LISTA*/
void insertarAdelante(tProducto pProd){
	/Cuando la lista ya posee nodos, se insertara adelante los nuevos/
		/* 1. Se crea el nodo que se va a insertar */
		tListaProductos * nuevoNodo;

		/* 2. Se asigna memoria al nodo */
		nuevoNodo = (tListaProductos *)malloc(sizeof(tListaProductos));
		
		/* 3. Se asigna el dato recibido al componente correspondiente al elemento */
		nuevoNodo -> producto = pProd;
		
		/* 4. Como la inserción es por la parte de adelante de la lista, se indica que al nuevo nodo le sigue el resto de la lista 	 */
		nuevoNodo -> siguiente = lista;/Apunta al resto d ela lista de nodos los cuales ya estan/
		
		/* 5. Se agrega el nodo a la lista, la lista debe apuntar al nuevo nodo */
		lista = nuevoNodo;
		printf("\nNuevo elemento insertado\n");
}

/*  E) ELIMINA PRIMER pRODUCTO DE LA LISTA*/
void eliminarPrimero(){
		if ( listaVacia( lista ) ) {
		printf("No hay elementos para eliminar\n");
	} else {
		/* 1. Se guarda en una variable auxiliar el primer nodo de la lista */
		tListaProductos * nodoEliminar = lista;
	
		/* 2. Se avanza el puntero una vez, es decir se pasa al siguiente nodo de la lista */
		lista=lista->siguiente;
		
		printf("Primer elemento eliminado, contenido: Codigo: %d  Descripcion: %s   Precio: $%.2f\n", 
		nodoEliminar->producto.codProducto, nodoEliminar->producto.descripcion, nodoEliminar->producto.pUnit);
				
		/* 3. Se libera la memoria del nodo al suprimir lo que contenía el primer elemento de la lista */
		free(nodoEliminar);
		
		/* 4. Se asigna NULL a la variable auxiliar que guarda el nodo a suprimir */
		nodoEliminar = NULL;	
}
}

/*  F) AGREGAR PRODUCTO K (AL AZAR)*/
void insertarK(int pos, tProducto nuevoDato){
	int i;
	tListaProductos * aux, * nuevoNodo;
	
		/* 1.Se debe utilizar una lista auxiliar aux */
		aux = lista;
	
		/* 2. Utilizar un bucle para avanzar aux hasta el nodo que se encuentra en pos-1. Asi nos ubicamos en el nodo a eliminar */
		for(i=1; i<pos-1; i++ ) {
			aux = aux->siguiente;
		}
	
		/* 3. Reservar memoria para el nodo a insertar */
		nuevoNodo = ( tListaProductos * ) malloc(sizeof(tListaProductos));
		
		/* 4. Se asigna el dato recibido al componente correspondiente al elemento */
		nuevoNodo->producto = nuevoDato;
	
		/* 5. Se actualizan los punteros */
		nuevoNodo->siguiente = aux->siguiente;
		aux->siguiente = nuevoNodo;
		
		printf("Nuevo elemento insertado \n Codigo: %d  Descripcion: %s   Precio: $%.2f\n",
		 nuevoDato.codProducto, nuevoDato.descripcion, nuevoDato.pUnit);	
	
}

/*  G) ELIMINAR PRODUCTO K (AL AZAR)*/
void eliminarK(int pos)
{
	 int i, cantNodos;
	tListaProductos * aux, * nodoEliminar;

	cantNodos = contNodos(lista);
	
	if(pos <= cantNodos && pos > 0)
	{
		if(pos == 1)
		{
			eliminarPrimero();
		}
		else
		{
			
			aux = lista;
			int i;
			
			for(i=1; i<pos-1; i++)
			{
				aux = aux->siguiente;
			}
		
			nodoEliminar = aux->siguiente;
		
			aux->siguiente = nodoEliminar->siguiente;
			
			free(nodoEliminar);
			
			nodoEliminar = NULL;
		}
	}
}
	
/CONTADOR DE NODOS/
int contNodos(tListaProductos * pListaProd){
	tListaProductos * aux;
	int contador = 0;
	aux = pListaProd;
	
	if (!listaVacia (aux)){
		
		while(aux != NULL){
			contador++; /CONTADOR/
			aux = aux -> siguiente; /ITERADOR/
		}
	}
	return contador;
}


/*  H  VISUALIZAR*/
void visualizar(tListaProductos * pLista){
	tListaProductos * auxi;
	auxi = pLista;

	if( !listaVacia(auxi) ) {/*Si la lista NO esta vacia. */
		printf("\n*** Elementos en la lista ***\n");
			printf("Los datos ingresados son: \n");
		while(auxi != NULL) {/Mientras no apunte al vacio se imprimen los datos ingresados/
				printf("Codigo: %d  Descripcion: %s   Precio: $%.2f\n", auxi->producto.codProducto, auxi->producto.descripcion, auxi->producto.pUnit);
				printf("------------------------------- \n");
			auxi = auxi->siguiente;
		}
		
	} else {
		printf("No hay elementos para mostar\n");/en el caso de no haber elemntos/
	}	

}
