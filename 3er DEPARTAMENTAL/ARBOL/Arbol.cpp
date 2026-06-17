#include "Arbol.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

bool Arbol::agregarConexion(const ConexionNodo2Nodo& conexion) {
    if (padres.find(conexion.nodoFinal) != padres.end() && padres[conexion.nodoFinal] != conexion.nodoInicial) {
        cout << "Error de Arbol: El nodo '" << conexion.nodoFinal 
             << "' ya tiene un padre (" << padres[conexion.nodoFinal] << "). No puede tener dos.\n";
        return false;
    }

    rutas[conexion.nodoInicial].push_back(conexion);
    padres[conexion.nodoFinal] = conexion.nodoInicial; 
    
    if (rutas.find(conexion.nodoFinal) == rutas.end()) {
        rutas[conexion.nodoFinal] = vector<ConexionNodo2Nodo>();
    }
    return true;
}

void Arbol::mostrarArbol() const {
    cout << "\nESTRUCTURA DEL ARBOL\n";
    string raiz = encontrarRaiz();
    if (!raiz.empty()) {
        cout << "[Raiz del Arbol]: " << raiz << "\n";
    }

    for (const auto& par : rutas) {
        if (!par.second.empty()) {
            cout << "Nodo Padre: " << par.first << "\n";
            for (const auto& conexion : par.second) {
                cout << "  -> Hijo: " << conexion.nodoFinal 
                     << " | Arista: " << conexion.aristaConexion 
                     << " | Tiempo: " << conexion.tiempo 
                     << " | Costo: $" << conexion.costo << "\n";
            }
        }
    }
}

// Dijkstra se mantiene intacto porque la instrucción lo pide
void Arbol::calcularDijkstra(const string& inicio, const string& destino) const {
    if (rutas.find(inicio) == rutas.end() || rutas.find(destino) == rutas.end()) {
        cout << "Uno o ambos nodos no existen en el arbol.\n";
        return;
    }

    map<string, double> costosAcomulados;
    map<string, string> nodoPadreDijkstra;
    
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
                nodoPadreDijkstra[conexion.nodoFinal] = nodoActual; 
                cola.push({nuevoCosto, conexion.nodoFinal});
            }
        }
    }

    if (costosAcomulados[destino] == numeric_limits<double>::infinity()) {
        cout << "\nNo existe una ruta descendente posible de " << inicio << " a " << destino << ".\n";
    } else {
        vector<string> camino;
        string actual = destino;
        while (actual != inicio) {
            camino.push_back(actual);
            actual = nodoPadreDijkstra[actual];
        }
        camino.push_back(inicio);
        reverse(camino.begin(), camino.end()); 

        cout << "\nRUTA MAS CORTA (DIJKSTRA)\n";
        cout << "Rama: ";
        for (size_t i = 0; i < camino.size(); ++i) {
            cout << camino[i] << (i == camino.size() - 1 ? "" : " -> ");
        }
        cout << "\nCosto total: $" << costosAcomulados[destino] << "\n";
    }
}

string Arbol::encontrarRaiz() const {
    for (const auto& par : rutas) {
        if (padres.find(par.first) == padres.end()) {
            return par.first;
        }
    }
    return "";
}

void Arbol::exportarSVG(const string& archivoSVG) const {
    ofstream out(archivoSVG);
    if (!out.is_open()) return;

    string raiz = encontrarRaiz();
    if (raiz.empty()) {
        cout << "No se pudo encontrar una raiz valida para dibujar el arbol.\n";
        return;
    }

    map<string, int> niveles;
    map<int, vector<string>> nodosPorNivel;
    queue<string> q;
    
    q.push(raiz);
    niveles[raiz] = 0;

    while (!q.empty()) {
        string actual = q.front();
        q.pop();
        int nivelActual = niveles[actual];
        nodosPorNivel[nivelActual].push_back(actual);

        for (const auto& conexion : rutas.at(actual)) {
            niveles[conexion.nodoFinal] = nivelActual + 1;
            q.push(conexion.nodoFinal);
        }
    }

    map<string, pair<double, double>> posiciones;
    double lienzoAncho = 1000.0;
    
    for (const auto& par : nodosPorNivel) {
        int nivel = par.first;
        const vector<string>& nodos = par.second;
        double separacionX = lienzoAncho / (nodos.size() + 1);
        
        for (size_t i = 0; i < nodos.size(); ++i) {
            double x = separacionX * (i + 1);
            double y = 100.0 + (nivel * 150.0); 
            posiciones[nodos[i]] = {x, y};
        }
    }

    out << "<svg width=\"1000\" height=\"800\" xmlns=\"http://www.w3.org/2000/svg\">\n";
    out << "  <rect width=\"100%\" height=\"100%\" fill=\"#f4f4f9\" />\n";

    out << "  <defs>\n";
    out << "    <marker id=\"flecha\" viewBox=\"0 0 10 10\" refX=\"35\" refY=\"5\" markerWidth=\"6\" markerHeight=\"6\" orient=\"auto\">\n";
    out << "      <path d=\"M 0 0 L 10 5 L 0 10 z\" fill=\"#555\" />\n";
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
                << "\" stroke=\"#555\" stroke-width=\"2\" marker-end=\"url(#flecha)\" />\n";
                
            out << "  <text x=\"" << (x1 + x2)/2 << "\" y=\"" << (y1 + y2)/2 - 5 
                << "\" fill=\"#e91e63\" font-size=\"12\" font-family=\"Arial\" text-anchor=\"middle\">"
                << "$" << conexion.costo << "</text>\n";
        }
    }

    for (const auto& par : posiciones) {
        double x = par.second.first;
        double y = par.second.second;
        
        string colorFondo = (par.first == raiz) ? "#FF9800" : "#4CAF50";

        out << "  <circle cx=\"" << x << "\" cy=\"" << y 
            << "\" r=\"25\" fill=\"" << colorFondo << "\" stroke=\"#333\" stroke-width=\"2\" />\n";

        out << "  <text x=\"" << x << "\" y=\"" << y + 5 
            << "\" fill=\"black\" font-size=\"14\" font-weight=\"bold\" font-family=\"Arial\" text-anchor=\"middle\">"
            << par.first << "</text>\n";
    }

    out << "</svg>\n";
    out.close();
    cout << "Arbol exportado como imagen SVG en " << archivoSVG << "\n";
}

string limpiarValor(const string& texto) {
    size_t primeraComilla = texto.find_first_of("\"");
    size_t ultimaComilla = texto.find_last_of("\"");
    if (primeraComilla != string::npos && ultimaComilla != string::npos && primeraComilla != ultimaComilla) {
        return texto.substr(primeraComilla + 1, ultimaComilla - primeraComilla - 1);
    }
    return texto;
}

void guardarArbolJSON(const string& archivo, const Arbol& arbol) {
    ofstream out(archivo);
    out << "{\n  \"rutas\": [\n";
    bool primero = true;
    for (const auto& par : arbol.rutas) {
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
    cout << "Arbol guardado en " << archivo << " con formato JSON.\n";
}

Arbol leerArbolJSON(const string& archivo) {
    Arbol nuevoArbol;
    ifstream in(archivo);
    if (!in.is_open()) return nuevoArbol;

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
            nuevoArbol.agregarConexion(temporal); 
        }
    }
    in.close();
    return nuevoArbol;
}
