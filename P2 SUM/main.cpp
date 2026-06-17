#include <iostream>
#include "Operacion.h"
#include "mane_archivos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	OutputCapture cap;	
	Operacion obS;
	
	int num1 = 5;
	int num2 = 3;
	int res = obS.Suma(num1, num2);
	cout << "La suma de "<<num1<< " mas "<<num2<<" es: "<<res;
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");
	
	writeAllOutputs("P2.Suma de 2 numeros", cap.get());
	return 0;
}
