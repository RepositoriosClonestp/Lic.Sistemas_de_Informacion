#include <stdio.h>
#include <unistd.h>

void cuentaRegresiva(int);

int main() {
	cuentaRegresiva(10);
	return 0;
}

void cuentaRegresiva(int pNro) {
	if(pNro != 0) {
		printf("%d \n", pNro);
		sleep(1);	
		cuentaRegresiva(pNro - 1);		
	}else {
		printf("0\nFIN \n");	
	}
}
