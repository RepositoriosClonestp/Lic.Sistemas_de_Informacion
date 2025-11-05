#include <stdio.h> 
#include <string.h>

typedef char tString[40];

typedef struct {	    
    int nroTicket;
    int codProducto;
    tString nombre;
    int codCategoria;
    int cantVenta;
    float precioUnit;
}tRegistro;	 

/* Declaración de prototipos */
void inicializacion();
void procesoCorte();
void finalizacion();

void principioCorte();
void unGrupo();
void finCorte();


/* Declaración de variables */
tRegistro registro;
FILE * archivo;

int codCampoControlAnt;

tString categoriaDescripcion[5]={"","Panaderia","Lacteos","Perfumeria","Limpieza"};
float totalXCategoria[5]={0,0,0,0,0};

float importeTotalRecuadado;
int cantTickets;


/* bloque principal */
int main() {		
	inicializacion(); 	//(abrir archivo, leer el primer registro, guardar el campo de control)
	procesoCorte();		//(principio de contre, unGrupo, finCorte)
	finalizacion();     //(mostrar totales generales)
}


void inicializacion() {

	int i;		
	archivo = fopen("nombrearchivo.dat","rb");
	
	fread(&registro,sizeof(tRegistro),1,archivo);
	
	codCampoControlAnt=registro.nroTicket;
		
	printf("** INFORME DE VENTAS POR DIA  **\n");
	
	printf("** nro ticket | cod producto | Nombre | categoria | cantidad | total **\n");


	cantTickets=0;
	importeTotalRecuadado=0;
}

void procesoCorte() {
	while (!feof(archivo)) { 
	
		principioCorte(); 
		
	    while(!feof(archivo) && registro.nroTicket == codCampoControlAnt) { 
			
			unGrupo();
			
			fread(&registro,sizeof(tRegistro),1,archivo);	
		} 
		
		finCorte();
	}

}



void principioCorte() {
	int i;

	for(i=1; i<=4; i++){
	
		totalXCategoria[i]=0;
	
	}
}



void unGrupo() {
			
	//PUNTO A) generar un listado detallado por nro de ticket				
	printf("%d   %d   %s  %s   %d   %.2f \n",registro.nroTicket, registro.codProducto, registro.nombre, categoriaDescripcion[registro.codCategoria], registro.cantVenta, registro.cantVenta * registro.precioUnit);		
	
	//PUNTO B)	
	totalXCategoria[registro.codCategoria] = totalXCategoria[registro.codCategoria] + (registro.cantVenta*registro.precioUnit);	
	
	//PUNTO B) mostrar Total por ticket (se muestra en fin de corte)
	importeTotalRecuadado = importeTotalRecuadado + (registro.cantVenta*registro.precioUnit);		
	
}

void finCorte(){   
	int i;
	for	(i=1;i<=4;i++){
		printf("%s : $.2f\n",categoriaDescripcion[i],totalXCategoria[i]);
		importeTotalRecuadado=importeTotalRecuadado +totalXCategoria[i];
	}   		
	
	cantTickets=cantTickets+1;	
	
	codCampoControlAnt= registro.nroTicket;
}

void finalizacion(){

//PUNTO C)		
	
	printf("monto total recuadado: %.2f",importeTotalRecuadado);
	
	printf("cantidad de tickets %d ",cantTickets);
	
	fclose(archivo);
}


