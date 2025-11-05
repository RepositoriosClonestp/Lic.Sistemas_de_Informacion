#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int cosa;
typedef cosa *apuntadorACosa;
cosa cc, c;
apuntadorACosa apuntC, apuntCC;

int main() {
    apuntC = NULL;
    apuntCC =(cosa*) malloc(sizeof(int)); // tipo (*) malloc (sizeof(tipo))
    *apuntCC = cc;
    printf(" 1) Direccion de apuntC: %p", &apuntC);
    printf("\n 1) Direccion apuntada de apuntC: %p", apuntC);
    printf("\n 2) Direccion de apuntCC: %p", &apuntCC);
    printf("\n 2) Direccion apuntada de apuntCC: %p", apuntCC);
    printf("\n 3) Entero no asignado: %d", c);
    printf("\n 4) Entero no asignado: %d", cc);
    printf("\n 5) ApuntaCC a nada : %d", *apuntCC);
    printf("\n 6) ApuntaC a nada: %d", *apuntC);
    return 0;
}

