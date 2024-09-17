#ifndef AGENDA_H
#define AGENDA_H
#include <vector>
#include "persona.h"

struct strPersona
{
    int id;
    char nombre[100];
    char dir[150];
};

struct strContacto
{
  int id_persona;
  char tipo[100];
  char valor[150];
};

class Agenda
{
private:
    std::vector<Persona> personas;

public:
    Agenda();
    void leer();
    bool add(Persona persona);
    void generarDatosDeEjemplo();
    std::vector<Persona> filtrar(char * nombre);
    const std::vector<Persona> &getPersonas() const;
};

#endif // AGENDA_H
