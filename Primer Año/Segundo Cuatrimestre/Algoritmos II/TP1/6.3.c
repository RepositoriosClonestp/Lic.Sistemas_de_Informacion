#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//DECLARACION TIPOS
typedef char tString[25]; //defino tipo tString

typedef struct{
	int lu;
	tString nombre;
} tAlumno;

typedef struct nodo{
	tAlumno alumno;
	struct nodo * siguiente;
} tLista;

//PROTOTIPOS

void inicializarLista();
void menu();


void ingresarAlumno();
void insertarAlumno();
void insertarPrimero();
void insertarDelante();
bool listaVacia();


//DECLARACION DE VARIABLES GLOBALES
tLista * lista;
tAlumno vAlumno;//para usar con scanf
//MAIN
int main()
{
	//inicialiar lista
	inicializarLista();
	//mostrar menu
	menu();
	
	return 0;
}

//IMPLEMENTACION
void inicializarLista()
{
	lista = NULL;
	printf("Lisa Inicilizada \n");
}

void menu()
{
	int opcion = 1;
	while(opcion!=0)
	{
		printf("Ingrese Opcion\n");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 0:
				printf("Salir");
			case 1:
				//Insertar alumnos al principio de la lista.
				ingresarAlumno();
				insertarAlumno();
				break;
			case 2:
				//d) Eliminar el primer alumno de la lista.
				eliminarAlumno();
				break;
			case 3:
				//e) Insertar un alumno en una determinada posición dentro de la lista.
				int posicion;
				ingresarAlumno();
					prinf("En que posicion desea insertar el alumno \n");
					scanf("%d",&posicion);
				insertarAlumnok(posicion);
				break;
			case 4:	
				//f) Eliminar un alumno de una determinada posición de la lista.
				int posicion;
				prinf("Que alumno desea eliminar?\n");
				scanf("%d",&posicion);
				
				eliminarAlumnoK(posicion);
				break;
			case 5:
				//g) Visualizar todos los datos de los alumnos que están en la listac 
				visualizarLista();
				break;
			case 6:
				//Mostrar la a cantidad de alumnos que contiene la lista
				printf("%d alumnos",contarNodos());
				break;
			default:
				printf("Opcion incorrecta");
		}
			
		
		
		
		
	}
	
}

void insertarAlumno()
{
	if(listaVacia())
	{
		insertarPrimero();
	}
	else
	{
		insertarDelante();
	}
}

bool listaVacia()
{
	return (lista == NULL);
}

void insertarPrimero()
{
	// crar un nuevo nodo
	tLista * nuevoNodo;
	// asignar memoria a ese nodo
	nuevoNodo = (tLista *) malloc(sizeof(tLista));//siempre devuevl void*
	// meter el alumno al nodo
	nuevoNodo->alumno = vAlumno;
	// actualizar punteros //como es el primero , el nodo apunta a null
	nuevoNodo->siguiente = NULL;
	//agregar el nodo a la lista
	lista = nuevoNodo;
}

void insertarDelante()
{
	//cerar un nodo
	tLista * nuevoNodo;
	//asignar memoria
	nuevoNodo = (tLista *) malloc(sizeof(tLista));
	//meter alumno al nodo
	nuevoNodo->alumno = vAlumno;
	//actualizar punteros
	nuevoNodo->siguiente = lista;
	//agrego nodo a la lista
	lista = nuevoNodo;
}

void eliminarDelante()
{
	if(listaVacia())
	{
		printf("No hay elemento para eliminar");
	}
	else
	{
		//se guarda en una var auxiliar el nodo a eliminar
		tLista * nodoEliminar;
		nodoEliminar = lista;
		
		//apuntar la lista al siguiente elemento, es decir al 2do
		lista = nodoEliminar->siguiente;
		
		free(nodoEliminar);
		nodoEliminar = NULL;
		
	}
}


void eliminarK(int pos)
{
	
	tLista * nodoEliminar;
	tLista * aux;//auxiliar para recorrer la lista

	//validar que el elemento en pos exista
	cantNodos = contarNodos();
	
	if(pos <= cantNodos && pos > 0)
	{
		if(pos == 1)
		{
			eliminarDelante();
		}
		else
		{
			//necesito un auxliar para recorrer la lista
			aux = lista;
			int i;
			//recorrer la lista hasta encontra el anterior al eliminado pos-1
			for(i=1; i<pos-1; i++)
			{
				aux = aux->siguiente;
			}
			// florenica
			nodoEliminar = aux->siguiente;//ale
			//
			aux->siguiente = nodoEliminar->siguiente
			
			free(nodoEliminar);
			
			nodoEliminar = NULL;
		}
	}
	
	
	
}


int contarNodos()
{
	tLista * aux;//iterador
	int contador = 0;
	
	aux = lista;
	
	if(!listaVacia())
	{
		while(aux != NULL)
		{
			contador++;
			aux = aux->siguiente;
		}
	}
	return contador
	
}
