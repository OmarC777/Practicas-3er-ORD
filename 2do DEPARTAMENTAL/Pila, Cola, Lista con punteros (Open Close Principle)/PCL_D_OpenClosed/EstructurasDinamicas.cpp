#include "EstructurasDinamicas.h"
#include <iostream>
using namespace std;

//logica de la pila
Pila::Pila() 
{ 
	tope = nullptr; 
}
Pila::~Pila() 
{
    int temp;
    while (!estaVacia()) { desapilar(temp); }
}

void Pila::apilar(int valor) 
{
    Nodo* nuNodo = new Nodo();
    nuNodo->dato = valor;
    nuNodo->sig = tope;
    tope = nuNodo;
    cout << "El valor: " << valor << " se agrego a la pila\n";
}

bool Pila::desapilar(int& valor) 
{
    if (estaVacia()) return false;
    Nodo* ex = tope;
    valor = ex->dato;
    tope = ex->sig;
    delete ex;
    return true;
}

//interfaz de la pila
void Pila::agregar() 
{
    int valor;
    cout << "Ingresa el valor entero a agregar: ";
    cin >> valor;
    cout << valor << "\n";
    apilar(valor);
}

void Pila::quitar() 
{
    int valor;
    if (desapilar(valor)) cout << "El valor: " << valor << " a sido extraido de la pila\n";
    else cout << "La pila esta vacia\n";
}

void Pila::mostrar() 
{
    if (estaVacia()) 
	{ 
		cout << "La pila esta vacia.\n"; return; 
	}
    cout << "Tope -> ";
    Nodo* actual = tope;
    while (actual != nullptr) 
	{
        cout << "[" << actual->dato << "] ";
        actual = actual->sig;
        if (actual != nullptr) cout << "-> ";
    }
    cout << "\n";
}

bool Pila::estaVacia() { return tope == nullptr; }
bool Pila::estaLlena() { return false; }
int Pila::tamano() 
{
    int contador = 0;
    Nodo* actual = tope;
    while (actual != nullptr) { contador++; actual = actual->sig; }
    return contador;
}
string Pila::getNombre() { return "Pila Dinamica"; }

//logica de la cola
Cola::Cola() { prim = nullptr; fin = nullptr; }
Cola::~Cola() {
    int temp;
    while (!estaVacia()) { retirar(temp); }
}

void Cola::insertar(int valor) 
{
    Nodo* NuNodo = new Nodo();
    NuNodo->dato = valor;
    NuNodo->sig = nullptr;
    if (estaVacia()) prim = NuNodo;
    else fin->sig = NuNodo;
    fin = NuNodo;
    cout << "Se inserto el numero: " << valor << "\n";
}

void Cola::retirar(int& valorRec) 
{
    if (estaVacia()) return;
    valorRec = prim->dato;
    Nodo* nEliminar = prim;
    if (prim == fin) { prim = nullptr; fin = nullptr; }
    else { prim = prim->sig; }
    delete nEliminar;
}

// interfaz de la cola
void Cola::agregar() {
    int valor;
    cout << "Ingresa el valor entero a agregar: ";
    cin >> valor;
    cout << valor << "\n";
    insertar(valor);
}

void Cola::quitar() {
    int numElim = 0;
    if (!estaVacia()) {
        retirar(numElim);
        cout << "Se elimino el numero: " << numElim << "\n";
    } else {
        cout << "La cola esta vacia, no se puede eliminar nada\n";
    }
}

void Cola::mostrar() {
    if (estaVacia()) { cout << "La cola esta vacia. No hay elementos.\n"; return; }
    cout << "FRENTE -> ";
    Nodo* actual = prim;
    while (actual != nullptr) {
        cout << "[" << actual->dato << "] ";
        actual = actual->sig;
    }
    cout << "<- FINAL\n";
}

bool Cola::estaVacia() { return prim == nullptr; }
bool Cola::estaLlena() { return false; }
int Cola::tamano() {
    int contador = 0;
    Nodo* actual = prim;
    while (actual != nullptr) { contador++; actual = actual->sig; }
    return contador;
}
string Cola::getNombre() { return "Cola Dinamica"; }

//logica de la lista
Lista::Lista() { cabeza = nullptr; }
Lista::~Lista() {
    while (!estaVacia())
	{
        Nodo* ex = cabeza;
        cabeza = cabeza->sig;
        delete ex;
    }
}

void Lista::insertarFin(int n) {
    Nodo* NuNodo = new Nodo();
    NuNodo->dato = n;
    NuNodo->sig = nullptr;
    if (cabeza == nullptr) cabeza = NuNodo;
    else {
        Nodo* actual = cabeza;
        while (actual->sig != nullptr) actual = actual->sig;
        actual->sig = NuNodo;
    }
}

bool Lista::eliminarEspecifico(int n) {
    if (cabeza == nullptr) return false;
    if (cabeza->dato == n) {
        Nodo* ex = cabeza;
        cabeza = cabeza->sig;
        delete ex;
        return true;
    }
    Nodo* actual = cabeza;
    while (actual->sig != nullptr && actual->sig->dato != n) {
        actual = actual->sig;
    }
    if (actual->sig != nullptr) {
        Nodo* ex = actual->sig;
        actual->sig = ex->sig;
        delete ex;
        return true;
    }
    return false;
}

//interfaz de la lista
void Lista::agregar() {
    int valor;
    cout << "Ingresa el valor entero a agregar al final: ";
    cin >> valor;
    cout << valor << "\n";
    insertarFin(valor);
    cout << "-> Se inserto el numero: " << valor << " al final.\n";
}

void Lista::quitar() {
    int valor;
    cout << "Ingresa el valor entero a quitar: ";
    cin >> valor;
    cout << valor << "\n";
    if (eliminarEspecifico(valor)) {
        cout << "-> Se quito el numero: " << valor << " de la lista.\n";
    } else {
        cout << "-> El numero " << valor << " no se encontro en la lista o esta vacia.\n";
    }
}

void Lista::mostrar() {
    if (cabeza == nullptr) { cout << "La lista esta vacia.\n"; return; }
    cout << "INICIO -> ";
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "[" << actual->dato << "] ";
        actual = actual->sig;
        if (actual != nullptr) cout << "-> ";
    }
    cout << "\n";
}

bool Lista::estaVacia() { return cabeza == nullptr; }
bool Lista::estaLlena() { return false; }
int Lista::tamano() {
    int contador = 0;
    Nodo* actual = cabeza;
    while (actual != nullptr) { contador++; actual = actual->sig; }
    return contador;
}
string Lista::getNombre() { return "Lista Dinamica"; }
