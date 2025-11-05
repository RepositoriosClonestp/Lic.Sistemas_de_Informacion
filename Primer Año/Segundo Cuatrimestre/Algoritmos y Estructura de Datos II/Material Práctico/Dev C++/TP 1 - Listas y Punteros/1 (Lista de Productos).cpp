#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo{
	int codigo;
	char descripcion[50];
	float precio;
	struct nodo *sig;
}producto;

// Prototipado
void visualizar(producto *lista);
//------------

producto *inicializar(producto *lista){
	lista = NULL;
	return lista;
}
// ----------------------------------- FUNCION QUE PERMITE AGREGAR UN PRODUCTO -------------------------------------------------------
producto *agregarProducto(producto *lista, int codigo, char descripcion[50], float precio){ // Parámetros que son otorgados en el main, en base al tipo de datos de nuestra lista.
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

// FUNCIÓN PRINCIPAL

int main(){
	producto *lista1;
	int codigo;
	char descripcion[50];
	float precio;
	
	/* ---- Primer producto ingresado por teclado ---- */
	
	printf(" Ingrese Codigo del Producto: ");
	scanf("%d", &codigo);
	fflush(stdin);
	
	printf(" Ingrese Descripcion: ");
	scanf("%[^\n]s", &descripcion);
	
	printf(" Ingrese Precio del Producto: ");
	scanf("%f", &precio);
	
	// ---- Los demás antes de ejecutar el programa ----
	lista1 = inicializar(lista1);
	lista1 = agregarProducto(lista1, codigo, descripcion, precio);
	lista1 = agregarProducto(lista1, 7737, "Ropa Puma", 899.99); 
	lista1 = agregarProducto(lista1, 7738, "Ropa Adidas", 1299.99);
	
	visualizar(lista1);
	
	return 0;
}

// Desarrollo de Módulos 

void visualizar(producto *lista){
	while(lista != NULL){
		printf("\n %d - %s - %.2f - %p\n", lista->codigo, lista->descripcion, lista->precio, lista->sig);
		lista = lista->sig;
	}
	
}




















