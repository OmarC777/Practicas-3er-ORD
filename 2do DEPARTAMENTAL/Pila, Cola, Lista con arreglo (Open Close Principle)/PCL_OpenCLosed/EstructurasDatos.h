#ifndef ESTRUCTURASDATOS_H
#define ESTRUCTURASDATOS_H
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
    virtual int getMaximo() = 0;
    virtual string getNombre() = 0;
};
class Pila : public EstructurasDatos
{
	public:
		static const int MAX = 5;
	    int datos[MAX];
	    int tope;
	    Pila();
	    ~Pila();
	    
	    void push(int valor);
	    void pop();
	    
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    int getMaximo() override;
	    string getNombre() override;
};
class ColaConcierto : public EstructurasDatos
{
	public:
		static const int MAX = 5;
	    int boletos[MAX];
	    int frente;
	    int final;
	    ColaConcierto();
    	~ColaConcierto();
    
	    void formarFan(int numeroBoleto);
	    void dejarEntrar();
	    
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    int getMaximo() override;
	    string getNombre() override;	
};
class Lista : public EstructurasDatos
{
	public:
		static const int MAXIMO = 10;
    	int elementos[MAXIMO];
    	int cantidad;
		Lista();
    	~Lista();
    
	    void insertar(int valor);
	    void eliminar(int posicion);
	    
	    void agregar() override;
	    void quitar() override;
	    void mostrar() override;
	    bool estaVacia() override;
	    bool estaLlena() override;
	    int tamano() override;
	    int getMaximo() override;
	    string getNombre() override;
};
#endif
