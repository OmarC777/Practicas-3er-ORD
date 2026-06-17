#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <vector>

class Alumno {
public:
    std::string nombre;
    int edad;
    std::vector<int> calificaciones; 
    Alumno();
    Alumno(std::string n, int e, std::vector<int> c);
    void mostrar() const;
};

void guardarEnCSV(const std::string& nombreArchivo, const std::vector<Alumno>& listaAlumnos);
std::vector<Alumno> leerDesdeCSV(const std::string& nombreArchivo);

#endif


