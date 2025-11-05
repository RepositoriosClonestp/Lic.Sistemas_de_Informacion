#include <stdio.h>

int divisionRecursiva(int,int);

int main()
{
	int resultado = divisionRecursiva(66,11);//10 / 2 = 5
	printf("Resultado %d: ",resultado);//5
	return 0;
}

int divisionRecursiva(int dividendo, int divisor)
{
	printf(" divisionRecursiva ( %d,%d); \n",dividendo,divisor );
	if( divisor > dividendo )
	{
		printf(" resultado: %d \n",0);
		return 0;
	}
	else
	{	
		dividendo = dividendo - divisor;
		int resultado =   1 + divisionRecursiva ( dividendo,divisor);
		printf(" resultado: %d \n",resultado);
		return resultado;
	}
	
}
