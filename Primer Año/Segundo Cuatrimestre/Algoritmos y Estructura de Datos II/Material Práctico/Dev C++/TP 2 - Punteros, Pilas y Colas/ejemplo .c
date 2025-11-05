#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Alumno: Esquenón Ignacio Agústin - DNI: 44089034
// --------------------------
// Declaracion de Estructuras
typedef char tString [40];
typedef enum {VISA = 1, MASTERCARD
}tTarjeta; //Definición de las constantes numéricas visa y mastercard.

typedef struct {
	int tipoTarjeta;
	long numTarjeta;
	long dni;
	tString nombre;
}tDatosCliente;

typedef struct nodo {
	tDatosCliente cliente;
	struct nodo *siguiente;
}tNodo;

typedef struct{
	tNodo *principio;
	tNodo *final;
}tCola;

// Prototipos Principales
void inicializar(tCola *pCola);
bool colaVacia(tCola pCola);
void agregarCliente(tCola pCola, tCola *pCola2);
void venderEntrada(tCola pCola, tCola *pCola2);
void visualizarEnEspera(tCola pCola);
void menu(tCola pCola, tCola *pCola2);

// Prototipos Complementarios
int contadorTipoTarjeta(tCola pCola, int tarjeta);
int ingresarOpcion();
	
// Declaración de Variables (global)
tCola colaClientes;
int datoControl;

// ------------------------------------------------
// Función Principal
int main(){
	
	inicializar(&colaClientes);
	menu(colaClientes, &colaClientes);
	visualizarEnEspera(colaClientes);
	
	return 0;
}

// Desarrollo de Funciones
void inicializar(tCola *pCola){ // (parámetro por referencia) Inicializa con parámetro que hace referencia a la variable global.
	pCola->principio = NULL;
	pCola->final = NULL;
}

bool colaVacia(tCola pCola){ // (parámetro por valor) Evalúa si la cola está vacía, por un parámetro que es la copia de los valores actuales de la variable global.
	return (pCola.principio == NULL && pCola.final == NULL);
}

void agregarCliente(tCola pCola, tCola *pCola2){ // (Parámetro por valor y referencia) Utiliza una copia del valor actual de la cola 
	tNodo *nuevoCliente;                         // para saber si está vacía, prosigue a modificar los valores originales de la cola                             
	int tipoTarjeta;                             // con el parámetro por referencia.                                       
	int numTarjeta;
	long dni;
	char nombre[40];
	
	nuevoCliente = (tNodo *) malloc(sizeof(tNodo)); 
	
	// Ingreso de Datos por Teclado
	printf(" Ingrese tipo de tarjerta: 1) Visa - 2) Mastercard: ");
	scanf("%d", &tipoTarjeta);
	printf(" Ingrese numero de tarjerta: ");
	scanf("%d", &numTarjeta);
	printf(" Ingrese DNI: ");
	scanf("%d", &dni);
	fflush(stdin);
	printf(" Ingrese nombre y apellido: ");
	gets(nombre);
	nuevoCliente->cliente.tipoTarjeta = tipoTarjeta; 
	nuevoCliente->cliente.numTarjeta = numTarjeta;
	nuevoCliente->cliente.dni = dni;
	strcpy(nuevoCliente->cliente.nombre, nombre);
	nuevoCliente->siguiente = NULL;
	
	if(colaVacia(pCola)){
		pCola2->principio = nuevoCliente;
		pCola2->final = nuevoCliente;
	}
	else{
		pCola2->final->siguiente = nuevoCliente;
		pCola2->final = nuevoCliente;
	}
}

void venderEntrada(tCola pCola, tCola *pCola2){ 
	float precioEntrada = 12500;
	tNodo *venderEntrada, *aux;
	
	
	if (colaVacia(pCola)){
		printf("\n No hay clientes.\n");
	}
	else{
	    venderEntrada = pCola2->principio;
	    
	    switch(venderEntrada->cliente.tipoTarjeta){
		case VISA: {
			precioEntrada = 12500 * 0.95;
			printf("\n Entrada vendida a %s con 5%% de descuento. Total pagado: %.2f\n", venderEntrada->cliente.nombre, precioEntrada);
			break;
		}
		case MASTERCARD: printf("\n Entrada vendida a %s. Total pagado: %.2f\n", venderEntrada->cliente.nombre, precioEntrada);
		break;
		default: printf("\n Tipo de tarjeta no valido, pago rechazado.");
	}
	
	    if (pCola2->principio == pCola2->final){
	    	inicializar(pCola2);
		}
		else{
			pCola2->principio = venderEntrada->siguiente;
		}
		free (venderEntrada);
		venderEntrada = NULL;
	}
}

void visualizarEnEspera(tCola pCola){ // recibe los valores actuales de la cola para visualizar los clientes.
	if (colaVacia(pCola)){
		printf(" No hay ningun cliente en espera.\n");
	}
	else {
		tNodo *aux;
		aux = pCola.principio;
		char visa[10], master[15];
		strcpy(visa, "Visa");
		strcpy(master, "Mastercard");
		
		printf("\n CLIENTES EN LA COLA: \n");
		printf("   TARJETA    |     DNI     | NOMBRE \n");
		while(aux != NULL){  
			switch(aux->cliente.tipoTarjeta){
				case VISA: printf(" %s         |  %ld   | %s\n", visa, aux->cliente.dni, aux->cliente.nombre);
				break;
				case MASTERCARD: printf(" %s   |  %ld   | %s\n", master, aux->cliente.dni, aux->cliente.nombre);
				break;
				default: printf(" ERROR, TARJETA NO PERMITIDA");
			}
			aux = aux->siguiente;
		}
		int cantVisa, cantMaster;
		cantVisa = 0;
		cantMaster = 0;
		cantVisa = contadorTipoTarjeta(pCola, VISA);
		cantMaster = contadorTipoTarjeta(pCola, MASTERCARD);
		
		printf("\n Cantidad de Clientes con visa: %d", cantVisa);
		printf("\n Cantidad de Clientes con mastercard: %d\n", cantMaster);
		}
}

void menu(tCola pCola, tCola *pCola2){ // El menu necesita saber tanto los valores actuales (que pueden ser una copia de la variable global)
	int opcion;                        // pero también hay funciones que necesitan modificar los valores originales, por lo tanto también se ingresa un parámetro por referencia.
	opcion = ingresarOpcion();
	while(opcion !=4){
		switch(opcion){
			case 1: agregarCliente(pCola, pCola2); // Las funciones que modifican los valores originales de la cola, necesitan ambos parámetros.
			break;
			case 2: venderEntrada(pCola, pCola2);
			break;
			case 3: visualizarEnEspera(pCola); // Los que no modifican los valores originales, solo necesitan un parámetro por valor.
			break;
			default: printf(" Opcion no valida");
	}
	if (opcion != 4) {
		menu(pCola, pCola2);
	}
	}
}
int ingresarOpcion(){
	int opcion;
	printf("--------------------------------------------------------------------------------------------------------------");
	printf("\n Ingrese opcion: 1) Agregar Cliente - 2) Vender Entrada - 3) Visualizar Clientes en Espera - 4) Finalizar: ");
	scanf("%d", &opcion);
	return opcion;
}

int contadorTipoTarjeta(tCola pCola, int tarjeta){
	int contador = 0;
	if(!colaVacia(pCola)){
		tNodo *aux;
		aux = pCola.principio;
		while(aux != NULL){
		if (aux->cliente.tipoTarjeta == tarjeta){
			contador = contador + 1;
		}
		aux = aux->siguiente;
	}
	}
	return contador;
}

