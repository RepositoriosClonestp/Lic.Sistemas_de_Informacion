
#include <stdio.h>
#include <string.h>

typedef char cadena [25];

typedef struct 
{
	cadena nombre;
	int cantidad;
	float precio_unitario;
} producto;

producto catalogo [5];

void ingresarDatos();
void recorrer_vector();
/*void buscar_menor();
void buscar_mayor();*/

int menor;
int mayor;

int main()
{
	ingresarDatos();
	recorrer_vector();
	return 0;
}

void ingresarDatos(){
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("Producto nro %d \n",i);

		printf("Ingrese el nombre: ");
		scanf("%s", &catalogo[i].nombre);
		fflush(stdin);
		printf("\n");

		printf("Ingrese cantidad: ");
		scanf("%d", &catalogo[i].cantidad);
		fflush(stdin);
		printf("\n");

		printf("Ingrese el precio unitario: ");
		scanf("%f", &catalogo[i].precio_unitario);		
		fflush(stdin);
		printf("\n");

	}
}

void recorrer_vector(){
	printf("RECORRIDA DEL VECTOR\n\n");
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("Producto nro %d : \n", i);
		printf("Nombre: %s \n", catalogo[i].nombre);
		printf("Cantidad: %d \n", catalogo[i].cantidad);
		printf("Precio unitario: %.2f \n", catalogo[i].precio_unitario);
	}
}
