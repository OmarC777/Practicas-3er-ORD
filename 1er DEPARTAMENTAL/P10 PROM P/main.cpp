#include <iostream>
#include "PromedioP.h"
#include "mane_archivos.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	OutputCapture cap;	
	
	PromedioP obOp;
	obOp.OperacionesP();
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("P10.Promedio P", cap.get());
	return 0;
}
