
/*Rodriguez Agustina Ailen 
  Ramirez Daiana Noelia */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 50
/*3. Un aeropuerto requiere un programa que permita visualizar en las pantallas led, los vuelos próximos a 
partir. Para ello se almacena en una lista enlazada la siguiente información de los vuelos: nro. de vuelo, 
origen, destino, hora de embarque(string), tipo de estado (1-En horario 2-Con demoras 3-Cancelado), 
posición en la lista. Los vuelos se insertan en la lista, según el orden en el cual despegarán.  Se requiere:  
• Codificar en lenguaje C, las estructuras de datos necesarias para la declaración del tipo tVuelos 
adecuado. 
• Una función que permita visualizar el detalle de vuelos según el tipo de estado que se recibe como 
parámetro. El formato de impresión solicitado es el siguiente: 
                          *** Vuelos “con demoras” *** 
                    -------------------------------------------------------------
                        Nro.vuelo        Origen         Destino       Embarque 
                    -------------------------------------------------------------
                          1452      Buenos Aires      Corrientes      14.45 hs 
                          1456      Buenos Aires      Córdoba         16.30 hs 
                    -------------------------------------------------------------
                                 Total de vuelos con demoras: 2 
• Una función que permita quitar un vuelo de la lista, una vez que despegó. Utilizar el algoritmo 
“Eliminar k o Eliminar de Pos”. Al quitar el vuelo de la lista se debe emitir la información del vuelo que 
despegó. */
/* Definición de tipos de datos*/
typedef char tString[MAX];

typedef struct {
    int nroVuelo;
    tString origen;
    tString destino;
    tString hEmbarque;
    int estado; /* 1-En horario, 2-Con demoras, 3-Cancelado*/
} tDatosVuelo;

typedef struct nodo {
    tDatosVuelo vuelo;
    struct nodo *siguiente;
} tVuelos;

tVuelos *vuelos = NULL;

/* Declaración de funciones*/
void inicializarLista();
bool listaVacia();
void insertarPrimero(tDatosVuelo);
void insertarAdelante(tDatosVuelo);
void insertarElemento(tDatosVuelo);
void eliminarPrimero();
void visualizarVuelos();
void visualizarVuelosPorEstado(int);
int cantidadVuelos();
void insertarSegunPosicion(tDatosVuelo, int);
void eliminarSegunPosicion(int);
void menu();

/* Función principal*/
int main() {
    menu();
    return 0;
}

/* Implementación de funciones*/
void inicializarLista() {
    vuelos = NULL;
}

bool listaVacia() {
    return (vuelos == NULL);
}

void insertarPrimero(tDatosVuelo pVuelo) {
    tVuelos *nuevoNodo = (tVuelos *)malloc(sizeof(tVuelos));
    nuevoNodo->vuelo = pVuelo;
    nuevoNodo->siguiente = vuelos;
    vuelos = nuevoNodo;
    printf("---- Primer vuelo agregado correctamente! ----\n");
}

void insertarAdelante(tDatosVuelo pVuelo) {
    tVuelos *nuevoNodo = (tVuelos *)malloc(sizeof(tVuelos));
    nuevoNodo->vuelo = pVuelo;
    nuevoNodo->siguiente = vuelos;
    vuelos = nuevoNodo;
    printf("----> Se agrego nuevo vuelo <----\n");
}

void insertarElemento(tDatosVuelo pVuelo) {
    if (listaVacia())
        insertarPrimero(pVuelo);
    else
        insertarAdelante(pVuelo);
}

void eliminarPrimero() {
    tVuelos *aux;
    if (!listaVacia()) {
        aux = vuelos;
        vuelos = vuelos->siguiente;
        printf("Vuelo %d con origen %s y destino %s despego y fue eliminado.\n", aux->vuelo.nroVuelo, aux->vuelo.origen, aux->vuelo.destino);
        free(aux);
    } else {
        printf("*****No se encontro vuelo para eliminar!*****\n");
    }
}

