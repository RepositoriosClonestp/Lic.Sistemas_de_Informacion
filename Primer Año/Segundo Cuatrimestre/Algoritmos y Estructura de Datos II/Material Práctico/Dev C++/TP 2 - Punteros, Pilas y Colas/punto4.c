/* Lista enlazada */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Declaración de tipos de datos personalizados */
typedef char tString[25];

typedef struct {
	char sexo;
	int rangoEdad;
	float peso;
	float altura;
	tString IMC;	
} tEncuesta;

typedef struct nodo {
	tEncuesta info;
	struct nodo * siguiente;
} tLista;

/* 	Declaración de prototipos de funciones 
	asociadas a las operaciones que se puede realizar 
	con la lista */
void inicializarLista();
bool listaVacia( tLista * );

void insertarPrimero( tEncuesta );
void insertarAdelante( tEncuesta );
void insertarElemento( tEncuesta );

void eliminarPrimero();

void visualizarElementos( tLista * );
int cantidadEncuestados( tLista * );
void promedioBajoPesoMenores(tLista *);
void listarSobrepeso(tLista *);
void armarListarSobrepeso(tLista *);

void insertarSobrepeso(tEncuesta);
void listaSobrepesoDeLista(tLista *);
void ingresarOpcion();
void ingresarEncuesta();

void calcularIMC();
void menu();


/* Declaración de variables globales*/
tLista * lista;
tLista * listaSobrepeso;
int opcion;
tEncuesta encuesta;

/* Función principal */
int main() {	
	tEncuesta data;	
	inicializarLista();
	menu();	
	
	return 0;
}

/* Implementación de funciones */
void menu(){
 	ingresarOpcion();
	while(opcion!=4){
		switch(opcion){
			case 1:
				ingresarEncuesta();
				insertarElemento(encuesta);
				break;
				
			case 2:
				visualizarElementos(lista);
				break;
				
			case 3:
				 //armarListarSobrepeso(lista);
				 //visualizarElementos(listaSobrepeso);
				 listarSobrepeso(lista);				 
				break;
		}				
		ingresarOpcion();
	}	
}

void ingresarOpcion(){
	printf("ingrese una opcion \n");
	printf("1 - insertar \n");
	printf("2 - visualizar \n");
	printf("3 - visualizar sobrepeso \n");
	printf("4 - salir \n");
	scanf("%d",&opcion);
}

void ingresarEncuesta(){
	printf("\ningrese el sexo F,M: ");
	fflush(stdin);
	scanf("%c",&encuesta.sexo);
	printf("\ningrese rango edad 1,2,3: ");
	scanf("%d",&encuesta.rangoEdad);
	printf("\ningrese el peso: ");
	scanf("%f",&encuesta.peso);
	printf("\ningrese altura: ");
	scanf("%f",&encuesta.altura);
	calcularIMC();
}

void calcularIMC(){
	int IMC = encuesta.peso/encuesta.altura;
	strcpy(encuesta.IMC,"                     ");
	if(IMC<20 && encuesta.sexo == 'F' || IMC<19 && encuesta.sexo == 'M'  ){
			strcpy(encuesta.IMC,"Peso bajo");
		}else{
			if(IMC<=25 && encuesta.sexo == 'F' || IMC<=24 && encuesta.sexo == 'M' ){
				strcpy(encuesta.IMC,"Peso normal");
			}else{
				strcpy(encuesta.IMC,"Sobrepeso");
			}	
		}
	}
}
	
void inicializarLista() {	
	lista = NULL;
	listaSobrepeso=NULL;
	
	printf("Lista inicializada\n");
}

bool  listaVacia( tLista * pLista ) {
	return ( pLista == NULL );
}

void insertarPrimero( tEncuesta pElem ) {
	tLista * nuevoNodo;
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	nuevoNodo->info = pElem;
	nuevoNodo->siguiente = NULL;
	lista = nuevoNodo;
}

void insertarAdelante( tEncuesta pElem ) {
	tLista * nuevoNodo;	
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	nuevoNodo->info = pElem;
	nuevoNodo->siguiente = lista;
	lista = nuevoNodo;
}

void insertarElemento( tEncuesta pElem ) {
	if ( listaVacia( lista ) ) {
		insertarPrimero( pElem );
	}else {
		insertarAdelante( pElem );
	}		
}

void eliminarPrimero() {
	if (listaVacia(lista)) {
		printf("No hay elementos para quitar!\n");
	} else {
		tLista * nodoSuprimir = lista;	
		lista = lista->siguiente;		
		printf("Primer elemento eliminado");		
		free(nodoSuprimir);		
		nodoSuprimir = NULL;
	}	
}

void visualizarElementos( tLista * pLista ) {
	tLista * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			printf("%c-%s\n", aux->info.sexo, aux->info.IMC);
			aux = aux->siguiente;
		}		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}

int cantidadEncuestados( tLista * pLista ) {
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


void promedioBajoPesoMenores(tLista * pLista){
	
	
}


void armarListarSobrepeso(tLista * pLista){
		tLista * aux;
		
	aux = pLista;
	listaSobrepeso=NULL;
	
	if( !listaVacia(aux) ) {
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			if(strcmp(aux->info.IMC,"Sobrepeso") == 0){				
				insertarSobrepeso (aux->info);
			}
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}



void insertarSobrepeso (tEncuesta pElem ) {
	tLista * nuevoNodo;	
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));	
	nuevoNodo->info = pElem;	
	nuevoNodo->siguiente = listaSobrepeso;			
	listaSobrepeso = nuevoNodo;
	

}

void listarSobrepeso(tLista * pLista){
	tLista * aux;
	aux = pLista;
	
	if( !listaVacia(aux) ) {
		printf("\n*** Elementos en la lista ***\n");
		while(aux != NULL) {
			if(strcmp(aux->info.IMC,"Sobrepeso") == 0){
				
					printf("%c-%s\n", aux->info.sexo, aux->info.IMC);
			}
			aux = aux->siguiente;
		}
		
	} else {
		printf("No hay elementos para visualizar!\n");
	}
}

