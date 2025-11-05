#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

const char *nombreArchivo = "C:\\Users\\Nacho\\Desktop\\Sulky.txt";

int main(){
	FILE *archivoTexto;
	char letra;
	
	archivoTexto = fopen(nombreArchivo, "r");
	if(archivoTexto == NULL){
		printf("Error al abrir el archivo para lectura");
		return -1;
	}
	
	while ((letra = fgetc(archivoTexto)) != EOF) {
            printf("%c", letra);
        }
	
	fclose(archivoTexto);
	
	return 0;
}
