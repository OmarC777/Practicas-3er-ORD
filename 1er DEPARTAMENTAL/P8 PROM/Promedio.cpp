#include "Promedio.h"
#include <iostream>
using namespace std;
Promedio::Promedio()
{
}

Promedio::~Promedio()
{
}

void Promedio::Operaciones()
{
	double suma = 0, numeros, maximo, minimo, prom;
	for (int i = 1; i <= 5; i++)
	{
		cout << "Ingresa valor No. " << i << " para hacer el calculo" << endl;
		cin >> numeros;
		cout << numeros <<"\n";
		
		suma += numeros; 
		
		prom = suma / i;
		
		if( i == 1)
		{
			maximo = numeros;
			minimo = numeros;	
		}
		else 
		{
			if (numeros > maximo)				
			{
				maximo = numeros;
			}
			if (numeros < minimo)
			{
				minimo = numeros;
			}
		}	
	}
	cout << "Este es el promedio de los valores: " << prom << endl;
	cout << "Este es el resultado de la suma de los valores: " << suma << endl;
	cout << "Este es el maximo de los valores: " << maximo << endl;
	cout << "Este es el minimo de los valores: " << minimo << endl;
	
}
