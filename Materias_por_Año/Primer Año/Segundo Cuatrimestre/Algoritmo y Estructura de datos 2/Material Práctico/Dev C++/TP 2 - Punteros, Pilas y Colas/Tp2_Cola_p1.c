#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define TAB4 "\t\t\t\t"

/* Declaración de tipos de datos personalizados */
typedef char tString [25];

typedef struct {
	int nroTurno;
	tString nombre;
	int codMotivo;
	
}tDatos;

typedef struct nodo {
	tDatos datos;
	struct nodo * siguiente;
}tNodo;

typedef struct {
	tNodo * principio;
	tNodo * final;
}tCola;

/* Declaración de prototipos */

void inicializarCola();
bool colaVacia( tCola );
void push( tDatos ); // insertar un elemento al final de la lista
void pop();	// quitar un elemento del frente de la lista
void visualizarElementos( tCola );
tNodo * primerElemento( tCola );
tDatos primerElemento2( tCola );
int cantidadSegunMovimiento(int );

void menu();
void ingresarGenerico(int);

/* Declaración de variables */
tCola cola;
tDatos datoNulo;

tDatos dato, primeroB;
tNodo * primero;
int opcion;

tString motivoDescripcion[3]={"","transaccion" , "Consulta"};
/* Bloque principal */
int main() {
	
	inicializarCola();
	menu();
	
	return 0;
}

/* Implementación de funciones */

void ingresarOpciones(){
	printf("\t\nIngrese la opcion que desee.\n");
	printf("1-cargar cola generico\n");
	printf("2-eliminar de la cola\n");
	printf("3-Visualizar cola\n");
	printf("4- mostrar cantidad transaccion");
	printf("5- mostrar cantidad consulta");
	printf("6-Finaliza\n");
	scanf("%d", &opcion);
}

void menu(){
	ingresarOpciones();
		while(opcion != 6){
			switch(opcion){
				case 1:
					ingresarGenerico(5);
					break;
				case 2:
					pop();
					break;
				case 3:
					visualizarElementos(cola);
					break;	
				case 4:
					printf("cantidad de transaccion: %d",cantidadSegunMovimiento(1));
					break;			
				case 5:
					printf("cantidad de consultas: %d",cantidadSegunMovimiento(2));
					break;		
				default : printf("\n opcion incorrecta!");
				break; 
			}
			ingresarOpciones();
		}
}

void ingresarGenerico(int pCantidad){
	int i=0;
	for(i=1;i<=pCantidad;i++){
		dato.nroTurno=i;
		
		char nro[20]; 
		
		sprintf(nro, "%d", i);
		strcpy(dato.nombre,"nombreTurno");	
		strcat(dato.nombre,nro);
					
	
		srand(i+time(NULL));
		dato.codMotivo = (rand() % (2))<1?1:2;
		 
		push( dato );
	}	
}


void inicializarCola() {
	cola.principio = NULL;
	cola.final = NULL;
	printf("Cola inicializada ... \n");	
}

bool colaVacia( tCola pCola ) {
	return ( pCola.principio == NULL && pCola.final == NULL );
}

void push( tDatos pDatos ) {	
	/* 1. Crear un nodo */
	tNodo * nuevoNodo;
	
	/* 2. Asignar memoria al nuevo nodo */
	nuevoNodo = (tNodo *) malloc(sizeof(tNodo));
	
	/* 3. 	Asignar valores a la parte de datos del nodo 
			y al campo siguiente */
	nuevoNodo->datos = pDatos;
	nuevoNodo->siguiente = NULL;
			
	/* 4. 	Si la cola está vacía estaríamos insertando el primer nodo
			entonces ambos punteros deben apuntar al nuevo nodo
			
			caso contrario significa que ya hay elementos en la cola,
			y solo se actualiza el puntero del final */
	if(colaVacia(cola)) {
		cola.principio = nuevoNodo;
		cola.final = nuevoNodo;
	}else {
		cola.final->siguiente = nuevoNodo;
		cola.final = nuevoNodo;
	}
	
	printf("Se inserto el elemento: %d-%s\n", pDatos.nroTurno, pDatos.nombre);
}

void pop() {	
	/* 1.	Si hay elementos en la cola, se puede quitar */	
	if(!colaVacia(cola)){
		/* 2. 	Resguardar el nodo del principio, que es el que se va a quitar */	
		tNodo * nodoSuprimir = cola.principio;
		
		/* 3.	Tener en cuenta si la cola es unitaria para inicializarla
			caso contrario solo se debe actualizar el puntero del principio */		
		if ( cola.principio == cola.final ) {
			// se quita el último elemento
			inicializarCola();
		}else {
			// la cola tiene más elementos, quito el del principio
			cola.principio = nodoSuprimir->siguiente;			
		}
		
		printf("Se quito el elemento: %d-%s\n", 
			nodoSuprimir->datos.nroTurno, nodoSuprimir->datos.nombre);
		
		/* 4.	Liberar la memoria del nodo eliminado */
		free(nodoSuprimir);
		nodoSuprimir = NULL;
	} else {
		printf("No hay elementos para quitar!\n");	
	}	
}
	
void visualizarElementos( tCola pCola ) {
	if(colaVacia(pCola)) {
		printf("No hay elementos para visualizar!\n");	
	}else {
		tNodo * aux = pCola.principio;
		printf("\n*** ELEMENTOS EN LA COLA ***\n");
		printf("Codigo | Descripcion | Motivo\n");
		while(aux != NULL) {
			printf("%d | %s | %s\n", aux->datos.nroTurno, aux->datos.nombre,motivoDescripcion[aux->datos.codMotivo]);
			aux = aux->siguiente;
		}
	}
}

tNodo * primerElemento( tCola pCola ) {
	return pCola.principio;
}

tDatos primerElemento2( tCola pCola ) {
	return colaVacia(pCola) == true ? datoNulo : pCola.principio->datos;	
} 

	
int cantidadSegunMovimiento(int pCodMotivo ) {
	int cantidad=0;
	
	if(!colaVacia(cola)) {
		
		tNodo * aux = cola.principio;		
		while(aux != NULL) {
			if(pCodMotivo == aux->datos.codMotivo){
				
				cantidad = cantidad + 1;
			}
			
			aux = aux->siguiente;
		}
	}
	
	return cantidad;
}
