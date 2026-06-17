#include <iostream>
#include <string>
#include <limits>
#include "Digrafo.h"

using namespace std;

int main() {
    Digrafo redDirigida;
    string archivoJSON = "rutas_digrafo.json";
    int opcion = 0;

    do {
        cout << "SISTEMA DE RUTAS (DIGRAFO)\n";
        cout << "1. Agregar una conexion dirigida (Flujo)\n";
        cout << "2. Mostrar todas las rutas\n";
        cout << "3. Calcular ruta mas corta (Dijkstra)\n";
        cout << "4. Guardar datos en JSON\n";
        cout << "5. Cargar datos desde JSON\n";
        cout << "6. Exportar Digrafo a imagen SVG\n";
        cout << "7. Salir\n";
        cout << "Elige una opcion: ";
        
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ConexionNodo2Nodo nuevaConexion;

                cout << "\nNUEVA CONEXION DIRIGIDA\n";
                cout << "Nodo de Origen: ";
                getline(cin, nuevaConexion.nodoInicial);
                
                cout << "Nodo de Destino (Solo ida): ";
                getline(cin, nuevaConexion.nodoFinal);
                
                cout << "Nombre de la Conexion (Arista): ";
                getline(cin, nuevaConexion.aristaConexion);
                
                cout << "Tiempo estimado: ";
                cin >> nuevaConexion.tiempo;
                
                cout << "Costo de la ruta: ";
                cin >> nuevaConexion.costo;

                redDirigida.agregarConexion(nuevaConexion);
                cout << "Conexion dirigida creada exitosamente.\n";
                break;
            }
            case 2:
                redDirigida.mostrarDigrafo();
                break;
            case 3: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string inicio, destino;
                
                cout << "\nALGORITMO DE DIJKSTRA\n";
                cout << "Desde que nodo partes?: ";
                getline(cin, inicio);
                cout << "A que nodo quieres llegar?: ";
                getline(cin, destino);
                
                redDirigida.calcularDijkstra(inicio, destino);
                break;
            }
            case 4:
                guardarDigrafoJSON(archivoJSON, redDirigida);
                break;
            case 5:
                redDirigida = leerDigrafoJSON(archivoJSON);
                cout << "Digrafo reconstruido desde " << archivoJSON << "\n";
                break;
            case 6:
                redDirigida.exportarSVG("visualizacion_digrafo.svg");
                break;
            case 7:
                cout << "Salir.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    return 0;
}
