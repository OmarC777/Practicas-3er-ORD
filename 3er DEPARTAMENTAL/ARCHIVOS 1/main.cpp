#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Alumno.h"
using namespace std;

int main() {
    string archivoCSV = "alumnos.csv";
    vector<Alumno> escuela;
    int opcion = 0;

    do {
        cout << "       MENU DE ALUMNOS        \n";
        cout << "1. Agregar un nuevo alumno\n";
        cout << "2. Guardar datos en CSV\n";
        cout << "3. Cargar y mostrar datos desde CSV\n";
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
                
                string nombre;
                int edad;
                vector<int> notas;
                int nota;

                cout << "\nAGREGAR ALUMNO\n";
                cout << "Nombre del alumno: ";
                getline(cin, nombre);

                cout << "Edad: ";
                cin >> edad;

                cout << "Ingresa las calificaciones (escribe -1 para terminar):\n";
                while (true) {
                    cout << "Nota: ";
                    cin >> nota;
                    
                    if (nota == -1) {
                        break;
                    }
                    
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Ingresa una calificacion numerica valida.\n";
                        continue;
                    }

                    notas.push_back(nota);
                }

                escuela.push_back(Alumno(nombre, edad, notas));
                cout << "\nAlumno '" << nombre << "' agregado al sistema.\n";
                break;
            }
            case 2:
                if (escuela.empty()) {
                    cout << "\nNo hay alumnos en el sistema para guardar.\n";
                } else {
                    cout << "\nGUARDANDO EN CSV\n";
                    guardarEnCSV(archivoCSV, escuela);
                }
                break;
            case 3: {
                cout << "\n--- LEYENDO Y CONSTRUYENDO DESDE CSV ---\n";
                vector<Alumno> alumnosCargados = leerDesdeCSV(archivoCSV);
                
                if (alumnosCargados.empty()) {
                    cout << "El archivo esta vacio o no existe.\n";
                } else {
                    for (const auto& alumno : alumnosCargados) {
                        alumno.mostrar();
                    }
                }
                break;
            }
            case 4:
                cout << "\nSaliendo del programa\n";
                break;
            default:
                cout << "\nOpcion no valida. Intenta de nuevo.\n";
                break;
        }

    } while (opcion != 4);

    return 0;
}
