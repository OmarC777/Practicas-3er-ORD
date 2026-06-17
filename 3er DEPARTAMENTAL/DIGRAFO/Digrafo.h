#ifndef DIGRAFO_H
#define DIGRAFO_H

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

class Digrafo {
public:
    map<string, vector<ConexionNodo2Nodo>> rutas;

    void agregarConexion(const ConexionNodo2Nodo& conexion);
    void mostrarDigrafo() const;
    void calcularDijkstra(const string& inicio, const string& destino) const;
    void exportarSVG(const string& archivoSVG) const;
};

void guardarDigrafoJSON(const string& archivo, const Digrafo& digrafo);
Digrafo leerDigrafoJSON(const string& archivo);
string limpiarValor(const string& texto);

#endif
