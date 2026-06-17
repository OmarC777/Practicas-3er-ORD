#ifndef ESTRUCTURASDATOS_H
#define ESTRUCTURASDATOS_H
#include <iostream>
#include <string>
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

//logica de agencia (pila)
class Vehiculo {
	public:
	    string marca;
	    int modelo;
	    Vehiculo();
	    Vehiculo(string m, int a);
};

class PilaAgencia : public EstructurasDatos 
{
	private:
	    static const int MAX = 5;
	    Vehiculo datos[MAX]; 
	    int tope;
	public:
	    PilaAgencia();
	    void push(Vehiculo objeto);
	    void pop();
	    
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};

//logica de cine (cola)
class Cine 
{
	private:
	    string cliente;
	    string combo;
	    float precio;
	public:	
	    Cine();
	    Cine(string cl, string cb, float p);
	    string getCliente() { return cliente; }
	    string getCombo() { return combo; }
	    float getPrecio() { return precio; }
};

class ColaCineEstructura : public EstructurasDatos {
	private:
	    static const int MAX = 5;
	    Cine cola[MAX];
	    int inicio, final;
	public:
	    ColaCineEstructura();
	    void nuevoCliente(Cine p); 
	    void atenderCliente();  
	
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};

//logica de clientes (lista)
class Cliente 
{
	private:
	    string nombre;
	    int numeroSocio;
	public:
	    Cliente();
	    Cliente(string nom, int num);
	    string getNombre();
	    int getNumeroSocio();
};

class ListaClientes : public EstructurasDatos {
	private:
	    static const int MAX = 5; 
	    Cliente clientes[MAX];
	    int cantidad;            
	public:
	    ListaClientes(); 
	    void insertar(Cliente valor);
	    void eliminar(int numSocio);
	
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};
#endif
