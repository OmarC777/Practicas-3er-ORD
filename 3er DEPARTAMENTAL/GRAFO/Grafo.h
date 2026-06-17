#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
struct ConexionNodo2Nodo {
    string nodoInicial;
    string nodoFinal;
    string aristaConexion;
    double tiempo;
    double costo;
};

class Grafo {
public:
    map<string, vector<ConexionNodo2Nodo>> rutas;

    void agregarConexion(const ConexionNodo2Nodo& conexion);
    void mostrarGrafo() const;
    void calcularDijkstra(const string& inicio, const string& destino) const;
    void exportarSVG(const string& archivoSVG) const;
};

void guardarGrafoJSON(const string& archivo, const Grafo& grafo);
Grafo leerGrafoJSON(const string& archivo);
string limpiarValor(const string& texto);

#endif
