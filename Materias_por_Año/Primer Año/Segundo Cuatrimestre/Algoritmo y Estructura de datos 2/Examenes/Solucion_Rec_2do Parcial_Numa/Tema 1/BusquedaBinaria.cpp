bool busquedaBinaria( tVectorFloat pVector, float pElem ) {
	int extInf = 0;
	int extSup = MAX;
	int posMedio = -1;
	bool encontrado = false;
	
	// while( (encontrado == false) && (extSup >= extInf)) {
	while( !encontrado && (extSup >= extInf)) {
		
		/* Determinar la posición central */
		posMedio = (extInf + extSup) / 2;
		
		/* Consultar si el elemento buscado es el que está en la posición central */
		if( pElem == pVector[posMedio] ) {
			encontrado = true;
		}else {
			/* Determinar de qué lado está el elemento */
			if( pElem > pVector[posMedio] ) {
				/* Actualizar el extremo inferior */
				extInf = posMedio + 1;
			}else {
				/* Actualizar el extremo superior */
				extSup = posMedio - 1;
			}						
		}		
	}
	
	printf("extInf algoritmo: %d\n", extInf);
	printf("extSup algoritmo: %d\n", extSup);
	
	return encontrado;	
}
