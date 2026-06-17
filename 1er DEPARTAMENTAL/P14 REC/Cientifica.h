#ifndef CIENTIFICA_H
#define CIENTIFICA_H
class Calculadora
{
	public:
		 void Sumar();
		 double Sumar(double n1, double n2);
		 double Sumar(double num1, double num2, double num3);//
		Calculadora();
		~Calculadora();
	protected:
};



class Cientifica : public Calculadora {
public:
	double Potencia(double base, double exponente);
    Cientifica();
    ~Cientifica();
    double Sumar(double n1, double n2); 
    int Factorial(int n);
    int Fibonacci(int n);
    double PotenciaRecursiva(double base, int exp);
    double DivisionRecursiva(double dividendo, double divisor);
};
#endif

