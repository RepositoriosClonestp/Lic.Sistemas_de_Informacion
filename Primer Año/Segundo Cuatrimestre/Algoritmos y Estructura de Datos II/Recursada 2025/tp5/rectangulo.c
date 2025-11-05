#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "rectangulo.h"

int main() {
    float base, altura;

    printf("Ingrese la base del rectangulo: ");
    scanf("%f", &base);

    printf("Ingrese la altura del rectangulo: ");
    scanf("%f", &altura);

    // Crear el rectángulo
    tRectangulo r = crearRectangulo(base, altura);

    printf("\nRectangulo creado: base=%.2f, altura=%.2f\n", r.base, r.altura);
    printf("Perimetro: %.2f\n", calcularPerimetro(r));
    printf("Area: %.2f\n", calcularArea(r));

    // Función booleana para saber si es cuadrado o rectángulo
    if (esCuadrado(r))
        printf("Es un cuadrado.\n");
    else
        printf("Es un rectangulo.\n");

    // Modificar dimensiones
    printf("\nIngrese nuevas dimensiones:\n");
    printf("Nueva base: ");
    scanf("%f", &base);
    printf("Nueva altura: ");
    scanf("%f", &altura);

    modificarDimensiones(&r, base, altura);

    printf("\nRectangulo modificado: base=%.2f, altura=%.2f\n", r.base, r.altura);
    printf("Perimetro: %.2f\n", calcularPerimetro(r));
    printf("Area: %.2f\n", calcularArea(r));

    if (esCuadrado(r))
        printf("Es un cuadrado.\n");
    else
        printf("Es un rectangulo.\n");

    return 0;
}


