#include <stdio.h>
#include <stdlib.h>

/*tipo de dato*/
typedef char string[50];

typedef struct nodo{
	
	string nombre;
	
	struct nodo *siguiente;
	
}t_nodo;

/*variables*/
t_nodo cabeza;
t_nodo fin;


/*prototipos*/
void inicializar_lista();

/*bloque principal*/
int main (){
	
	inicializar_lista();
	
	return 0;
}


/*funciones*/
void inicializar_lista(){
	
	cabeza -> NULL;
	
}


































