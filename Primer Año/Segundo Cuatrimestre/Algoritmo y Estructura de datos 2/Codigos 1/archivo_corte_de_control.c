#include <stdio.h>

/*tipos de datos*/
typedef char string[50];

typedef struct{
	
	int nroTicket;
    int codProducto;
    string nombre;
    int codCategoria;
    int cantVenta;
    float precioUnit;
	
}t_datos;



/*varibles*/
t_datos registro;
FILE *archivo;

int campo_control;

string categoria_descripcion[5] = {"","panaderia","lacteos","perfumeria","limpieza"};
float total_categoria[5] = {0,0,0,0,0};

float importe_total;
int cantidad_ticket;


/*prototipos*/
void inicializacion();
void proceso_corte();
void finalizacion();

void principio_corte();
void grupo_corte();
void fin_corte();



/*bloque principal*/
int main (){
	
	inicializacion();
	proceso_corte();
	finalizacion();
	
	return 0;
}


/*funciones*/
void inicializacion(){
	
	archivo = fopen("archivo ventas.dat","rb");
	
	fread( &registro, sizeof(t_datos), 1, archivo );
	
	campo_control = registro.nroTicket;
	
	importe_total = 0;
	cantidad_ticket = 0;
	
	printf("** INFORME DE VENTAS POR DIA  **\n");
	printf("** nro ticket | cod producto | Nombre | categoria | cantidad | total **\n");
		
}


void proceso_corte(){
	
	while( !feof (archivo) ){
		
		principio_corte();
		
		while( !feof (archivo) && registro.nroTicket == campo_control ){
			
			grupo_corte();
			
			fread(&registro, sizeof(t_datos), 1, archivo);
			
		}
		
		fin_corte();
		
	}
	
}


void finalizacion(){
	
	printf("\n monto total recuadado: %.2f \n", importe_total);
	printf("cantidad de tickets: %d ", cantidad_ticket);
	
	fclose(archivo);
	
}


void principio_corte(){

	int i;	
	for(i=1; i<=4; i++){
	
		total_categoria[i] = 0; 
	
	}
	
}


void grupo_corte(){
	
	printf("%d   %d   %s  %s   %d   %.2f \n", registro.nroTicket, registro.codProducto, registro.nombre, categoria_descripcion[registro.codCategoria], registro.cantVenta, registro.cantVenta * registro.precioUnit);
	
	total_categoria[registro.codCategoria] = total_categoria[registro.codCategoria ] + (registro.cantVenta * registro.precioUnit);

}


void fin_corte(){
	
	int i;
	for(i=1; i<=4; i++){
		
		printf("%s : $%.2f \n", categoria_descripcion[i], total_categoria[i]);
		
	}
	
	cantidad_ticket = cantidad_ticket + 1;
	
	campo_control = registro.nroTicket;
	
}


