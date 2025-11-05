#include <stdio.h> 
#include <string.h>

typedef char tString[30];

typedef struct{
	int nro;
	float precio;
}tRegEjem;

typedef struct {
	tString nombre;
	float real;
	int entero;
	FILE *archivo;
}tReg;

void escribirArchivo(tReg *, tRegEjem *);
void procesoCorte(tReg *, tRegEjem *);

int main(){
	tReg reg;
	tRegEjem regEjem;
	
	escribirArchivo(&reg, &regEjem);
	procesoCorte(&reg, &regEjem);
	return 0;
}

void escribirArchivo(tReg *pReg, tRegEjem *pEjemplo){
	strcpy(pReg->nombre, "ignacio.dat");
	pReg->real = 10;
	pReg->entero = 7;
	
	pReg->archivo = fopen(pReg->nombre, "wb");
	if(pReg->archivo == NULL){
		printf(" Error al abrir archivo para escritura");
	}
	else{
		int i;
		for(i=0; i<3; i++){
			printf(" Ingrese entero: ");
			scanf("%d", &pEjemplo->nro);
			printf(" Ingrese real: ");
			scanf("%f", &pEjemplo->precio);
			fwrite(&(*pEjemplo), sizeof(tRegEjem), 1, pReg->archivo);
		}
		fwrite(&pEjemplo, sizeof(tRegEjem), 1, pReg->archivo);
		fclose(pReg->archivo);
	}
}

void procesoCorte(tReg *pReg, tRegEjem *pRegEjemplo){
	
	pReg->archivo = fopen(pReg->nombre, "rb");
	
	if(pReg->archivo == NULL){
		printf(" Error al abrir archivo para lectura");
	}
	else{
		fread(&(*pRegEjemplo), sizeof(tRegEjem), 1, pReg->archivo);
		
		while(!feof(pReg->archivo)){
			printf("--- %d - %.2f ---\n", pRegEjemplo->nro, pRegEjemplo->precio);
			fread(&(*pRegEjemplo),sizeof(tRegEjem), 1, pReg->archivo);
		}
	}
	fclose(pReg->archivo);
}







