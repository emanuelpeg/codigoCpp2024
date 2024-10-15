#ifndef ALUMNO_H
#define ALUMNO_H
#include <vector>

class Alumno
{
private:
    char * nombre;
    std::vector<int> notas;
public:
    Alumno(char * nombre);
    char *getNombre() const;
    void setNombre(char *newNombre);
    double promedio();
    void addNota(int nota);
};

#endif // ALUMNO_H
