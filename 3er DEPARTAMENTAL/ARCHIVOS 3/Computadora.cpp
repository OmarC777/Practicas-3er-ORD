#include "Computadora.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
Computadora::Computadora() : procesador(""), wattsFuente(0) {}
Computadora::Computadora(string proc, int watts, vector<int> temps) 
    : procesador(proc), wattsFuente(watts), historialTemperaturas(temps) {}

void Computadora::mostrar() const {
    cout << "CPU: " << procesador << " | PSU: " << wattsFuente << "W | Temperaturas: [";
    for (size_t i = 0; i < historialTemperaturas.size(); ++i) {
        cout << historialTemperaturas[i] << (i == historialTemperaturas.size() - 1 ? "" : "C, ");
    }
    cout << "C]\n";
}

void guardarEnTXT(const string& nombreArchivo, const vector<Computadora>& inventario) {
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo TXT para escribir.\n";
        return;
    }

    for (const auto& pc : inventario) {
        archivo << pc.procesador << "\n";     
        archivo << pc.wattsFuente << "\n";    
        
        for (size_t i = 0; i < pc.historialTemperaturas.size(); ++i) {
            archivo << pc.historialTemperaturas[i];
            if (i < pc.historialTemperaturas.size() - 1) {
                archivo << " "; 
            }
        }
        archivo << "\n"; 
        archivo << "---\n"; 
    }

    archivo.close();
    cout << "Datos guardados exitosamente en " << nombreArchivo << "\n";
}

	vector<Computadora> leerDesdeTXT(const string& nombreArchivo) {
    vector<Computadora> listaDestino;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo TXT para leer.\n";
        return listaDestino;
    }

    string lineaProcesador;
    
    while (getline(archivo, lineaProcesador)) {
        if (lineaProcesador.empty() || lineaProcesador == "---") continue;

        string lineaWatts;
        string lineaTemperaturas;
        string lineaSeparador;

        getline(archivo, lineaWatts);
        getline(archivo, lineaTemperaturas);
        
        getline(archivo, lineaSeparador); 

        int watts = stoi(lineaWatts);

        vector<int> temps;
        stringstream ssTemps(lineaTemperaturas);
        string tempIndividual;
        
        while (getline(ssTemps, tempIndividual, ' ')) {
            if (!tempIndividual.empty()) {
                temps.push_back(stoi(tempIndividual));
            }
        }

        listaDestino.push_back(Computadora(lineaProcesador, watts, temps));
    }

    archivo.close();
    return listaDestino;
}
