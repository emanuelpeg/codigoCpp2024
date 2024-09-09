#include "gestor.h"
#include <algorithm>

Gestor::Gestor()
{
}

void Gestor::agregar(Empleado emp){
    this->empleados.push_back(emp);
    this->distintos[emp.getDni()]++;
    this->acumulaHs[emp.getDni()] += emp.getCantHs();
}

std::vector<Empleado> Gestor::max() {
    std::sort(this->empleados.begin(),this->empleados.end(),
              [](Empleado e, Empleado e2) -> bool {return (e.getCantHs() > e2.getCantHs()); });

    int maxHs = this->empleados[0].getCantHs();
    std::vector<Empleado> aux;
    aux.push_back(this->empleados[0]);

    for(int i = 1; i < this->empleados.size(); i++) {
        if (this->empleados[i].getCantHs() == maxHs) {
            aux.push_back(this->empleados[i]);
        } else break;
    }

    return aux;
}


std::vector<Empleado> Gestor::min() {
    std::sort(this->empleados.begin(),this->empleados.end(),
              [](Empleado e, Empleado e2) -> bool {return (e.getCantHs() < e2.getCantHs()); });

    int minHs = this->empleados[0].getCantHs();
    std::vector<Empleado> aux;
    aux.push_back(this->empleados[0]);

    for(int i = 1; i < this->empleados.size(); i++) {
        if (this->empleados[i].getCantHs() == minHs) {
            aux.push_back(this->empleados[i]);
        } else break;
    }

    return aux;
}



std::vector<Empleado> Gestor::ordenaFive() {
    std::sort(this->empleados.begin(),this->empleados.end(),
              [](Empleado e, Empleado e2) -> bool {return (e.getCantHs() > e2.getCantHs()); });

    int cant=5;
    std::vector<Empleado> aux;
    if (!this->empleados.size()>=cant)
    {
        cant = this->empleados.size();
    }
    for(int i = 0; i < cant; i++) {
        aux.push_back(this->empleados[i]);
    }
    return aux;
}

std::map<int, int> Gestor::getDistintos()
{
    return this->distintos;
}

std::map<int, int> Gestor::getAcumulaHs()
{
    return this->acumulaHs;
}
