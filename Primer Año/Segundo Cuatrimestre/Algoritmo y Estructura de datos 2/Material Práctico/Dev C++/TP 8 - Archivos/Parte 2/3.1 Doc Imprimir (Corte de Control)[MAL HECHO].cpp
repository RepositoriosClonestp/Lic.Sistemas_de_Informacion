#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char tString[30];
const int MAXINDEX = 5;
typedef struct{
	tString ip;
	tString nombreDoc[MAXINDEX];
	tString tipoDoc[MAXINDEX];
	int size[MAXINDEX];
	int cantDoc;
}regDocumento;

bool escribeArchivo(tString);
bool leeArchivo(tString, FILE *, regDocumento);
void corteControl(tString, FILE *, regDocumento);

int main(){
	tString nombreArchivo;
	strcpy(nombreArchivo, "Documentos.dat");
	
	if(escribeArchivo(nombreArchivo) == false){
		printf(" Error de escritura\n");
	};
}

bool escribeArchivo(tString pNombreArchivo){
	FILE *pArchivo;
	regDocumento pRegDocumento;
	pArchivo = fopen(pNombreArchivo, "wb");
	
	if(pArchivo == NULL){
		printf("Error al abrir el archivo para escritura");
		return false;
	}
	
	bool continuar = true;
	
	while(continuar == true){
		printf(" Ingrese IP (0 para finalizar): ");
		scanf("%d", &pRegDocumento.ip);
		//completar
		}

	fclose(pArchivo);
	return true;
}

bool leeArchivo(tString pNombreArchivo, FILE *pArchivo, regDocumento pRegDocumento){
	pArchivo = fopen(pNombreArchivo, "rb");
	if(pArchivo == NULL){
		printf("Error al abrir el archivo para lectura");
		return false;
	}
	while(fread(&pRegDocumento, sizeof(regDocumento), 1, pArchivo) != EOF){
		int pesoTotal = 0;
		int cantDoc = 0;
		
		printf(" IP: %d - Documentos: \n", pRegDocumento.ip);
		int i;
		for(i=0; i<MAXINDEX; i++){
			printf(" %s.%s", pRegDocumento.nombreDoc[i], pRegDocumento.tipoDoc[i]);
			pesoTotal = pesoTotal + pRegDocumento.size[i];
			cantDoc++;
		}
		printf(" Cantidad de Documentos PC %d: %d", pRegDocumento.ip, cantDoc);
		printf(" Peso Total: %d", pesoTotal);
	}
	
	fclose(pArchivo);
	return true;
}

/*
while(fread(&pRegDocumento, sizeof(regDocumento), 1, pArchivo) != EOF){
		int contImg = 0;
		int contDoc = 0;
		printf(" IP: %d - Documentos: \n", pRegDocumento.ip);
		int i;
		for(i=0; i<MAXINDEX; i++){
			printf(" %s.%s", pRegDocumento.nombreDoc[i], pRegDocumento.tipoDoc[i]);
			if((strcmp(pRegDocumento.tipoDoc[i], "jpg") == 0) || (strcmp(pRegDocumento.tipoDoc[i], "png") == 0) ){
				contImg++;
			}
			else{
				contDoc++;
			}
		}
	}
	
	if (pRegDocumento.cantDoc > MAXINDEX) {
                printf("Error: La cantidad de documentos no puede superar 5");
                fclose(pArchivo);
                return false;
            }
            
			while (getchar() != '\n');
	
			int i;
			for(i=0; i<pRegDocumento.cantDoc; i++){
				printf(" Ingrese nombre del documento: ");
				scanf("%s", &pRegDocumento.nombreDoc[i]);
				
				printf(" Ingrese tipo de documento (docx-pdf-jpg-png-xlsx): ");
				scanf("%s", &pRegDocumento.tipoDoc[i]);
				
				printf(" Ingrese tamanio del documento en KB: ");
				scanf("%d", &pRegDocumento.size[i]);
				}
				fwrite(&pRegDocumento, sizeof(regDocumento), 1, pArchivo);
*/





