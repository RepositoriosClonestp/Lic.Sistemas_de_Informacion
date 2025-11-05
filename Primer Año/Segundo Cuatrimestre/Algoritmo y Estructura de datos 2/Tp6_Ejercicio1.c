/*Ejercicio 1: Una empresa necesita llevar un control de su inventario de los 200 productos que 
comercializa. Se requiere un programa en C que determine el producto con mayor cantidad 
disponible y el producto con menor cantidad disponible. Para ello: 
- Almacene la información de cada producto en un array ingresando por teclado los datos de cada 
producto: nombre del producto (hasta 25 caracteres), cantidad disponible y precio unitario. 
o El nombre del producto debe almacenarse en mayúsculas, para esto se debe disponer de una 
función que reciba un nombre como parámetro y lo convierta a mayúsculas
- Recorra el array para determinar el producto con mayor cantidad disponible y el producto con 
menor cantidad disponible (utilizar 2 funciones diferentes). Al momento de mostrar estos 
resultados por pantalla, en ambos casos se debe mostrar el nombre del producto y la cantidad 
correspondiente. 
**Nota: para simplificar la prueba considere solo 5 productos.*/



#include <stdio.h> // Entrada y Salida de C
#include <string.h> // Parametro de habilitacion para funciones en Cadena

typedef char cadena [25]; // Funcion Cadena maximo 25

typedef struct  //Almacenar informacion sobre los productos
{
	cadena nombre;
	int cantidad;
	float precio_unitario;
} producto;

producto catalogo [5]; // Almacenar hasta 5 productos en el catalogo

void ingresarDatos();  //Declarar Funciones
void recorrer_vector(); // Declarar Funciones
/*void buscar_menor();
void buscar_mayor();*/

int menor; //Declarar Variables Enteras
int mayor; //Declarar Variables Enteras

int main() // Punto de Entrada C
{
	ingresarDatos();
	recorrer_vector();
	return 0; //Punto de Salida
}
//Solicitar Informacion 
void ingresarDatos(){ 
	int i;
	for (i = 0; i < 5; i++) //Bucle x5
	{
		printf("Producto nro %d \n",i); 

		printf("Ingrese el nombre: ");
		scanf("%s", &catalogo[i].nombre); //Direccion de arreglo de caracteres
		fflush(stdin); //Limpiar bucle
		printf("\n");

		printf("Ingrese cantidad: ");
		scanf("%d", &catalogo[i].cantidad); //Direccion de arregle de Caracteres
		fflush(stdin); // Limpiar bucle
		printf("\n");

		printf("Ingrese el precio unitario: ");
		scanf("%f", &catalogo[i].precio_unitario);		
		fflush(stdin);
		printf("\n");

	}
}
// Llamado de Datos Almacenados
void recorrer_vector(){ //Parametro de informacion almacenada
	printf ("----------------------------------\n");
	printf("RECORRIDA DEL VECTOR\n\n");
	int i;
	for (i = 0; i < 5; i++) //bucle
	{ //Impresion de Datos almacenados
		printf("Producto nro %d : \n", i);
		printf("Nombre: %s \n", catalogo[i].nombre);
		printf("Cantidad: %d \n", catalogo[i].cantidad);
		printf("Precio unitario: %.2f \n", catalogo[i].precio_unitario);
	}
} 

