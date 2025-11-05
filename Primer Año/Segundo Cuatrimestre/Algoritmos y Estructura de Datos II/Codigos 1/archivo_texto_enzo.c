/*
	# archivo de texto #
*/

#include <stdio.h>
#include <stdbool.h>

/*typedef*/
typedef char string[50];


/*variables*/



/*prototipos*/
void crear_abrir_archivo();

void scanner_archivo();

void procesar_caracter_archivo();

void insertar_texto_archivo();

void insertar_tipo_dato_archivo();

void leer_tipo_dato_archivo();

void cerrar_archivo();

/*bloque principal*/
int main (){
	
	crear_abrir_archivo();
	
	scanner_archivo();
	
	procesar_caracter_archivo();
	
	insertar_texto_archivo();
	
	insertar_tipo_dato_archivo();
	
	leer_tipo_dato_archivo();
	
	cerrar_archivo();
	
	return 0;
}


/*funciones*/
void crear_abrir_archivo(){
	
	/*
		Modo Significado
		r Abre un archivo de texto para lectura
		w Crea un archivo de texto para escritura
		a Abre un archivo de texto para añadir
		rb Abre un archivo binario para lectura
		wb Crea un archivo binario para escritura
		ab Abre un archivo binario para añadir
	*/

	FILE *archivo_texto;
	
	archivo_texto = fopen ("notas.txt","r");
	
	
}


void cerrar_archivo(){
	
	if( feof ("notas.txt") ){
	
	fclose ("notas.txt");
	
	}
	
}


void scanner_archivo(){
	
	if( !feof ("notas.txt") ){
		
		/* procesar datos */ /* verifica si quedan datos en el archivo */
		
	}
	
}


void procesar_caracter_archivo(){
	
	char caracter = getc ("notas.txt");		/* lee un caracter del archivo */
	
	/*mostrando caracter*/
	
	//fflush(stdin);
	printf(" %c ", caracter);
	
}


void insertar_texto_archivo(){
	
	fputs (" \n Esta linea de texto fue agregado; \n ", "notas.txt");		/* inserta o agrega una linea de texto plano en el archivo */
	
}


void insertar_tipo_dato_archivo(){
	
	int dni = 45247524;
	
	string nombre = "Cañete_Enzo_Rodrigo";
	
	fprintf( "notas.txt" ," \n %i \n %s \n", dni, nombre);		/* insertar un tipo de dato en especifico en el archivo */
	
}


void leer_tipo_dato_archivo(){
	
	int dni = 0;
	
	string nombre = "";
	
	fscanf( "notas.txt" ,"%i %s", dni, nombre);		/* lee un tipo de dato en especifico en el archivo */
	
}




















