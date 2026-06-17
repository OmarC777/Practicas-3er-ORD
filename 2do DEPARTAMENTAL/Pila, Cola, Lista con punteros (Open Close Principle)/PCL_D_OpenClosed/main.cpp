#include <iostream>
#include <vector>
#include "EstructurasDinamicas.h"
#include "mane_archivos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menuUniversal(EstructurasDatos* estructura) 
{
    int opcion;
    do {
        cout << "\nMenu de " << estructura->getNombre() << endl;
        cout << "1. Agregar elemento" << endl;
        cout << "2. Quitar elemento" << endl;
        cout << "3. Mostrar contenido" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Verificar si esta llena" << endl;
        cout << "6. Mostrar tamano" << endl;
        cout << "7. Regresar al menu principal" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout << opcion << "\n";

        switch(opcion) 
		{
            case 1: estructura->agregar(); break;
            case 2: estructura->quitar(); break;
            case 3: 
                cout << "\n--- CONTENIDO ---" << endl;
                estructura->mostrar(); 
                break;
            case 4: 
                cout << "-> La estructura " << (estructura->estaVacia() ? "SI" : "NO") << " esta vacia." << endl; 
                break;
            case 5: 
                cout << "-> La estructura " << (estructura->estaLlena() ? "SI" : "NO") << " esta llena (Es dinamica)." << endl; 
                break;
            case 6: 
                cout << "-> El tamano actual es de: " << estructura->tamano() << " elementos." << endl; 
                break;
            case 7: 
                cout << "Regresando..." << endl; 
                break;
            default: 
                cout << "Opcion no valida." << endl; 
                break;
        }
    } while (opcion != 7);
}
int main(int argc, char** argv) 
{
	OutputCapture cap;
	
	Pila obPilaD;
    Cola obColaD;
    Lista obListaD;
    
    vector<EstructurasDatos*> Estructuras = {&obPilaD, &obColaD, &obListaD};
    
    int opcionP;
    do {
        cout << "MENU DE ESTRUCTURAS DINAMICAS" << endl;
        
        for (size_t i = 0; i < Estructuras.size(); i++) {
            cout << i + 1 << ". Trabajar con " << Estructuras[i]->getNombre() << endl;
        }
        cout << Estructuras.size() + 1 << ". Salir" << endl;
        cout << "Elige una estructura: ";
        cin >> opcionP;
        cout << opcionP << "\n";

        if (opcionP > 0 && opcionP <= Estructuras.size()) {
            menuUniversal(Estructuras[opcionP - 1]);
        } else if (opcionP == Estructuras.size() + 1) {
            cout << "Cerrando sistema..." << endl;
        } else {
            cout << "Opcion invalida." << endl;
        }
        
    } while (opcionP != Estructuras.size() + 1);

	system("start out.txt");
	system("start out.json");
	system("start out.xml");
	system("start out.csv");

	writeAllOutputs("Pila, Cola y Lista con Punteros.", cap.get());

    return 0;
}
