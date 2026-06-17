#include <iostream>
#include <vector>
#include "EstructurasDatos.h"
#include "mane_archivos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menuUniversal(EstructurasDatos* estructuras) 
{
    int opcion;
    do {
        cout << "\n---- M - E - N - U : " << estructuras->getNombre() << " ----" << endl;
        cout << "1. Agregar un nuevo elemento" << endl;
        cout << "2. Quitar elemento" << endl;
        cout << "3. Mostrar estado" << endl;
        cout << "4. Verificar si esta llena" << endl;
        cout << "5. Verificar si esta vacia" << endl;
        cout << "6. Mostrar el tamano actual" << endl;
        cout << "7. Regresar al panel principal" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout << opcion << "\n";
        cout <<"\n";
       

        switch(opcion) 
		{
            case 1: estructuras->agregar(); break;
            case 2: estructuras->quitar(); break;
            case 3: 
                cout << "ESTADO ACTUAL" << endl;
                estructuras->mostrar(); 
                break;
            case 4: 
                if (estructuras->estaLlena()) cout << "Estado: SI esta llena.\n";
                else cout << "Estado: AUN NO esta llena (o es dinamica).\n";
                break;
            case 5: 
                if (estructuras->estaVacia()) cout << "Estado: SI esta vacia.\n";
                else cout << "Estado: NO esta vacia.\n";
                break;
            case 6: 
                cout << "El tamano actual es de: " << estructuras->tamano() << " elemento(s).\n"; 
                break;
            case 7: 
                cout << "Regresando al panel principal...\n"; 
                break;
            default: 
                cout << "Opcion no valida. Por favor intenta de nuevo.\n"; 
                break;
        }
    } while (opcion != 7);
}

int main(int argc, char** argv) 
{
	OutputCapture cap;
	
	PilaAgencia obAgencia;
    ColaCineEstructura obCine;
    ListaClientes obClientes; 
    
    vector<EstructurasDatos*> estructuras = {&obAgencia, &obCine, &obClientes};
    
    int opcionP;
    do {
        cout << "MENU DE ESTRUCTURAS" << endl;
        
        for (size_t i = 0; i < estructuras.size(); i++) {
            cout << i + 1 << ". Administrar " << estructuras[i]->getNombre() << endl;
        }
        cout << estructuras.size() + 1 << ". Salir de la aplicacion" << endl;
        cout << "Elige un negocio: ";
        cin >> opcionP;
        cout << opcionP << "\n";

        if (opcionP > 0 && opcionP <= estructuras.size()) {
            menuUniversal(estructuras[opcionP - 1]);
        } else if (opcionP == estructuras.size() + 1) {
            cout << "Cerrando sistema universal..." << endl;
        } else {
            cout << "Opcion invalida." << endl;
        }
        
    } while (opcionP != estructuras.size() + 1);
    
	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("Pila, Cola y Lista con NTD.", cap.get());
    
    
	return 0;
}
