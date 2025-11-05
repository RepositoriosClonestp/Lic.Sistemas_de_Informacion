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
int opcion;

/*bloque principal*/
int main (){
	
	//abrir archivo
	FILE *archivo_texto = fopen("registro_usuario.txt","w");
	
	if( archivo_texto == NULL ){
		
		printf("	| FILE ERROR 404 |	");
		
		fclose (archivo_texto);
		
	}
	
	//escribir archivo
	printf("\n desea ingresar un usuario? \n\t SI (1) \t NO (2) \n");
	scanf("%i", &opcion);
	
	if(opcion == 1){
		
		while(opcion == 1){
		
			printf("\n ingrese el nombre del usuario: \n");
			scanf("%s", &registro.nombre);
		
			printf("\n ingrese el apellido del usuario: \n");
			scanf("%s", &registro.apellido);
		
			printf("\n ingrese la edad del usuario: \n");
			scanf("%i", &registro.edad);
		
			printf("\n ingrese el dni del usuario: \n");
			scanf("%i", &registro.dni);
	
			//guardar datos en archivo
			fprintf(archivo_texto, "%s %s %i %i\n", registro.nombre, registro.apellido, registro.edad, registro.dni);
	
			printf("\n desea ingresar otro usuario? \n\t SI (1) \t NO (2) \n");
			scanf("%i", &opcion);
			
		}
	
	}
	
	//cerrar archivo
	fclose(archivo_texto);
	
	return 0;
}
