#include <stdio.h>

void cuentaRegresiva(int);

int main() {
	cuentaRegresiva(10);
	return 0;
}

void cuentaRegresiva(int pNro) {
	if(pNro != 0) {
		printf("%d \n", pNro);	
		cuentaRegresiva(pNro - 1);		
	}else {
		printf("0\nFIN \n");	
	}
}

