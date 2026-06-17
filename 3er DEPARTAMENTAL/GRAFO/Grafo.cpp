#include "Grafo.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

void Grafo::agregarConexion(const ConexionNodo2Nodo& conexion) {
    rutas[conexion.nodoInicial].push_back(conexion);
    
    if (rutas.find(conexion.nodoFinal) == rutas.end()) {
        rutas[conexion.nodoFinal] = vector<ConexionNodo2Nodo>();
    }
}

void Grafo::mostrarGrafo() const {
    cout << "\nRUTAS DEL GRAFO\n";
    for (const auto& par : rutas) {
        cout << "Nodo: " << par.first << "\n";
        for (const auto& conexion : par.second) {
            cout << "  -> Conecta con: " << conexion.nodoFinal 
                 << " | Arista: " << conexion.aristaConexion 
                 << " | Tiempo: " << conexion.tiempo 
                 << " | Costo: $" << conexion.costo << "\n";
        }
    }
}

void Grafo::calcularDijkstra(const string& inicio, const string& destino) const {
    if (rutas.find(inicio) == rutas.end() || rutas.find(destino) == rutas.end()) {
        cout << "Uno o ambos nodos no existen en el grafo.\n";
        return;
    }

    map<string, double> costosAcomulados;
    map<string, string> nodoPadre;
    
    for (const auto& par : rutas) {
        costosAcomulados[par.first] = numeric_limits<double>::infinity();
    }
    costosAcomulados[inicio] = 0.0;

    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> cola;
    cola.push({0.0, inicio});

    while (!cola.empty()) {
        string nodoActual = cola.top().second;
        double costoActual = cola.top().first;
        cola.pop();

        if (nodoActual == destino) continue;

        for (const auto& conexion : rutas.at(nodoActual)) {
            double nuevoCosto = costoActual + conexion.costo;

            if (nuevoCosto < costosAcomulados[conexion.nodoFinal]) {
                costosAcomulados[conexion.nodoFinal] = nuevoCosto;
                nodoPadre[conexion.nodoFinal] = nodoActual; 
                cola.push({nuevoCosto, conexion.nodoFinal});
            }
        }
    }

    if (costosAcomulados[destino] == numeric_limits<double>::infinity()) {
        cout << "\nNo existe una ruta posible entre " << inicio << " y " << destino << ".\n";
    } else {
        vector<string> camino;
        string actual = destino;
        while (actual != inicio) {
            camino.push_back(actual);
            actual = nodoPadre[actual];
        }
        camino.push_back(inicio);
        reverse(camino.begin(), camino.end()); 

        cout << "\nRUTA MAS CORTA (DIJKSTRA)\n";
        cout << "Camino: ";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i] << (i == camino.size() - 1 ? "" : " -> ");
        }
        cout << "\nCosto total: $" << costosAcomulados[destino] << "\n";
    }
}

string limpiarValor(const string& texto) {
    size_t primeraComilla = texto.find_first_of("\"");
    size_t ultimaComilla = texto.find_last_of("\"");
    if (primeraComilla != string::npos && ultimaComilla != string::npos && primeraComilla != ultimaComilla) {
        return texto.substr(primeraComilla + 1, ultimaComilla - primeraComilla - 1);
    }
    return texto;
}

void guardarGrafoJSON(const string& archivo, const Grafo& grafo) {
    ofstream out(archivo);
    out << "{\n  \"rutas\": [\n";
    
    bool primero = true;
    for (const auto& par : grafo.rutas) {
        for (const auto& c : par.second) {
            if (!primero) out << ",\n";
            out << "    {\n      \"conexionNodo2Nodo\": {\n";
            out << "        \"nodoInicial\": \"" << c.nodoInicial << "\",\n";
            out << "        \"nodoFinal\": \"" << c.nodoFinal << "\",\n";
            out << "        \"aristaConexion\": \"" << c.aristaConexion << "\",\n";
            out << "        \"tiempo\": " << c.tiempo << ",\n";
            out << "        \"costo\": " << c.costo << "\n      }\n    }";
            primero = false;
        }
    }
    out << "\n  ]\n}\n";
    out.close();
    cout << "Grafo guardado en " << archivo << " con formato JSON.\n";
}

