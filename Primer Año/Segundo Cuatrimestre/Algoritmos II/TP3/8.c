#include <stdio.h>

int b = 0;
int a = 0;

int calcularExponente(int _a, int _b)
{
    if (_b <= 0)
    {
        return 1;
    }
    else
    {
        return _a * (calcularExponente(_a, _b - 1));
    }
}

int main()
{
    printf("ingrese un numero: ");
    scanf("%d", &a);
    printf("ingrese otro numero: ");
    scanf("%d", &b);
    printf("%d\n", calcularExponente(a, b));
    return 1;
}