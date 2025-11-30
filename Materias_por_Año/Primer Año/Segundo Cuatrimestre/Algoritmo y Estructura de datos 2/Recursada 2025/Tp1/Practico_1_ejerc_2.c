#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarString();

int main() {
    mostrarString();
    return 0;
}

void mostrarString() {
    char *pChar;  /* Puntero a char*/

    /* Reservar memoria para el string "Anastacia")*/
    pChar = ( char * ) malloc( sizeof(char) ); 

    
    /* Copiar el string a la memoria reservada*/
    strcpy(pChar, "Anastacia");

    /* Mostrar información*/
    printf("Direccion del puntero pChar: %p\n", &pChar);
    printf("Direccion a la que apunta pChar: %p\n", *pChar);
    printf("Contenido apuntado por pChar: %s\n", pChar);

    /* Liberar memoria*/
    free(pChar);
    pChar = NULL;
}
