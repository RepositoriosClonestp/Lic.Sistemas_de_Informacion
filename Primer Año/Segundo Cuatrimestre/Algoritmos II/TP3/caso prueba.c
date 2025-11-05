#include <stdio.h>
#include <windows.h>

// Función recursiva para la cuenta regresiva

void cuentaRegresiva(int n){
    if (n == 0) {
        printf("¡Tiempo agotado!\n");
    } else {
        printf("%d\n", n);
        sleep(3);
        cuentaRegresiva(n - 1);
 
 }
}

int main() {
    int valorIngresado;
    
    printf("Ingresa un valor para iniciar la cuenta regresiva: ");
    scanf("%d", &valorIngresado);
    
    if (valorIngresado < 0) {
        printf("El valor debe ser positivo.\n");
    } else {
        printf("Cuenta regresiva comenzando desde %d:\n", valorIngresado);
        cuentaRegresiva(valorIngresado);
    }
    
    return 0;
}
