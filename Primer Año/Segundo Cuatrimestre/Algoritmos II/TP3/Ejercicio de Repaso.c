#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaracion de variables globales
int totalEntradasVendidas = 0, contadorVisa = 0, contadorMaster = 0;
char continuar = 's';

// Declaracion de estructuras
typedef struct {
    char nombreyapellido[100];
    int dni;
    char tipoTarjeta;
    char nrotarjeta[16];
} tCliente;

typedef struct nodo {
    tCliente cliente;
    struct nodo *siguiente;
} tListaClientes;

// Prototipos de funciones
void inicializarLista(tListaClientes **lista);
void tomarDatos(tCliente *cliente);
void venderEntrada(tListaClientes **lista);
void mostrarClientesEnEspera(tListaClientes *lista);

int main() {
    tListaClientes *lista = NULL;
    inicializarLista(&lista);

    do {
        venderEntrada(&lista);
        printf("¿Desea ingresar otro Cliente? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    printf("Clientes esperando para comprar entradas:\n");
    mostrarClientesEnEspera(lista);

    printf("Total clientes Visa: %d\n", contadorVisa);
    printf("Total clientes Mastercard: %d\n", contadorMaster);

    return 0;
}

void inicializarLista(tListaClientes **lista) {
    *lista = NULL;
}

void tomarDatos(tCliente *cliente) {
    printf("Nombre y apellido: ");
    scanf("%s", cliente->nombreyapellido);

    printf("DNI: ");
    scanf("%d", &cliente->dni);

    printf("Tipo de Tarjeta (1-Visa, 2-Mastercard): ");
    scanf(" %c", &cliente->tipoTarjeta);

    printf("Numero de Tarjeta: ");
    scanf("%s", cliente->nrotarjeta);
}

void venderEntrada(tListaClientes **lista) {
    tCliente nuevoCliente;
    tomarDatos(&nuevoCliente);

    if (nuevoCliente.tipoTarjeta == '1') {
        float totalentrada = 12500 * 0.95; // Descuento del 5% para Visa
        printf("Valor de la entrada con descuento: $%.2f\n", totalentrada);
        contadorVisa++;
    } else {
        float totalentrada = 12500;
        printf("Valor de la entrada: $%.2f\n", totalentrada);
        contadorMaster++;
    }

    tListaClientes *nuevoNodo = (tListaClientes *)malloc(sizeof(tListaClientes));
    nuevoNodo->cliente = nuevoCliente;
    nuevoNodo->siguiente = NULL;

    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        tListaClientes *temp = *lista;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }

    totalEntradasVendidas++;
}

void mostrarClientesEnEspera(tListaClientes *lista) {
    printf("%-10s %-10s %-20s\n", "Tarjeta", "DNI", "Nombre y Apellido");
    while (lista != NULL) {
        printf("%-10c %-10d %-20s\n", lista->cliente.tipoTarjeta, lista->cliente.dni, lista->cliente.nombreyapellido);
        lista = lista->siguiente;
    }
}
