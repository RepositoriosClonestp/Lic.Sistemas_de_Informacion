#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char tString[30];

const int SIZEGENERAL = 1048;

typedef struct{
	tString ip;
	tString nombreDoc[5];
	tString tipoDoc[5];
	int size;
}regDocumento;

typedef regDocumento regDocumentos[3];

bool escribeArchivo(regDocumentos, int, tString);
bool leeArchivo(regDocumentos, int, tString);
void imprimeArchivo(regDocumentos, int);
void imprimeReg(regDocumento);

int main(){
	regDocumentos docImpr;
	int sizeDoc;
	int cantDoc;
	tString nombreArchivo;
	strcpy(nombreArchivo, "Documentos.dat");
	
	int i;
	for(i=0; i<3; i++){
		printf("\n Ingrese ip: ");
		gets(docImpr[i].ip);
		fflush(stdin);
		
		printf(" Ingrese Cantidad de Documentos a Imprimir (max 5): ");
		scanf("%d", &cantDoc);
		fflush(stdin);
		
		int k;
		for(k=0; k<cantDoc; k++){
			printf(" Ingrese nombre del documento: ");
			gets(docImpr[i].nombreDoc[k]);
			fflush(stdin);
			printf(" Ingrese tipo de Doc (docx, pdf, jpg, png o xlsx): ");
			gets(docImpr[i].tipoDoc[k]);
			fflush(stdin);
		}
		
		int h;
		for(h=cantDoc; h<5; h++){
			strcpy(docImpr[i].nombreDoc[h], "");
		}
		
		docImpr[i].size = cantDoc * SIZEGENERAL; 
	}
	sizeDoc = sizeof(docImpr) / sizeof(regDocumento);
	regDocumento docImprEntrada[sizeDoc];
	if((escribeArchivo(docImpr, sizeDoc, nombreArchivo)) == false){
		printf(" Error de escritura!");
		return 1;
	}
	if(leeArchivo(docImprEntrada, sizeDoc, nombreArchivo) == false){
		printf(" Error de lectura!");
		return -1;
	}
	printf("\n----------------------------------\n");
	imprimeArchivo(docImprEntrada, sizeDoc);
	
	return 0;
}

bool escribeArchivo(regDocumentos pDoc, int pSize, tString pNombreArchivo){
	FILE *F;
	F = fopen(pNombreArchivo, "wb");
	if(F == NULL){
		printf("Error al abrir el archivo para escritura");
		return false;
	}
	int i;
	for(i=0; i<pSize; i++){
		fwrite(&pDoc[i], sizeof(regDocumento), 1, F);
	}
	fflush(F);
	fclose(F);
	return true;
}

bool leeArchivo(regDocumentos pDoc, int pSize, tString pNombreArchivo){
	FILE *F;
	F = fopen(pNombreArchivo, "rb");
	if(F == NULL){
		printf("Error al abrir el archivo para lectura");
		return false;
	}
	int i;
	for(i=0; i<pSize; i++){
		fread(&pDoc[i], sizeof(regDocumento), 1, F);
	}
	fclose(F);
	return true;
}

void imprimeArchivo(regDocumentos pDoc, int pSize){
	int i;
	for(i=0; i<pSize; i++){
		imprimeReg(pDoc[i]);
		printf("\n----------------------------------\n");
	}
}

void imprimeReg(regDocumento pDoc){
		printf(" IP: %s \n", pDoc.ip);
		printf(" Documentos: ");
		int i, contador = 0;
		for(i=0; i<5; i++){
			if((strcmp(pDoc.nombreDoc[i], "") != 0)){
			printf(" %s.%s - ", pDoc.nombreDoc[i], pDoc.tipoDoc[i]);
			contador++;
			}
		}
		printf("\n Tama%co en Bytes: %d", 164, pDoc.size);
		printf("\n Cantidad de documentos: %d", contador);
		
}





