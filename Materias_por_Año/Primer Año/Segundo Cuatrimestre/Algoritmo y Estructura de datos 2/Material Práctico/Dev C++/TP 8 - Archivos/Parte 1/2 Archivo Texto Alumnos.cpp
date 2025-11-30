#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char tString[30];

typedef struct{
	int dni;
	tString nombre;
}regAlumno;

bool escribirArchivo(tString, FILE *, regAlumno);
bool leerArchivo(tString, FILE *, regAlumno);

FILE *F;

int main(){
	regAlumno alumno;
	tString archivoAlumnos;
	strcpy(archivoAlumnos, "alumnos.txt");
	
	if(escribirArchivo(archivoAlumnos, F, alumno) != false){
		printf("\n Escritura de archivo realizada correctamente\n");
	}
	if(leerArchivo(archivoAlumnos, F, alumno) != false){
		printf("\n Lectura de archivo realizada correctamente\n");
	}
	
	return 0;
}

bool escribirArchivo(tString nombreArchivo, FILE *pArchivo, regAlumno pRegAlumno){
	pArchivo = fopen(nombreArchivo, "a");
	if(pArchivo == NULL){
		printf("\n  Error al abrir el archivo para escritura\n");
		return false;
	}
	
	int continuar = 1;
	int contadorRegAlumno = 0;
	
	while(continuar == 1){
		printf(" Ingrese DNI alumno (0 para finalizar): ");
		scanf("%d", &pRegAlumno.dni);
		fflush(stdin);
		if(pRegAlumno.dni == 0){
			continuar = 0;
			break;
		}
		else{
			printf(" Ingrese nombre del alumno: ");
			gets(pRegAlumno.nombre);
			
			fprintf(pArchivo, "%d - %s \n", pRegAlumno.dni, pRegAlumno.nombre);
			
			contadorRegAlumno++;
		}
	}
	printf("\n Cantidad de Alumnos Registrados Recientemente: %d\n", contadorRegAlumno);
	fclose(pArchivo);
	return true;
}

bool leerArchivo(tString nombreArchivo, FILE *pArchivo, regAlumno pRegAlumno){
	pArchivo = fopen(nombreArchivo, "r");
	int cantTotalAlum;
	if(pArchivo == NULL){
		printf("\n Error al abrir archivo para lectura\n");
		return false;
	}
	
	printf("\n Registros de alumnos en el archivo: \n");
	while(fscanf(pArchivo, "%d %[^\n]", &pRegAlumno.dni, &pRegAlumno.nombre) != EOF){
		printf(" DNI: %d - Nombre: %s\n", pRegAlumno.dni, pRegAlumno.nombre);
		cantTotalAlum++;
	}
	printf(" Cantidad Total de Alumnos: %d\n", cantTotalAlum);
	fclose(pArchivo);
}

