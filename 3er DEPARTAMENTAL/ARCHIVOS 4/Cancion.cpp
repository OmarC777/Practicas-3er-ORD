#include "Cancion.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
Cancion::Cancion() : titulo(""), anioLanzamiento(0) {}
Cancion::Cancion(string t, int a, vector<int> r) 
    : titulo(t), anioLanzamiento(a), reproduccionesMensuales(r) {}

void Cancion::mostrar() const {
    cout << "Track: " << titulo << " (" << anioLanzamiento << ") | Reproducciones: [";
    for (size_t i = 0; i < reproduccionesMensuales.size(); ++i) {
        cout << reproduccionesMensuales[i] << (i == reproduccionesMensuales.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

	string limpiarComillas(const string& texto) {
    size_t primeraComilla = texto.find_first_of("\"");
    size_t ultimaComilla = texto.find_last_of("\"");
    if (primeraComilla != string::npos && ultimaComilla != string::npos && primeraComilla != ultimaComilla) {
        return texto.substr(primeraComilla + 1, ultimaComilla - primeraComilla - 1);
    }
    return texto;
}

void guardarEnJSON(const string& nombreArchivo, const vector<Cancion>& playlist) {
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo JSON para escribir.\n";
        return;
    }

    archivo << "[\n"; 

    for (size_t i = 0; i < playlist.size(); ++i) {
        archivo << "  {\n";
        
        archivo << "    \"titulo\": \"" << playlist[i].titulo << "\",\n";
        archivo << "    \"anioLanzamiento\": " << playlist[i].anioLanzamiento << ",\n";
        
        archivo << "    \"reproduccionesMensuales\": [";
        for (size_t j = 0; j < playlist[i].reproduccionesMensuales.size(); ++j) {
            archivo << playlist[i].reproduccionesMensuales[j];
            if (j < playlist[i].reproduccionesMensuales.size() - 1) {
                archivo << ", ";
            }
        }
        archivo << "]\n";
        
        archivo << "  }";
        if (i < playlist.size() - 1) {
            archivo << ",";
        }
        archivo << "\n";
    }

    archivo << "]\n"; 
    archivo.close();
    cout << "Datos guardados exitosamente en " << nombreArchivo << "\n";
}

	vector<Cancion> leerDesdeJSON(const string& nombreArchivo) {
    vector<Cancion> listaDestino;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo JSON para leer.\n";
        return listaDestino;
    }

    string linea;
    Cancion cancionTemporal;
    bool leyendoObjeto = false;

    while (getline(archivo, linea)) {
        if (linea.find("{") != string::npos) {
            leyendoObjeto = true;
            cancionTemporal = Cancion();
        } 
        else if (linea.find("}") != string::npos && leyendoObjeto) {
            listaDestino.push_back(cancionTemporal);
            leyendoObjeto = false;
        } 
        else if (leyendoObjeto) {
            if (linea.find("\"titulo\"") != string::npos) {
                size_t posDosPuntos = linea.find(":");
                cancionTemporal.titulo = limpiarComillas(linea.substr(posDosPuntos + 1));
            } 
            else if (linea.find("\"anioLanzamiento\"") != string::npos) {
                size_t posDosPuntos = linea.find(":");
                string valorAnio = linea.substr(posDosPuntos + 1);
                valorAnio.erase(remove(valorAnio.begin(), valorAnio.end(), ','), valorAnio.end()); 
                cancionTemporal.anioLanzamiento = stoi(valorAnio);
            } 
            else if (linea.find("\"reproduccionesMensuales\"") != string::npos) {
                size_t posCorcheteIzq = linea.find("[");
                size_t posCorcheteDer = linea.find("]");
                
                if (posCorcheteIzq != string::npos && posCorcheteDer != string::npos) {
                    string arrayStr = linea.substr(posCorcheteIzq + 1, posCorcheteDer - posCorcheteIzq - 1);
                    
                    stringstream ss(arrayStr);
                    string numeroStr;
                    while (getline(ss, numeroStr, ',')) {
                        cancionTemporal.reproduccionesMensuales.push_back(stoi(numeroStr));
                    }
                }
            }
        }
    }

    archivo.close();
    return listaDestino;
}
