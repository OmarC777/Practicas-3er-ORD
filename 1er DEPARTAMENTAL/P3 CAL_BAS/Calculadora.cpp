#include "Calculadora.h"
#include <iostream>
using namespace std;
Calculadora::Calculadora()
{
}

Calculadora::~Calculadora()
{
}

void Calculadora :: Suma()
{
	double s1, s2, resS;
	cout <<"Introduzca el primero numero de su operacion: " <<endl;
	cin >> s1;
	cout << s1 << "\n"; 
	cout <<"Introduzca el segundo numero de su operacion: " <<endl;
	cin >> s2;
	cout << s2 << "\n"; 
	resS = s1 + s2;
	cout <<"El resultado de su operacion es: " << resS;
}

void Calculadora :: Resta()
{
	double r1, r2, resR;
	cout <<"Introduzca el primero numero de su operacion: " <<endl;
	cin >> r1;
	cout << r1 << "\n"; 
	cout <<"Introduzca el segundo numero de su operacion: " <<endl;
	cin >> r2;
	cout << r2 << "\n"; 
	resR = r1 - r2;
	cout <<"El resultado de su operacion es: " << resR;	
}

void Calculadora :: Multiplicacion()
{
	double m1, m2, resM;
	cout <<"Introduzca el primero numero de su operacion: " <<endl;
	cin >> m1;
	cout << m1 << "\n"; 
	cout <<"Introduzca el segundo numero de su operacion: " <<endl;
	cin >> m2;
	cout << m2 << "\n"; 
	resM = m1 * m2;
	cout <<"El resultado de su operacion es: " << resM;	
}

void Calculadora :: Division()
{
	double d1, d2, resD;
	cout <<"Introduzca el primero numero de su operacion: " <<endl;
	cin >> d1;
	cout << d1 << "\n"; 
	cout <<"Introduzca el segundo numero de su operacion: " <<endl;
	cin >> d2;
	cout << d2 << "\n"; 
	resD = d1 / d2;
	cout <<"El resultado de su operacion es: " << resD;	
}

void Calculadora :: Operaciones ()
{
	Calculadora op;
	int selec;
	cout <<"Selecciones la operacion que guste: " <<endl <<"1 -> Suma; 2 -> Resta; 3 -> Multiplicacion; 4 -> Division"<<endl;
	cin >> selec;
	cout << selec << "\n";
	switch (selec)
	{
		case 1: op.Suma();
		break;
		case 2: op.Resta();
		break;
		case 3: op.Multiplicacion();
		break;
		case 4: op.Division();
		break;
		default: cout << "Error";
	}
}



