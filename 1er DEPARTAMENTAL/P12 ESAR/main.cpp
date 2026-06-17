#include <iostream>
#include <string>
#include "mane_archivos.h"
using namespace std;

struct Auto 
{
    double precio;
    int anio;
};

struct Persona 
{
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
	Auto vehiculo;
	
	void mostrarInformacion() 
		{
        	cout << "Nombre: " << nombre << endl << "Apellido Paterno: " << ap <<endl << "Apellido Materno: " << am << endl;
        	cout << "Genero: " << genero << endl << "Edad: " << edad << endl;
        	cout << "Precio del auto: $" << vehiculo.precio << endl << "Modelo: " << vehiculo.anio << endl;
        	cout << "____________________________" << endl;
		}
};

int main() 
{
	OutputCapture cap;
	
	Persona lista[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "---------Datos Persona---------" << endl; 
       	cout << "Nombre: "; cin >> lista[i].nombre;
       	cout << "Ap. Paterno: "; cin >> lista[i].ap;
       	cout << "Ap. Materno: "; cin >> lista[i].am;
       	cout << "Edad: "; cin >> lista[i].edad;        	
		cout << "Genero: "; cin >> lista[i].genero;
		cout << ">>>>>>>>>Datos de su auto<<<<<<<" << endl;
		cout << "Precio: "; cin >> lista[i].vehiculo.precio;
		cout << "Anio: "; cin >> lista[i].vehiculo.anio;
		
	}
	cout << "---------Registros-----------" << endl;
	for (int i = 0; i < 5; i++)
	{
		lista[i].mostrarInformacion();
	}

	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("P12. Nuevo tpd", cap.get());
    return 0;
}

