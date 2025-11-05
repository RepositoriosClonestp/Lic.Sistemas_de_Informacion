#include <stdio.h>
#include <stdlib.h>

/*tipos de datos*/
typedef char string[100];
typedef struct{
	
	string nombre;
	int edad;
	int dni;
	
}t_datos;

/*variables*/
t_datos registro;
FILE *archivo;
char opcion;

/*prototipos*/
void abrir_archivo();

void escribir_archivo();

void cerrar_archivo();


/*bloque principal*/
int main(){
	
	abrir_archivo();
	
	escribir_archivo();
	
	cerrar_archivo();
	
	return 0;
}


/*funciones*/
void abrir_archivo(){
	
	archivo = fopen("usuarios.dat","wb");
	
	if( archivo == NULL ){
		
		printf("	FILE ERROR 404	");
		
		fclose(archivo);
		
	}
	
}



void cerrar_archivo(){
	
	if( feof(archivo) ){
		
		fclose(archivo);
		
	}
	
}


void escribir_archivo(){
	
	printf("\n desea ingresar datos de un usuario?	( Si = s | No = n ) \n");
	fflush(stdin);
	scanf("%c", &opcion);
	
	
	while( (opcion == 's') || (opcion == 'S') ){
	
	printf("\n ingresar nombre del usuario: \n");
	scanf("%s", &registro.nombre);
	
	printf("\n ingrese edad del usuario: \n");
	scanf("%i", &registro.edad);
	
	printf("\n ingrese dni del usuario: \n");
	scanf("%i", &registro.dni);
	
	
	fwrite(archivos, sizeof(t_datos), 1, registro);
	
	
	printf("\n desea ingresar datos de otro usuario?	( Si = s | No = n ) \n");
	fflush(stdin);
	scanf("%c", &opcion);
	
	}
	
}


