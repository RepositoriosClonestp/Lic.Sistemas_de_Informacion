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

char opcion;


/*prototipos*/
void abrir_archivo();

void escribir_archivo();

void cerrar_archivo();



/*bloque principal*/
int main (){
	
	abrir_archivo();
	
	escribir_archivo();
	
	cerrar_archivo();
	
	return 0;
}


/*funiones*/
void abrir_archivo(){
	
	archivo = fopen("registro_booleano.dat","wb");
	
	printf("\n abriendo archivo... \n\n");
	
	if( archivo == NULL ){
		
		printf("	FILE ERROR 404	");
		
		fclose (archivo);
		
	}
	
}



void cerrar_archivo(){
	
	if( feof (archivo) ){
		
		printf("\n cerrando archivo... \n");
		
		fclose (archivo);
		
	}
	
}



void escribir_archivo(){
	
	printf("\n desea ingresar un usuario?	( SI = s | NO = n )	 \n");
	fflush(stdin);
	scanf("%c", &opcion);
	
	while( opcion == 's' || opcion == 'S' ){
		
		printf("\n ingrese nombre del usuario: \n");
		scanf("%s", &registro.nombre);
		
		printf("\n ingrese edad del usuario: \n");
		scanf("%i", &registro.edad);
		
		fwrite( &registro, sizeof(t_datos), 1, archivo );
		
		printf("\n desea ingresar otro usuario?		( SI = s | NO = n )	 \n");
		fflush(stdin);
		scanf("%c", &opcion);
		
	}
	
}




