#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITULO "\n*** Informe de Transacciones Bancarias por Cliente ***\n"

typedef struct {
    int cliente;   /* Número de cliente */
    int dia;       /* Día */
    float monto;   /* Monto */
    char tipo;     /* 'D' depósito, 'R' retiro */
} tTransaccion;

void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unRegistro();
void finCorte();

FILE *archivo;
tTransaccion reg, regAnt;
int lecturaOK;

/* Totales por cliente */
int opsCliente;
float depositadoCliente, retiradoCliente;

/* Totales generales */
int totalClientes;
int clientConMasOps;
int maxOps;
float totalDepositadoAll, totalRetiradoAll;
int totalOperacionesAll;

int main() {
    inicializacion();
    procesoCorte();
    finalizacion();
    return 0;
}

void inicializacion() {
    archivo = fopen("Transacciones.dat", "rb");
    if (archivo == NULL) {
        printf("No se encuentra el archivo Transacciones.dat\n");
        exit(EXIT_FAILURE);
    }

    /* Leer primer registro para iniciar el proceso de corte */
    lecturaOK = (fread(&reg, sizeof(tTransaccion), 1, archivo) == 1);
    if (!lecturaOK) {
        printf("Archivo vacío o sin registros.\n");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    regAnt = reg;

    /* Inicializar totales generales */
    totalClientes = 0;
    clientConMasOps = 0;
    maxOps = 0;
    totalDepositadoAll = 0.0f;
    totalRetiradoAll = 0.0f;
    totalOperacionesAll = 0;

    printf("%s", TITULO);
}

void procesoCorte() {
    while (1) {
        principioCorte();

        /* Encabezado del cliente */
        printf("\nCliente: %d\n\n", regAnt.cliente);
        printf("Dia\tMonto\t\tTipo\n");
        printf("-------------------------------\n");

        /* Procesar todas las transacciones del mismo cliente */
        while (lecturaOK && reg.cliente == regAnt.cliente) {
            /* Imprimir el registro actual */
            printf("%2d\t$%8.2f\t%s\n",
                   reg.dia,
                   reg.monto,
                   (reg.tipo == 'D' || reg.tipo == 'd') ? "Depósito" : "Retiro");

            /* Acumular en los totales del cliente y generales */
            unRegistro();

            /* Leer siguiente registro (si hay) */
            lecturaOK = (fread(&reg, sizeof(tTransaccion), 1, archivo) == 1);
        }

        finCorte();

        /* Si ya no hay más registros, salir */
        if (!lecturaOK)
            break;

        /* Preparar siguiente cliente */
        regAnt = reg;
    }
}

void principioCorte() {
    opsCliente = 0;
    depositadoCliente = 0.0f;
    retiradoCliente = 0.0f;
}

void unRegistro() {
    if (reg.tipo == 'D' || reg.tipo == 'd') {
        depositadoCliente += reg.monto;
        totalDepositadoAll += reg.monto;
    } else if (reg.tipo == 'R' || reg.tipo == 'r') {
        retiradoCliente += reg.monto;
        totalRetiradoAll += reg.monto;
    }
    opsCliente++;
    totalOperacionesAll++;
}

void finCorte() {
    /* Mostrar totales del cliente */
    printf("-------------------------------\n");
    printf("Total depositado: $%.2f | Total retirado: $%.2f | Operaciones: %d\n",
           depositadoCliente, retiradoCliente, opsCliente);

    /* Actualizar resumen general */
    totalClientes++;
    if (opsCliente > maxOps) {
        maxOps = opsCliente;
        clientConMasOps = regAnt.cliente;
    }
}

void finalizacion() {
    printf("\n================ RESUMEN GENERAL ================\n");
    printf("Cantidad de clientes procesados: %d\n", totalClientes);
    if (totalClientes > 0) {
        printf("Cliente con mayor cantidad de operaciones: %d (%d operaciones)\n",
               clientConMasOps, maxOps);
    }
    printf("Total depositado (general): $%.2f\n", totalDepositadoAll);
    printf("Total retirado (general):  $%.2f\n", totalRetiradoAll);
    printf("Total de operaciones (general): %d\n", totalOperacionesAll);

    fclose(archivo);
}
