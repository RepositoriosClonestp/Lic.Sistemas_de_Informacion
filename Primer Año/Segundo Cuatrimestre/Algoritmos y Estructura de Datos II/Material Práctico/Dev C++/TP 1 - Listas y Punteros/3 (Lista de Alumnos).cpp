#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct nodo{
	int libreta;
	char nombre[30];
	char apellido[30];
	struct nodo *sig;
}datos;

// Prototipado
void visualizar(datos *lista);
bool listaVacia(datos *lista);
datos *inicializar(datos *lista);
datos *agregar(datos *lista, int libreta, char nombre[30], char apellido[30]);
datos *agregarPrimero(datos *lista, int libreta, char nombre[30], char apellido[30]);
datos *eliminarPrimero(datos *lista);
datos *eliminarPosicion(int k, datos *lista);
datos *insertarEnPosicion(int k, datos *lista, int libreta, char nombre[30], char apellido[30]);
datos *menu(datos *lista);

// Función Principal
int main(){
	int datoControl;
	datos *ficha;
	
	ficha = inicializar(ficha);
	printf("\n 1 para realizar operacion: ");
	scanf("%d", &datoControl);
	while (datoControl == 1){
		ficha = menu(ficha);
		printf("\n 1 para seguir, 2 para visualizar datos cargados: ");
		scanf("%d", &datoControl);
		if (datoControl == 2){
			visualizar(ficha);
		}
	}
	
	return 0;
}

void visualizar(datos *lista){
	while(lista != NULL){
		printf("\n Libreta: %d - Nombre: %s - Apellido: %s ", lista->libreta, lista->nombre, lista->apellido);
		lista = lista->sig;
	}
	
}

bool listaVacia(datos *lista){
	return (lista == NULL);
}

datos *inicializar(datos *lista){
	lista = NULL;
	
	return lista;
}

datos *agregar(datos *lista, int libreta, char nombre[30], char apellido[30]){
	datos *nuevoAlumno, *aux; 
	
	nuevoAlumno = (datos *) malloc(sizeof(datos)); 
	
	nuevoAlumno->libreta = libreta; 
	strcpy(nuevoAlumno->nombre, nombre);
	strcpy(nuevoAlumno->apellido, apellido);
	nuevoAlumno->sig = NULL; 
	
	if(lista == NULL){ 
		lista = nuevoAlumno;
	}
	else{       
		aux = lista; 
		while (aux->sig != NULL){ 
			aux = aux->sig;
			
		}
		aux->sig = nuevoAlumno; 
	}
	
	return lista;
}

datos *agregarPrimero(datos *lista, int libreta, char nombre[30], char apellido[30]){
	datos *nuevoAlumno;                                                         
	
	nuevoAlumno = (datos *) malloc(sizeof(datos)); 
	
	nuevoAlumno->libreta = libreta; 
	strcpy(nuevoAlumno->nombre, nombre);
	strcpy(nuevoAlumno->apellido, apellido);
	nuevoAlumno->sig = lista;
	lista = nuevoAlumno;
	
	return lista;
	
}

datos *eliminarPrimero(datos *lista){
	if (listaVacia(lista)){
		printf(" No hay elemento para eliminar.\n");
	}
	else{
		datos *eliminarAlumno;
	
	eliminarAlumno = lista;
	lista = lista->sig;
	free (eliminarAlumno);
	eliminarAlumno = NULL;
	}
	
	return lista;
}

datos *eliminarPosicion(int k, datos *lista){
	datos *eliminarAlumno, *aux;
	int i;
	
	aux = lista;
	if (listaVacia(lista)){
		printf(" No hay elemento para eliminar.\n");
	}
	else{
		for(i=1; i<k-1; i++){
		aux = aux->sig;
	}
	
    	eliminarAlumno = aux->sig;
    	aux->sig = eliminarAlumno->sig;
    	free (eliminarAlumno);
    	eliminarAlumno = NULL;
}
	return lista;
}

datos *insertarEnPosicion(int k, datos *lista, int libreta, char nombre[30], char apellido[30]){
	datos *nuevoAlumno, *aux;
	int i, contador;
	aux = lista;
	
	if (listaVacia(lista)){
		printf(" La posicion a ingresar no existe.\n");
	}
	else{
		for(i=1; i<k-1; i++){
		aux = aux->sig;
	}
	nuevoAlumno = (datos *) malloc(sizeof(datos)); 
	
	nuevoAlumno->libreta = libreta; 
	strcpy(nuevoAlumno->nombre, nombre);
	strcpy(nuevoAlumno->apellido, apellido);
	nuevoAlumno->sig = aux->sig;
	aux->sig = nuevoAlumno;
	
	return lista;
	}
	
}

datos *menu(datos *lista){
	int opcion;
	printf(" Ingrese Opcion: 1) Agregar, 2) Agregar Primero, 3) Eliminar Primero, 4) Eliminar En, 5) Insertar en: ");
	scanf("%d", &opcion);
	fflush(stdin);
	
	switch(opcion){
		case 1: agregar(lista, 1, "nombre 1", "apellido 1");
	    break;
		case 2: agregarPrimero(lista, 2, "Nombre 2", "Apellido 2");
		break;
		case 3: eliminarPrimero(lista);
		break;
		case 4: eliminarPosicion(2, lista);
		break;
		case 5: insertarEnPosicion(2, lista, 3, "Nombre 3", "Apellido 3");
		break;
		default: printf(" Opcion no valida");
	}
}
