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
	
	void mostrarInformacion() {
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
	Persona *pun = lista;
	for (int i = 0; i < 5; i++)
	{
		cout << "---------Datos Persona---------" << endl; 
       	cout << "Nombre: "; cin >> lista[i].nombre; cout << lista[i].nombre <<"\n";
       	cout << "Ap. Paterno: "; cin >> lista[i].ap; cout << lista[i].ap <<"\n";
       	cout << "Ap. Materno: "; cin >> lista[i].am; cout << lista[i].am <<"\n";
       	cout << "Edad: "; cin >> lista[i].edad; cout << lista[i].edad <<"\n";	
		cout << "Genero: "; cin >> lista[i].genero; cout << lista[i].genero<<"\n";
		cout << ">>>>>>>>>Datos de su auto<<<<<<<" << endl; 
		cout << "Precio: "; cin >> lista[i].vehiculo.precio; cout << lista[i].vehiculo.precio<<"\n";
		cout << "Anio: "; cin >> lista[i].vehiculo.anio; cout << lista[i].vehiculo.anio <<"\n";
		
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

	writeAllOutputs("P13. NTPD puntero", cap.get());
    return 0;
}
