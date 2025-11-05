#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Estructura para devolver resultados
typedef struct {
    int comparaciones;
    int intercambios;
    double tiempo;
} tResultado;

// Prototipos
tResultado burbuja(int v[], int n);
tResultado seleccion(int v[], int n);
tResultado insercion(int v[], int n);
int estaOrdenado(int v[], int n);
void copiarVector(int origen[], int destino[], int n);

int main() {
    int vOriginal[MAX], vBurbuja[MAX], vSeleccion[MAX], vInsercion[MAX];
    srand(time(NULL));

    // Generar 100 numeros aleatorios entre 1 y 1000
    for (int i = 0; i < MAX; i++)
        vOriginal[i] = rand() % 1000 + 1;

    copiarVector(vOriginal, vBurbuja, MAX);
    copiarVector(vOriginal, vSeleccion, MAX);
    copiarVector(vOriginal, vInsercion, MAX);

    tResultado rBurbuja = burbuja(vBurbuja, MAX);
    tResultado rSeleccion = seleccion(vSeleccion, MAX);
    tResultado rInsercion = insercion(vInsercion, MAX);

    printf("\n--- RESULTADOS COMPARATIVOS ---\n");
    printf("Metodo\t\tComparaciones\tIntercambios\tTiempo (seg)\tOrdenado\n");
    printf("Burbuja\t\t%d\t\t%d\t\t%.5f\t\t%s\n",
           rBurbuja.comparaciones, rBurbuja.intercambios, rBurbuja.tiempo,
           estaOrdenado(vBurbuja, MAX) ? "Si" : "No");
    printf("Seleccion\t%d\t\t%d\t\t%.5f\t\t%s\n",
           rSeleccion.comparaciones, rSeleccion.intercambios, rSeleccion.tiempo,
           estaOrdenado(vSeleccion, MAX) ? "Si" : "No");
    printf("Insercion\t%d\t\t%d\t\t%.5f\t\t%s\n",
           rInsercion.comparaciones, rInsercion.intercambios, rInsercion.tiempo,
           estaOrdenado(vInsercion, MAX) ? "Si" : "No");

    return 0;
}

// FUNCIONES

tResultado burbuja(int v[], int n) {
    tResultado r = {0, 0, 0};
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            r.comparaciones++;
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                r.intercambios++;
            }
        }
    }

    r.tiempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    return r;
}

tResultado seleccion(int v[], int n) {
    tResultado r = {0, 0, 0};
    clock_t inicio = clock();

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            r.comparaciones++;
            if (v[j] < v[menor])
                menor = j;
        }
        if (menor != i) {
            int aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
            r.intercambios++;
        }
    }

    r.tiempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    return r;
}

tResultado insercion(int v[], int n) {
    tResultado r = {0, 0, 0};
    clock_t inicio = clock();

    for (int i = 1; i < n; i++) {
        int clave = v[i];
        int j = i - 1;
        r.comparaciones++;
        while (j >= 0 && v[j] > clave) {
            v[j + 1] = v[j];
            j--;
            r.intercambios++;
            r.comparaciones++;
        }
        v[j + 1] = clave;
    }

    r.tiempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    return r;
}

int estaOrdenado(int v[], int n) {
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1])
            return 0;
    return 1;
}

void copiarVector(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origen[i];
}

