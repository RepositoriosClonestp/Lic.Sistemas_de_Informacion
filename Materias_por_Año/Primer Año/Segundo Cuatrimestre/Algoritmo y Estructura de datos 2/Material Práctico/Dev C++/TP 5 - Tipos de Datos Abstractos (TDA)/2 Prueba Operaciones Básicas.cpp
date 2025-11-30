#include<iostream>
#include<string.h>
#include<iomanip>
#include<string>
#include<operacionesBasicas.h>


int main(){
	float num1, num2;
	char operacion;
	std:: string solicitarDato = " Ingrese Número Real: ";
	std:: cout << solicitarDato;
	std:: cin >> num1;
	std:: cout << " Ingrese Segundo Real: ";
	std:: cin >> num2;
	std:: cout << " Ingrese Operacion (+, -, *, /): ";
	std:: cin >> operacion;
	
	switch(operacion){
		case '+': std:: cout << " Resultado de Sumarlos: " << std:: fixed << std:: setprecision(2) << suma(num1, num2) << std:: endl;
		break;
		case '-': std:: cout << " Resultado de Restarlos: " << std:: fixed << std:: setprecision(2) << resta(num1, num2) << std:: endl;
		break;
		case '*': std:: cout << " Resultado de Multiplicar el 1ro por el 2do: " << std:: fixed << std:: setprecision(2) << multiplicacion(num1, num2) << std:: endl;
		break;
		case '/': std:: cout << " Resultado de Dividir el 1ro por el 2do: " << std:: fixed << std:: setprecision(2) << division(num1, num2) << std:: endl;
		break;
		default: std:: cout << " Operacion No Valida";
	}
	return 0;
}
