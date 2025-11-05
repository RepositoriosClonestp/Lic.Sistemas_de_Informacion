#define TITULO "Campana de vacunacion - Provincia de Corrientes"
#define LINEA "******************"

#include <stdio.h>
#include <stdlib.h>


//variables

int dni, edad, tipoVacuna, nroDosis, lugarNum;
int vacunados, vacunadoGripe, vacunados_covid_menores;
char *lugares[] ={"CAP","Facultad de Medicina"};
char *vacunas[] ={"Antigripal", "Covid"};
float porcentaje;

//prototipos
void inicializarVariables();
void ingresarDatos();
void imprimirEnPantalla();
void procesarDatos();
float porcentaje_covid_menores(int, int);
void imprimirInforme(float);


int main(){
 inicializarVariables();
do{
 ingresarDatos();
 imprimirEnPantalla();
if (dni >0){
 procesarDatos();
 porcentaje = porcentaje_covid_menores(vacunados_covid_menores, vacunados);
}
} while(dni > 0);

 imprimirInforme(porcentaje);
return 0;
}

void inicializarVariables(){
 vacunados = 0;
 vacunadoGripe = 0;
 vacunados_covid_menores = 0;
}
void ingresarDatos(){
 printf("\nIngrese su DNI (0 para terminar):\n");
 scanf("%d", &dni);
if (dni >0){

 printf("Ingrese su edad: \n");
 scanf("%d", &edad);

 printf("Ingrese el tipo de vacuna: (1- Antigripal, 2- Covid)\n");
 scanf("%d", &tipoVacuna);
 if (tipoVacuna > 2 || tipoVacuna <1){
  printf("Tipo de vacuna invalida.\n");
  exit(0);
 }

 printf("Ingrese el numero de dosis que tiene:\n");
 scanf("%d", &nroDosis);


 printf("Ingrese el lugar de vacunacion: (1-CAP, 2-Facultad de Medicina) \n");
 scanf("%d", &lugarNum);
 if (lugarNum > 2 || lugarNum < 1){
  printf("Lugar invalido.\n");
  exit(0);
 }
 fflush(stdin);
}
}


void imprimirEnPantalla(){

char *lugarNombre = lugares[tipoVacuna -1];
char *vacunaNombre = vacunas[tipoVacuna -1];
if (dni > 0){
 printf("%s - DNI: %d Edad: %d Lugar: %s \n", vacunaNombre, dni, edad, lugarNombre);
}
}

void procesarDatos(){
 vacunados++;

 if (tipoVacuna == 1){
  vacunadoGripe++;
 }
 else if (tipoVacuna == 2 && edad < 19 && nroDosis > 4)
 {
  vacunados_covid_menores++;
 }

}

float porcentaje_covid_menores(int a, int b){

 return (float) a / b * 100;

}

void imprimirInforme(float porcentaje){

printf("%s\n", LINEA);
printf("-----%s-----\n", TITULO);
printf("%s\n", LINEA);
printf("Cantidad de vacunados TOTALES %d\n", vacunados);
printf("Cantidad de vacunados Antigripal: %d\n", vacunadoGripe);
printf("Cantidad de vacunados COVID con 5ta dosis menores de edad:%d\n", vacunados_covid_menores);
printf("Porcentaje con quinta dosis menores de edad sobre total de vacunados: %.2f%%\n", porcentaje);
}
