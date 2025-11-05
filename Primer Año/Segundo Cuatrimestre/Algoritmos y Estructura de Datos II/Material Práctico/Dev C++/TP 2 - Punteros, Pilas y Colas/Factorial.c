#include <stdio.h>

int factorial(int);

int main() {
	int nro = factorial( 4 );
	printf("Factorial: %d\n", nro );
	return 0;
}

int factorial( int pNro ) {	
	if( pNro == 0 ) {
		return 1;	
	} else {
		return pNro * factorial( pNro - 1 );
	}			
}

