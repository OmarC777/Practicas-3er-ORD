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

    obCien.Sumar();
    
    cout << "Suma heredada: " << obCien.Sumar(10, 20) << endl;

    cout << "Resultado Potencia: " << obCien.Potencia(2, 3) << endl;
    
    system("start out.txt");
    system("start out.json");
    system("start out.xml");
    system("start out.csv");
    
	writeAllOutputs("P5.Herencia", cap.get());
    return 0;
}


