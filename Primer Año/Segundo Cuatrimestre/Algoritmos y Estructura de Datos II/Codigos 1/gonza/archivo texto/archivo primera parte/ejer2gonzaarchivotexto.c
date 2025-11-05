/*Escribir un programa que permita grabar un archivo de texto con datos de alumnos contenidos en una 
línea de texto que se ingresa por teclado. Cada línea contiene los siguientes datos: DNI, nombre del 
alumno y finaliza con un salto de línea. Ingresar alumnos hasta que el usuario indique que no desea 
continuar ingresando datos. Informar al final la cantidad de registros grabados.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tString [200];
char nombreArchivo [50];

typedef struct{
tString dni;
tString nombre;
}regAlumnos;

regAlumnos alumnos;


FILE * archivo;


void crearArchivo();
void grabarAlumno();


void abrirarchivolectura();
void visualizar();

void finalizarProceso();

void menu();

int main(){
	menu();
	
	return 0;
}

void crearArchivo(){
	
	printf("Ingrese el nombre del archivo de texto: ");
    scanf("%s", nombreArchivo);
    archivo = fopen(nombreArchivo, "w");
    printf("archivo abierto modo escritura");
    fflush(stdin);
}
void grabarAlumno(){
	
	char continuar;
	do{
	printf("ingresar dni");
	scanf("%s",&alumnos.dni);
	
	printf("ingresar nombre");
	scanf("%s",&alumnos.nombre);

	fprintf(archivo,"%s %s\n",alumnos.dni,alumnos.nombre);
	
	printf("¿Desea continuar ingresando datos? (S/N): ");
        scanf(" %c", &continuar);
		fflush(stdin);
	}while (continuar == 'S' || continuar == 's');
	
	fclose(archivo);
}
void abrirarchivolectura(){	
	archivo=fopen (nombreArchivo,"r");
	printf("archivo abierto modo lectura\n");
	fflush(stdin);
}
void visualizar(){
	int cantidadRegistros=0;
	abrirarchivolectura();
	 if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
    }
    
	while (fscanf(archivo, "%s %s", alumnos.dni, alumnos.nombre) != EOF) {
        printf("DNI: %s, Nombre: %s\n", alumnos.dni, alumnos.nombre);
        cantidadRegistros++;
    }

	
}
void finalizarProceso(){
	fclose(archivo);
	printf("archivo cerrado");
	fflush(stdin);
	
}
void menu(){
	int opciones;
	

	do{
		printf("elegir opcion:\n1:crear archivo \n2:grabar 1 alumno \n3:visualizar\n 4:cerrarArchivo\n");
		scanf("%d",&opciones);
		fflush(stdin);
			switch(opciones){
		
			case 1:
			crearArchivo();	
			system("pause");
			break;
		
			case 2:
			grabarAlumno();
			system("pause");
			break;	
		
			case 3:	
			visualizar(alumnos);
			system("pause");
			break;
			
			case 4:
			finalizarProceso();
			system("pause");
			break;

			
			defauld:printf("error al cargar el archivo");
			system("pause");
			}	
		
		
		system("cls");
	}while(opciones!=0);
	
	
	
	
}
