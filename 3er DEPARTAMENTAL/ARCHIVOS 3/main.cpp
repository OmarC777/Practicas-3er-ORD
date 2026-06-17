#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Computadora.h"

using namespace std;

int main() {
    string archivoTXT = "equipos.txt";
    vector<Computadora> taller;
    int opcion = 0;

    do {
        cout << "INVENTARIO DE EQUIPOS\n";
        cout << "1. Registrar nueva computadora\n";
        cout << "2. Guardar datos en TXT\n";
        cout << "3. Cargar y mostrar datos desde TXT\n";
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
                
                string cpu;
                int watts;
                vector<int> temps;
                int temp;

                cout << "\nREGISTRAR EQUIPO\n";
                cout << "Procesador (CPU): ";
                getline(cin, cpu);

                cout << "Capacidad de la fuente de poder (Watts): ";
                cin >> watts;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada invalida para los watts. Registro cancelado.\n";
                    break;
                }

                cout << "Ingresa el historial de temperaturas (escribe -1 para terminar):\n";
                while (true) {
                    cout << "Temperatura (°C): ";
                    cin >> temp;
                    
                    if (temp == -1) {
                        break;
                    }
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ingresa un valor numerico valido.\n";
                        continue;
                    }

                    temps.push_back(temp);
                }

                taller.push_back(Computadora(cpu, watts, temps));
                cout << "\nEquipo con '" << cpu << "' registrado correctamente.\n";
                break;
            }
            case 2:
                if (taller.empty()) {
                    cout << "\nNo hay equipos en el sistema para guardar.\n";
                } else {
                    cout << "\nGUARDANDO EN TXT\n";
                    guardarEnTXT(archivoTXT, taller);
                }
                break;
            case 3: {
                cout << "\nLEYENDO Y RECONSTRUYENDO DESDE TXT\n";
                vector<Computadora> equiposCargados = leerDesdeTXT(archivoTXT);
                
                if (equiposCargados.empty()) {
                    cout << "El archivo esta vacio o no existe.\n";
                } else {
                    for (const auto& pc : equiposCargados) {
                        pc.mostrar();
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
