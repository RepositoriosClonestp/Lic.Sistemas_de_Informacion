#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char tString[20];
typedef struct{
	int nroTurno;
	tString nombre;
	tString apellido;
	int tConsulta;
}tDatos;

typedef struct nodo{
	tDatos datosTurno;
	struct nodo *siguiente;
}tLista;

void agregar(tLista**);
void visualizarConsulta(tLista *, int);
void insertarEn(tLista **, int);

tString tipoConsulta[4] = {"", "Haberes", "Maternidad", "Obra Social"};
tLista *listaTurnos;

int main(){
	listaTurnos = NULL;
	agregar(&listaTurnos);
	agregar(&listaTurnos);
	insertarEn(&listaTurnos, 2);
	visualizarConsulta(listaTurnos, 2);
	
	return 0;
}

void agregar(tLista ** pLista){
	tLista *nuevoNodo;
	int nroTurno;
	tString nombre;
	tString apellido;
	int tConsulta;
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	
	printf(" Ingrese nro turno: ");
	scanf("%d", &nroTurno);
	fflush(stdin);
	printf(" Nombre: ");
	gets(nombre);
	fflush(stdin);
	printf(" Apellido: ");
	gets(apellido);
	printf("Tipo Consulta: ");
	scanf("%d", &tConsulta);
	
	nuevoNodo->datosTurno.nroTurno = nroTurno;
	strcpy(nuevoNodo->datosTurno.nombre, nombre);
	strcpy(nuevoNodo->datosTurno.apellido, apellido);
	nuevoNodo->datosTurno.tConsulta = tConsulta;
	nuevoNodo->siguiente = NULL;
	
	if(*pLista == NULL){
		*pLista = nuevoNodo;
	}
	else{
		tLista *aux;
		aux = *pLista;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevoNodo;
	}
}

void insertarEn(tLista **pLista, int lugar){
	tLista *nuevoNodo;
	int nroTurno;
	tString nombre;
	tString apellido;
	int tConsulta;
	nuevoNodo = (tLista *) malloc (sizeof(tLista));
	
	if(*pLista == NULL){
		// no hay lugar
	}
	else{
		tLista *aux;
		aux = *pLista;
		int i;
		for (i=1; i<lugar-1; i++){
			aux = aux->siguiente;
		}
		printf(" Nro Turno: ");
		scanf("%d", &nroTurno);
		fflush(stdin);
		printf(" Nombre: ");
		gets(nombre);
		fflush(stdin);
		printf(" Apellido:");
		gets(apellido);
		printf(" Tipo Consulta: ");
		scanf("%d", &tConsulta);
	
		nuevoNodo->datosTurno.nroTurno = nroTurno;
		strcpy(nuevoNodo->datosTurno.nombre, nombre);
		strcpy(nuevoNodo->datosTurno.apellido, apellido);
		nuevoNodo->datosTurno.tConsulta = tConsulta;
		
		nuevoNodo->siguiente = aux->siguiente;
		aux->siguiente = nuevoNodo;
	}
	
	
}

void visualizarConsulta(tLista *pLista, int pConsulta){
	tLista *aux;
	aux = pLista;
	printf("\n - Turnos para %s - \n", tipoConsulta[pConsulta]);
	while (aux != NULL){
		if(aux->datosTurno.tConsulta == pConsulta){
			printf(" Nro Turno: %d", aux->datosTurno.nroTurno);
			printf(" Nombre: %s", aux->datosTurno.nombre);
			printf(" Apellido: %s \n", aux->datosTurno.apellido);
		}
		aux = aux->siguiente;
	}
}





















