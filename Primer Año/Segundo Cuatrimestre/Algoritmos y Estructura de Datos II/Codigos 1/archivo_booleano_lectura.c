#include <stdio.h>

/*tipos de datos*/
typedef char string[50];

typedef struct{
	
	string nombre;
	int edad;
	
}t_datos;

/*variables*/
t_datos registro;

FILE *archivo;


/*prototipos*/
void abrir_archivo();

void leer_archivo();

void cerrar_archivo();


/*bloque principal*/
int main(){
	
	abrir_archivo();
	
	leer_archivo();
	
	cerrar_archivo();
	
	return 0;
}


/*funciones*/
void abrir_archivo(){
	
	archivo = fopen("registro_booleano.dat","rb");
	
	printf("\n abriendo archivo... \n\n");
	
	if( archivo == NULL ){
		
		printf("	FILE ERROR 404	");
		
		fclose(archivo);
		
	}
	
}

void cerrar_archivo(){
	
	if( feof (archivo) ){
		
		printf("\n cerrando archivo... \n");
		
		fclose(archivo);
		
	}
	
}


void leer_archivo(){
	
	fread( &registro, sizeof( t_datos ), 1, archivo );
	
	while( !feof (archivo) ){
		
		printf(" %s %i \n", registro.nombre, registro.edad);
		
		fread( &registro, sizeof( t_datos ), 1, archivo );
		
	}
	
}



