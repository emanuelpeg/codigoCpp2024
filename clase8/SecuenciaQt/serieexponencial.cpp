#include "serieexponencial.h"
#include <ctime>
#include <cmath>
#include <cstdlib>

SerieExponencial::SerieExponencial()
{

}

void SerieExponencial::generar()
{
    int auxIndex = rand() % 10;
    for(int i = 0; i < 4; i++)
    {
        this->nros[i] = pow(auxIndex,2); auxIndex++;
    }
}
