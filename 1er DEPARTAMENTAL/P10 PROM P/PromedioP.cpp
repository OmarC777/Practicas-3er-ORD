#include "PromedioP.h"
#include <iostream>
using namespace std;
PromedioP::PromedioP()
{
}

PromedioP::~PromedioP()
{
}

void PromedioP::OperacionesP()
{
	double suma = 0, numeros[5], maximo = 0, minimo = 0, prom = 0, *pun = numeros;
	for (int i = 0; i <= 4; i++)
	{
		cout << "Ingresa valor No. " << i << " para hacer el calculo" << endl;
		cin >> numeros[i];
		cout << numeros[i] << "\n";
	}
		suma = 0; 
		maximo = numeros[0];
		minimo = numeros[0];
		for (int i = 0; i <=4; i++)
		{
			suma = suma + numeros[i];
			if (numeros[i] > maximo)				
			{
				maximo = numeros[i];
			}
			if (numeros[i] < minimo)
			{
				minimo = numeros[i];
			}	
		}
		prom = suma / 5;
	cout << "Este es el promedio de los valores: " << prom << endl;
	cout << "Este es el resultado de la suma de los valores: " << suma << endl;
	cout << "Este es el maximo de los valores: " << maximo << endl;
	cout << "Este es el minimo de los valores: " << minimo << endl;
	cout << "La direccion de memoria del arreglo es: " << pun;
	
}

