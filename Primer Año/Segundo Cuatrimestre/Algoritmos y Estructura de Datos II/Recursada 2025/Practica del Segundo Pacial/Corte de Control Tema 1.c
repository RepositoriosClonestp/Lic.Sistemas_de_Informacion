#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TITULO1 "\n*** INFORME DE INVENTARIO POR DÍA ***\n"

/* Tipos de datos personalizados */

// tRegistro adaptado a la consigna del inventario
typedef struct {    
    char fecha[9];      // formato: AAAAMMDD. Campo de Control.
    int cantEntrantes;
    int cantSalientes;
} tRegistro;

/* Declaración de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unRegistro(); /* procesar un registro del mismo día */
void finCorte();

/* Declaración de variables (Adaptadas al Inventario) */
FILE * inventario;
tRegistro reg, regAnterior;

// Acumuladores parciales (por día)
int entradasDia, salidasDia;

// Acumuladores generales y Máximo
int totalDias;
int maxSalidas;
char fechaMaxSalidas[9]; // Para guardar la fecha del día con más salidas


/* Bloque principal */
int main() {        
    inicializacion();    
    
    if (inventario != NULL) { // Solo si el archivo se abrió correctamente
        procesoCorte();        
    }
    
    finalizacion();
    return 0;
}

/* Implementación de funciones */

void inicializacion() {
    /* 1. Abrir archivo en modo lectura, 2. Leer el primer registro */
    inventario = fopen("Inventario.dat", "rb");    
    
    if (inventario != NULL ) {
        // Leemos el primer registro del archivo
        if (fread(&reg, sizeof(tRegistro), 1, inventario) != 1) {
            // Manejo de archivo vacío
            printf("Advertencia: El archivo de inventario está vacío.\n");
            reg.fecha[0] = '\0'; // Marca para salir del procesoCorte si es vacío
        }
    } else {
        printf("Error: No se encuentra el archivo Inventario.dat!\n");
        // No salimos de aquí, solo evitamos el procesoCorte en main.
        return; 
    }
    
    /* 3. Guardar campo de control anterior (regAnterior) */
    regAnterior = reg;
    
    /* 4. Inicializar contadores/acumuladores generales/totales */
    totalDias = 0;
    maxSalidas = -1; // Usamos un valor inicial bajo
    fechaMaxSalidas[0] = '\0';
    
    /* 5. Escribir titulos */
    printf("%s", TITULO1);    
    printf("Fecha     | Total de Entradas | Total de Salidas\n");
    printf("----------|-------------------|------------------\n");
}

void procesoCorte() {
    /* Recorrer el archivo hasta el final (feof) */
    // Además, verificamos que el primer registro se haya leído correctamente
    while (!feof(inventario) && regAnterior.fecha[0] != '\0') { 
        
        principioCorte();    
        
        /* Con este while trabajamos con cada grupo (mismo día) */
        // La comparación del campo de control ahora es la FECHA
        while(!feof(inventario) && strcmp(reg.fecha, regAnterior.fecha) == 0) { 
            unRegistro();
            
            // Lectura del siguiente registro
            if (fread(&reg, sizeof(tRegistro), 1, inventario) != 1) {
                // Si la lectura falla, salimos del bucle interno para procesar el último corte.
                break;
            }    
        }    
        /* Cuando termina este while significa que terminó un grupo (cambio de día) */
        
        finCorte();
    }
}

void principioCorte() {
    /* 1. Inicializar los contadores/acumuladores parciales */         
    entradasDia = 0;
    salidasDia = 0;    
}

void unRegistro() {
    /* Actividades por grupo: 1. Actualizar contadores/acumuladores parciales */
    // Acumulamos las cantidades al total del día
    entradasDia += reg.cantEntrantes;
    salidasDia += reg.cantSalientes;

    // Nota: El ejercicio NO pide imprimir detalle de cada artículo, solo el total por día.
}

void finCorte(){             
    /* 1. Mostrar subtotales (resumen diario) */
    printf("%-9s | %-17d | %-16d\n", 
           regAnterior.fecha, // Usamos la fecha del día que acaba de terminar
           entradasDia, 
           salidasDia);
           
    /* 4. Actualizar contadores/acumuladores generales y 5. Buscar el mayor */    
    totalDias++; // Contamos un día más
    
    // Chequeo del máximo
    if (salidasDia > maxSalidas) {
        maxSalidas = salidasDia;
        strcpy(fechaMaxSalidas, regAnterior.fecha); // Guardamos la fecha
    }
    
    /* 2. Guardar la clave anterior(campo de control) */    
    regAnterior = reg;
}

void finalizacion(){
    /* 1. Mostrar totales (Total de días y día con más salidas) */
    printf("----------|-------------------|------------------\n");

    if (totalDias > 0) {
        printf("\nTotal de días registrados en el mes: %d\n", totalDias);
        printf("Día con más artículos salientes: %s (%d salidas)\n", 
               fechaMaxSalidas, 
               maxSalidas);
    } else {
        printf("\nNo se procesó ningún día.\n");
    }

    /* 3. Cerrar el archivo */    
    if (inventario != NULL) {
        fclose(inventario);
    }
}
