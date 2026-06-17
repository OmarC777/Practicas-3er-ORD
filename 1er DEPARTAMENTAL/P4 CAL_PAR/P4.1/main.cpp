#include <iostream>
#include "Calculadora.h"
#include "mane_archivos.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	OutputCapture cap;
	Calculadora obpar;
	cout << obpar.Sumar(5, 62) <<endl;
	cout << obpar.Sumar(37, 54, 11) <<endl;
	obpar.Sumar();
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("P4.Calculadora Parametros", cap.get());
	return 0;
}