Grafo leerGrafoJSON(const string& archivo) {
    Grafo nuevoGrafo;
    ifstream in(archivo);
    if (!in.is_open()) return nuevoGrafo;

    string linea;
    ConexionNodo2Nodo temporal;
    
    while (getline(in, linea)) {
        if (linea.find("\"nodoInicial\"") != string::npos) {
            temporal.nodoInicial = limpiarValor(linea.substr(linea.find(":") + 1));
        } else if (linea.find("\"nodoFinal\"") != string::npos) {
            temporal.nodoFinal = limpiarValor(linea.substr(linea.find(":") + 1));
        } else if (linea.find("\"aristaConexion\"") != string::npos) {
            temporal.aristaConexion = limpiarValor(linea.substr(linea.find(":") + 1));
        } else if (linea.find("\"tiempo\"") != string::npos) {
            string val = linea.substr(linea.find(":") + 1);
            val.erase(remove(val.begin(), val.end(), ','), val.end());
            temporal.tiempo = stod(val);
        } else if (linea.find("\"costo\"") != string::npos) {
            string val = linea.substr(linea.find(":") + 1);
            val.erase(remove(val.begin(), val.end(), ','), val.end());
            temporal.costo = stod(val);
            nuevoGrafo.agregarConexion(temporal); 
        }
    }
    in.close();
    return nuevoGrafo;
}
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void Grafo::exportarSVG(const string& archivoSVG) const {
    ofstream out(archivoSVG);
    if (!out.is_open()) {
        cout << "Error al crear el archivo SVG.\n";
        return;
    }

    set<string> nodosUnicos;
    for (const auto& par : rutas) {
        nodosUnicos.insert(par.first);
        for (const auto& conexion : par.second) {
            nodosUnicos.insert(conexion.nodoFinal);
        }
    }

    map<string, pair<double, double>> posiciones;
    int totalNodos = nodosUnicos.size();
    int i = 0;
    double radio = 300.0;
    double centroX = 400.0, centroY = 400.0;

    for (const string& nodo : nodosUnicos) {
        double angulo = 2.0 * M_PI * i / totalNodos;
        double x = centroX + radio * cos(angulo);
        double y = centroY + radio * sin(angulo);
        posiciones[nodo] = {x, y};
        i++;
    }

    out << "<svg width=\"800\" height=\"800\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    out << "  \n";
    out << "  <rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";

    for (const auto& par : rutas) {
        for (const auto& conexion : par.second) {
            double x1 = posiciones[conexion.nodoInicial].first;
            double y1 = posiciones[conexion.nodoInicial].second;
            double x2 = posiciones[conexion.nodoFinal].first;
            double y2 = posiciones[conexion.nodoFinal].second;

            out << "  <line x1=\"" << x1 << "\" y1=\"" << y1 
                << "\" x2=\"" << x2 << "\" y2=\"" << y2 
                << "\" stroke=\"#888\" stroke-width=\"2\" />\n";

            double medioX = (x1 + x2) / 2;
            double medioY = (y1 + y2) / 2;
            out << "  <text x=\"" << medioX << "\" y=\"" << medioY - 5 
                << "\" fill=\"red\" font-size=\"14\" font-family=\"Arial\" text-anchor=\"middle\">"
                << "$" << conexion.costo << "</text>\n";
        }
    }

    for (const auto& par : posiciones) {
        double x = par.second.first;
        double y = par.second.second;

        out << "  <circle cx=\"" << x << "\" cy=\"" << y 
            << "\" r=\"25\" fill=\"#4CAF50\" stroke=\"#388E3C\" stroke-width=\"3\" />\n";

        out << "  <text x=\"" << x << "\" y=\"" << y + 5 
            << "\" fill=\"black\" font-size=\"14\" font-weight=\"bold\" font-family=\"Arial\" text-anchor=\"middle\">"
            << par.first << "</text>\n";
    }

    out << "</svg>\n";
    out.close();
    
    cout << "Grafo exportado como imagen SVG en " << archivoSVG << "\n";
}
