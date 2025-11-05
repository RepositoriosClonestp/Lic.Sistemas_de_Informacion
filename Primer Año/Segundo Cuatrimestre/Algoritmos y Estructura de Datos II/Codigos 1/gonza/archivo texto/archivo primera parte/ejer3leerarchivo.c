#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char tString [200];

typedef struct{
tString dni;
tString nombre;
}regAlumnos;


regAlumnos alumnos;


FILE * archivo;

void abrirarchivolectura();
void visualizar();
void menu();


int main(){
	menu();
	
	return 0;
}






void abrirarchivolectura(){	
	archivo=fopen ("archivo","r");
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
	
	printf("%d",cantidadRegistros);
}





void menu(){
	int opciones;
	

	do{
		printf("elegir opcion:\n1:crear archivo \n2:grabar 1 alumno \n3:visualizar\n 4:cerrarArchivo\n");
		scanf("%d",&opciones);
		fflush(stdin);
			switch(opciones){
		
			case 1:
		
			system("pause");
			break;
		
			case 2:
			
			system("pause");
			break;	
		
			case 3:	
			visualizar(alumnos);
			system("pause");
			break;
			
			case 4:
		
			system("pause");
			break;

			
			defauld:printf("error al cargar el archivo");
			system("pause");
			}	
		
		
		system("cls");
	}while(opciones!=0);
	
	
	
	
}
