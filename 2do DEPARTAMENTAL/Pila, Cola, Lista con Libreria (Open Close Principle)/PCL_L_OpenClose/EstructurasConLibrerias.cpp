#include "EstructurasConLibrerias.h"

Navegador::Navegador() {}
Navegador::~Navegador() {}

//logica de navegador (pila)
void Navegador::Pagina(const string &dir) {
    pilaHistorial.push(dir);
    cout << "Visitando: " << dir << endl; 
}
void Navegador::Anterior() {
    if(pilaHistorial.empty()) cout << "El historial esta vacio no hay pagina anterior" << endl;
    else {
        cout << "Saliendo de: " << pilaHistorial.top() << endl;
        pilaHistorial.pop();
        if(!pilaHistorial.empty()) cout << "Ahora estas en: " << pilaHistorial.top() << endl;
        else cout << "Estas en una pestania en blanco" << endl;
    }
}
void Navegador::agregar() {
    string url;
    cout << "Ingresa la URL a visitar (ej. www.google.com): ";
    cin >> url; 
    cout << url <<"\n";
    Pagina(url);
}
void Navegador::quitar() { Anterior(); }
void Navegador::mostrar() {
    if (pilaHistorial.empty()) cout << "El historial del navegador esta vacio." << endl;
    else {
        cout << "ACTUAL -> ";
        stack<string> copiaHistorial = pilaHistorial; 
        while (!copiaHistorial.empty()) {
            cout << "[" << copiaHistorial.top() << "] ";
            copiaHistorial.pop();
            if (!copiaHistorial.empty()) cout << "-> ";
        }
        cout << "\n";
    }
}
bool Navegador::estaVacia() { return pilaHistorial.empty(); }
bool Navegador::estaLlena() { return false; }
int Navegador::tamano() { return pilaHistorial.size(); }
string Navegador::getNombre() { return "Navegador Web (Pila)"; }

//logica de turnos (cola)
Turnos::Turnos() {}
Turnos::~Turnos() {}

void Turnos::registrarC(const string &nombre) {
    filaC.push(nombre);
    cout << "El cliente se a registrado: " << nombre << endl;
}
void Turnos::atenderSig() {
    if(filaC.empty()) cout << "No hay clientes en la fila" << endl;
    else { cout << "Atendiendo a: " << filaC.front() << endl; filaC.pop(); }
}
void Turnos::agregar() {
    string nombreCliente;
    cout << "Ingresa el nombre del cliente: ";
    cin.ignore();
    cout << nombreCliente <<"\n";
    getline(cin, nombreCliente); 
    registrarC(nombreCliente);

}
void Turnos::quitar() { atenderSig(); }
void Turnos::mostrar() {
    if (filaC.empty()) cout << "La fila esta vacia. No hay clientes esperando." << endl;
    else {
        cout << "FRENTE -> ";
        queue<string> copiaFila = filaC; 
        while (!copiaFila.empty()) {
            cout << "[" << copiaFila.front() << "] ";
            copiaFila.pop();
        }
        cout << "<- FINAL\n";
    }
}
bool Turnos::estaVacia() { return filaC.empty(); }
bool Turnos::estaLlena() { return false; }
int Turnos::tamano() { return filaC.size(); }
string Turnos::getNombre() { return "Sistema de Turnos (Cola)"; }

//logica de inventario (lista)
Producto::Producto(string _codigo, string _nombre, int _cantidad) {
    codigo = _codigo; nombre = _nombre; cantidad = _cantidad;
}
Producto::~Producto() {}
void Producto::mostrarDet() const {
    cout << "Codigo: " << codigo << " | Producto: " << nombre << " | Cantidad disponible: " << cantidad << " unidades" << endl;
}

Inventario::Inventario() {}
Inventario::~Inventario() {}

void Inventario::agregar() {
    string codigoTemp, nombreTemp; int cantidadTemp;
    cout << "Ingresa el codigo: "; cin >> codigoTemp;
     	cout << codigoTemp <<"\n";
    cout << "Ingresa el nombre: "; cin.ignore(); getline(cin, nombreTemp);
    	cout << nombreTemp <<"\n";
    cout << "Ingresa la cantidad: "; cin >> cantidadTemp;
    	cout << cantidadTemp <<"\n";
    obInv.push_back(Producto(codigoTemp, nombreTemp, cantidadTemp));
    cout << "-> Elemento agregado con exito." << endl;
}
void Inventario::quitar() {
    if (!obInv.empty()) {
        cout << "-> Se quito el elemento: " << obInv.back().nombre << endl;
        obInv.pop_back();
    } else cout << "-> No se puede quitar, el inventario ya esta vacio." << endl;
}
void Inventario::mostrar() {
    if(obInv.empty()) cout << "El inventario esta vacio." << endl;
    else {
        for(list<Producto>::iterator it = obInv.begin(); it != obInv.end(); ++it) {
            it->mostrarDet();
        }
    }
}
bool Inventario::estaVacia() { return obInv.empty(); }
bool Inventario::estaLlena() { return false; }
int Inventario::tamano() { return obInv.size(); }
string Inventario::getNombre() { return "Inventario de Productos (Lista)"; }
