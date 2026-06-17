#include <iostream>
#include <string>
#include "mane_archivos.h"
using namespace std;

struct Auto 
{
    double precio;
    int anio;

    void mostrarInformacion() {
        cout << "Auto - Precio: $" << precio << " | Modelo: " << anio << endl;
    }
};

struct Persona {
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

    void capturar() {
        cout << "Nombre: "; cin >> nombre;
        cout << "Ap. Paterno: "; cin >> ap;
        cout << "Ap. Materno: "; cin >> am;
        cout << "Edad: "; cin >> edad;
        cout << "Genero: "; cin >> genero;
    }

    void saludar() {
    	cout << endl;
        cout << "Mi Nombre es: " << nombre << " " << ap << " "<< am << endl << "Tengo: " << edad << " años." << endl;
		cout << "Me identifico como: " << genero;
	}
};

int main() 
{
	OutputCapture cap;
    Persona p1;
    
    p1.capturar();
    p1.saludar();
    
    system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");
	
	writeAllOutputs("P7.Creacion de dato", cap.get());
    return 0;
}

