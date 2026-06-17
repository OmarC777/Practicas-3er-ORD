#include <iostream>
#include "HM.h"
#include "mane_archivos.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
int main(int argc, char** argv) 
{
	OutputCapture cap;
	HM obsal;
	obsal.saludo();
	
	writeAllOutputs("P1.HolaMundo", cap.get());
	
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");
	return 0;
}
