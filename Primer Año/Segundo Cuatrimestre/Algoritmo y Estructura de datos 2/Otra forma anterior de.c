#include<stdio.h>

/*Declaramos variables globales*/
int num1 = 0;
int num2 = 1;

/*Declaramos prototipos*/ 
int restar(int, int);
void mostrarResultado();

int main ()
{ 
 printf("Ingrese un numero: \n");
 scanf("%d",&num1); 
  mostrarResultado();
return 0;    
}

int restar(int nRo1, int nRo2){
  return nRo1 - nRo2;/*Resultado de la operación*/ 
}

void mostrarResultado() {
    printf("El numero anterior al ingresado es: %d \n",restar(num1,num2));
    }
