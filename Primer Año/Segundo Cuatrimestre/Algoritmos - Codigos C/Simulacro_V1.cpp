#include <stdio.h>

int dni, edad, tipoVacuna, nroDosis;
float total1 = 0, total2 = 0;
float cant_5_dosis = 0, cant_menores_5_dosis = 0;
char lugarVacunacion, continuar;

void ingresoDatos();

int main() {
    printf("Campaña de vacunación - Provincia de Corrientes\n");

    ingresoDatos();

    printf("\nMinisterio de Salud de la Provincia - Informe de Campaña de Vacunación");
    printf("\n-------------------------------------------------------------\n");

    // Cálculo del porcentaje
    float porcentaje_menores_quinta_dosis = 0;
    if (cant_5_dosis > 0) {
        porcentaje_menores_quinta_dosis = (cant_menores_5_dosis / cant_5_dosis) * 100;
    }

    // Generación del informe
    printf("\nCantidad vacunados antigripal: %.0f", total2);
    printf("\nCantidad de vacunados Covid con quinta dosis menores de edad: %.0f", cant_menores_5_dosis);
    printf("\nPorcentaje con quinta dosis menores de edad sobre total de vacunados Covid: %.2f%%\n", porcentaje_menores_quinta_dosis);

    return 0;
}

// Carga de datos de vacunados
void ingresoDatos() {
    do {
        printf("Ingrese DNI: ");
        scanf("%d", &dni);
        fflush(stdin);

        printf("Ingrese edad: ");
        scanf("%d", &edad);
        fflush(stdin);

        printf("Ingrese tipo de vacuna (1-Covid, 2-Antigripal): ");
        scanf("%d", &tipoVacuna);
        fflush(stdin);

        printf("Ingrese numero de dosis: ");
        scanf("%d", &nroDosis);
        fflush(stdin);

        printf("Ingrese lugar de vacunación (1-CAP, 2-Facultad de Medicina): ");
        scanf(" %c", &lugarVacunacion);
        fflush(stdin);

        if (tipoVacuna == 2) {
            printf("* Antigripal - ");
            printf("DNI: %d - ", dni);
            printf("Edad: %d - ", edad);
            printf("Lugar: %c\n", lugarVacunacion);
            total2 += 1;
        } else if (tipoVacuna == 1) {
            printf("***CAP - ");
            printf("DNI: %d - ", dni);
            printf("Edad: %d - ", edad);
            printf("Lugar: %c\n", lugarVacunacion);
            total1 += 1;
            if (nroDosis == 5 && edad < 18) {
                cant_5_dosis += 1;
                cant_menores_5_dosis += 1;
            }
        }

        printf("\n¿Desea cargar otro vacunado? (S/N): ");
        scanf(" %c", &continuar);
        fflush(stdin);
        printf("\n-------------------------------------------------------------\n");
    } while (continuar == 's' || continuar == 'S');
}

