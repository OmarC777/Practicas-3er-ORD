#include <iostream>
#include "Alumno.h"
#include "mane_archivos.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct
{
	char x[90], b[10];
	double c;
}AlumnoS;

int main(int argc, char** argv) 
{
	OutputCapture cap;
	cout << "tamaño de un enetero " <<sizeof(argc) <<endl <<endl <<endl;
	Alumno a = Alumno();
	cout << "tamaño de un entero -->" <<sizeof(a) <<endl <<endl <<endl;
	cout << "tamaño de un entero --> " <<sizeof(AlumnoS) <<endl <<endl <<endl;
	cout << "tamaño de un double --> "  <<sizeof(double) <<endl <<endl <<endl;
	cout << "tamaño de un char --> "  <<sizeof(char) <<endl <<endl <<endl;
	cout << "tamaño de un float --> "  <<sizeof(float) <<endl <<endl <<endl;
	cout << "tamaño de un bool --> "  <<sizeof(bool) <<endl <<endl <<endl;
	a.msg();
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");
	
	writeAllOutputs("P7BIS.Tamanos", cap.get());	
	return 0;
}


