#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "AñadirNotas.h"

/*define constante maxima*/
#define MAX 100

/* Declaracion de tipos de datos personalizados */
typedef char tString[50];

typedef struct{
	int numLibreta;
	tString nombreyApellido;
	int CodDeMateria;
	float NotaObt;
}tRegAlumnos;

/* Declaracion de variables */
tRegAlumnos Alumnos;
	
FILE * vArchivo;

int	numLibretaAnt;

float AcumNotas;
int contMate;
float notaPromedio;
int ContAlumnos;

tString alumnoMayorPromedio;
tString nombreAlumnoant;
float mayorProm;

int totalAlumnos;

/*Funciones*/

void menu();
void crearArreglo();
void busqueda();
void ordenamiento();

/*corte control*/
void corteControl();

void inicializar();
void procesoCorte();
void finalizar();
void principioCorte();
void unaNota();
void finCorte();

/* Bloque principal */
int main(){
	 menu();

}
/* para operar las funciones realizadas de todo el programa*/
void menu(){
	int n;
	
	printf("Indique que actividad desea realizar: \nPara realizar una Busqueda marque: \t1\nPara realizar un Ordenamiento marque:   2\nPara realizar Corte de control marque:  3\nAgregar nuevo alumno: 4\nPara finalizar marque:0\n");
	scanf("%d", &n);

	switch(n) {
		case 1:
			system("cls");
			busqueda();
			system("pause");
			system("cls");
			menu();
		break;
		case 2:
			system("cls");
			ordenamiento();
			system("pause");
			system("cls");
			menu();
		break;	
		case 3:
			system("cls");
			corteControl();
			system("pause");
			system("cls");
			menu();
		break;
			case 4:
			system("cls");
			agregarnuevanota();
			system("pause");
			system("cls");
			menu();
		break;
		case 0:
			system("cls");
			printf("\n\n");
			printf("Gracias por su tiempo \nTrabajo Realizado por:\nGalarza, Gonzalo Maximilino.\n\n");
			system("pause");
			exit (-1);
		break;
		default:
			system("cls");
			printf("\t\t\t**** ERROR ****\n");
			printf("El comando ingresado no es correcto, verifique y vuelva a intentarlo:\n\n");
			system("pause");
			system("cls");
			menu();
		break;	
	}
}
/* Implementacion de funciones */


/*busqueda secuencial consulta al usuario de 
cuantos elementos quiere que sea el arreglo y genera un arreglo 
de números enteros aleatorios, después el usuario decide que 
numero buscar y lo encuentra, el programa le indica la ubicación
del mismo*/
void busqueda()	{
	int *a;
	int size, n, i, j;
	
	printf("Entre cuantos numeros quiere buscar?\n");
	printf("*Nota: No mas de 100\n");
    scanf("%d", &size);
	if(size<=MAX){
		a = malloc(size * sizeof(int));
    
    srand(time(NULL));
    for(i=0;i<size;i++)
    {
        a[i]=rand()/100;
    }

        for(i=0;i<size;i++)
        {
            printf("%d: %d\n",i,a[i]);
        }
    

    printf("Que numero desea buscar ");
    scanf("%d", &n);
    j = 0;

    for(i=0;i<size;i++)
    {
        if( a[i]==n )
        {
            printf("%d se encuentra en la posicion %d\n",n,i);
            j = 1;
        }
    }
    if(!j)
    {
        printf("No se encontro el numero\n");
    }
 
    free(a);
	}else{
		system("cls");
		printf("El numero ingresado exede el maximo permitido, volver a intentar: \n");
		busqueda();
	}
    
}
/* ordenamiento burbuja consulta al usuario de 
cuantos elementos quiere que sea el arreglo para ordena depues, le advierte que sea no mas de 100 y genera un arreglo 
de números enteros aleatorios de la cantidad de valor puesto por teclado,depues ordena el arreglo de menor a mayor*/
void ordenamiento(){
	int *a;
	int size, n, i, j;
	
	printf("Entre cuantos numeros quiere ordenar? \n");
	printf("*Nota: No mas de 100\n");
    scanf("%d", &size);
	
	if(size<=MAX){
		a = malloc(size * sizeof(int));
    
    srand(time(NULL));
    for(i=0;i<size;i++)
    {
        a[i]=rand()/100;
    }

        for(i=0;i<size;i++)
        {
            printf("%d: %d\n",i,a[i]);
        }
	
	int aux;	
	
	for (i = 0; i < size-1; i++) { 
		for (j = 0; j < size-1; j++) { 
			
			if (a[j] > a[j+1]) { 
				/*intercambio*/
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
			}			
		}		
	}
	printf("\nArreglo ya ordenado de menor a mayor:\n");
	for(i=0;i<size;i++)
        {
            printf("%d, ",a[i]);
        }
    printf("\n"); 
    free(a);
	}else{
		system("cls");
		printf("El numero ingresado exede el maximo permitido, volver a intentar: \n");
		ordenamiento();
	}
    
}
/*funcion que contiene lo necesario para corte de control*/
void corteControl()	{
	inicializar();
	procesoCorte();
	finalizar();
}

