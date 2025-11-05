#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char tString[25];

typedef struct {
	int dni;
	tString nombre;	
	tString apellido;	
	char sexo;
	float notaFinal;
} tAlumno;

typedef struct nodo {
	tAlumno alumno;
	struct nodo * siguiente;
} tLista;

void inicializarLista();
bool listaVacia( tLista * );

void insertarElemento( tAlumno );
void insertarPrimero( tAlumno );
void insertarAdelante( tAlumno );

void ingresarCantidadAlumno(int);
void visualizarAlumnos( tLista *);
void visualizarNotaMayor(tLista *);

tLista * listaAlumno;

tAlumno alumno;
	
int main() {	
	int cantidadAlumno;	
	inicializarLista();	
	printf("ingrese la cantidad de alumnos a agregar: ");
	scanf("%d",&cantidadAlumno);
	ingresarCantidadAlumno(cantidadAlumno);
	visualizarAlumnos(listaAlumno);
	visualizarNotaMayor(listaAlumno);
	//agregar funcion que muestre los datos de alumnos que sacaron un nota mayor o igual a la nota ingresada por teclado 
	
	return 0;
}

void inicializarLista() {	
	listaAlumno = NULL;
	printf("Lista inicializada\n");
}

bool  listaVacia( tLista * pLista ) {
	return ( pLista == NULL );
}

void insertarElemento( tAlumno pAlumno ) {
	if ( listaVacia( listaAlumno ) ) {
		insertarPrimero( pAlumno );
	}else {
		insertarAdelante( pAlumno );
	}		
}

void insertarPrimero( tAlumno pAlumno ) {
	tLista * nuevoNodo;
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));	
	nuevoNodo->alumno = pAlumno;	
	nuevoNodo->siguiente = NULL;
	listaAlumno = nuevoNodo;
		
}

void insertarAdelante( tAlumno pAlumno ) {
	tLista * nuevoNodo;	
	nuevoNodo = ( tLista * ) malloc(sizeof(tLista));
	if(nuevoNodo != NULL){
		nuevoNodo->alumno = pAlumno;	
		nuevoNodo->siguiente = listaAlumno;			
		listaAlumno = nuevoNodo;
		
	}else{
		printf("\nmemoria insuficiente");
	}
	
}

void ingresarCantidadAlumno(int pCantidad){
	int i=0;
	for(i=1;i<=pCantidad;i++){
		alumno.dni=i;
		char nro[20]; 
		
		sprintf(nro, "%d", i);
		strcpy(alumno.nombre,"nombre");	
		strcat(alumno.nombre,nro);
					
		strcpy(alumno.apellido,"apellido");
		strcat(alumno.apellido,nro);
					
		srand(i+time(NULL));
		
		alumno.notaFinal = (rand() % (11));
		alumno.sexo = (rand() % (2))<1?'M':'F';
		 
		insertarElemento( alumno );
	}	
}

void visualizarAlumnos(tLista * pLista){
	tLista * auxLista= pLista;
	
	if(auxLista==NULL){
		printf("\nLista de alumno vacia");
	}else{
		printf("\nLista de alumno");
		while(auxLista!=NULL){
			
			printf("\nnombre: %s apellido:%s dni:%d  sexo:%c nota final:%.2f",auxLista->alumno.nombre,auxLista->alumno.apellido,auxLista->alumno.dni,auxLista->alumno.sexo,auxLista->alumno.notaFinal);
			
			auxLista=auxLista->siguiente;
		}
	}
	
	
	
}

void visualizarNotaMayor(tLista *pLista){
	tLista *auxLista = pLista;
	tLista *aux2 = pLista;
	float notaMayor = 0;
	
	if (auxLista == NULL){
		printf("\n Lista de Alumnos vacia.");
	}
	else {
		while (auxLista != NULL){
			if (auxLista->alumno.notaFinal >= notaMayor){
				notaMayor = auxLista->alumno.notaFinal;
				aux2 = auxLista;
			}
			auxLista=auxLista->siguiente;
		}
		printf("\n\n La nota mayor es del alumno: %s - apellido:%s - dni:%d -  sexo:%c - nota final:%.2f",aux2->alumno.nombre,aux2->alumno.apellido,aux2->alumno.dni,aux2->alumno.sexo,aux2->alumno.notaFinal); 
	}
}
















