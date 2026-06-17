#include "EstructurasDatos.h"
#include <iostream>
using namespace std;

//logica de agencia (pila)
Vehiculo::Vehiculo() {}
Vehiculo::Vehiculo(string m, int a) : marca(m), modelo(a) {}

PilaAgencia::PilaAgencia() { tope = -1; }
void PilaAgencia::push(Vehiculo objeto) {
    if (estaLlena()) cout << "Pila llena" << endl;
    else datos[++tope] = objeto;
}
void PilaAgencia::pop() {
    if (estaVacia()) cout << "Error: La pila esta vacia, no se puede quitar el vehiculo." << endl;
    else { cout << "Vehiculo retirado: " << datos[tope].marca << endl; tope--; }
}
void PilaAgencia::agregar() {
    string marca; int modelo;
    cout << "Ingrese la marca: "; cin >> ws; getline(cin, marca);
    cout << marca << "\n";
    cout << "Ingrese el modelo (anio): "; cin >> modelo;
    cout << modelo << "\n";
    push(Vehiculo(marca, modelo));
}
void PilaAgencia::quitar() { pop(); }
void PilaAgencia::mostrar() {
    if (estaVacia()) cout << "Pila vacia" << endl;
    else {
        for (int i = tope; i >= 0; i--) {
            cout << " -Marca: " << datos[i].marca << "\n -Modelo: " << datos[i].modelo << "\n\n";
        }
    }
}
bool PilaAgencia::estaVacia() { return tope == -1; }
bool PilaAgencia::estaLlena() { return tope == MAX - 1; }
int PilaAgencia::tamano() { return tope + 1; }
string PilaAgencia::getNombre() { return "Agencia de Vehiculos (Pila)"; }

//logia de cine (cola)
Cine::Cine() : cliente(""), combo(""), precio(0) {}
Cine::Cine(string cl, string cb, float p) : cliente(cl), combo(cb), precio(p) {}

ColaCineEstructura::ColaCineEstructura() { inicio = -1; final = -1; }
void ColaCineEstructura::nuevoCliente(Cine p) {
    if (estaLlena()) { cout << "Fila llena! " << p.getCliente() << " debe esperar afuera\n"; return; }
    if (inicio == -1) inicio = 0;
    cola[++final] = p;
    cout << ">> " << p.getCliente() << " se ha formado para comprar \n";
}
void ColaCineEstructura::atenderCliente() {
    if (estaVacia()) { cout << "No hay clientes en la fila de dulceria\n"; return; }
    cout << "Cliente: " << cola[inicio].getCliente() << "\nEntregando: " << cola[inicio].getCombo() << "\nCobro: $" << cola[inicio].getPrecio() << "\n-----------------------------------\n";
    if (inicio >= final) inicio = final = -1;
    else inicio++;
}
void ColaCineEstructura::agregar() {
    if (estaLlena()) { cout << "¡No puedes agregar mas! La cola esta LLENA.\n"; return; }
    string nombreCliente, nombreCombo; float costoTotal;
    cout << "Ingresa el nombre del cliente: "; cin >> ws; getline(cin, nombreCliente);
    cout << nombreCliente << "\n";
    cout << "Ingresa el combo que comprara: "; getline(cin, nombreCombo);
    cout << nombreCombo << "\n";
    cout << "Ingresa el precio: $"; cin >> costoTotal;
    cout << costoTotal << "\n";
    nuevoCliente(Cine(nombreCliente, nombreCombo, costoTotal));
}
void ColaCineEstructura::quitar() { atenderCliente(); }
void ColaCineEstructura::mostrar() {
    if (estaVacia()) { cout << "La cola actual esta vacia.\n"; return; }
    cout << "\n--- ESTADO DE LA COLA ---\n";
    for (int i = inicio; i <= final; i++) {
        cout << (i - inicio + 1) << ". " << cola[i].getCliente() << " | " << cola[i].getCombo() << " | $" << cola[i].getPrecio() << "\n";
    }
    cout << "-------------------------\n";
}
bool ColaCineEstructura::estaVacia() { return inicio == -1; }
bool ColaCineEstructura::estaLlena() { return final == MAX - 1; }
int ColaCineEstructura::tamano() { return estaVacia() ? 0 : (final - inicio) + 1; }
string ColaCineEstructura::getNombre() { return "Fila de Cine Extream (Cola)"; }

//logica de clientes (lista)
Cliente::Cliente() : nombre(""), numeroSocio(0) {}
Cliente::Cliente(string nom, int num) : nombre(nom), numeroSocio(num) {}
string Cliente::getNombre() { return nombre; }
int Cliente::getNumeroSocio() { return numeroSocio; }


ListaClientes::ListaClientes() { cantidad = 0; }

void ListaClientes::insertar(Cliente valor) {
    if (estaLlena()) {
        cout << "Error: La lista esta llena. No caben mas clientes.\n";
    } else {
        clientes[cantidad++] = valor;
        cout << "Cliente '" << valor.getNombre() << "' agregado a la lista con exito.\n";
    }
}

void ListaClientes::eliminar(int numSocio) {
    if (estaVacia()) { 
        cout << "La lista esta vacia. No hay clientes para quitar.\n"; 
        return; 
    }
    
    int pos = -1;
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i].getNumeroSocio() == numSocio) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        cout << "El socio numero '" << numSocio << "' no se encontro en la lista.\n";
        return;
    }
    
    string nombreEliminado = clientes[pos].getNombre();
    
    for (int i = pos; i < cantidad - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    cantidad--;
    cout << "Cliente '" << nombreEliminado << "' quitado de la lista.\n";
}

void ListaClientes::agregar() 
{
    if (estaLlena()) 
	{
        cout << "¡La lista esta llena! (Limite: " << MAX << ")\n";
        return;
    }
    string nombreCliente;
    int numSocio;
    
    cout << "Ingresa el nombre del cliente: "; 
    cin >> ws; getline(cin, nombreCliente);
    cout << nombreCliente << "\n";
    cout << "Ingresa el numero de socio asignado: "; 
    cin >> numSocio;
    cout << numSocio << "\n";
    
    insertar(Cliente(nombreCliente, numSocio));
}

void ListaClientes::quitar() {
    if (estaVacia()) {
        cout << "La lista ya esta vacia.\n";
        return;
    }
    int numSocio;
    cout << "Ingresa el numero de socio exacto a quitar: "; 
    cin >> numSocio;
    cout << numSocio << "\n";
    
    eliminar(numSocio);
}

void ListaClientes::mostrar() {
    if (estaVacia()) { cout << "La lista esta vacia.\n"; return; }
    
    cout << "Estado actual (" << cantidad << "/" << MAX << " espacios ocupados):\n";
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << clientes[i].getNombre() 
             << " | Socio #: " << clientes[i].getNumeroSocio() << "\n";
    }
    cout << "-------------------------\n";
}

bool ListaClientes::estaVacia() { return cantidad == 0; }
bool ListaClientes::estaLlena() { return cantidad == MAX; }
int ListaClientes::tamano() { return cantidad; }
string ListaClientes::getNombre() { return "Registro de Clientes"; }
