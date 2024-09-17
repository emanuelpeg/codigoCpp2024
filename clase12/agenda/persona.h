#ifndef PERSONA_H
#define PERSONA_H
#include "contacto.h"
#include <vector>

class Persona
{
private:
    char * nombre;
    char * dir;
    std::vector<Contacto> contactos;
public:
    Persona(char * nombre);

    char *getNombre() const;
    void setNombre(char *newNombre);
    char *getDir() const;
    void setDir(char *newDir);
    std::vector<Contacto> getContactos();
    void addContacto(Contacto c);
    void setContactos(const std::vector<Contacto> &newContactos);
};

#endif // PERSONA_H
