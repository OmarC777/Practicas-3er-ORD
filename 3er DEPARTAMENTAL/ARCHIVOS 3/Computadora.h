#ifndef COMPUTADORATXT_H
#define COMPUTADORATXT_H

#include <string>
#include <vector>
using namespace std;
class Computadora {
public:
    string procesador;
    int wattsFuente;
    vector<int> historialTemperaturas; 
    Computadora();
    Computadora(string proc, int watts, vector<int> temps);
    void mostrar() const;
};

void guardarEnTXT(const string& nombreArchivo, const vector<Computadora>& inventario);
vector<Computadora> leerDesdeTXT(const string& nombreArchivo);

#endif


