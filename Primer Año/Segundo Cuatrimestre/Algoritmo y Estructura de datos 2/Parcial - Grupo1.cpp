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

#define MAX_ESTUDIANTES 100

const char* TITULO_INFORME = "Dto. Sistemas FACENA - Taller de Programacion";

typedef struct {
    int lu;
    int modalidadClase;
    int asistencias;
    int comision;
} Estudiante;

float calcularPromedioAsistencias(Estudiante estudiantes[], int cantidadEstudiantes) {
    int totalAsistencias = 0;
    int totalEstudiantes = 0;

    for (int i = 0; i < cantidadEstudiantes; i++) {
        totalAsistencias += estudiantes[i].asistencias;
        totalEstudiantes++;
    }

    return (float)totalAsistencias / totalEstudiantes;
}

void mostrarMensajeModalidadVirtual(int lu, int comision) {
    if (comision == 5) {
        printf("*** LU: %d - Comisión %d - Modalidad Virtual ***\n", lu, comision);
    }
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes = 0;

    printf("%s\n", TITULO_INFORME);

    /* Carga de datos */
    while (1) {
        Estudiante nuevoEstudiante;

        printf("\nIngrese los datos del estudiante:\n");
        printf("LU: ");
        scanf("%d", &nuevoEstudiante.lu);
        printf("Modalidad de Clase (1-Presencial, 2-Virtual): ");
        scanf("%d", &nuevoEstudiante.modalidadClase);
        printf("Cantidad de Asistencias: ");
        scanf("%d", &nuevoEstudiante.asistencias);
        printf("Comision: ");
        scanf("%d", &nuevoEstudiante.comision);

        mostrarMensajeModalidadVirtual(nuevoEstudiante.lu, nuevoEstudiante.comision);

        estudiantes[cantidadEstudiantes] = nuevoEstudiante;
        cantidadEstudiantes++;

        char respuesta;
        printf("\n¿Desea ingresar más datos? (s/n): ");
        scanf(" %c", &respuesta);

        if (respuesta == 'n' || respuesta == 'N') {
            break;
        }
    }

    /* Informe final */
    printf("\nLa cantidad de estudiantes que asistieron a clases: %d\n", cantidadEstudiantes);
    printf("Cantidad promedio de asistencias a clases: %.2f clases por alumno\n", calcularPromedioAsistencias(estudiantes, cantidadEstudiantes));

    return 0;
}
/* casos de prueba
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

*/
