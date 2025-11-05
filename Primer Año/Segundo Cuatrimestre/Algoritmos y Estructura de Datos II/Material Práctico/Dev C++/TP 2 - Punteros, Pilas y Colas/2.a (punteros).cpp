#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int indice;
typedef indice *apuntIndice;
indice i;
apuntIndice apuntI;

int main() {
    apuntI = (int*) malloc(sizeof(int));
    *apuntI = 2;
    i = 4;
    
    printf(" Direccion: %p", apuntI);
    printf(" Valor: %d", *apuntI);
    return 0;
}
