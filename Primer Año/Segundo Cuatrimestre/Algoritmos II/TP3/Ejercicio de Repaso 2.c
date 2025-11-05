#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaracion de variables g 
int totalentrada; 
tListaClientes * lista; 
tCliente cliente; 
char continuar; 

// Declaracion estructura lista 
typedef struct {
  char nombreyapellido; 
  int dni; 
  char tipoTarjeta; 
  char nrotarjeta; 
}tCliente; 

typedef struct nodo {
  tCliente cliente; 
  struct nodo * siguiente; 
}tListaClientes; 



//toma de datos 
tomaDatos () { 
  do {
  printf ("nombre y apellido: "); 
  scanf ("%c", &cliente.nombreyapellido); 
  fflush (stdin); 

  printf ("dni: "); 
  scanf ("%d", &cliente.dni); 
  fflush (stdin); 

 printf ("Tipo de Tarjeta: 1-Visa, 2-Mastercard "); 
  scanf ("%c", &cliente.tipoTarjeta); 
  fflush (stdin); 

    if (tipoTarjeta == '1') {
        totalentrada = 12500 * 0.05; 
        return totalentrada; 
        printf ("Valor de la entrada con finalizacion de descuento = %d", totalentrada);
    } else {
    totalentrada = 12500;
    printf ("Valor de la entrada = %d", totalentrada); } 

 printf ("Numero de Tarjeta: "); 
  scanf ("%c", &cliente.nrotarjeta); 
  fflush (stdin); 

  printf ("Desea ingresar otro Cliente? si = si")
    } while (continuar == 'si'|| 'Si'); 
  
}
