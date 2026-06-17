#ifndef CIENTIFICA_H
#define CIENTIFICA_H
class Calculadora
{
	public:
		 Sumar();
		 double Sumar(double n1, double n2);
		 double Sumar(double num1, double num2, double num3);//
		Calculadora();
		~Calculadora();
	protected:
};



class Cientifica : public Calculadora
{
	public:
		double Sumar(double n1, double n2);
		double Potencia(double base, double exponente);
		double MultiplicacionSucesiva(double base, double exp);
   	 	double DivisionSucesiva(double dividendo, double divisor);
		Cientifica();
		~Cientifica();
	protected:
};
#endif

