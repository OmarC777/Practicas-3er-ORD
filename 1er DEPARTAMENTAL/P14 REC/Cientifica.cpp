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

void Calculadora::Sumar()
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


double Cientifica::Sumar(double n1, double n2) {
    if (n2 <= 0) return 0;
    return n1 + Cientifica::Sumar(n1, n2 - 1); 
}

double Cientifica::PotenciaRecursiva(double base, int exp) {
    if (exp == 0) return 1;
    return Cientifica::Sumar(base, PotenciaRecursiva(base, exp - 1));
}
	
double Cientifica::DivisionRecursiva(double dividendo, double divisor) 
{
    if (divisor == 0) return 0;
    if (dividendo < divisor) return 0;
    return 1 + DivisionRecursiva(dividendo - divisor, divisor);
}

int Cientifica::Factorial(int n) 
{
    if (n <= 1) return 1;
    return n * Factorial(n - 1);
}

int Cientifica::Fibonacci(int n) 
{
    if (n <= 1) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
