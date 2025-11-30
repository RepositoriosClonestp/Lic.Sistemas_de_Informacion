// Lista enlazada
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodoEncuesta {
    char sexo;      // F: Femenino, M: Masculino
    char rangoEdad; // 01: Menor de 15 años, 02: Entre 15 y 30 años, 03: Más de 30 años
    float peso;
    float altura;
    char clasificacion[20]; // Clasificación del IMC
    struct NodoEncuesta* siguiente;
} tNodoEncuesta;

tNodoEncuesta* crearNodo(char sexo, char rangoEdad, float peso, float altura) {
    tNodoEncuesta* nuevoNodo = (tNodoEncuesta*)malloc(sizeof(tNodoEncuesta));
    nuevoNodo->sexo = sexo;
    nuevoNodo->rangoEdad = rangoEdad;
    nuevoNodo->peso = peso;
    nuevoNodo->altura = altura;

    // Cálculo del IMC y asignación de clasificación
    float imc = peso / (altura * altura);
    if (sexo == 'F') {
        if (imc < 20)
            strcpy(nuevoNodo->clasificacion, "Peso bajo");
        else if (imc >= 20 && imc <= 25)
            strcpy(nuevoNodo->clasificacion, "Peso normal");
        else
            strcpy(nuevoNodo->clasificacion, "Sobrepeso");
    } else if (sexo == 'M') {
        if (imc < 19)
            strcpy(nuevoNodo->clasificacion, "Peso bajo");
        else if (imc >= 19 && imc <= 24)
            strcpy(nuevoNodo->clasificacion, "Peso normal");
        else
            strcpy(nuevoNodo->clasificacion, "Sobrepeso");
    } else {
        strcpy(nuevoNodo->clasificacion, "No definido");
    }

    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

tNodoEncuesta* insertarAlPrincipio(tNodoEncuesta* lista, tNodoEncuesta* nuevoNodo) {
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

int contarEncuestados(tNodoEncuesta* lista) {
    int contador = 0;
    tNodoEncuesta* actual = lista;
    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

float promedioPesosMenores15(tNodoEncuesta* lista) {
    int contador = 0;
    float sumaPesos = 0;
    tNodoEncuesta* actual = lista;
    while (actual != NULL) {
        if (actual->rangoEdad == '01' && actual->clasificacion[0] == 'P') {
            contador++;
            sumaPesos += actual->peso;
        }
        actual = actual->siguiente;
    }
    if (contador == 0)
        return 0; // Para evitar división por cero
    return sumaPesos / contador;
}

void mostrarSobrepeso(tNodoEncuesta* lista) {
    printf("\nPersonas con sobrepeso:\n");
    tNodoEncuesta* actual = lista;
    while (actual != NULL) {
        if (actual->clasificacion[0] == 'S') {
            printf("Sexo: %c\n", actual->sexo);
            printf("Rango de Edad: %c\n", actual->rangoEdad);
            printf("Peso: %.2f kg\n", actual->peso);
            printf("Altura: %.2f m\n", actual->altura);
            printf("Clasificación IMC: %s\n\n", actual->clasificacion);
        }
        actual = actual->siguiente;
    }
}

void liberarLista(tNodoEncuesta* lista) {
    tNodoEncuesta* actual = lista;
    while (actual != NULL) {
        tNodoEncuesta* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    tNodoEncuesta* lista = NULL;
    int opcion;
    char sexo;
    char rangoEdad;
    float peso;
    float altura;

    do {
        printf("\nMenú Principal:\n");
        printf("1. Agregar encuesta\n");
        printf("2. Cantidad total de encuestados\n");
        printf("3. Promedio de pesos de personas de peso bajo menores de 15 años\n");
        printf("4. Listado de personas con sobrepeso\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el código de sexo (F/M): ");
                scanf(" %c", &sexo);
                printf("Ingrese el código de rango de edad (01/02/03): ");
                scanf(" %c", &rangoEdad);
                printf("Ingrese el peso (kg): ");
                scanf("%f", &peso);
                printf("Ingrese la altura (m): ");
                scanf("%f", &altura);
                lista = insertarAlPrincipio(lista, crearNodo(sexo, rangoEdad, peso, altura));
                break;

            case 2:
                printf("Cantidad total de encuestados: %d\n", contarEncuestados(lista));
                break;

            case 3:
                printf("Promedio de pesos de personas de peso bajo menores de 15 años: %.2f kg\n", promedioPesosMenores15(lista));
                break;

            case 4:
                mostrarSobrepeso(lista);
                break;

            case 5:
                liberarLista(lista);
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}

