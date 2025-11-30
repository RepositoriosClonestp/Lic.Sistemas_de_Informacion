/*
 1.5.Ingresar por teclado 10 elementos de tipo char para generar un vector A. A continuación, a partir del 
 vector A, generar un vector B con los mismos elementos, pero en orden inverso. Imprimir 
 simultáneamente ambos vectores. Utilizar una función para generar el vector B, y otra función para 
 mostrar los vectores simultáneamente.
*/


#include <stdio.h>

typedef char tVector[10];

//Declaracion de prototipos de funciones.
void ingresarDatosVectorA(tVector);
void generarVectorB(tVector, tVector);
void mostrarDatos(tVector, tVector);

int main(){
 tVector A, B;
 
 ingresarDatosVectorA(A);
 generarVectorB(A, B);
 mostrarDatos(A, B);
 
 return 0;
}

void ingresarDatosVectorA(tVector pVector){
 int i;
 
 printf("Ingrese los 10 caracteres: \n");
 
 for(i=0; i<10; i++){
  printf("Caracter %d: \n", i+1);
  fflush(stdin);
  scanf("%c", &pVector[i]);
 }
}

void generarVectorB(tVector pVectorA, tVector pVectorB){
 int i;
 
 for(i=0; i<10; i++){
  pVectorB[9-i] = pVectorA[i]; 
 }
}

void mostrarDatos(tVector pVectorA, tVector pVectorB){
 int i;
 
 printf("Vector A: ");
 for(i=0; i<10; i++){
  printf("%c - ", pVectorA[i]);
 }
 
 printf("\nVector B: ");
 for(i=0; i<10; i++){
  printf("%c - ", pVectorB[i]);
 }
}
