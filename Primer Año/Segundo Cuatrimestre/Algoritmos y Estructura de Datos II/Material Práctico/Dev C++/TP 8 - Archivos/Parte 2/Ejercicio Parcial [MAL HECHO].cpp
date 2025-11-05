#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char tString[50];

typedef struct{
	int codProv;
	tString producto;
	int codCat;
	float importe;
}regEnvio;

bool escribirArchivo(tString);
bool leerArchivo(tString);
void corteControl(tString);

tString PROVINCIAS[5] = {"", "Corrientes", "Chaco     ", "Formosa   ", "Santa Fe  "};

int main(){
	tString nombreArchivo;
	strcpy(nombreArchivo, "enviosMercadoLibre.dat");
	
	if(escribirArchivo(nombreArchivo) == true){
		printf(" Escritura realizada correctamente.\n");
	}
	else{
		printf(" Error de escritura!\n");
	}
	corteControl(nombreArchivo);
	
	return 0;
}

bool escribirArchivo(tString pNombreArchivo){
	FILE *F;
	regEnvio reg;
	F = fopen(pNombreArchivo, "wb");
	if(F == NULL){
		printf(" Error al abrir el archivo para escritura.\n");
		return false;
	}
	else{
		bool continuar = true;
		
		while(continuar == true){
			printf(" Ingrese provincia de destino (0 para finalizar - 1 Corrientes - 2 Chaco - 3 Formosa - 4 Santa Fe): ");
			scanf("%d", &reg.codProv);
			fflush(stdin);
			if(reg.codProv == 0){
				continuar = false;
			}
			else{
			printf(" Ingrese nombre del producto: ");
			gets(reg.producto);
			fflush(stdin);
			
			printf(" Ingrese codigo de categoria (1-Muebles, 2-Electronica, 3-Moda, 4-Herramientas): ");
			scanf("%d", &reg.codCat);
			
			printf(" Ingrese importe del producto: ");
			scanf("%f", &reg.importe);
			
			fwrite(&reg, sizeof(regEnvio), 1, F);
			}
		}
		fclose(F);
		return true;
	}
	
}

bool leerArchivo(tString pNombreArchivo, int pCodProv){
	FILE *F;
	regEnvio reg;
	F = fopen(pNombreArchivo, "rb");
	if(F == NULL){
		printf(" Error al abrir el archivo para lectura.");
		return false;
	}
	else{
		int cantEnvios = 0;
		float impProm = 0;
		printf("\n Provincia - Cantidad de Envios - Importe Promedio \n");
		while(fread(&reg, sizeof(regEnvio), 1, F) == 1){
			if(reg.codProv == pCodProv){
				cantEnvios++;
				impProm = impProm + reg.importe;
			}
		}
		if(cantEnvios != 0){
			impProm = impProm / cantEnvios;
		}
		printf(" %s -	 %d 		- %.2f", PROVINCIAS[pCodProv], cantEnvios, impProm);	
		fclose(F);
		return true;
	}	
}

void corteControl(tString pNombreArchivo){
	int i;
	for(i = 1; i < 5; i++){
		if(leerArchivo(pNombreArchivo, i) == false){
			printf(" Error de lectura!");
		}
		}
	}










