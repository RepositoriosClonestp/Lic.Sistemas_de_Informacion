#include <stdio.h>
#include <stdlib.h>

/*tipos de datos*/
typedef char string[50];

typedef struct Registro{
	
	string nombre;
	string apellido;
	
	int edad;
	int dni;
	
}t_registro;


/*variables*/
t_registro registro;


/*bloque principal*/
int main (){
	
	//abrir archivo
	FILE *archivo_texto = fopen("registro_usuario.txt","r");
	
	if( archivo_texto == NULL ){
		
		printf("	| FILE ERROR 404 |	");
		
		fclose (archivo_texto);
		
	}
	
	//leer archivo
	while( !feof (archivo_texto) ){
	
		fscanf(archivo_texto,"%s %s %i %i", &registro.nombre, &registro.apellido, &registro.edad, &registro.dni);
	
		//mostrar en pantalla
		printf("%s %s %i %i \n", registro.nombre, registro.apellido, registro.edad, registro.dni);
	
	}
	
	//cerrar archivo
	fclose(archivo_texto);
	
	return 0;
}


