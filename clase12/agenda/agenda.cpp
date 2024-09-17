#include "agenda.h"
#include <fstream>
#include <string.h>
#include <stdio.h>

const std::vector<Persona> &Agenda::getPersonas() const
{
    return personas;
}

Agenda::Agenda()
{

}

void Agenda::leer()
{
    this->personas.clear();
    std::vector<Contacto> contactos;

    std::ifstream archiContacto("contacto.dat",
                        std::ios::binary | std::ios::app);
    if (archiContacto.is_open()) {
        strContacto c;
        while (archiContacto.read((char*)&c, sizeof(strContacto))) {
            Contacto unContacto(c.tipo, c.valor);
            unContacto.setId_persona(c.id_persona);
            contactos.push_back(unContacto);
        }
        archiContacto.close();
    }

    std::ifstream archi("persona.dat",
                        std::ios::binary | std::ios::app);
    if (archi.is_open()) {
        strPersona p;
        while(archi.read((char *)&p, sizeof(strPersona))) {
            Persona unaPersona(p.nombre);
            unaPersona.setDir(p.dir);
            for (int i = 0; i < contactos.size(); i++) {
                if (p.id == contactos[i].getId_persona()) {
                    unaPersona.addContacto(contactos[i]);
                }
            }
            this->personas.push_back(unaPersona);
        }
        archi.close();
    }
}

bool Agenda::add(Persona persona)
{
    this->personas.push_back(persona);
    std::ofstream archi("persona.dat",
                        std::ios::binary | std::ios::app);
    if (archi.is_open()) {
        strPersona p;
        p.id = this->personas.size();
        strcpy(p.nombre, persona.getNombre());
        strcpy(p.dir, persona.getDir());
        archi.write((char*)&p, sizeof(strPersona));
        archi.close();

        std::ofstream archiContacto("contacto.dat",
                            std::ios::binary | std::ios::app);
        if (archiContacto.is_open()) {
            for(size_t i = 0; i < persona.getContactos().size(); i++) {
                strContacto c;
                c.id_persona = p.id;
                strcpy(c.tipo, persona.getContactos()[i].getTipo());
                strcpy(c.valor, persona.getContactos()[i].getValor());
                archiContacto.write((char*)&c, sizeof(strContacto));
            }
            archiContacto.close();
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Agenda::generarDatosDeEjemplo()
{
    Persona juan("juan");
    juan.setDir("dir de juan");
    Contacto contactoJuanEmail("email", "juan@algo");
    Contacto contactoJuanTel("tel", "12321236565465");
    juan.addContacto(contactoJuanEmail);
    juan.addContacto(contactoJuanTel);
    this->add(juan);

    Persona nico("Nico");
    nico.setDir("dir de nico");
    Contacto contactoNicoEmail("email", "nico@algo");
    Contacto contactoNicoTel("tel", "6565465");
    nico.addContacto(contactoNicoEmail);
    nico.addContacto(contactoNicoTel);
    this->add(nico);
}

std::vector<Persona> Agenda::filtrar(char *nombre)
{
    std::vector<Persona> aux;
    for (int i = 0; i < this->personas.size(); i++) {
        auto p = this->personas[i];
        int len = strlen(nombre);
        if (strncmp(p.getNombre(), nombre, len) == 0) {
            aux.push_back(p);
        }
    }
    return aux;
}
