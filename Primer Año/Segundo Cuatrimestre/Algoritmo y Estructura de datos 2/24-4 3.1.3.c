#include <stdio.h>
#define MAX 10

void ingresarDatos();
void mostrarTabla();

int nro;

int main ()
{
	ingresarDatos();
    mostrarTabla();
	
	return 0;
}

void ingresarDatos()
{
	printf("Ingrese un numero entero: \n");
	scanf("%d",&nro);
	
}

void mostrarTabla (){
	int i;
	
	printf ("----------------------\n");
	printf("Tabla del %d \n",nro);
	printf ("----------------------\n");
	
for (i=0; i<=MAX; i++)
{
	printf ("\t %d x %d = %d \n", nro, i, nro*i);
}


}

/*for hasta que complete maximo en este caso se ejecuta hasta que el amximo sea 10*/
