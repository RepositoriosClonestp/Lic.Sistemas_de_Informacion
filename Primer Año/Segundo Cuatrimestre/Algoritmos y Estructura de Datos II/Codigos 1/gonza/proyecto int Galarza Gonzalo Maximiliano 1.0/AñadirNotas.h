#include<stdio.h>
#include<string.h>

typedef char tString[50];

typedef struct{
	int numLibreta;
	tString nombreyApellido;
	int CodDeMateria;
	float NotaObt;
}tRegNotas;


void procesarRegistro();
void ingresarDatos();
void grabarRegistro();
void finalizarRegistro();
void agregarnuevanota();

tRegNotas Notas;

FILE * vArchivo;
int contMov;


 
 
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
		fwrite(&Notas, sizeof(tRegNotas), 1, vArchivo);
		
		printf("\n\nNota Cargada!!!!...");
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


