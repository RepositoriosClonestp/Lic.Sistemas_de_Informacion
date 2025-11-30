#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Para usar bool


// ESTRUCTURAS Y FUNCIONES GENÉRICAS PARA COLAS (Reutilizadas del contexto)


// Definicion de la estructura para un nodo generico de cola
typedef struct nodoColaGenerico {
    void *dato; // Puntero generico para almacenar cualquier tipo de dato
    struct nodoColaGenerico *siguiente;
} tNodoColaGenerico;

// Definicion de la estructura para la cola generica
typedef struct {
    tNodoColaGenerico *frente; // Puntero al primer elemento de la cola
    tNodoColaGenerico *final;  // Puntero al último elemento de la cola
    int cantidadElementos;     // Contador de elementos en la cola
} tColaGenerica;

// Inicializa la cola
void inicializarCola(tColaGenerica *cola) {
    cola->frente = NULL;
    cola->final = NULL;
    cola->cantidadElementos = 0;
}

// Verifica si la cola esta vacia
bool estaVaciaCola(tColaGenerica *cola) {
    return (cola->frente == NULL);
}

// Inserta un elemento al final de la cola (Encolar)
// dato: puntero al dato a encolar
// tamanoDato: tamaño en bytes del dato
void encolar(tColaGenerica *cola, void *dato, size_t tamanoDato) {
    tNodoColaGenerico *nuevoNodo = (tNodoColaGenerico *)malloc(sizeof(tNodoColaGenerico));
    if (nuevoNodo == NULL) {
        printf("Error: No hay memoria disponible para el nuevo nodo de cola.\n");
        exit(1);
    }
    nuevoNodo->dato = malloc(tamanoDato); // Asignar memoria para el dato
    if (nuevoNodo->dato == NULL) {
        printf("Error: No hay memoria disponible para el dato en cola.\n");
        free(nuevoNodo);
        exit(1);
    }
    memcpy(nuevoNodo->dato, dato, tamanoDato); // Copiar el dato
    nuevoNodo->siguiente = NULL;

    if (estaVaciaCola(cola)) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
    cola->cantidadElementos++;
}

// Elimina y devuelve el elemento del frente de la cola (Desencolar)
// Retorna un puntero al dato desencolado. El llamador es responsable de liberar esta memoria.
void *desencolar(tColaGenerica *cola) {
    if (estaVaciaCola(cola)) {
        printf("Error: La cola esta vacia.\n");
        return NULL;
    }
    tNodoColaGenerico *nodoAEliminar = cola->frente;
    void *datoDesencolado = nodoAEliminar->dato; // El dato ya esta asignado en el heap

    cola->frente = nodoAEliminar->siguiente;
    if (cola->frente == NULL) { // Si la cola queda vacia
        cola->final = NULL;
    }
    free(nodoAEliminar); // Liberar el nodo, no el dato
    cola->cantidadElementos--;
    return datoDesencolado; // El llamador es responsable de liberar este dato
}

// Obtiene el elemento del frente sin eliminarlo 
void *frenteCola(tColaGenerica *cola) {
    if (estaVaciaCola(cola)) {
        printf("Error: La cola esta vacia.\n");
        return NULL;
    }
    return cola->frente->dato;
}

// Vacia completamente la cola y libera toda la memoria de los nodos y los datos
void vaciarCola(tColaGenerica *cola) {
    while (!estaVaciaCola(cola)) {
        void *dato = desencolar(cola);
        free(dato); // Liberar la memoria del dato almacenado
    }
    printf("Cola vaciada completamente.\n");
}

// =============================================================================
// EJERCICIO 3: CENTRO DE DISTRIBUCIÓN (PAQUETES)
// =============================================================================

// Definicion de la estructura para un paquete
typedef struct {
    int codigoUnico;
    char destinatario[100];
    char direccion[200];
    char codigoPostal[10];
    bool esFragil; // true si es fragil, false si no
} tPaquete;

/* a) Codificar en lenguaje C, las estructuras de datos necesarias para la declaración del tipo tPaquetes adecuado. 
La estructura tPaquete ya está definida arriba. La cola genérica tColaGenerica y sus funciones son adecuadas para manejar 
tPaquete.

b) Una función que permita indicar que un paquete se almacenó en el camión, para ello, se debe obtener el próximo paquete, 
indicar con una leyenda que se insertará en el camión y quitarlo de la cola de paquetes.*/

void almacenarProximoPaqueteEnCamion(tColaGenerica *cola) {
    if (estaVaciaCola(cola)) {
        printf("La cola de paquetes esta vacia. No hay paquetes para almacenar en el camion.\n");
        return;
    }

    tPaquete *paqueteAAlmacenar = (tPaquete *)desencolar(cola);

    printf("\n--- Almacenando paquete en camion ---\n");
    printf("Paquete con Codigo Unico: %d\n", paqueteAAlmacenar->codigoUnico);
    printf("Destinatario: %s\n", paqueteAAlmacenar->destinatario);
    printf("Direccion: %s (CP: %s)\n", paqueteAAlmacenar->direccion, paqueteAAlmacenar->codigoPostal);
    printf("Es fragil: %s\n", paqueteAAlmacenar->esFragil ? "Si" : "No");
    printf("-> Paquete insertado en el camion y quitado de la cola.\n");

    free(paqueteAAlmacenar); // Liberar la memoria del dato desencolado
}

