#include <stdio.h>

int a = 0;
int sumarNaturales(int _a)
{
    if (_a <= 0)
    {
        printf("0 ");
        return 0;
    }
    else
    {
        printf("%d + ", _a);
        return _a + sumarNaturales(_a - 1);
    }
}

int main()
{
    printf("ingrese un numero: ");
    scanf("%d", &a);
    printf("= %d\n", sumarNaturales(a));
    return 1;
}