void inicializar(){
	
	vArchivo = fopen("dNotas.dat","rb");
	printf("_________________________________________\n");
	printf("|\t*** Listado de promedios ***\t|\n");
	printf("_________________________________________\n");
	printf("|Numero de Libreta \t|Nota Promedio\t|\n");
	printf("_________________________________________\n");
	
	fread(&Alumnos,sizeof(tRegAlumnos),1,vArchivo);

	numLibretaAnt = Alumnos.numLibreta;
	strcpy(nombreAlumnoant, Alumnos.nombreyApellido);
	totalAlumnos= 0;
	mayorProm = 0;
}

void procesoCorte() {
	/*Recorrer todo el archivo */
	while(!feof(vArchivo)) {
		principioCorte();
		while(!feof(vArchivo) && Alumnos.numLibreta == numLibretaAnt){
				unaNota();
				fread(&Alumnos,sizeof(tRegAlumnos),1,vArchivo);	
						
		}
		finCorte();
		
	}
	
}

void principioCorte() {
	/*actuliza los contadores para volver a hacer calculos*/
	AcumNotas=0;
    contMate=0; 
	ContAlumnos=0; 	
}

void unaNota() {
	/*acumulacion y contadores de valores que seran usados en el fin corte*/
	AcumNotas = AcumNotas + Alumnos.NotaObt;
	contMate++;
	
}
	
void finCorte() {
	/*1-contador de alumnos cada vez que entra fin corte 
	2-calculo de notapromedio 
	3-muestra en pantalla valores parciales que ofrece el programa
	4- pregunta si el valor notapromedio calculado es el valor mayor si es correcto reserva el nombre y promedio
	5-acumula contador de alumnos para el total necesario en finalizar
	6-cambia de valor libretaant 
	7-reserva nombre de alumno para asi tener como mostrar en pantalla si es el alumno mayor promedio
	*/
	
	ContAlumnos++;
	notaPromedio = AcumNotas/contMate;
	
	printf("|%d\t\t\t|\t%2.f\t|\n",numLibretaAnt,notaPromedio);
	printf("_________________________________________\n");
	if(mayorProm < notaPromedio){
		mayorProm = notaPromedio;
		strcpy(alumnoMayorPromedio,nombreAlumnoant );
		}
		
			totalAlumnos = totalAlumnos + ContAlumnos;
			
			numLibretaAnt = Alumnos.numLibreta;
			strcpy(nombreAlumnoant, Alumnos.nombreyApellido);
	
}

void finalizar() {
/*mostrar totales y cerrar el archivo*/
	printf("\n\t\tTotal de alumnos:%d\n",totalAlumnos);
	printf("El alumno con mayor promedio es: %s \t su nota:  %2.f\n\n",alumnoMayorPromedio,mayorProm);
		
	fclose(vArchivo);
}
