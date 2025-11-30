#include <stdio.h>

int cantidad;
float precio_unitario;
float bonificacion = 0.0;
float total;

float calcularTotal(int, float);
void imprimirTicket();


int main()
{
    cantidad = 11;
    precio_unitario = 10.5;
    total = calcularTotal(cantidad, precio_unitario);
    
    imprimirTicket();
    
    return 1;
}

float calcularTotal(int cant, float p_unitario){

 float subtotal = (float)cant*p_unitario;

if (subtotal >= 5000 || cant > 10){
	bonificacion = (float)subtotal*0.15;
}
else if (subtotal >= 10){
	bonificacion = (float)subtotal*0.20;
}
else if (cant >= 10){

	bonificacion = (float)subtotal*0.20;
}
else {
	bonificacion = (float)subtotal*0.10;
}
    return subtotal;
}

void imprimirTicket()
{
    printf("Cant. Unidades: %d - Precio unit.: %.2f\n", cantidad, precio_unitario);
    printf("Subtotal: $ %.2f \n",total);
    printf("Bonificacion: $ %.2f \n",bonificacion);
    printf("Total: $ %.2f \n",total,bonificacion);
    printf("¡Gracias por su compra!");
}
