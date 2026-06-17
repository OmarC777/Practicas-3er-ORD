#ifndef ESTRUCTURASDINAMICAS_H
#define ESTRUCTURASDINAMICAS_H
#include <string>
#include <iostream>
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
class Pila : public EstructurasDatos 
{
	private:
	    struct Nodo {
	        int dato;
	        Nodo* sig;
	    };
	    Nodo* tope;
	
	public:
	    Pila();
	    ~Pila();
	    void apilar(int valor);
	    bool desapilar(int& valor);
	
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};

class Cola : public EstructurasDatos 
{
	private:
	    struct Nodo {
	        int dato;
	        Nodo* sig;
	    };
	    Nodo* prim;
	    Nodo* fin;
	
	public:
	    Cola();
	    ~Cola();
	    void insertar(int valor);
	    void retirar(int& valorRec);
	
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};

class Lista : public EstructurasDatos 
{
	private:
	    struct Nodo {
	        int dato;
	        Nodo* sig;
	    };
	    Nodo* cabeza;
	
	public:
	    Lista();
	    ~Lista();
	    void insertarFin(int n); 
	    bool eliminarEspecifico(int n);
	
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    string getNombre() override;
};
#endif
