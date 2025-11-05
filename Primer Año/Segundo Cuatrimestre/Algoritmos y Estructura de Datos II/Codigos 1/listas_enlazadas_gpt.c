/*	|Bibliotecas|	*/
#include <stdio.h> 
#include <stdlib.h>



/*	|Tipos de Datos|	*/
typedef char string[50];

typedef struct nodo{
	
	int cod_producto;
	string descripcion;
	float precio_unitario;
	
	struct nodo *siguiente;		/* Puntero al siguiente nodo */
	
}tListaProductos;



/*	|Variables Globales|	*/





/*	|Prototipados|	*/
void agregarNodo(int valor);
void liberarLista();



/*	|Bloque Principal|	*/
int main (){
	
	struct Nodo* cabeza = NULL;  // Inicializamos la lista como vacía
	
	agregarNodo(int valor);
	
	void liberarLista();
	
	return 0;
}



/*	|Definicion de Funciones|	*/
void agregarNodo(int valor) {
	
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));  // Crear un nuevo nodo
    
	nuevoNodo->dato = valor;  // Asignar el valor al nuevo nodo
    
	nuevoNodo->siguiente = NULL;  // El nuevo nodo apunta al siguiente como NULL

    // Verificar si la lista está vacía
    if (cabeza == NULL) {
    
	    cabeza = nuevoNodo;  // Si está vacía, el nuevo nodo es la cabeza
    
	} else {
        
		// Si la lista no está vacía, encontrar el último nodo y hacer que apunte al nuevo nodo
        
		struct Nodo* ultimo = cabeza;
        	
			while (ultimo->siguiente != NULL) {
       	
		        ultimo = ultimo->siguiente;
    	   
		    }
    
	    ultimo->siguiente = nuevoNodo;
    }
}



void liberarLista() {
	
    struct Nodo* actual = cabeza;
    
	struct Nodo* siguiente;

    while (actual != NULL) {
    
	    siguiente = actual->siguiente;
    
	    free(actual);
    
	    actual = siguiente;
    
	}

    cabeza = NULL;  // Asegurarse de que la cabeza apunte a NULL después de liberar la lista

}




