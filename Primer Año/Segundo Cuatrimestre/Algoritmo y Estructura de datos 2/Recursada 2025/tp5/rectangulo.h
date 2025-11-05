#include <stdio.h>
#include <stdbool.h>

typedef struct {
    float base;
    float altura;
} tRectangulo;

// Crear/Inicializar
tRectangulo crearRectangulo(float base, float altura) {
    tRectangulo r;
    r.base = base;
    r.altura = altura;
    return r;
}

// Calcular perímetro
float calcularPerimetro(tRectangulo r) {
    return 2 * (r.base + r.altura);
}

// Calcular área
float calcularArea(tRectangulo r) {
    return r.base * r.altura;
}

// Modificar dimensiones
void modificarDimensiones(tRectangulo *r, float nuevaBase, float nuevaAltura) {
    r->base = nuevaBase;
    r->altura = nuevaAltura;
}

// Función booleana: ¿es cuadrado?
bool esCuadrado(tRectangulo r) {
    return (r.base == r.altura);
}










