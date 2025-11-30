#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*tipos de datos*/
typedef char string[50];

typedef struct registro{
	
	string pais;
	int fecha;
	string deporte;
	string nombre;
	int puntos;
	
}t_registro;


/*prototipos*/
void corte_control();
int leer_lista(FILE *,t_registro *);

/*bloque principal*/
int main (){
	
	corte_control();
	
//	leer_lista(FILE *lista_camp, t_registro *registro);
	
	return 0;
}


/*funciones*/
void corte_control(){
	
	FILE *lista_camp = fopen ("lista olimpica.txt","r");
	
	if(lista_camp == NULL){
		
		printf(" FILE ERROR 404 ");
		
		fclose(lista_camp);
		
	}
	else{
		
	int puntos_pais, puntos_fecha;
	string pais_actual ;
	int fecha_actual;
	string deporte_actual;	
	t_registro registro_actual;
	int cantidad_leidos = leer_lista( lista_camp, &registro_actual);
	
	while(cantidad_leidos != EOF){
		
		puntos_pais = 0;
		
		strcpy (pais_actual, registro_actual.pais);
		
		printf("pais: %s \n", pais_actual);
		
			while( strcmp (pais_actual, registro_actual.pais) == 0 && cantidad_leidos != EOF){
				
				printf("");
				
			}
		
	}
	
	
		
	}
	
	fclose(lista_camp);
	
}





int leer_lista(FILE *lista_camp, t_registro *registro){
	
	fscanf(lista_camp, " %s %i %s %s %i ", &registro -> pais, &registro -> fecha, &registro -> deporte, &registro -> nombre, &registro -> puntos);	
	
	
	
	
	
	
}
