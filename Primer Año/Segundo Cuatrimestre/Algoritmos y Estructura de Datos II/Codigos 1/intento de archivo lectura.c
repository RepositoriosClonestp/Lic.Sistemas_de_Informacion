#include <stdio.h>
#include <stdlib.h>

/*tipos de datos*/
typedef char string[50];


/*bloque principal*/
int main (){
	
	//abrir archivo
	FILE * archivo_texto;
	
	archivo_texto = fopen ("archivo.txt","r");
	
	
	//mostrar error si el archivo esta vacio
	if (archivo_texto == NULL ){
		
		printf("	FILE ERROR	");
		
		fclose(archivo_texto);
		
	}
	else{
		
		//lectura del archivo		
		do{	
		
			char caracter = getc (archivo_texto);
		
			printf(" %c ", caracter);
		
		
	}while(!feof(archivo_texto));
		
	//cerrar el archivo
	fclose(archivo_texto);
		
	}
	
	return 0;
}

