#include <stdio.h>
#include <string.h>
typedef char string[];
string palabra = "reconocer";

int funcionPalindroma(int _inicio, int _fin, string _palabra)
{
    printf("%d", _inicio);
    printf("%c", _palabra[_inicio]);
    printf("%d", _fin);
    printf("%c\n", _palabra[_fin]);

    if (_inicio == _fin)
    {
        printf("Es palindroma\n");
        return 1;
    }
    if (_palabra[_inicio] == _palabra[_fin])
    {
        funcionPalindroma(_inicio + 1, _fin - 1, _palabra);
    }
    else
    {
        printf("No es palindroma\n");
        return 1;
    }
}

int main()
{
    // printf("ingrese una palabra: ");
    // scanf("%s", &palabra);
    int inicio = 0;
    int fin = sizeof(palabra) - 2;
    printf("%d\n", funcionPalindroma(inicio, fin, palabra));
    return 1;
}
// R  E  C  O  N  O  C  E  R

// 0  1  2  3  4  5  6  7  8

//