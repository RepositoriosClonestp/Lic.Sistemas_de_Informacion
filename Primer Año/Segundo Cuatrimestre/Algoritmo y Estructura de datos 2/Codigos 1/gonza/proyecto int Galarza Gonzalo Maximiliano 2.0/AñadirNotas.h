#include<stdio.h>
#include<string.h>
/* Declaracion de tipos de datos personalizados */
typedef char tString[50];

typedef struct{
	int numLibreta;
	tString nombreyApellido;
	int CodDeMateria;
	float NotaObt;
}tRegNotas;

/*Funciones*/
void procesarRegistro();
void ingresarDatos();
void grabarRegistro();
void finalizarRegistro();
void agregarnuevanota();

/* Declaracion de variables */
tRegNotas Notas;

FILE * vArchivo;
int contMov;


/*el archivo se abre modo añadir para que el usuario pueda ingresar nuevos datos al dNotas.dat
(se habre en este modo para que no se pisen los datos perderlos)*/ 
 
void agregarnuevanota(){
	 procesarRegistro();
	 grabarRegistro();
	 finalizarRegistro();
}


 
 
	 
void procesarRegistro(){
vArchivo = fopen("dNotas.dat", "ab");
printf("Abierto para agregar nuevas notas!\n");
system("pause");
system("cls");
}

void ingresarDatos(){
	printf("Ingrese numero de libreta\n");
	scanf("%d", &Notas.numLibreta);
	fflush(stdin);
	printf("Ingrese nombre y apellido\n", 163);
	scanf("%[^\n]s", &Notas.nombreyApellido);
	fflush(stdin);
	
	printf("Ingrese codigo de materia\n", 162, 162, 162);
	scanf("%d", &Notas.CodDeMateria);
	printf("Ingrese nota\n");
	scanf("%f", &Notas.NotaObt);
	
}

void grabarRegistro(){
	char opcion;
	int contMov = 0;
	while (opcion != 's'){
		
		ingresarDatos();
		/*graba en un archivo de 
	datos, los datos que se encuentran en la variable registro apuntada por el puntero del primer parámetro, 
	habitualmente es 1 registro del tamaño que se indica en el segundo parámetro.
	*/
		fwrite(&Notas, sizeof(tRegNotas), 1, vArchivo);
		
		printf("\n\nNota Cargada!!!!...");
		/*cuenta movimiento para depues poder mostrar en pantalla la cantidad cargada*/
		contMov++;
		
		printf("\n\n\t >>>> Presione >ENTER< para realizar otro movimiento...");
		printf("\n\t >>>> Ingrese > s < para finalizar... :");
		fflush(stdin);
		scanf("%c", &opcion);
		system("cls");
		printf("\n >>> Notas Cargadas: %d\n", contMov);
		
}
}

void finalizarRegistro(){
	fclose(vArchivo);
}


