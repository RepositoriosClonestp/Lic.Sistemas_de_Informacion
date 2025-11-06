#include <stdio.h>

/* Interfaz pública */
float suma(float, float);
float resta(float, float);
float producto(float, float);
float cociente(float, float);

/* Implementación */
float suma(float nro1, float nro2) {
	return nro1+nro2;
}

float resta(float nro1, float nro2) {
	return nro1-nro2;
}

float producto(float nro1, float nro2) {
	return nro1*nro2;
}

float cociente(float nro1, float nro2){
	return (float) nro1/nro2;
}
