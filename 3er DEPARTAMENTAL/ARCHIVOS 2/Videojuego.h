#ifndef VIDEOJUEGOXML_H
#define VIDEOJUEGOXML_H

#include <string>
#include <vector>
using namespace std;
class Videojuego {
public:
    string titulo;
    int horasJugadas;
    vector<int> puntajesPartidas;
    Videojuego();
    Videojuego(string t, int h, vector<int> p);
    void mostrar() const;
};

void guardarEnXML(const string& nombreArchivo, const vector<Videojuego>& catalogo);
vector<Videojuego> leerDesdeXML(const string& nombreArchivo);

string extraerContenidoEtiqueta(const string& linea, const string& etiqueta);

#endif


