#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definición del tipo de dato "producto", que será la lista enlazada.
typedef struct nodo{
	int codigo;
	char descripcion[50];
	float precio;
	struct nodo *sig;
}producto;

// Prototipado
void visualizar(producto *lista);
bool listaVacia(producto *lista);
//


// ---- Desarrollo de Módulos que regresan valor.

// Función que inicia la lista en NULL.
producto *inicializar(producto *lista){
	lista = NULL;
	return lista;
}

//Función que agrega un elemento al final de la lista.
producto *agregarProducto(producto *lista, int codigo, char descripcion[50], float precio){
	producto *nuevoProducto, *aux; //                                                          Declaración de variables, el producto nuevo, y una variable auxiliar.
	
	nuevoProducto = (producto *) malloc(sizeof(producto)); //                    Reserva el espacio en memoria del nuevo producto.
	
	nuevoProducto->codigo = codigo; //                                           Se guardan los datos en nuestra lista, recibidos de los parámetros.
	strcpy(nuevoProducto->descripcion, descripcion);
	nuevoProducto->precio = precio;
	nuevoProducto->sig = NULL; //                                                Se apunta el nuevo dato creado a NULL, o sea que se posiciona al final.
	
	if(lista == NULL){ //                                                        Si la lista está vacía, entonces se agrega nuevoProducto como primero en la lista.
		lista = nuevoProducto;
	}
	else{ //                                                    Si no está vacía:          
		aux = lista; //                                                          El auxiliar nos permite guardar el/los elemento/s que ya existía/n.
		while (aux->sig != NULL){ //                                             Una vez guardado en el auxiliar, recorre toda la lista mientras no sea el último elemento.
			aux = aux->sig;
			
		}
		aux->sig = nuevoProducto; //                                             El anterior último elemento, ahora pasa a apuntar al último agregado, y éste último apunta a NULL.
	}
	
	return lista;
}

// Función que inserta un nuevo elemento al principio de la lista.
producto *insertarPrimero(producto *lista, int codigo, char descripcion[50], float precio){
	producto *nuevoProducto;                                                         
	
	nuevoProducto = (producto *) malloc(sizeof(producto)); 
	
	nuevoProducto->codigo = codigo;
	strcpy(nuevoProducto->descripcion, descripcion);
	nuevoProducto->precio = precio;
	nuevoProducto->sig = lista;
	lista = nuevoProducto;
	
	return lista;
	
}

// Función que elimina el primer elemento de la lista.
producto *eliminarPrimero(producto *lista){
	if (listaVacia(lista)){
		printf(" No hay elemento para eliminar.\n");
	}
	else{
		producto *eliminarProducto;
	
	eliminarProducto = lista;
	lista = lista->sig;
	free (eliminarProducto);
	eliminarProducto = NULL;
	}
	
	return lista;
}

// Función que elimina un producto de una determinada posición de la lista
producto *eliminarPosicion(int k, producto *lista){
	producto *eliminarProducto, *aux;
	int i;
	
	aux = lista;
	
	for(i=1; i<k-1; i++){
		aux = aux->sig;
	}
	
	eliminarProducto = aux->sig;
	aux->sig = eliminarProducto->sig;
	free(eliminarProducto);
	eliminarProducto = NULL;
	
	return lista;
}

// Función que inserta un nuevo elemento en una determinada posición de la lista.
producto *insertarEnPosicion(int k, producto *lista, int codigo, char descripcion[50], float precio){
	producto *nuevoProducto, *aux;
	int i;
	aux = lista;
	
	for(i=1; i<k-1; i++){
		aux = aux->sig;
	}
	
	nuevoProducto = (producto *) malloc(sizeof(producto)); 
	
	nuevoProducto->codigo = codigo;
	strcpy(nuevoProducto->descripcion, descripcion);
	nuevoProducto->precio = precio;
	nuevoProducto->sig = aux->sig;
	aux->sig = nuevoProducto;
	
	return lista;
	
}

// FUNCIÓN PRINCIPAL
int main(){
	producto *lista1;
	int codigo, resp;
	char descripcion[50];
	float precio;
	
	{ // Ingreso de Datos por Teclado
	printf(" Ingrese Codigo del Producto: ");
	scanf("%d", &codigo);
	fflush(stdin);
	
	printf(" Ingrese Descripcion: ");
	scanf("%[^\n]s", &descripcion);
	
	printf(" Ingrese Precio del Producto: ");
	scanf("%f", &precio);
    }


	// Ingreso de Datos antes de ejecutar el programa
	lista1 = inicializar(lista1);
	resp = listaVacia(lista1);
	printf(" %d", resp);
	lista1 = agregarProducto(lista1, codigo, descripcion, precio);
	lista1 = agregarProducto(lista1, 7737, "Ropa Puma", 899.99); 
	lista1 = agregarProducto(lista1, 7738, "Ropa Adidas", 1299.99);
	lista1 = insertarEnPosicion(2, lista1, 7736, "Ropa China", 299.99);
	
	visualizar(lista1);
	
	return 0;
}

// Desarrollo de Módulos 

void visualizar(producto *lista){
	while(lista != NULL){
		printf("\n %d - %s - %.2f - apunta a: %p - desde: %p\n", lista->codigo, lista->descripcion, lista->precio, lista->sig, lista);
		lista = lista->sig;
	}
	
}

bool listaVacia(producto *lista){
	return (lista == NULL);
}









