#include <iostream>
#include <string>
#include <limits>
#include "Arbol.h"

using namespace std;

int main() {
    Arbol miArbol;
    string archivoJSON = "rutas_arbol.json";
    int opcion = 0;

    do {
        cout << "SISTEMA DE RUTAS (ARBOL TDA)\n";
        cout << "1. Agregar una conexion (Padre a Hijo)\n";
        cout << "2. Mostrar estructura jerarquica\n";
        cout << "3. Calcular ruta mas corta (Dijkstra)\n";
        cout << "4. Guardar datos en JSON\n";
        cout << "5. Cargar datos desde JSON\n";
        cout << "6. Exportar Arbol a imagen SVG\n";
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

                cout << "\nNUEVA RAMA DE ARBOL\n";
                cout << "Nodo Padre (Origen): ";
                getline(cin, nuevaConexion.nodoInicial);
                
                cout << "Nodo Hijo (Destino): ";
                getline(cin, nuevaConexion.nodoFinal);
                
                cout << "Nombre de la Conexion (Arista): ";
                getline(cin, nuevaConexion.aristaConexion);
                
                cout << "Tiempo estimado: ";
                cin >> nuevaConexion.tiempo;
                
                cout << "Costo de la ruta: ";
                cin >> nuevaConexion.costo;

                if (miArbol.agregarConexion(nuevaConexion)) {
                    cout << "Rama creada exitosamente.\n";
                }
                break;
            }
            case 2:
                miArbol.mostrarArbol();
                break;
            case 3: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string inicio, destino;
                
                cout << "\n--- BUSCAR RUTA (DIJKSTRA) ---\n";
                cout << "Desde que nodo (Padre/Ancestro) partes?: ";
                getline(cin, inicio);
                cout << "A que nodo (Hijo/Descendiente) quieres llegar?: ";
                getline(cin, destino);
                
                miArbol.calcularDijkstra(inicio, destino);
                break;
            }
            case 4:
                guardarArbolJSON(archivoJSON, miArbol);
                break;
            case 5:
                miArbol = leerArbolJSON(archivoJSON);
                cout << "Arbol reconstruido desde " << archivoJSON << "\n";
                break;
            case 6:
                miArbol.exportarSVG("visualizacion_arbol.svg");
                break;
            case 7:
                cout << "Saliendo.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);

    return 0;
}
