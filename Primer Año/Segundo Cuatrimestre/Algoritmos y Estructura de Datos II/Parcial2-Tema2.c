/*Objetivo: Programa en lenguaje C donde se pueda cargar las ventas mensuales de cada sucursal y halle por cada sucursal el mes con mayor venta  y la sucursal
que mas ventas tuvo de las 3 en todo el año.
	Estrategia:
				a)Ingreso_Datos():
					-Ventas_mensuales   				valor entero de ventas por 12 meses que contiene un año
					-Titulo								 menor a 50 caracteres
					-promedio							promedio de mayor venta entre 3 sucursales
				b)imprimir_pantalla():
					-Matriz_mayorVenta
					-titulo definido
					-promedio Ventas
					
					
					
*/					
#include <stdio.h>
#include <string.h>

#define SUCURSALES 3
#define MES 12
typedef char string[50];
int i,j;

int mregistroVentas[SUCURSALES][MES];
float vpromedios[SUCURSALES];
string Titulo;
int TotalVentas = 0;

void IngresarDatos();
void CalcularPromedio();
void GenerarPromedio();
void GenerarVectores();
void ImprimirDatos();
void IngresarTitulo();

void IngresarDatos() {
    for ( i = 0; i < SUCURSALES; i++) {
        for ( j = 0; j < MES; j++) {
            printf("Ingrese la cantidad de ventas anuales por mes para la sucursal %d, mes %d: ", i + 1, j + 1);
            scanf("%d", &mregistroVentas[i][j]);
        }
    }
}

void GenerarVectores() {
    for ( i = 0; i < SUCURSALES; i++) {
        for ( j = 0; j < MES; j++) {
            TotalVentas += mregistroVentas[i][j];
        }
        vpromedios[i] = TotalVentas / MES;
    }
}

void IngresarTitulo() {
    printf("Ingrese un titulo para el informe (menos de 50 caracteres): ");
    scanf("%s", Titulo);
    int longitud = strlen(Titulo);
    if (longitud > 50) {
        printf("Titulo no valido");
        return;
    }
}

void ImprimirDatos() {
    printf("Titulo: %s\n", Titulo);
    for ( i = 0; i < SUCURSALES; i++) {
        printf("Sucursal %d - Ventas mensuales: ", i + 1);
        for ( j = 0; j < MES; j++) {
            printf("%d ", mregistroVentas[i][j]);
        }
        printf("\n");
    }
    for ( i = 0; i < SUCURSALES; i++) {
        printf("Promedio de ventas para la sucursal %d: %.2f\n", i + 1, vpromedios[i]);
    }
}

int main() {
    IngresarTitulo();
    IngresarDatos();
    GenerarVectores();
    ImprimirDatos();

    return 0;
}
