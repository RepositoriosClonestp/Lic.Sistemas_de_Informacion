#include <stdio.h>
#include <stdlib.h>

typedef char string[50];


int main (){
	
	//crear archivo
	FILE * archivo_texto;
	
	archivo_texto = fopen ("archivo.txt","w");
	
	
	//mostrar error si el archivo esta vacio
	if(archivo_texto == NULL){
		
		printf("-----------file error------------");
		
		fclose(archivo_texto);
		
	}
	else{
		
		//escritura
		int dni;
		string nombre;
		
		printf("ingrese DNI y nombre:");
		
		scanf("%i %s",&dni, &nombre);
		
		fprintf(archivo_texto, "%i \n", dni);
		fputs(nombre,archivo_texto);
		
	}
	
	//cerrar archivo
	fclose(archivo_texto);
	
	return 0;
}



