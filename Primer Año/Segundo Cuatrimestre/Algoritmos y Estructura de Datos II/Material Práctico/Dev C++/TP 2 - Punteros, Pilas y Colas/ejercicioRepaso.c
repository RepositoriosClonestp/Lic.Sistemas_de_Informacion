#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define PRECIO 12500

typedef char tString [50];
//tInfo
typedef struct{
		int codTarjeta;
		int numTarjeta;
		int dni;
		tString nyP;
}tCliente;

//nodo
	//info
	//puntero siguiente
typedef struct nodo{
	tCliente cliente;
	struct nodo * siguiente;
}tNodo;

//tcola
typedef struct {
	tNodo * principio;
	tNodo * final;
}tCola;

//declarar la variable
tCola colaVenta;


tString tarjetaDescripcion [3] ={"","Visa","Mastercard"};


void inicializarCola();
bool colaVacia(tCola);
void push(tCliente);
void push2(tCola *, tCliente);
void pop();
void pop2(tCola*);
void visualizarCola(tCola );

void venderEntrada();
void mostrarValorEntrada(int);
tCliente ingresarDatosCliente();

float mostrarValorEntrada2(int);

void mostrarClienteEnEspera(tCola);

void menu();

int opcion;

int main(){
	inicializarCola();
	menu();	
	
	return 0;
}

//implementacion
void opciones(){
	
	printf("\nSeleccione una opcion:\n\t1-Agregar cliente\t");
	printf("\n\t2-Vender entrada");
	printf("\n\t3-Listado clientes ");		
	printf("\n\t4-Listado cola en espera ");	
	printf("\n\ts-salir:  ");	
	fflush(stdin);
	scanf("%c", &opcion);
	
	opcion = tolower(opcion);
}

void menu(){
	opciones();
	tCliente aux;
	while (opcion != 's'){
		system("cls");
		
		switch(opcion) {
			case '1':  	aux=ingresarDatosCliente();
						push(aux);	
						//push2(&colaVenta,ingresarDatosCliente());	
						break;
			case '2': 	venderEntrada();				
						break;			
			case '3': 	visualizarCola(colaVenta);				
						break;
			case '4': 	mostrarClienteEnEspera(colaVenta);				
						break;					
			case 's': 	printf("Salir\n");
						break;
		}
		
		opciones();
	}
		
}

tCliente ingresarDatosCliente() {
	tCliente cliente;
	
	printf("Cod tarjeta(1-Visa 2-Mastercard): ");
	scanf("%d", &cliente.codTarjeta);
	
	printf("Nro tarjeta: ");
	scanf("%d", &cliente.numTarjeta);
	
	printf("DNI: ");
	scanf("%d", &cliente.dni);
	
	printf("Nombre y apellido(como figura en la tarjeta): ");
	fflush(stdin);
	scanf("%s",cliente.nyP);
	
	return cliente;	
}

void inicializarCola(){
	colaVenta.principio=NULL;
	colaVenta.final=NULL;
}

void venderEntrada(){
	
	mostrarValorEntrada(colaVenta.principio->cliente.codTarjeta);
	
	//printf("el valor de la entra es: %.2f",mostrarValorEntrada2(colaVenta.principio->cliente.codTarjeta));
	//pop2(&colaVenta);
	pop();
}

void mostrarValorEntrada(int pCodTarjeta){
	float bonificacion=0.0;
	if(pCodTarjeta==1){
		bonificacion = PRECIO * 0.05;
	}
	printf("el valor de la entra es: %.2f",PRECIO-bonificacion);
}

float mostrarValorEntrada2(int pCodTarjeta){
	float bonificacion=0.0;
	if(pCodTarjeta==1){
		
		bonificacion = PRECIO * 0.05;
		
	}
	return PRECIO-bonificacion;
}

bool colaVacia(tCola pCola){
	
	return pCola.principio == NULL && pCola.final==NULL;
}


void pop2(tCola * pCola){
	if(colaVacia(*pCola)){
		printf("cola vacia");	
	}else{
		
		tNodo * nodoSuprimir = pCola->principio;
		if(pCola->principio==pCola->final){
			inicializarCola();
		}else{
			pCola->principio=nodoSuprimir->siguiente;
		}
		
		free(nodoSuprimir);
		nodoSuprimir=NULL;
		
	}
}

void pop(){
	if(colaVacia(colaVenta)){
		printf("cola vacia");	
	}else{
		
		tNodo * nodoSuprimir = colaVenta.principio;
		if(colaVenta.principio==colaVenta.final){
			inicializarCola();
		}else{
			colaVenta.principio=nodoSuprimir->siguiente;
		}
		
		free(nodoSuprimir);
		nodoSuprimir=NULL;
		
	}
}


void visualizarCola(tCola pCola){
	tNodo *aux= pCola.principio;
	
	if(colaVacia(pCola)){
		printf("cola vacia");	
	}else{
		while(aux!=NULL){
			
			printf("%d",aux->cliente.dni);
			
			aux=aux->siguiente;	
		}
	}	
}


void mostrarClienteEnEspera(tCola pCola){
	tNodo * aux= pCola.principio;
	int cantVisa=0;
	int cantMaster=0;
	int vCantTarjeta [3]= {0,0,0};
	
	if(colaVacia(pCola)){
		printf("cola vacia");	
	}else{
		while(aux!=NULL){	
			if(aux->cliente.codTarjeta==1){
				cantVisa=cantVisa+1;
			}else{
				cantMaster=cantMaster+1;
			}
			
			vCantTarjeta[aux->cliente.codTarjeta] =	vCantTarjeta[aux->cliente.codTarjeta] + 1;
			
			printf("%s %d %s",tarjetaDescripcion[aux->cliente.codTarjeta], aux->cliente.dni,aux->cliente.nyP);
			
			aux=aux->siguiente;	
		}
		
		printf("total cliente visa :%d",vCantTarjeta[1]);
		printf("total cliente mastercard :%d",vCantTarjeta[2]);
		
		
		printf("total cliente visa :%d",cantVisa);
		printf("total cliente mastercard :%d",cantMaster);
	}	
}


void push(tCliente pCliente){
	
	tNodo * nuevoCliente = (tNodo *)malloc(sizeof(tNodo));
	
	nuevoCliente->cliente = pCliente; 
	nuevoCliente->siguiente = NULL;
	
	if(colaVacia(colaVenta)){
		colaVenta.principio = nuevoCliente;
		colaVenta.final = nuevoCliente;
		
	}else{
		
		colaVenta.final->siguiente =nuevoCliente;
		colaVenta.final=nuevoCliente;
	}
		
}



void push2(tCola * pCola, tCliente pCliente){
	
	tNodo * nuevoCliente = (tNodo *)malloc(sizeof(tNodo));
	
	nuevoCliente->cliente = pCliente; 
	nuevoCliente->siguiente = NULL;
	
	if(colaVacia(*pCola)){
		pCola->principio = nuevoCliente;
		(*pCola).final = nuevoCliente;
		
	}else{
		
		pCola->final->siguiente =nuevoCliente;
		pCola->final=nuevoCliente;
	}
		
}
