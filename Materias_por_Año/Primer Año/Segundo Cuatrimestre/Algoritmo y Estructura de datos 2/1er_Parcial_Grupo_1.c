/*Objetivo: Informe de evaluacion respecto de la efectividad de los talleres de programacion

Nombre: Grupo 1. Zimerman Benjamin 43064294. Stoppello Agustin M. 46316920

Estrategia:
			1) ingresoDatos();
				a) Libreta Universitaria del Estudiante (LU);
				b) Modalidad de clases (1- Presencial, 2- Virtual);
				c) Cantidad de asistencias;
				d) Comision (1-2-3-4-5-6-7);
			2) analisisDatos();
				a) Comision 5, en caso que sean de la comision 5 con modalidad virtual de clases, se debe emitir un mensaje 
				aclarando la modalidad.
				b) Total de estudiantes que asisten a clases.
				c) Promedio de asistencia a clases.
			3)imprimirPantalla()
				a) Dto. Sistemas FACENA - Taller de Programación
				b) La cantidad de estudiantes que asistieron a clases: 120
				c)  Cantidad promedio de asistencias a clases: 10 clases por alumno
			

Desarrollo de Estrategia:
Variables:
			int lU,
			float cantAsistencias = 0;
			char modClases, comision;
			
			ingreso_y_analisis_Datos();
			imprimirPantalla();
			
			1) ingreso_y_analisis_Datos();
			
			
				a) Libreta Universitaria del Estudiante (LU);
				b) Modalidad de clases (1- Presencial, 2- Virtual);
				c) Cantidad de asistencias;
				d) Comision (1-2-3-4-5-6-7);
			
				e) Comision 5, en caso que sean de la comision 5 con modalidad virtual de clases, se debe emitir un mensaje 
				aclarando la modalidad.
				f) Total de estudiantes que asisten a clases.
				g) Promedio de asistencia a clases.
				
			3)imprimirPantalla()
				a) Dto. Sistemas FACENA - Taller de Programación
				b) La cantidad de estudiantes que asistieron a clases: 120
				c)  Cantidad promedio de asistencias a clases: 10 clases por alumno
*/

#include <stdio.h>

/* Variables */
int lU, totalEstudiantes = 0; 
float totalAsistencias = 0; 
float promedio = 0;
char modClases, comision, continuar;

/* Prototipos */			
void ingreso_y_analisis_Datos();
void imprimirPantalla();

int main() {
    printf("--------------------------------------------------\n");
    printf("Dto. Sistemas FACENA - Informe de Asistencias\n");
    printf("--------------------------------------------------\n");

    ingreso_y_analisis_Datos();
    imprimirPantalla();
    
    return 0;
}

void ingreso_y_analisis_Datos() {
    do {
        printf("Ingrese Libreta Universitaria del Estudiante: \n");
        scanf("%d", &lU);
        
        printf("Ingrese la modalidad de clases (1- Presencial, 2- Virtual): \n");
        scanf(" %c", &modClases); // Espacio antes de %c para ignorar el salto de línea
        
        printf("Ingrese cantidad de asistencias: \n");
        scanf("%f", &totalAsistencias);
        
        printf("Ingrese comision (1-2-3-4-5-6-7): \n");
        scanf(" %c", &comision); // Espacio antes de %c para ignorar el salto de línea
        
        // Contar total de estudiantes
        totalEstudiantes++;
        
        // Mensaje para comision 5 con modalidad virtual
        if (comision == '5' && modClases == '2') {
            printf("*** LU: %d - Comision 5 - Modalidad Virtual ***\n", lU);
        }
        
        printf("Desea cargar más datos: S-SI , N-NO :  \n");
        scanf(" %c", &continuar); // Espacio antes de %c para ignorar el salto de línea
        
    } while (continuar == 's' || continuar == 'S');
    
    // Calcular promedio de asistencias
    if (totalEstudiantes > 0) {
        promedio = totalAsistencias / totalEstudiantes;
    }
}

void imprimirPantalla() {
    printf("Dto. Sistemas FACENA - Taller de Programación \n");
    printf("La cantidad de estudiantes que asistieron a clases: %d\n", totalEstudiantes);
    printf("Cantidad promedio de asistencias a clases: %.2f\n", promedio);
}

/* Casos de prueba
-Prueba 1
    lu: 1234
    Modalidad de clase: 1- Presencial
    Cantidad de asistencia: 20
    Comision: 5

-Prueba 2
    lu: 2345
    Modalidad de clase: 2- Virtual
    Cantidad de asistencia: 10
    Comision: 1

-Prueba 3
    lu: 9874
    Modalidad de clase: 2- Virtual
    Cantidad de asistencia: 1
    Comision: 2
Promedio = 10.33
*/
