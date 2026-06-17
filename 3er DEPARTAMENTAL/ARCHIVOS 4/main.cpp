#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Cancion.h"

using namespace std;

int main() {
    string archivoJSON = "discografia.json";
    vector<Cancion> miPlaylist;
    int opcion = 0;

    do {
        cout << "GESTOR DE DISCOGRAFIA\n";
        cout << "1. Agregar una nueva cancion\n";
        cout << "2. Guardar datos en JSON\n";
        cout << "3. Cargar y mostrar datos desde JSON\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        
        cin >> opcion;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\nEntrada invalida. Por favor, ingresa un numero.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                string titulo;
                int anio;
                vector<int> reproducciones;
                int rep;

                cout << "\nAGREGAR CANCION\n";
                cout << "Titulo de la cancion: ";
                getline(cin, titulo);

                cout << "Anio de lanzamiento: ";
                cin >> anio;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida para el anio. Registro cancelado.\n";
                    break;
                }

                cout << "Ingresa las reproducciones mensuales (escribe -1 para terminar):\n";
                while (true) {
                    cout << "Reproducciones: ";
                    cin >> rep;
                    
                    if (rep == -1) {
                        break;
                    }
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ingresa un valor numerico valido.\n";
                        continue;
                    }

                    reproducciones.push_back(rep);
                }

                miPlaylist.push_back(Cancion(titulo, anio, reproducciones));
                cout << "\nLa cancion '" << titulo << "' agregado correctamente a la playlist.\n";
                break;
            }
            case 2:
                if (miPlaylist.empty()) {
                    cout << "\nNo hay canciones en la playlist para guardar.\n";
                } else {
                    cout << "\nGUARDANDO EN JSON\n";
                    guardarEnJSON(archivoJSON, miPlaylist);
                }
                break;
            case 3: {
                cout << "\nLEYENDO Y RECONSTRUYENDO DESDE JSON\n";
                vector<Cancion> cancionesCargadas = leerDesdeJSON(archivoJSON);
                
                if (cancionesCargadas.empty()) {
                    cout << "El archivo esta vacio o no existe.\n";
                } else {
                    for (const auto& cancion : cancionesCargadas) {
                        cancion.mostrar();
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
