#include <iostream>
#include <iomanip>
using namespace std;

const string TITULO_INFORME = "Campaña de vacunación - Provincia de Corrientes";

int main() {
    int dni, edad, tipoVacuna, nroDosis, lugarVacunacion;
    int cantidad_vacunados_antigripal = 0;
    int cantidad_vacunados_quinta_dosis = 0;
    int cantidad_menores_quinta_dosis = 0;
    int total_vacunados = 0;
    
    cout << "Ministerio de Salud de la Provincia - Informe de Campaña de Vacunación" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    // Carga de datos de vacunados
    char continuar;
    do {
        cout << "Ingrese DNI: ";
        cin >> dni;
        
        cout << "Ingrese edad: ";
        cin >> edad;
        
        cout << "Ingrese tipo de vacuna (1-Covid, 2-Antigripal): ";
        cin >> tipoVacuna;
        
        cout << "Ingrese número de dosis: ";
        cin >> nroDosis;
        
        cout << "Ingrese lugar de vacunación (1-CAP, 2-Facultad de Medicina): ";
        cin >> lugarVacunacion;
        
        if (tipoVacuna == 2) {
            cout << "*** Antigripal - DNI: " << dni << " Edad: " << edad << " Lugar: ";
            if (lugarVacunacion == 1) {
                cout << "CAP ***" << endl;
            } else if (lugarVacunacion == 2) {
                cout << "Facultad de Medicina ***" << endl;
            }
            cantidad_vacunados_antigripal++;
        }
        
        if (tipoVacuna == 1 && nroDosis => 5 && edad < 18) {
            cantidad_vacunados_quinta_dosis++;
            cantidad_menores_quinta_dosis++;
        }
        
        total_vacunados++;
        
        cout << "¿Desea cargar otro vacunado? (s/n): ";
        cin >> continuar;
        
        cout << "-------------------------------------------------------------" << endl;
    } while (continuar == 's' || continuar == 'S');
    
    // Cálculo del porcentaje
    float porcentaje_menores_quinta_dosis = (cantidad_menores_quinta_dosis / (float)cantidad_vacunados_quinta_dosis) * 100;
    
    // Generación del informe
    cout << TITULO_INFORME << endl;
    cout << "Cantidad vacunados antigripal: " << cantidad_vacunados_antigripal << endl;
    cout << "Cantidad de vacunados Covid con quinta dosis menores de edad: " << cantidad_menores_quinta_dosis << endl;
    cout << "Porcentaje con quinta dosis menores de edad sobre total de vacunados Covid: " << fixed << setprecision(2) << porcentaje_menores_quinta_dosis << "%" << endl;
    
    return 0;
}

