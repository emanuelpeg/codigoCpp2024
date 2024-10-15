#ifndef CURSO_H
#define CURSO_H
#include "alumno.h"
#include <vector>

class Curso
{
private:
    char * nombre;
    std::vector<Alumno> alumnos;
public:
    Curso(char * nombre);
    char *getNombre() const;
    void setNombre(char *newNombre);
    void addAlumno(Alumno a);
    double promedioGeneral();
};

#endif // CURSO_H
