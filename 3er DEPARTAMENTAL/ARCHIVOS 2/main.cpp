#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Videojuego.h"

using namespace std;

int main() {
    string archivoXML = "biblioteca.xml";
    vector<Videojuego> miColeccion;
    int opcion = 0;

    do {
        cout << "BIBLIOTECA DE VIDEOJUEGOS\n";
        cout << "1. Agregar un nuevo videojuego\n";
        cout << "2. Guardar datos en XML\n";
        cout << "3. Cargar y mostrar datos desde XML\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\nEntrada invalida, ingresa un numero.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                string titulo;
                int horas;
                vector<int> puntajes;
                int puntaje;

                cout << "\nAGREGAR VIDEOJUEGO\n";
                cout << "Titulo del juego: ";
                getline(cin, titulo);

                cout << "Horas jugadas: ";
                cin >> horas;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida para horas. Registro cancelado.\n";
                    break;
                }

                cout << "Ingresa los puntajes de las partidas (escribe -1 para terminar):\n";
                while (true) {
                    cout << "Puntaje: ";
                    cin >> puntaje;
                    
                    if (puntaje == -1) {
                        break;
                    }
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ingresa un puntaje numerico valido.\n";
                        continue;
                    }

                    puntajes.push_back(puntaje);
                }

                miColeccion.push_back(Videojuego(titulo, horas, puntajes));
                cout << "\nJuego '" << titulo << "' agregado correctamente a la biblioteca.\n";
                break;
            }
            case 2:
                if (miColeccion.empty()) {
                    cout << "\nNo hay videojuegos en el sistema para guardar.\n";
                } else {
                    cout << "\nGUARDANDO EN XML\n";
                    guardarEnXML(archivoXML, miColeccion);
                }
                break;
            case 3: {
                cout << "\nLEYENDO Y RECONSTRUYENDO DESDE XML\n";
                vector<Videojuego> juegosCargados = leerDesdeXML(archivoXML);
                
                if (juegosCargados.empty()) {
                    cout << "El archivo esta vacio o no existe.\n";
                } else {
                    for (const auto& juego : juegosCargados) {
                        juego.mostrar();
                    }
                }
                break;
            }
            case 4:
                cout << "\nSaliendo del programa.\n";
                break;
            default:
                cout << "\nOpcion no valida. Intenta de nuevo.\n";
                break;
        }

    } while (opcion != 4);

    return 0;
}
