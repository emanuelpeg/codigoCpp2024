#include "curso.h"
#include <algorithm>
#include <string.h>
#include <numeric>

char *Curso::getNombre() const
{
    return nombre;
}

void Curso::setNombre(char *newNombre)
{
    nombre = new char(strlen(newNombre));
    strcpy(nombre, newNombre);
}

void Curso::addAlumno(Alumno a)
{
    this->alumnos.push_back(a);
}


double Curso::promedioGeneral()
{
    std::vector<double> promedios;
    std::transform(this->alumnos.begin(),
                   this->alumnos.end(),
                   std::back_inserter(promedios),
            [](Alumno elem) {
                return elem.promedio();
            });
    double acu = std::reduce(promedios.begin(),
                             promedios.end(),
                                   0);

    return acu / promedios.size();
}

Curso::Curso(char *newNombre)
{
    nombre = new char(strlen(newNombre));
    strcpy(nombre, newNombre);
}
