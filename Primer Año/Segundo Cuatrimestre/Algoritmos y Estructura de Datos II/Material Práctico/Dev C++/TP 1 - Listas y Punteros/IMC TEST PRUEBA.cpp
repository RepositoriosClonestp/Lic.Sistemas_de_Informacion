#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct{
	char sexo;
	int edad;
	int peso;
	float altura;
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
encuesta *clasificar();
void agregar(encuesta **lista); //Agregar declarado como una función que recibe un parámetro por referencia que modifica directamente a la variable global lista.
void mostrarBajoPeso(encuesta *lista);
void mostrarSobrepeso(encuesta *lista);
void menu(encuesta *lista, encuesta **pLista); //p es puntero

// Funcion Principal
int main(){
	int datoControl, p;
	printf("\n Quiere ingresar encuestados? 1 para si: ");
	scanf("%d", &datoControl);
	
	inicializar(listaPersonas);
	while (datoControl == 1){
		
	    menu(listaPersonas, &listaPersonas);
	    
		printf("\n Quiere continuar? 1 para si: ");
	    scanf("%d", &datoControl);
	}
	
	return 0;
}

void inicializar(encuesta *lista){
	lista = NULL;
}

void visualizar(encuesta *lista){
	while(lista != NULL){
		printf("\n Altura: %.2f - Peso: %d - edad: %d - IMC: %.2f - Clasificacion: %s ", lista->infoPersona.altura, lista->infoPersona.peso, lista->infoPersona.edad, lista->infoPersona.IMC, lista->infoPersona.clasif);
		lista = lista->sig;
	}
	
}

bool listaVacia(encuesta *lista){
	return (lista == NULL);
}

encuesta *clasificar(){
	encuesta *aux;
	int edad, peso;
	float altura;
	char sexo;
	float IMC;
	
	aux = (encuesta *) malloc(sizeof(encuesta));
	printf("\n Ingrese edad: ");
	scanf("%d", &edad);
	fflush(stdin);
	printf("\n Ingrese sexo: ");
	scanf("%c", &sexo);
	printf("\n Ingrese altura en m: ");
	scanf("%f", &altura);
	printf("\n Ingrese peso en kg: ");
	scanf("%d", &peso);
	
	IMC = peso / (altura * altura);
	
	aux->infoPersona.IMC = IMC;
	aux->infoPersona.edad = edad;
	aux->infoPersona.altura = altura;
	aux->infoPersona.peso = peso;
	aux->infoPersona.sexo = sexo;
	
	char bajo[15], normal[15], sobre[15];
	
	strcpy(bajo, "Bajo Peso");
	strcpy(normal, "Peso Normal");
	strcpy(sobre, "Sobrepeso");
	
	if (((sexo == 'm') || (sexo == 'M'))  && (IMC < 19)){
		strcpy(aux->infoPersona.clasif, bajo);
	}
	if (((sexo == 'm') || (sexo == 'M')) && (IMC > 19) && (IMC < 24)){
		strcpy(aux->infoPersona.clasif, normal);
	}
	if (((sexo == 'm') || (sexo == 'M')) && (IMC > 24)){
		strcpy(aux->infoPersona.clasif, sobre);
	}
	
	if (((sexo == 'f') || (sexo == 'F')) && (IMC < 20)){
		strcpy(aux->infoPersona.clasif, bajo);
	}
	if (((sexo == 'f') || (sexo == 'F')) && (IMC > 20) && (IMC < 25)){
		strcpy(aux->infoPersona.clasif, normal);
	}
	if (((sexo == 'f') || (sexo == 'F')) && (IMC > 25)){
		strcpy(aux->infoPersona.clasif, sobre);
	}
	
	return aux;
}


void agregar(encuesta **lista){
	encuesta *nuevaPersona, *aux; 
	
	nuevaPersona = (encuesta *) malloc(sizeof(encuesta));
	nuevaPersona = clasificar(); 
	nuevaPersona->sig = NULL;
	
	if(*lista == NULL){ 
		*lista = nuevaPersona;
	}
	else{       
		aux = *lista; 
		while (aux->sig != NULL){ 
			aux = aux->sig;
			
		}
		aux->sig = nuevaPersona; 
	}
}

void mostrarBajoPeso(encuesta *lista){
	while(lista != NULL){
		if ((lista->infoPersona.IMC < 19) && (lista->infoPersona.edad < 15)){
		printf("\n Sexo: %c - Altura: %.2f - Peso: %d - Edad: %d - IMC: %.2f ", lista->infoPersona.sexo, lista->infoPersona.altura, lista->infoPersona.peso, lista->infoPersona.edad, lista->infoPersona.IMC);
		printf("\n Clasificacion: %s \n ----------------------------------", lista->infoPersona.clasif);
		lista = lista->sig;
	    }
	    else {
	    	lista = lista->sig;
		}
	}
}


void mostrarSobrepeso(encuesta *lista){
	while(lista != NULL){
		if (lista->infoPersona.IMC > 25){
		printf("\n Sexo: %c - Altura: %.2f - Peso: %d - Edad: %d - IMC: %.2f ", lista->infoPersona.sexo, lista->infoPersona.altura, lista->infoPersona.peso, lista->infoPersona.edad, lista->infoPersona.IMC);
		printf("\n Clasificacion: %s \n ----------------------------------", lista->infoPersona.clasif);
		lista = lista->sig;
	    }
	    else {
	    	lista = lista->sig;
		}
	}
}


void menu(encuesta *lista, encuesta **pLista){
		int opcion;
	    printf("\n Ingrese opcion: 1) Agregar - 2) Visualizar Bajo Peso - 3) Visualizar Sobrepeso - 4) Visualizar Encuestados:  ");
	    scanf("%d", &opcion);
	    
	switch(opcion){
		case 1: agregar(pLista);
		break;
		case 2: mostrarBajoPeso(lista);
		break;
		case 3: mostrarSobrepeso(lista);
		break;
		case 4: visualizar(lista);
		break;
		default: printf("\n Opcion no valida.");
	}
}
