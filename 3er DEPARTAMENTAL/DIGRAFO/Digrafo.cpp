#include "Digrafo.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

void Digrafo::agregarConexion(const ConexionNodo2Nodo& conexion) {
    rutas[conexion.nodoInicial].push_back(conexion);
    if (rutas.find(conexion.nodoFinal) == rutas.end()) {
        rutas[conexion.nodoFinal] = vector<ConexionNodo2Nodo>();
    }
}

void Digrafo::mostrarDigrafo() const {
    cout << "\nRUTAS DEL DIGRAFO\n";
    for (const auto& par : rutas) {
        cout << "Nodo: " << par.first << "\n";
        for (const auto& conexion : par.second) {
            cout << "  -> Flujo hacia: " << conexion.nodoFinal 
                 << " | Arista: " << conexion.aristaConexion 
                 << " | Tiempo: " << conexion.tiempo 
                 << " | Costo: $" << conexion.costo << "\n";
        }
    }
}

void Digrafo::calcularDijkstra(const string& inicio, const string& destino) const {
    if (rutas.find(inicio) == rutas.end() || rutas.find(destino) == rutas.end()) {
        cout << "Uno o ambos nodos no existen en el digrafo.\n";
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
        cout << "\nNo existe una ruta posible con direccion de " << inicio << " a " << destino << ".\n";
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
        cout << "Camino Dirigido: ";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i] << (i == camino.size() - 1 ? "" : " -> ");
        }
        cout << "\nCosto total: $" << costosAcomulados[destino] << "\n";
    }
}

void Digrafo::exportarSVG(const string& archivoSVG) const {
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
    out << "  <rect width=\"100%\" height=\"100%\" fill=\"white\" />\n";
    
    out << "  <defs>\n";
    out << "    <marker id=\"flecha\" viewBox=\"0 0 10 10\" refX=\"35\" refY=\"5\" markerWidth=\"6\" markerHeight=\"6\" orient=\"auto\">\n";
    out << "      <path d=\"M 0 0 L 10 5 L 0 10 z\" fill=\"#888\" />\n";
    out << "    </marker>\n";
    out << "  </defs>\n";

    for (const auto& par : rutas) {
        for (const auto& conexion : par.second) {
            double x1 = posiciones[conexion.nodoInicial].first;
            double y1 = posiciones[conexion.nodoInicial].second;
            double x2 = posiciones[conexion.nodoFinal].first;
            double y2 = posiciones[conexion.nodoFinal].second;

            out << "  <line x1=\"" << x1 << "\" y1=\"" << y1 
                << "\" x2=\"" << x2 << "\" y2=\"" << y2 
                << "\" stroke=\"#888\" stroke-width=\"2\" marker-end=\"url(#flecha)\" />\n";

            double medioX = (x1 + x2) / 2;
            double medioY = (y1 + y2) / 2;
            out << "  <text x=\"" << medioX << "\" y=\"" << medioY - 10 
                << "\" fill=\"red\" font-size=\"14\" font-family=\"Arial\" text-anchor=\"middle\">"
                << "$" << conexion.costo << "</text>\n";
        }
    }

    for (const auto& par : posiciones) {
        double x = par.second.first;
        double y = par.second.second;

        out << "  <circle cx=\"" << x << "\" cy=\"" << y 
            << "\" r=\"25\" fill=\"#2196F3\" stroke=\"#1976D2\" stroke-width=\"3\" />\n";

        out << "  <text x=\"" << x << "\" y=\"" << y + 5 
            << "\" fill=\"black\" font-size=\"14\" font-weight=\"bold\" font-family=\"Arial\" text-anchor=\"middle\">"
            << par.first << "</text>\n";
    }

    out << "</svg>\n";
    out.close();
    cout << "Digrafo exportado como imagen SVG en " << archivoSVG << "\n";
}

string limpiarValor(const string& texto) {
    size_t primeraComilla = texto.find_first_of("\"");
    size_t ultimaComilla = texto.find_last_of("\"");
    if (primeraComilla != string::npos && ultimaComilla != string::npos && primeraComilla != ultimaComilla) {
        return texto.substr(primeraComilla + 1, ultimaComilla - primeraComilla - 1);
    }
    return texto;
}

void guardarDigrafoJSON(const string& archivo, const Digrafo& digrafo) {
    ofstream out(archivo);
    out << "{\n  \"rutas\": [\n";
    bool primero = true;
    for (const auto& par : digrafo.rutas) {
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
    cout << "Digrafo guardado en " << archivo << " con formato JSON.\n";
}

Digrafo leerDigrafoJSON(const string& archivo) {
    Digrafo nuevoDigrafo;
    ifstream in(archivo);
    if (!in.is_open()) return nuevoDigrafo;

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
            nuevoDigrafo.agregarConexion(temporal); 
        }
    }
    in.close();
    return nuevoDigrafo;
}
