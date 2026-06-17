#include "EstructurasDatos.h"
#include <iostream>
using namespace std;

//logica de la pila
Pila::Pila() { tope = -1; }
Pila::~Pila() {}

void Pila::push(int valor) 
{
    if (estaLlena()) 
	{
        cout << "Error: Pila llena (Overflow)" << endl;
    } else {
        datos[++tope] = valor;
        cout << "Insertado: " << valor << endl;
    }
}

void Pila::pop() 
{
    if (estaVacia()) 
	{
        cout << "Error: Pila vacia (Underflow)" << endl;
    } else 
	{
        cout << "Eliminado: " << datos[tope--] << endl;
    }
}

// logica de la interfaz 
void Pila::agregar() 
{
    int valor;
    cout << "Ingresa el valor entero a agregar en la pila: ";
    cin >> valor;
    cout << valor <<"\n";
    push(valor);
}

void Pila::quitar() 
{
    pop();
}

void Pila::mostrar() 
{
    if (estaVacia()) 
	{
        cout << "La pila esta vacia." << endl;
    } else 
	{
        cout << "Contenido: ";
        for (int i = 0; i <= tope; i++) cout << datos[i] << " ";
        cout << " <- Tope" << endl;
    }
}

bool Pila::estaVacia() { return tope == -1; }
bool Pila::estaLlena() { return tope == MAX - 1; }
int Pila::tamano() { return tope + 1; }
int Pila::getMaximo() { return MAX; }
string Pila::getNombre() { return "Pila (Stack)"; }

//logica de la cola 
ColaConcierto::ColaConcierto() { frente = -1; final = -1; }
ColaConcierto::~ColaConcierto() {}

void ColaConcierto::formarFan(int numeroBoleto) 
{
    if (estaLlena()) 
	{
        cout << "La cola esta llena. El boleto " << numeroBoleto << " no entra.\n";
        return;
    }
    if (frente == -1) frente = 0;
    boletos[++final] = numeroBoleto;
    cout << "Boleto #" << numeroBoleto << " formado en la cola.\n";
}

void ColaConcierto::dejarEntrar() 
{
    if (estaVacia()) 
	{
        cout << "La cola esta vacia.\n";
        return;
    }
    cout << "El boleto #" << boletos[frente] << " ha entrado.\n";
    if (frente >= final) { frente = -1; final = -1; } 
    else { frente++; }
}

//logica de la interfaz
void ColaConcierto::agregar() 
{
    int boleto;
    cout << "Ingresa el numero de boleto para la cola: ";
    cin >> boleto;
     cout << boleto <<"\n";
    formarFan(boleto);
}

void ColaConcierto::quitar() 
{
    dejarEntrar();
}

void ColaConcierto::mostrar() 
{
    if (estaVacia()) 
	{
	 	cout << "La cola esta completamente vacia.\n"; return; 
	}
    cout << "Estado de la cola: ";
    for (int i = frente; i <= final; i++) cout << "[" << boletos[i] << "] ";
    cout << "\n";
}

bool ColaConcierto::estaVacia() { return frente == -1; }
bool ColaConcierto::estaLlena() { return final == MAX - 1; }
int ColaConcierto::tamano() { return estaVacia() ? 0 : (final - frente) + 1; }
int ColaConcierto::getMaximo() { return MAX; }
string ColaConcierto::getNombre() { return "Cola (Queue)"; }

//logica de la lista
Lista::Lista() { cantidad = 0; }
Lista::~Lista() {}

void Lista::insertar(int valor) 
{
    if (estaLlena()) 
	{
	 	cout << "Lista llena.\n"; 
	}
    else { elementos[cantidad++] = valor; cout << "Valor " << valor << " insertado.\n"; }
}

void Lista::eliminar(int posicion) 
{
    if (posicion < 0 || posicion >= cantidad) 
	{ 
		cout << "Posicion invalida.\n"; return; 
	}
    for (int i = posicion; i < cantidad - 1; i++) elementos[i] = elementos[i + 1];
    cantidad--;
    cout << "Elemento en la posicion " << posicion << " eliminado.\n";
}

//logica de la interfaz
void Lista::agregar() 
{
    int valor;
    cout << "Ingresa el valor entero a agregar en la lista: ";
    cin >> valor;
    cout << valor <<"\n";
    insertar(valor);
}

void Lista::quitar() 
{
    if (estaVacia()) 
	{
        cout << "No se puede quitar, la lista ya esta vacia." << endl;
    } else 
	{
        int posicion;
        cout << "Ingresa la posicion del elemento a quitar (0 a " << (cantidad - 1) << "): ";
        cin >> posicion;
         cout << posicion <<"\n";
        eliminar(posicion);
    }
}

void Lista::mostrar() 
{
    if (estaVacia()) 
	{
	 	cout << "La lista esta vacia.\n"; return; 
	}
    cout << "Elementos: ";
    for (int i = 0; i < cantidad; i++) cout << "[" << elementos[i] << "] ";
    cout << "\n";
}

bool Lista::estaVacia() { return cantidad == 0; }
bool Lista::estaLlena() { return cantidad == MAXIMO; }
int Lista::tamano() { return cantidad; }
int Lista::getMaximo() { return MAXIMO; }
string Lista::getNombre() { return "Lista"; }
