#include<stdio.h>
#include <iostream>
#include <iomanip> // para establecer precision
#include<operacionesRectangulo.h>

int main(){
	float base, altura;
	std:: cout << " Ingrese Base: ";
	std:: cin >> base;
	std:: cout << " Ingrese Altura: ";
	std:: cin >> altura;
	std:: cout << std:: endl << " Base: " << std:: fixed << std:: setprecision(2) << base << std:: endl;
	std:: cout << " Altura: " << std:: fixed << std:: setprecision(2) << altura << std:: endl;
	std:: cout << " Perimetro: " << std:: fixed << std:: setprecision(2) << calcularPerimetro(base, altura) << std:: endl;
	std:: cout << " Area: " << std:: fixed << std:: setprecision(2) << calcularArea(base, altura) << std:: endl;
	
	return 0;
}
