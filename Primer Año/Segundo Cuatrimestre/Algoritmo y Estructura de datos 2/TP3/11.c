#include <stdio.h>

int a = 0;

int factorial(int _a)
{
    if (_a <= 0)
    {
        return 1;
    }
    else
    {
        return factorial(_a - 1) * _a;
    }
}

int main()
{
    printf("ingrese un numero: ");
    scanf("%d", &a);
    printf("%d\n", factorial(a));
    return 1;
}