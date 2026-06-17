#include "Alumno.h"
#include <iostream>
#include <fstream>
#include <sstream>

Alumno::Alumno() : nombre(""), edad(0) {}
Alumno::Alumno(std::string n, int e, std::vector<int> c) : nombre(n), edad(e), calificaciones(c) {}

void Alumno::mostrar() const {
    std::cout << "Nombre: " << nombre << " | Edad: " << edad << " | Calificaciones: [";
    for (size_t i = 0; i < calificaciones.size(); ++i) {
        std::cout << calificaciones[i] << (i == calificaciones.size() - 1 ? "" : ", ");
    }
    std::cout << "]\n";
}

void guardarEnCSV(const std::string& nombreArchivo, const std::vector<Alumno>& listaAlumnos) {
    std::ofstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para escribir.\n";
        return;
    }

    archivo << "Nombre,Edad,Calificaciones\n";

    for (const auto& alumno : listaAlumnos) {
        archivo << alumno.nombre << "," << alumno.edad << ",";
        
        for (size_t i = 0; i < alumno.calificaciones.size(); ++i) {
            archivo << alumno.calificaciones[i];
            if (i < alumno.calificaciones.size() - 1) {
                archivo << ";"; 
            }
        }
        archivo << "\n"; 
    }

    archivo.close();
    std::cout << "Datos guardados exitosamente en " << nombreArchivo << "\n";
}

std::vector<Alumno> leerDesdeCSV(const std::string& nombreArchivo) {
    std::vector<Alumno> listaDestino;
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para leer.\n";
        return listaDestino;
    }

    std::string linea;
    std::getline(archivo, linea);

    while (std::getline(archivo, linea)) {
        if (linea.empty()) continue; 

        std::stringstream ss(linea);
        std::string campoNombre;
        std::string campoEdad;
        std::string campoCalificaciones;

        std::getline(ss, campoNombre, ',');
        std::getline(ss, campoEdad, ',');
        std::getline(ss, campoCalificaciones, ',');

        int edad = std::stoi(campoEdad);

        std::vector<int> notas;
        std::stringstream ssNotas(campoCalificaciones);
        std::string notaIndividual;
        
        while (std::getline(ssNotas, notaIndividual, ';')) {
            if (!notaIndividual.empty()) {
                notas.push_back(std::stoi(notaIndividual));
            }
        }

        listaDestino.push_back(Alumno(campoNombre, edad, notas));
    }

    archivo.close();
    return listaDestino;
}
