#include <iostream>
#include "mane_archivos.h"
#include "fractales.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	OutputCapture cap;
	fractales fract;
    Cantor cantor1;
    int n, d;
	
	cout << "Ingresa Nivel (Serpinski): ";
    cin >> n;
    cout << "Triangulos en nivel " << n << ": " << fract.nElemsLvl(n) << endl;

    cout << "\nIngresa Nivel (Cantor): ";
    cin >> n;
    cout << n << "\n";
    cout << "Ingresa Dimension (Cantor): ";
    cin >> d;
    cout << d << "\n";
    cout << "Elementos en nivel " << n << ", dimension " << d << ": "
         << cantor1.nElemsLvl(n, d) << endl;
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("P15.Triangulo Sierpinski", cap.get());
	return 0;
}


 


