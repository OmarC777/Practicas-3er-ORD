#ifndef ARBOL_H
#define ARBOL_H

#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct ConexionNodo2Nodo {
    string nodoInicial;
    string nodoFinal;
    string aristaConexion;
    double tiempo;
    double costo;
};

class Arbol {
public:
    map<string, vector<ConexionNodo2Nodo>> rutas;
    map<string, string> padres; 

    bool agregarConexion(const ConexionNodo2Nodo& conexion);
    void mostrarArbol() const;
    void calcularDijkstra(const string& inicio, const string& destino) const;
    void exportarSVG(const string& archivoSVG) const;
    string encontrarRaiz() const; 
};

void guardarArbolJSON(const string& archivo, const Arbol& arbol);
Arbol leerArbolJSON(const string& archivo);
string limpiarValor(const string& texto);

#endif
