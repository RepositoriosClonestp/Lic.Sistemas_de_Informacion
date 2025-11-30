/*3.1.Para emitir los certificados de aprobación de un curso de Python, se dispone de una planilla en la que se
informan en columnas diferentes el nombre y el apellido de los participantes. Escribir un programa que
lea dos datos de tipo cadena, correspondientes al nombre y apellido, respectivamente. Utilice una
función que reciba como parámetro el nombre y el apellido y concatene en una sola cadena el apellido y
nombre, separados por coma. Mostrar en pantalla la nueva cadena y la longitud de la misma. El
programa termina cuando el usuario indique una condición de fin de ingreso de datos.
*/
#include <stdio.h>
#include<string.h>

typedef char string [50];

string Nombre;
string Apellido;
string nombre_apellido;
int longitud;
char continuar;

void ingresoDatos();
void analisisDatos();
void imprimirPantalla();



int main(){
	do{
		ingresoDatos();
		analisisDatos();
		imprimirPantalla();
    }while(continuar == '1');
	
}

void ingresoDatos(){
	
	printf("Ingrese nombre: \n");
	scanf("%s",&Nombre);
	fflush(stdin);
	
	printf("Ingrese apellido: \n");
	scanf("%s",&Apellido);
	fflush(stdin);
	
}

void analisisDatos(){

	strcat (nombre_apellido, Nombre);
	strcat (nombre_apellido, ",");
	strcat (nombre_apellido, " ");
	strcat (nombre_apellido, Apellido);	

	
}

void imprimirPantalla(){
	
	longitud=strlen(nombre_apellido);
	printf("La cadena concatenada es: %s \n", nombre_apellido);
	printf("La longitud de la cadena es: %d \n", longitud);
	printf("Desea seguir ingresando datos? 1- SI 0- NO \n");
	scanf("%c",&continuar);
	fflush(stdin);
}
