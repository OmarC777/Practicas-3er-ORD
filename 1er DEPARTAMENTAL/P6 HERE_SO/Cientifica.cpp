#include "Cientifica.h"
#include <iostream>
#include <math.h>
using namespace std;

Cientifica::Cientifica() {}
Cientifica::~Cientifica() {}

Calculadora::Calculadora()
{
}

Calculadora::~Calculadora()
{
}

Calculadora::Sumar()
{
	double n1 = 0; double n2 = 0; double res = 0;
	cout << "Suma sin parametros" <<endl;
	cout << "Escribe el primer numero: " <<endl;
	cin >> n1;
	cout << n1 << "\n";
	cout << "Escribe el segundo numero: " <<endl;
	cin >> n2;
	cout << n2 << "\n";
	res = n1 + n2;
	cout << "El resultado es: " << res;
	cout <<"\n";
}

double Calculadora::Sumar(double n1, double n2)  
{
	cout << "Suma con dos parametros" <<endl;
	cout << n1 << " + " << n2 << " = ";
	double res = n1 + n2;
	return res;
}
double Calculadora::Sumar(double num1, double num2, double num3)  
{
	cout << "Suma con tres parametros" <<endl;
	cout << num1 << " + " << num2 << " + " << num3 << " = ";
	double res = num1 + num2 + num3;
	return res;
}

double Cientifica::Potencia(double base, double exponente) 
{
    cout << "--- Operacion de Potencia Cientifica ---" << endl;
    return pow(base, exponente);
}

double Cientifica::Sumar(double n1, double n2) 
{
    cout << "\n[Cientifica] Multiplicando " << n1 << " x " << n2 << " mediante sumas:" << endl;
    double resultado = 0;
    for(int i = 0; i < n2; i++) {
        resultado += n1;
    }
    return resultado;
}

double Cientifica::MultiplicacionSucesiva(double base, double exp) 
{
    cout << "\n[Cientifica] Potencia mediante multiplicaciones:" << endl;
    double resultado = 1;
    for(int i = 0; i < exp; i++) {
        resultado = Sumar(resultado, base); // Reutilizamos nuestra multiplicación de arriba
    }
    return resultado;
	}
	
double Cientifica::DivisionSucesiva(double dividendo, double divisor) 
{
    cout << "\n[Cientifica] Dividiendo mediante restas:" << endl;
    if(divisor == 0) return 0;
    
    double cociente = 0;
    double resto = dividendo;
    while(resto >= divisor) 
	{
        resto -= divisor;
        cociente++;
    }
    return cociente;
	}
