#include "alumno.h"
#include <string.h>
#include <numeric>

char *Alumno::getNombre() const
{
    return nombre;
}

void Alumno::setNombre(char *newNombre)
{
    nombre = new char(strlen(newNombre));
    strcpy(nombre, newNombre);
}

double Alumno::promedio()
{
    int sum = std::reduce(this->notas.begin(),
                          this->notas.end(),
                          0);
    return ((double)sum) / this->notas.size();
}

void Alumno::addNota(int nota)
{
    this->notas.push_back(nota);
}

Alumno::Alumno(char *newNombre)
{
    nombre = new char(strlen(newNombre));
    strcpy(nombre, newNombre);
}
