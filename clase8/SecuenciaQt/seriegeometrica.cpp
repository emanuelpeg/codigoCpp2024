#include "seriegeometrica.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

SerieGeometrica::SerieGeometrica()
{

}

void SerieGeometrica::generar()
{
    srand(time(0));
    int razon = 2;
    int semilla = rand()%10;
    for(int i = 0; i < 4; i++) this->nros[i] = semilla * pow(razon,i);
}
