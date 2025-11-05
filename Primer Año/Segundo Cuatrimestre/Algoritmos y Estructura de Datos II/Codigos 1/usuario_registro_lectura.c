#include <stdio.h>

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

/*prototipós*/
void abrir_archivo();

void leer_archivo();

void cerrar_archivo();


/*bloque principal*/
int main (){
	
	abrir_archivo();
	
	leer_archivo();
	
	cerrar_archivo();
	
	return 0;
}



/*funciones*/
void abrir_archivo(){
	
	archivo = fopen("usuarios_registro.txt","r");
	
	if( archivo == NULL ){
		
		printf("	FILE ERROR 404	");
		
		fclose(archivo);
		
	}
	
}



void cerrar_archivo(){
	
	if( feof (archivo) ){
		
		fclose(archivo);
		
	}
	
}



void leer_archivo(){
	
	fscanf(archivo, "%s%i%i", &registro.nombre, &registro.edad, &registro.dni);
	
	while( !feof (archivo) ){
	
	printf("%s %i %i \n", registro.nombre, registro.edad,registro.dni);
	
	fscanf(archivo, "%s%i%i", &registro.nombre, &registro.edad, &registro.dni);
	
	}
	
}





















