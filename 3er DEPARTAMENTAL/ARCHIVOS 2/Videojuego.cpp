#include "Videojuego.h"
#include <iostream>
#include <fstream>
using namespace std;
Videojuego::Videojuego() : titulo(""), horasJugadas(0) {}
Videojuego::Videojuego(string t, int h, vector<int> p) : titulo(t), horasJugadas(h), puntajesPartidas(p) {}

void Videojuego::mostrar() const {
    cout << "Juego: " << titulo << " | Horas: " << horasJugadas << " | Puntajes: [";
    for (size_t i = 0; i < puntajesPartidas.size(); ++i) {
        cout << puntajesPartidas[i] << (i == puntajesPartidas.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

	string extraerContenidoEtiqueta(const string& linea, const string& etiqueta) {
    string tagInicio = "<" + etiqueta + ">";
    string tagFin = "</" + etiqueta + ">";
    
    size_t posInicio = linea.find(tagInicio);
    size_t posFin = linea.find(tagFin);
    
    if (posInicio != string::npos && posFin != string::npos) {
        posInicio += tagInicio.length(); 
        return linea.substr(posInicio, posFin - posInicio);
    }
    return "";
}

void guardarEnXML(const string& nombreArchivo, const vector<Videojuego>& catalogo) {
    ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo XML para escribir.\n";
        return;
    }

    archivo << "<LibreriaJuegos>\n";

    for (const auto& juego : catalogo) {
        archivo << "  <Videojuego>\n"; 
        
        archivo << "    <Titulo>" << juego.titulo << "</Titulo>\n";
        archivo << "    <HorasJugadas>" << juego.horasJugadas << "</HorasJugadas>\n";
        
        archivo << "    <Partidas>\n";
        for (int puntaje : juego.puntajesPartidas) {
            archivo << "      <Puntaje>" << puntaje << "</Puntaje>\n";
        }
        archivo << "    </Partidas>\n";
        
        archivo << "  </Videojuego>\n"; 
    }

    archivo << "</LibreriaJuegos>\n"; 
    archivo.close();
    cout << "Datos guardados exitosamente en " << nombreArchivo << "\n";
}

	vector<Videojuego> leerDesdeXML(const string& nombreArchivo) {
    vector<Videojuego> listaDestino;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo XML para leer.\n";
        return listaDestino;
    }

    string linea;
    Videojuego juegoTemporal;
    bool leyendoJuego = false;
    
    while (getline(archivo, linea)) {
        if (linea.find("<Videojuego>") != string::npos) {
            leyendoJuego = true;
            juegoTemporal = Videojuego(); 
            juegoTemporal.puntajesPartidas.clear();
        } 
        else if (linea.find("</Videojuego>") != string::npos) {
            listaDestino.push_back(juegoTemporal);
            leyendoJuego = false;
        } 
        else if (leyendoJuego) {
            if (linea.find("<Titulo>") != string::npos) {
                juegoTemporal.titulo = extraerContenidoEtiqueta(linea, "Titulo");
            } 
            else if (linea.find("<HorasJugadas>") != string::npos) {
                juegoTemporal.horasJugadas = stoi(extraerContenidoEtiqueta(linea, "HorasJugadas"));
            } 
            else if (linea.find("<Puntaje>") != string::npos) {
                juegoTemporal.puntajesPartidas.push_back(stoi(extraerContenidoEtiqueta(linea, "Puntaje")));
            }
        }
    }

    archivo.close();
    return listaDestino;
}
