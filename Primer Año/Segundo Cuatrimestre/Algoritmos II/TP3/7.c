// 7.
// El siguiente pseudocódigo corresponde a una función que permite sumar los elementos de un vector en forma recursiva:
// Función: sumaVec
// Datos de entrada: un vector de números enteros, representado por la pareja de datos <v, n>. como precondición se considera que el vector ya tiene cargados un conjunto de valores válidos y que n es un valor comprendido entre el cero (el vector puede estar vacío) y NMAX (la dimensión máxima del array).
// Datos de salida: la suma de los elementos del vector, es decir,

// Función sumaVec ( v: tArray; n: Entero): Entero
// Inicio
// Si (n = 0) Entonces
// { la solución para el caso base es directa }
// retorna 0;
// Sino
// { la solución para el caso general es recursiva }
// retorna sumaVec ( v, n-1 ) + v[n];
// Fin-Si
// Fin

#include <stdio.h>
typedef int array[5];
array vector = {1, 2, 3, 4, 5};

int sumaElementosVector(array v, int i)
{
    if (i < 0)
    {
        return 0;
    }
    else
    {
        return sumaElementosVector(v, i - 1) + v[i];
    }
}
int main()
{
    printf("%d", sumaElementosVector(vector, 2));
    return 1;
}