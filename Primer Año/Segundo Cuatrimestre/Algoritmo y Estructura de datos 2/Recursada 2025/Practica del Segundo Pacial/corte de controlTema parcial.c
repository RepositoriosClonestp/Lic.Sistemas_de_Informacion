#include <stdio.h>

typedef struct {
    int codigoVendedor;
    int dia;
    float montoVenta;
} tRegistro;

int main() {
    FILE * archivo = fopen("Ventas.dat", "rb");
    if (archivo == NULL) {
        printf("Error: No se encuentra el archivo Ventas.dat\n");
        return 1;
    }

    tRegistro reg, regAnterior;
    float totalVendedor = 0;
    int cantVentasVendedor = 0;
    float totalGeneral = 0;
    int cantVendedores = 0;
    int vendedorMayor = -1;
    float mayorTotal = -1;

    // Leer primer registro
    if (fread(&reg, sizeof(tRegistro), 1, archivo) != 1) {
        printf("Archivo vacío.\n");
        fclose(archivo);
        return 0;
    }

    regAnterior = reg;
    totalVendedor = 0;
    cantVentasVendedor = 0;

    printf("\n*** Informe de Ventas por Vendedor ***\n");

    do {
        // Mientras mismo vendedor
        //
        while (!feof(archivo) && reg.codigoVendedor == regAnterior.codigoVendedor) {
            totalVendedor += reg.montoVenta;
            cantVentasVendedor++;

            if (fread(&reg, sizeof(tRegistro), 1, archivo) != 1) {
                break;
            }    
        }

        // Mostrar total y promedio vendedor actual
        printf("Vendedor: %d\n", regAnterior.codigoVendedor);
        printf("Total: $%.2f | Promedio: $%.2f\n", totalVendedor, totalVendedor / cantVentasVendedor);
        printf("--------------------------------------------------\n");

        // Acumular totales generales
        totalGeneral += totalVendedor;
        cantVendedores++;

        // Verificar mayor total
        if (totalVendedor > mayorTotal) {
            mayorTotal = totalVendedor;
            vendedorMayor = regAnterior.codigoVendedor;
        }

        // Preparar para siguiente vendedor
        regAnterior = reg;
        totalVendedor = 0;
        cantVentasVendedor = 0;

    } while (!feof(archivo));

    // Resumen general
    printf("\nRESUMEN GENERAL\n");
    printf("Total general: $%.2f\n", totalGeneral);
    printf("Cantidad de vendedores: %d\n", cantVendedores);
    printf("Vendedor con mayor total: %d ($%.2f)\n", vendedorMayor, mayorTotal);

    fclose(archivo);
    return 0;
}
