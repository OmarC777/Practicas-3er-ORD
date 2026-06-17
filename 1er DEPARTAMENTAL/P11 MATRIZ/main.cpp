#include <iostream>
#include "Matriz.h"
#include "mane_achivos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	OutputCapture cap;	
	Matriz obMa;
	int matrA[2][2] = {{4,3}, {5,2}};
	int matrB[2][2] = {{7,9}, {4,10}};
	int k = 5;
	
	obMa.Multi(matrA, k);
	obMa.Multi(matrB, k);
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("P11.Matrices", cap.get());
	return 0;
}
