#ifndef CANCIONJSON_H
#define CANCIONJSON_H

#include <string>
#include <vector>
using namespace std;
class Cancion {
public:
    string titulo;
    int anioLanzamiento;
    vector<int> reproduccionesMensuales; 

    Cancion();
    Cancion(string t, int a, vector<int> r);

    void mostrar() const;
};

void guardarEnJSON(const string& nombreArchivo, const vector<Cancion>& playlist);
vector<Cancion> leerDesdeJSON(const string& nombreArchivo);

string limpiarComillas(const string& texto);

#endif


