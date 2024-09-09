#ifndef GESTOR_H
#define GESTOR_H
#include <vector>
#include <map>
#include "empleado.h"

class Gestor
{
private:
    std::vector<Empleado> empleados;
    std::map<int,int> distintos;

    std::map<int,int> acumulaHs;
public:
    Gestor();
    void agregar(Empleado emp);
    std::vector<Empleado> max();
    std::vector<Empleado> min();
    std::vector<Empleado> ordenaFive();

    std::map<int, int> getDistintos();
    std::map<int, int> getAcumulaHs();
};

#endif // GESTOR_H
