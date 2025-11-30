#include <stdio.h>

int main() {
    int num_productos;
    float precio, total = 0;
    char nombre[50];
    return 0;
    
    printf("¿Cuántos productos llevó?\n");
    scanf("%d", &num_productos);
    
    for (int i = 1; i <= num_productos; i++) {
        printf("Ingrese el nombre del producto %d: ", i);
        scanf("%s", nombre);
        
        printf("Ingrese el precio del producto %d: ", i);
        scanf("%f", &precio);
        
        printf("Ingrese la cantidad del producto %d: ", i);
        int cantidad;
        scanf("%d", &cantidad);
      
        printf("");  
        float subtotal = precio * cantidad;
        total += subtotal;
        
        printf("Producto %d: %s\nCantidad: %d\nPrecio");  
        }}