#include "Cientifica.h"
#include <iostream>
#include "mane_archivos.h"

using namespace std;
int main() 
{
	OutputCapture cap;
	Calculadora obpar;
	cout << obpar.Sumar(5, 62) <<endl;
	cout << obpar.Sumar(37, 54, 11) <<endl;
	obpar.Sumar();

    Cientifica obCien;

    //cout << "Suma heredada: " << obCien.Sumar(10, 20) << endl;
    //cout << "Resultado Potencia: " << obCien.Potencia(2, 3) << endl;
    //cout << "Suma Normal: " << obpar.Sumar(5, 4) << endl;
    //cout << "Multiplicacion (Suma Sucesiva): " << obCien.Sumar(5, 4) << endl;


    cout << "\n\nFactorial de 5: " << obCien.Factorial(5) << endl;
    cout << "Fibonacci (posicion 6): " << obCien.Fibonacci(6) << endl; 
    cout << "Multiplicacion Rec (5x3): " << obCien.Sumar(5, 3) << endl;
    cout << "Potencia Rec (2^4): " << obCien.PotenciaRecursiva(2, 4) << endl;
    cout << "Division Rec (20/5): " << obCien.DivisionRecursiva(20, 5) << endl;
    
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("P14.Recursividad", cap.get());
    return 0;
}