void visualizarVuelos() {
    tVuelos *aux = vuelos;
    if (!listaVacia()) {
        printf("\nLista de Vuelos:\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("  Nro.vuelo    Origen          Destino         Embarque   Estado de Vuelo\n");
        printf("-----------------------------------------------------------------------------\n");
        while (aux != NULL) {
            printf("  %d        %s       %s       %s       %s\n", aux->vuelo.nroVuelo, aux->vuelo.origen, aux->vuelo.destino, aux->vuelo.hEmbarque, 
                (aux->vuelo.estado == 1) ? "En horario" : (aux->vuelo.estado == 2) ? "Con demoras" : "Cancelado");
            aux = aux->siguiente;
        }
        printf("-----------------------------------------------------------\n");
    } else {
        printf("\nNO EXISTEN VUELOS EN LA LISTA\n");
    }
    printf("\n");
}

void visualizarVuelosPorEstado(int estado) {
    tVuelos *aux = vuelos;
    int total = 0;
    if (!listaVacia()) {
        switch (estado) {
            case 1: printf("\n*** Vuelos en horario ***\n"); break;
            case 2: printf("\n*** Vuelos con demoras ***\n"); break;
            case 3: printf("\n*** Vuelos cancelados ***\n"); break;
            default: printf("\n*** Estado no valido ***\n"); return;
        }
        printf("-----------------------------------------------------------\n");
        printf("  Nro.vuelo    Origen         Destino        Embarque\n");
        printf("-----------------------------------------------------------\n");
        while (aux != NULL) {
            if (aux->vuelo.estado == estado) {
                printf("  %d        %s       %s       %s\n", aux->vuelo.nroVuelo, aux->vuelo.origen, aux->vuelo.destino, aux->vuelo.hEmbarque);
                total++;
            }
            aux = aux->siguiente;
        }
        printf("-----------------------------------------------------------\n");
        printf("  Total de vuelos: %d\n", total);
    } else {
        printf("\nNO EXISTEN VUELOS EN LA LISTA\n");
    }
    printf("\n");
}

int cantidadVuelos() {
    tVuelos *aux = vuelos;
    int cantidad = 0;
    while (aux != NULL) {
        cantidad++;
        aux = aux->siguiente;
    }
    return cantidad;
}

void insertarSegunPosicion(tDatosVuelo pVueloNuevo, int posicion) {
    tVuelos *nuevoNodo, *aux = vuelos;
    int i;
    if (posicion == 1) {
        insertarPrimero(pVueloNuevo);
        return;
    }
    for (i = 1; i < posicion - 1 && aux != NULL; i++) {
        aux = aux->siguiente;
    }
    if (aux != NULL) {
        nuevoNodo = (tVuelos *)malloc(sizeof(tVuelos));
        nuevoNodo->vuelo = pVueloNuevo;
        nuevoNodo->siguiente = aux->siguiente;
        aux->siguiente = nuevoNodo;
        printf("Vuelo se agrego en la posicion %d!\n", posicion);
    } else {
        printf("**** No se puede agregar vuelo en la posicion %d! ****\n", posicion);
    }
}

void eliminarSegunPosicion(int posicion) {
    tVuelos *nodoSuprimir, *aux = vuelos;
    int i;
    if (posicion == 1) {
        eliminarPrimero();
        return;
    }
    for (i = 1; i < posicion - 1 && aux != NULL; i++) {
        aux = aux->siguiente;
    }
    if (aux != NULL && aux->siguiente != NULL) {
        nodoSuprimir = aux->siguiente;
        aux->siguiente = nodoSuprimir->siguiente;
        printf("Vuelo %d con origen %s y destino %s fue eliminado.\n", nodoSuprimir->vuelo.nroVuelo, nodoSuprimir->vuelo.origen, nodoSuprimir->vuelo.destino);
        free(nodoSuprimir);
    } else {
        printf("**** No se puede eliminar un vuelo de la posicion %d! ****\n", posicion);
    }
}

void menu() {
    int opcion, estado, posicion;
    tDatosVuelo vuelo;
    inicializarLista();

    do {
        system("cls"); /* Limpia la pantalla al inicio del ciclo del menu*/

        printf("\n_________MENU DE VUELOS_________\n");
        printf("1. Insertar vuelo\n");
        printf("2. Visualizar todos los vuelos\n");
        printf("3. Visualizar vuelos por estado\n");
        printf("4. Eliminar primer vuelo\n");
        printf("5. Insertar vuelo en una posicion\n");
        printf("6. Eliminar vuelo por posicion\n");
        printf("7. Cantidad de vuelos\n");
        printf("8. Salir\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese nro de vuelo: ");
                scanf("%d", &vuelo.nroVuelo);
                printf("Ingrese origen: ");
                scanf("%s", vuelo.origen);
                printf("Ingrese destino: ");
                scanf("%s", vuelo.destino);
                printf("Ingrese hora de embarque: ");
                scanf("%s", vuelo.hEmbarque);
                printf("Ingrese estado (1-En horario, 2-Con demoras, 3-Cancelado): ");
                scanf("%d", &vuelo.estado);
                insertarElemento(vuelo);
                break;
            case 2:
                visualizarVuelos();
                break;
            case 3:
                printf("Ingrese estado a visualizar (1-En horario, 2-Con demoras, 3-Cancelado): ");
                scanf("%d", &estado);
                visualizarVuelosPorEstado(estado);
                break;
            case 4:
                eliminarPrimero();
                break;
            case 5:
                printf("Ingrese nro de vuelo: ");
                scanf("%d", &vuelo.nroVuelo);
                printf("Ingrese origen: ");
                scanf("%s", vuelo.origen);
                printf("Ingrese destino: ");
                scanf("%s", vuelo.destino);
                printf("Ingrese hora de embarque: ");
                scanf("%s", vuelo.hEmbarque);
                printf("Ingrese estado (1-En horario, 2-Con demoras, 3-Cancelado): ");
                scanf("%d", &vuelo.estado);
                printf("Ingrese posicion: ");
                scanf("%d", &posicion);
                insertarSegunPosicion(vuelo, posicion);
                break;
            case 6:
                printf("Ingrese posicion a eliminar: ");
                scanf("%d", &posicion);
                eliminarSegunPosicion(posicion);
                break;
            case 7:
                printf("Cantidad de vuelos en la lista: %d\n", cantidadVuelos());
                break;
            case 8:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }

        /* Pausar para que el usuario vea el mensaje antes de que la pantalla se limpie*/
        if (opcion != 2 && opcion != 3) {
            printf("\nPresione Enter para continuar...");
            getchar();  /* Espera a que se presione Enter*/
            getchar();  /* Para manejar el '\n' */
        }

    } while (opcion != 8);
}

