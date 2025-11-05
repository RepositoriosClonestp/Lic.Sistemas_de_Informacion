#include <stdio.h>

int intercambio(int, int);

int main(){
	int n1, n2, c;
	n1 = 5;
	n2 = 6;
	c=intercambio(n1, n2);
	printf("%d %d %d", n1, n2, c);
	
	return 0;
}

int intercambio(int a, int b){
	return a + b;
}
