#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// prefijo t (tDatos), es "tipo tal".

//Definición de los datos compuestos y estructuras.
typedef struct {
	int turno;
	char nombre[30];
	int motivo;
}tDatos;

typedef struct nodo{
	tDatos ticket;
	struct nodo *sig;
}tNodo;

typedef struct {
	tNodo *principio;
	tNodo *final;
}tCola;

tCola colaTurnos;

//Prototipado
void inicializar(tCola *cola);
void visualizar(tCola *cola);
bool colaVacia(tCola *cola);
void push(tCola **cola);
tNodo *asignarDatos();
void pop(tCola ** cola); 
int contadorTransacciones(int motivo);
void visualizarTranscciones(tCola *cola);
int contadorConsultas(int motivo);
void visualizarConsultas(tCola *cola);
void menu(tCola *cola);
// comentarios

// if colavacia, else aux = pcola.principio, visualizar while aux!=null
/*Fijarse slack codigo c para ver la funcion que asigna nodos con datos genéricos para
probar en el programa*/
/* se necesita una funcion que cuente la cantidad de gente que tiene turnos de consulta y devuelva ese valor
En el menu se puede agregar una opcion para finalizar el while

*/

int main(){
	
}

//Desarrollo de Funciones.
void inicializar(tCola *cola){
	cola->principio = NULL;
	cola->final = NULL;
}

bool colaVacia(tCola *lista){
	return ((cola->principio == NULL) && (cola->final == NULL));
}

void visualizar(tCola *cola){
	if(colaVacia(cola)){
		printf("\n No hay turnos en cola. ");
	}
	else {
		
	}
}















