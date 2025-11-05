#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
	char sexo;
	int edad;
	int peso;
	int altura;
	float IMC;
	char clasif[15];
}tDatos;

typedef struct nodo{
	tDatos infoPersona;
	struct nodo *sig;
}encuesta;

//Lista de Encuestados como Variable Global
encuesta *listaPersonas;

//Prototipado
void inicializar(encuesta *lista);
void visualizar(encuesta *lista);
bool listaVacia(encuesta *lista);
void ingresarDatos(encuesta *lista);
void calcularIMC(encuesta *lista);
void clasificar(encuesta *lista);
void agregar(encuesta *lista);
void mostrarBajoPeso(encuesta *lista);
void mostrarSobrepeso(encuesta *lista);
void menu(encuesta *lista);

// Funcion Principal
int main(){
	int datoControl;
	printf("\n Quiere ingresar encuestados? 1 para si: ");
	scanf("%d", &datoControl);
	
	inicializar(listaPersonas);

	while(datoControl == 1){
		menu(listaPersonas);
		printf("\n Desea realizar otra operacion? 1 para si: ");
		scanf("%d", &datoControl);
	}
}

void inicializar(encuesta *lista){
	lista = NULL;
}

void visualizar(encuesta *lista){
	while(lista != NULL){
		printf("\n Altura: %d - Peso: %d - edad: %d - IMC: %.2f ", lista->infoPersona.altura, lista->infoPersona.peso, lista->infoPersona.edad, lista->infoPersona.IMC);
		lista = lista->sig;
	}
	
}

bool listaVacia(encuesta *lista){
	return (lista == NULL);
}
void clasificar(encuesta *lista){
	ingresarDatos(lista);
	calcularIMC(lista);
	char bajo[15], normal[15], sobre[15];
	
	strcpy(bajo, "Bajo Peso");
	strcpy(normal, "Peso Normal");
	strcpy(sobre, "Sobrepeso");
	
	if (lista->infoPersona.sexo ==( 'm' || 'M') && lista->infoPersona.IMC < 19){
		strcpy(lista->infoPersona.clasif, bajo);
	}
	if ((lista->infoPersona.sexo ==( 'm' || 'M')) && (lista->infoPersona.IMC >19) && (lista->infoPersona.IMC < 24)){
		strcpy(lista->infoPersona.clasif, normal);
	}
	if ((lista->infoPersona.sexo ==( 'm' || 'M')) && (lista->infoPersona.IMC > 24)){
		strcpy(lista->infoPersona.clasif, sobre);
	}
	
	if (lista->infoPersona.sexo ==( 'f' || 'F') && lista->infoPersona.IMC < 20){
		strcpy(lista->infoPersona.clasif, bajo);
	}
	if ((lista->infoPersona.sexo ==( 'f' || 'F')) && (lista->infoPersona.IMC > 20) && (lista->infoPersona.IMC < 25)){
		strcpy(lista->infoPersona.clasif, normal);
	}
	if ((lista->infoPersona.sexo ==( 'f' || 'F')) && (lista->infoPersona.IMC > 25)){
		strcpy(lista->infoPersona.clasif, sobre);
	}
}
void ingresarDatos(encuesta *lista){
	fflush(stdin);
	printf("\n Ingrese sexo: ");
	scanf("%c", lista->infoPersona.sexo);
	fflush(stdin);
	printf("\n Ingrese edad: ");
	scanf("%d", lista->infoPersona.edad);
	printf("\n Ingrese altura en cm: ");
	scanf("%d", lista->infoPersona.altura);
	printf("\n Ingrese peso en kg: ");
	scanf("%d", lista->infoPersona.peso);
}

void calcularIMC(encuesta *lista){
	int peso, altura;
	float IMC;
	
	peso = lista->infoPersona.peso;
	altura = lista->infoPersona.altura;
	
	IMC = peso * (altura * altura);
	lista->infoPersona.IMC = IMC;
	
}

void agregar(encuesta *lista){
	encuesta *nuevaPersona, *aux; 
	
	nuevaPersona = (encuesta *) malloc(sizeof(encuesta));
	clasificar(nuevaPersona); 
	nuevaPersona->sig = NULL;
	
	if(lista == NULL){ 
		lista = nuevaPersona;
	}
	else{       
		aux = lista; 
		while (aux->sig != NULL){ 
			aux = aux->sig;
			
		}
		aux->sig = nuevaPersona; 
	}
}

void mostrarBajoPeso(encuesta *lista){
	if ((lista->infoPersona.clasif == "Bajo Peso") && (lista->infoPersona.edad < 15)){
		printf("\n Personas menores a 15 años con Bajo Peso: ");
	while(lista != NULL){
		printf("\n Sexo: %c - Altura: %d - Peso: %d - Edad: %d - IMC: %.2f ",lista->infoPersona.sexo, lista->infoPersona.altura, lista->infoPersona.peso, lista->infoPersona.edad, lista->infoPersona.IMC);
		printf("\n Clasificacion: %s", lista->infoPersona.clasif);
		lista = lista->sig;
	}
}
	else {
		printf("\n Ninguna persona encuestada tiene bajo peso y es menor de 15 años");
	}
}


void mostrarSobrepeso(encuesta *lista){
	if ((lista->infoPersona.clasif == "Sobrepeso")){
		printf("\n Personas con Sobrepeso: ");
	while(lista != NULL){
		printf("\n Sexo: %c - Altura: %d - Peso: %d - Edad: %d - IMC: %.2f ",lista->infoPersona.sexo, lista->infoPersona.altura, lista->infoPersona.peso, lista->infoPersona.edad, lista->infoPersona.IMC);
		printf("\n Clasificacion: %s", lista->infoPersona.clasif);
		lista = lista->sig;
	}
}
	else {
		printf("\n Ninguna persona encuestada tiene sobrepeso");
	}
}

void menu(encuesta *lista){
	int opcion;
	printf("\n Ingrese opcion: 1) Agregar - 2) Visualizar Bajo Peso - 3) Visualizar Sobrepeso: ");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1: agregar(lista);
		break;
		case 2: mostrarBajoPeso(lista);
		break;
		case 3: mostrarSobrepeso(lista);
		break;
		default: printf("\n Opcion no valida.");
	}
}

