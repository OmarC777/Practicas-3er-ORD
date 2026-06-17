#include <iostream>
#include <string>
#include <limits>
#include "Grafo.h"

using namespace std;

int main() {
    Grafo red;
    string archivoJSON = "rutas.json";
    int opcion = 0;

    do {
        cout << "SISTEMA DE RUTAS (TDA)\n";
        cout << "1. Agregar una conexion (Arista)\n";
        cout << "2. Mostrar todas las rutas\n";
        cout << "3. Calcular ruta mas corta (Dijkstra)\n";
        cout << "4. Guardar datos en JSON\n";
        cout << "5. Cargar datos desde JSON\n";
        cout << "6. Graficar\n";
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

                cout << "\nNUEVA CONEXION\n";
                cout << "Nodo de Origen: ";
                getline(cin, nuevaConexion.nodoInicial);
                
                cout << "Nodo de Destino: ";
                getline(cin, nuevaConexion.nodoFinal);
                
                cout << "Nombre de la Conexion (Arista): ";
                getline(cin, nuevaConexion.aristaConexion);
                
                cout << "Tiempo estimado: ";
                cin >> nuevaConexion.tiempo;
                
                cout << "Costo de la ruta: ";
                cin >> nuevaConexion.costo;

                red.agregarConexion(nuevaConexion);
                cout << "Conexion creada exitosamente.\n";
                break;
            }
            case 2:
                red.mostrarGrafo();
                break;
            case 3: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string inicio, destino;
                
                cout << "Desde que nodo partes?: ";
                getline(cin, inicio);
                cout << "A que nodo quieres llegar?: ";
                getline(cin, destino);
                
                red.calcularDijkstra(inicio, destino);
                break;
            }
            case 4:
                guardarGrafoJSON(archivoJSON, red);
                break;
            case 5:
                red = leerGrafoJSON(archivoJSON);
                cout << "Grafo reconstruido desde " << archivoJSON << "\n";
                break;
            case 6:
    			red.exportarSVG("visualizacion_grafo.svg");
    			break;
    		case 7:
                cout << "Saliendo.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 6);

    return 0;
}
