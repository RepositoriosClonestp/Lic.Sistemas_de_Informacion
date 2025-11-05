#include <stdio.h>
#include <iostream>
#include <string.h>

void alReves(int);

int main() {
	int nro;
	
	printf(" Ingrese numero para invertirlo: ");
	scanf("%d", &nro);
	alReves(nro);
	return 0;
}

void alReves(int pNro) {
		if (pNro >= 1){
			printf("%d", pNro % 10);
			alReves(pNro/10);
		}
}
