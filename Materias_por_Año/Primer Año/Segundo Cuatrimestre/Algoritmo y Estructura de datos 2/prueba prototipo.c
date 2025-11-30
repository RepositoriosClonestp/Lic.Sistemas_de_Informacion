#include<stdio.h>
float valorAbsoluto (float);
int main(){
	
	float v, a;
	printf("Ingrese un valor numerico: ");
	scanf("%f",&v);
	
	a = valorAbsoluto(v);
	printf("El valor absoluto de %f es %f",v,a);
	return 0;	
}

float valorAbsoluto (float d){
	float valorDevuelto;
	valorDevuelto;
	valorDevuelto = d;
	 if (d < 0){
	  valorDevuelto = - valorDevuelto;
}	
return valorDevuelto;
}
