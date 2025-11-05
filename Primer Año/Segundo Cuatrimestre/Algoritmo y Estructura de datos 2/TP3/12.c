#include <stdio.h>

int a = 0;

int fibonacci(int _a)
{
    if (_a <= 0)
    {
        return 0;
    }
    if (_a <= 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(_a - 1) + fibonacci(_a - 2);
    }
}

int main()
{
    printf("ingrese un numero: ");
    scanf("%d", &a);
    printf("%d\n", fibonacci(a));
    return 1;
}