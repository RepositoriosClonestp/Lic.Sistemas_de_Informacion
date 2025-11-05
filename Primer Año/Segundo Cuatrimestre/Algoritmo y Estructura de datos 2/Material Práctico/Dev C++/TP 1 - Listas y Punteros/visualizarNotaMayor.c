// Función que muestra al alumno con mayor nota de la lista.

// - Prototipado -
void visualizarNotaMayor(tLista *);

// - FUNCION PRINCIPAL -

// - Desarrollo de la Función -
void visualizarNotaMayor(tLista *pLista){
	tLista *auxLista = pLista;
	tLista *aux2 = pLista;
	float notaMayor = 0;
	
	if (auxLista == NULL){
		printf("\n Lista de Alumnos vacia.");
	}
	else {
		while (auxLista != NULL){
			if (auxLista->alumno.notaFinal >= notaMayor){
				notaMayor = auxLista->alumno.notaFinal;
				aux2 = auxLista;
			}
			auxLista=auxLista->siguiente;
		}
		printf("\n\n La nota mayor es del alumno: %s - apellido:%s - dni:%d -  sexo:%c - nota final:%.2f",aux2->alumno.nombre,aux2->alumno.apellido,aux2->alumno.dni,aux2->alumno.sexo,aux2->alumno.notaFinal); 
	}
}