/* c) Una función que permita visualizar el detalle de paquetes según un valor booleano
 que se recibe como parámetro que cuando llega true significa que se desea obtener
 información de paquetes marcados como frágiles, y como no frágiles en caso contrario.*/

void visualizarPaquetesPorFragilidad(tColaGenerica *colaOriginal, bool buscarFragiles) {
    if (estaVaciaCola(colaOriginal)) {
        printf("La cola de paquetes esta vacia.\n");
        return;
    }

    tColaGenerica colaAuxiliar;
    inicializarCola(&colaAuxiliar);

    int contadorPaquetes = 0;
    const char* tipoPaquete = buscarFragiles ? "fragiles" : "no fragiles";

    printf("\n*** Paquetes marcados como \"%s\" ***\n", tipoPaquete);
    printf("%-10s %-20s %-30s %s\n", "Cod. unico", "Destinatario", "Direccion", "CP");

    // Recorrer la cola: Desencolar de la original y encolar en la auxiliar
    
    while (!estaVaciaCola(colaOriginal)) {
        tPaquete *paquete = (tPaquete *)desencolar(colaOriginal);
        
        // Verificar si el paquete coincide con el criterio de fragilidad
        
        if (paquete->esFragil == buscarFragiles) {
            printf("%-10d %-20s %-30s %s\n",
                   paquete->codigoUnico,
                   paquete->destinatario,
                   paquete->direccion,
                   paquete->codigoPostal);
            contadorPaquetes++;
        }
        
        // Encolar el paquete en la cola auxiliar para restaurar la original
        
        encolar(&colaAuxiliar, paquete, sizeof(tPaquete));
        free(paquete); // Liberar la memoria del dato que fue desencolado
    }

    // Restaurar la cola original: Desencolar de la auxiliar y encolar de nuevo en la original
    
    while (!estaVaciaCola(&colaAuxiliar)) {
        tPaquete *paquete = (tPaquete *)desencolar(&colaAuxiliar);
        encolar(colaOriginal, paquete, sizeof(tPaquete));
        free(paquete); // Liberar la memoria del dato que fue desencolado
    }

    printf("Total de paquetes marcados como %s: %d\n", tipoPaquete, contadorPaquetes);
}

// FUNCION MAIN PARA PRUEBAS


int main() {
    tColaGenerica colaPaquetes;
    inicializarCola(&colaPaquetes);

    // Crear algunos paquetes de prueba
    
    tPaquete p1 = {1452, "Juan Martinez", "Av. Cordoba 123 (Bs. As.)", "1234", true};
    tPaquete p2 = {1456, "Maria Almada", "Irigoyen 435 (Entre Rios)", "2345", true};
    tPaquete p3 = {1457, "Pedro Gomez", "San Martin 789 (Cordoba)", "5000", false};
    tPaquete p4 = {1458, "Ana Lopez", "Belgrano 101 (Santa Fe)", "3000", true};
    tPaquete p5 = {1459, "Luis Perez", "Rivadavia 202 (Mendoza)", "5500", false};

    // Encolar los paquetes
    
    printf("Encolando paquetes...\n");
    encolar(&colaPaquetes, &p1, sizeof(tPaquete));
    encolar(&colaPaquetes, &p2, sizeof(tPaquete));
    encolar(&colaPaquetes, &p3, sizeof(tPaquete));
    encolar(&colaPaquetes, &p4, sizeof(tPaquete));
    encolar(&colaPaquetes, &p5, sizeof(tPaquete));
    printf("Cantidad de paquetes en cola: %d\n", colaPaquetes.cantidadElementos);

    // Probar la función c) - Visualizar paquetes frágiles
    visualizarPaquetesPorFragilidad(&colaPaquetes, true);

    // Probar la función c) - Visualizar paquetes no frágiles
    visualizarPaquetesPorFragilidad(&colaPaquetes, false);

    // Probar la función b) - Almacenar el próximo paquete
    almacenarProximoPaqueteEnCamion(&colaPaquetes);
    printf("Cantidad de paquetes en cola despues de almacenar 1: %d\n", colaPaquetes.cantidadElementos);

    // Almacenar otro paquete
    almacenarProximoPaqueteEnCamion(&colaPaquetes);
    printf("Cantidad de paquetes en cola despues de almacenar 2: %d\n", colaPaquetes.cantidadElementos);

    // Visualizar de nuevo para ver el estado actual
    visualizarPaquetesPorFragilidad(&colaPaquetes, true);
    visualizarPaquetesPorFragilidad(&colaPaquetes, false);

    // Vaciar la cola al final
    printf("\nVaciando la cola de paquetes...\n");
    vaciarCola(&colaPaquetes);
    printf("Cantidad de paquetes en cola despues de vaciar: %d\n", colaPaquetes.cantidadElementos);

    return 0;
}

