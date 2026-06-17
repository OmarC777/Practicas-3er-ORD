#ifndef ESTRUCTURASCONLIBRERIAS_H
#define ESTRUCTURASCONLIBRERIAS_H
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <list>
using namespace std;

class EstructurasDatos
{
	public:
		virtual ~EstructurasDatos() {}
	    virtual void agregar() = 0;
	    virtual void quitar() = 0;
	    virtual void mostrar() = 0;
	    virtual bool estaVacia() = 0;
	    virtual bool estaLlena() = 0;
	    virtual int tamano() = 0;
	    virtual string getNombre() = 0;
};

//clase navegador (pila)
class Navegador : public EstructurasDatos 
{
public:
	stack<string> pilaHistorial;
    Navegador();
    ~Navegador();
    void Pagina(const string &dir);
    void Anterior();
    
    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

//clase turnos (cola)
class Turnos : public EstructurasDatos 
{
	public:
		queue<string> filaC;
	    Turnos();
	    ~Turnos();
	    void registrarC(const string &nombre);
	    void atenderSig();
	
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};

//clses de inventario y producto (lista)
class Producto 
{
	public:
	    string codigo;
	    string nombre;
	    int cantidad;
	    Producto(string _codigo, string _nombre, int _cantidad);
	    ~Producto();
	    void mostrarDet() const;
};

class Inventario : public EstructurasDatos 
{
private:
    list<Producto> obInv;
public:
    Inventario();
    ~Inventario();

    //interfaz
    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

#endif
