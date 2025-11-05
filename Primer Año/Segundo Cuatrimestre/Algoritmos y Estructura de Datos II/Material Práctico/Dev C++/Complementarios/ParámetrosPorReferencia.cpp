#include <stdio.h>

void intercambio(int *, int *);

int main(){
	int n1, n2;
	n1 = 5;
	n2 = 10;
	intercambio(&n1, &n2);
	printf("%d %d", n1, n2);
	
	return 0;
}

void intercambio(int *x, int *y){
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}
