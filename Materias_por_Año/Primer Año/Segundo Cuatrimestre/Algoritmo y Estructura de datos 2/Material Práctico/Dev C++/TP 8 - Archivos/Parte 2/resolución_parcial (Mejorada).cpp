#include <stdio.h> 
#include <string.h>
#include <iostream>

typedef char tString[30];
tString CAT[5] = {"","Panaderia ","Lacteos   ","Perfumeria","Limpieza  "};

typedef struct{
	int codProducto;
	tString nombre;
	int codCateg;
	int cantVendida;
	float precioUnit;
}tDatos;

typedef struct{
	int nroTicket;
	int cantCategorias;
	tDatos datosTicket[4];
}tRegSup;

typedef struct{
	int codCampoControl;
	tString nombreArchivo;
	FILE *archivo;
	float importePorCat[5];
	float importeTotal;
	float importePorTicket;
	int cantTicket;
}tRegCorteControl;

void escribirDatos(tRegCorteControl *, tRegSup *);

void inicializar(tRegCorteControl *, tRegSup *);

void principioCorte(tRegCorteControl *);
void unTicket(tRegCorteControl *, tRegSup *);
void finCorte(tRegCorteControl *);

void procesoCorte(tRegCorteControl *, tRegSup *);
void finalizar(tRegCorteControl *);

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
	strcpy(pRegCorte->nombreArchivo, "registroSupermecado2.dat");
	
	pRegCorte->archivo = fopen(pRegCorte->nombreArchivo, "ab");
	if(pRegCorte->archivo == NULL){
		printf(" Error al abrir el archivo");
	}
	else{
		int cantTicket = 0;
		
		printf(" Ingrese cantidad de tickets a registrar: ");
		scanf("%d", &cantTicket);
		
		int i, j;
		for(i=1; i<=cantTicket; i++){
			pRegSup->nroTicket = i;
			printf(" Ingrese cantidad de categorias compradas (max 4): ");
			scanf("%d", &pRegSup->cantCategorias);
			for(j=0; j<pRegSup->cantCategorias; j++){
				
				printf(" Ingrese Codigo Producto: ");
				scanf("%d", &pRegSup->datosTicket[j].codProducto);
				while (getchar() != '\n');
					
				printf(" Ingrese Nombre Producto: ");
				scanf("%[^\n]", &pRegSup->datosTicket[j].nombre);
					
				printf(" Ingrese Categoria del Producto: ");
				scanf("%d", &pRegSup->datosTicket[j].codCateg);
					
				printf(" Ingrese Cantidad de Productos: ");
				scanf("%d", &pRegSup->datosTicket[j].cantVendida);
					
				printf(" Ingrese Precio Producto: ");
				scanf("%f", &pRegSup->datosTicket[j].precioUnit);
				
				printf("\n");
			}
			fwrite(pRegSup, sizeof(tRegSup), 1, pRegCorte->archivo);
		}
		fclose(pRegCorte->archivo);
	}
}

void inicializar(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	pRegCorte->archivo = fopen(pRegCorte->nombreArchivo, "rb");
	fread(pRegSup, sizeof(tRegSup), 1, pRegCorte->archivo);
	pRegCorte->codCampoControl = pRegSup->nroTicket;
	
	printf("			 | Informe de Ventas Del Dia |\n");
	printf(" | Nro Ticket | Cod Producto | Nombre Producto | Categoria Producto | Cantidad Vendido | Precio Unitario |\n");
	int i;
	for(i=0; i<=4; i++){
		pRegCorte->importePorCat[i] = 0;
	}
	pRegCorte->importeTotal = 0;
}

void principioCorte(tRegCorteControl *pRegCorte){
	int i;
	for(i=0; i<5; i++){
		pRegCorte->importePorCat[i] = 0;
	}
	pRegCorte->importePorTicket = 0;
}

void unTicket(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	int i;
	tDatos datosTicket[pRegSup->cantCategorias];
	
	printf(" ---------------------------------------------------------------------------------------------------------\n");
	printf(" | %d	      ", pRegSup->nroTicket);
	for(i=0; i<pRegSup->cantCategorias; i++){
		datosTicket[i] = pRegSup->datosTicket[i];
		printf("| %d	     | %s 	       | %s	    | %d 	       | %.2f		 |\n", datosTicket[i].codProducto, datosTicket[i].nombre, CAT[datosTicket[i].codCateg], datosTicket[i].cantVendida, datosTicket[i].precioUnit);
		pRegCorte->importePorCat[datosTicket[i].codProducto] += (datosTicket[i].cantVendida * datosTicket[i].precioUnit);
		pRegCorte->importePorTicket += (datosTicket[i].cantVendida * datosTicket[i].precioUnit);
		printf("     	      ");
	}
	printf("\n");
	pRegCorte->importeTotal += pRegCorte->importePorTicket;
	pRegCorte->cantTicket++;
}

void finCorte(tRegCorteControl *pRegCorte){
	int i;
	printf(" ---------------------------------------------------------------------------------------------------------\n");
	for(i=1; i<5; i++){
		printf(" | %s: $%.2f\n", CAT[i], pRegCorte->importePorCat[i]);
	}
	printf(" | Monto Ticket: %.2f\n", pRegCorte->importePorTicket);
	printf(" ---------------------------------------------------------------------------------------------------------\n");
}

void procesoCorte(tRegCorteControl *pRegCorte, tRegSup *pRegSup){
	while(!feof(pRegCorte->archivo)){
		
		principioCorte(pRegCorte);
		
		while(!feof(pRegCorte->archivo) && pRegCorte->codCampoControl == pRegSup->nroTicket){
			unTicket(pRegCorte, pRegSup);
			fread(pRegSup, sizeof(tRegSup), 1, pRegCorte->archivo);
		}
		finCorte(pRegCorte);
		pRegCorte->codCampoControl = pRegSup->nroTicket;
	}
}

void finalizar(tRegCorteControl *pRegCorte){
	printf(" | Monto Total Recuadado: %.2f", pRegCorte->importeTotal);
	
	fclose(pRegCorte->archivo);
}






















