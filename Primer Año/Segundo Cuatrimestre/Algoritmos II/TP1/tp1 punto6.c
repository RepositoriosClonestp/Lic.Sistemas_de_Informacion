#include <stdio.h>
#include <stdlib.h>

typedef char *apuntadorC; 
apuntadorC a1, a2; 


int main () {
	a1 = malloc(sizeof(char)); 
	a2 = malloc (sizeof(char)); 
	*a1 = 'A'; 
	*a2 = 'B'; 
	printf ("%c\n", *a1); 
	printf("%c\n", *a2);
	return 0; 	
}
