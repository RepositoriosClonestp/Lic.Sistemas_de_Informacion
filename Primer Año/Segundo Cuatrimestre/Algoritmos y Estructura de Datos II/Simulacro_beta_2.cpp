#include <iostream>
#include <iomanip>
#include <string>

const std::string TITLE = "Campaña de vacunación - Provincia de Corrientes";

void calcularPorcentaje(int total, int cantidad) {
    double porcentaje = static_cast<double>(cantidad) / total * 100;
    std::cout << "Porcentaje con quinta dosis menores de edad sobre total de vacunados Covid: "
              << std::fixed << std::setprecision(2) << porcentaje << "%\n";
}

int main() {
    int dni, edad, tipoVacuna, numDosis, lugarVacunacion;
    int vacunadosAntigripal = 0;
    int vacunadosQuintaDosis = 0;
    int vacunadosQuintaDosisMenoresEdad = 0;

    std::cout << TITLE << std::endl;

    while (true) {
        std::cout << "Ingrese DNI (0 para finalizar): ";
        std::cin >> dni;
        if (dni == 0)
            break;

        std::cout << "Ingrese Edad: ";
        std::cin >> edad;

        std::cout << "Ingrese Tipo de vacuna (1- Covid, 2- Antigripal): ";
        std::cin >> tipoVacuna;

        std::cout << "Ingrese Número de dosis: ";
        std::cin >> numDosis;

        std::cout << "Ingrese Lugar de vacunación (1-CAP, 2-Facultad de Medicina): ";
        std::cin >> lugarVacunacion;

        if (tipoVacuna == 2) {
            std::cout << "*** Antigripal - DNI: " << dni << " Edad: " << edad;
            std::cout << " Lugar: " << (lugarVacunacion == 1 ? "CAP" : "Facultad de Medicina") << " ***\n";
            vacunadosAntigripal++;
        }

        if (tipoVacuna == 1 && numDosis == 5 && edad < 18) {
            vacunadosQuintaDosis++;
            vacunadosQuintaDosisMenoresEdad++;
        } else if (tipoVacuna == 1 && numDosis == 5) {
            vacunadosQuintaDosis++;
        }
    }

    std::cout << "Cantidad vacunados antigripal: " << vacunadosAntigripal << std::endl;
    std::cout << "Cantidad de vacunados Covid con quinta dosis menores de edad: " << vacunadosQuintaDosisMenoresEdad << std::endl;

    calcularPorcentaje(vacunadosQuintaDosis, vacunadosQuintaDosisMenoresEdad);

    return 0;
}

