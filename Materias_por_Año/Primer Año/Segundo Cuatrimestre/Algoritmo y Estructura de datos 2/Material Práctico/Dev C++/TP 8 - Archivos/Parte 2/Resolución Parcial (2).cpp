#include <stdio.h> 
#include <string.h>
#include <iostream>

typedef char tString[30];

const int N = 5;

tString categoriaDescripcion[N]={"","Panaderia ","Lacteos   ","Perfumeria","Limpieza  "};

typedef struct {
	int nroTicket;
	int codProducto;
	tString nombre;
	int codCategoria;
	int cantVenta;
	float precioUnit;
}tRegSup;

typedef struct{
	tString nombreArchivo;
	int  campoControl;
	float totalPorTicket;
	float importeTotal;
	float importePorCat[5] = {0,0,0,0,0};
	FILE *Archivo;	
}tRegCorteControl;

void inicializar(tRegCorteControl *, tRegSup *);
void procesoCorte(tRegCorteControl *, tRegSup *);
void finalizar(tRegCorteControl *);

void principioCorte(tRegCorteControl *);
void unGrupo(tRegCorteControl *, tRegSup *);
void finCorte(tRegCorteControl *);

void escribirDatos(tRegCorteControl *, tRegSup *);

int main(){
	tRegSup regSup;
	tRegCorteControl regCorte;
	
	escribirDatos(&regCorte, &regSup);
	
	inicializar(&regCorte, &regSup);
	procesoCorte(&regCorte, &regSup);
	finalizar(&regCorte);
	
	return 0;
}

void escribirDatos(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	
	strcpy(pRegCorte->nombreArchivo, "registroSupermecado.dat");
	
	pRegCorte->Archivo = fopen(pRegCorte->nombreArchivo, "wb");
	if(pRegCorte->Archivo == NULL){
		printf(" Error al abrir el archivo");
	}
	else{
		int cantTicket = 0;
		
		printf(" Ingrese cantidad de tickets a registrar: ");
		scanf("%d", &cantTicket);
		
		int i;
		for(i=1; i<=cantTicket; i++){
			pRegSup->nroTicket = i;
			
				printf(" Ingrese Codigo Producto: ");
				scanf("%d", &pRegSup->codProducto);
				while (getchar() != '\n');
					
				printf(" Ingrese Nombre Producto: ");
				scanf("%[^\n]", &pRegSup->nombre);
					
				printf(" Ingrese Categoria del Producto: ");
				scanf("%d", &pRegSup->codCategoria);
					
				printf(" Ingrese Cantidad de Productos: ");
				scanf("%d", &pRegSup->cantVenta);
					
				printf(" Ingrese Precio Producto: ");
				scanf("%f", &pRegSup->precioUnit);
				
				printf("\n");
				
				fwrite(&(*pRegSup), sizeof(tRegSup), 1, pRegCorte->Archivo);
		}
		fclose(pRegCorte->Archivo);
	}
}

void inicializar(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	pRegCorte->Archivo = fopen(pRegCorte->nombreArchivo, "rb");
	
	fread(pRegSup, sizeof(tRegSup), 1, pRegCorte->Archivo);
	pRegCorte->campoControl = pRegSup->nroTicket;
	
	printf("			 | Informe de Ventas Del Dia |\n");
	printf(" | Nro Ticket | Cod Producto | Nombre Producto | Categoria Producto | Cantidad Vendido | Precio Unitario |\n");
	
	int i;
	for(i=0; i<4; i++){
		pRegCorte->importePorCat[i] = 0;
	}
	pRegCorte->importeTotal = 0;
}

void procesoCorte(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	while(!feof(pRegCorte->Archivo)){
		
		principioCorte(pRegCorte);
		
		while(!feof(pRegCorte->Archivo) && pRegSup->nroTicket == pRegCorte->campoControl){
			unGrupo(pRegCorte, pRegSup);
			fread(pRegSup, sizeof(tRegSup), 1, pRegCorte->Archivo);
		}
		
		finCorte(pRegCorte);
		pRegCorte->campoControl = pRegSup->nroTicket;
	}
	
}

void principioCorte(tRegCorteControl *pRegCorte){
	pRegCorte->totalPorTicket = 0;
}

void unGrupo(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	
	printf(" | %d	      | %d	     | %s 	       | %s	    | %d 	       | %.2f		 |\n", pRegSup->nroTicket, pRegSup->codProducto, pRegSup->nombre, categoriaDescripcion[pRegSup->codCategoria], pRegSup->cantVenta, pRegSup->precioUnit);
	
	pRegCorte->totalPorTicket = pRegCorte->totalPorTicket + (pRegSup->cantVenta * pRegSup->precioUnit);
	pRegCorte->importePorCat[pRegSup->codCategoria] = pRegCorte->importePorCat[pRegSup->codCategoria] + (pRegSup->cantVenta * pRegSup->precioUnit);
	pRegCorte->importeTotal = pRegCorte->importeTotal + pRegCorte->totalPorTicket;
}

void finCorte(tRegCorteControl *pRegCorte){
	printf(" | Total Ticket: %.2f\n", pRegCorte->totalPorTicket);
	printf(" |---------------------------------------------------------------------------------------------------------\n");
	
}

void finalizar(tRegCorteControl *pRegCorte){
	int i;
	for	(i=1; i<=4; i++){
		printf(" | %s: $%.2f\n", categoriaDescripcion[i], pRegCorte->importePorCat[i]);
	}
	printf(" | Monto Total Recuadado: %.2f", pRegCorte->importeTotal);
	
	fclose(pRegCorte->Archivo);
}






















