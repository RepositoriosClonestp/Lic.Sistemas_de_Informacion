#include<stdio.h>

float unFloat = 3.4E+38;
double unDouble = 1.7E+308;
int unEntero = 2147483647;
short unShort = 32767;
char unCaracter = 'Z';
long unLong = 2147483647;

int main(){
	printf("El tamaño de la variable de tipo: \n");
	printf("float     es %d bytes y su valor es: %e \n",sizeof(unFloat),unFloat);
	printf("double    es %d bytes y su valor es: %E \n", sizeof(unDouble),unDouble);
	printf("int       es %d bytes y su valor es: %d\n",sizeof(unEntero),unEntero);
	printf("short     es %d bytes y su valor es: %d \n", sizeof(unShort),unShort);
	printf("char      es %d bit y su valor es:   %c \n",sizeof(unCaracter),unCaracter);
	printf("long      es %d bytes y su valor es: %ld \n",sizeof(unLong),unLong);
	
}
