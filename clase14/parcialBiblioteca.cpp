#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
struct datosLibro{
    char nombre[200];
    char autor[200];
    int numeroIdentificacion;
};
struct datosEjemplar{
    char editorial[200];
    int anioImpresion;
    int isbn;
    int numeroIdentificacion;
};
class ejemplar{
    private:
    string editorial;
    int anioImpresion;
    int isbn;
    int numeroIdentificacion;
    public:
    ejemplar(string edi, int anio, int isbn){
        editorial = edi;
        this->isbn = isbn;
        anioImpresion = anio;
    }
    int getAnioImpresion() const{
        return anioImpresion;
    }
    int getisbn() const{
        return isbn;
    }
    void setNroIdentificacion(int nro){
        numeroIdentificacion = nro;
    }
    int getNroIdentificacion() const{
        return numeroIdentificacion;
    }
    string getEditorial() const{
        return editorial;
    }
    datosEjemplar getDatos(){
        datosEjemplar aux;
        strcpy(aux.editorial,editorial.c_str());
        aux.isbn = isbn;
        aux.anioImpresion = anioImpresion;
        aux.numeroIdentificacion = numeroIdentificacion;
        return aux;
    }

};

class Libro{
    vector<ejemplar>ejemplares;
    string nombre;
    string autor;
    int numeroIdentificacion;
    public:
    Libro(string nombre, string autor, int nroIden){
        this->nombre = nombre;
        this->autor = autor;
        numeroIdentificacion = nroIden;
    }
    void addEjemplar(ejemplar& ejem){
        ejem.setNroIdentificacion(numeroIdentificacion);
        ejemplares.push_back(ejem);
    }
    datosLibro getDatos(){
        datosLibro aux;
        strcpy(aux.nombre,nombre.c_str());
        strcpy(aux.autor,autor.c_str());
        aux.numeroIdentificacion = numeroIdentificacion;
        return aux;
    }
    int getNroIdentificacion() const{
        return numeroIdentificacion;
    }
    bool TieneVariasEditoriales(){
        if (ejemplares.size() <= 1) return false;
        string editorialAux = ejemplares[0].getEditorial();
        for (int i = 1; i < ejemplares.size(); ++i)
        {
            if (editorialAux != ejemplares[i].getEditorial()) return true;
        }
        return false;
    }
    vector<ejemplar> getEjemplares() {
        return ejemplares;
    }
    size_t getCantidadEjemplares() const{
        return ejemplares.size();
    }
    string getNombre() const{
        return nombre;
    }
    string getAutor() const{
        return autor;
    }

};

class Biblioteca{
    private:
    vector<Libro>Libros;

    public:
    void addLibro(Libro& libro2Aniadir){
        Libros.push_back(libro2Aniadir);
    }
    // Esta funcion de abajo ni siquiera la pide la actividad pero para practicar esta bien
    void guardarLibroYEjemplares(const char* direccionLibros, const char* direccionEjemplares){
        ofstream archivoLibros(direccionLibros, ios::binary);
        ofstream archivoEjemplares(direccionEjemplares, ios::binary);
        if (archivoEjemplares.fail() || archivoLibros.fail()) return;

        for (auto& libro : Libros){
            archivoLibros.write(reinterpret_cast<char*>(&libro.getDatos()),sizeof(datosLibro));
            auto ejemplares = libro.getEjemplares();
            for (ejemplar auxEjemplar : ejemplares){
                archivoEjemplares.write(reinterpret_cast<char*>(&auxEjemplar.getDatos()),sizeof(datosEjemplar));
            }
        }
        archivoLibros.close();
        archivoEjemplares.close();
    }
    /*(25) Realice una funcionalidad que dado el nombre de un libro permita saber todos sus ejemplares e imprima en un archivo de texto, todos los datos de los ejemplares.*/
    void ConsultarLibro(const char* direccion, string nombreLibro){
        ofstream archivo(direccion);
        if(archivo.fail()) return;

        auto lib = find_if(Libros.begin(), Libros.end(), [nombreLibro](Libro &libro){
            return libro.getNombre() == nombreLibro;
        });

        if(lib == Libros.end()){
            return;
        }
        auto ejemplares = lib->getEjemplares();
        archivo << "Ejemplares de " << lib->getNombre() << ": \n";
        for(auto& ejemplar : ejemplares ){
            archivo << ejemplar.getEditorial() << "   " << ejemplar.getisbn() << "   " << ejemplar.getAnioImpresion() << "\n";
        }
    }
    vector<Libro> mayorCantidadDeEjemplares(){
        vector<Libro>MasEjemplares;
        if (!Libros.size()) return MasEjemplares;
        sort(Libros.begin(),Libros.end(),[](Libro &aux1, Libro& aux2){
            return aux1.getCantidadEjemplares() > aux2.getCantidadEjemplares();
        });
        int mayor = Libros[0].getCantidadEjemplares();
        copy_if(Libros.begin(),Libros.end(),back_inserter(MasEjemplares),[mayor](Libro& aux1){
            return aux1.getCantidadEjemplares() == mayor;
        });
        return MasEjemplares;
    }

    vector<Libro> LibrosConVariasEditoriales(){
        vector<Libro>VariasEditoriales;
        copy_if(Libros.begin(),Libros.end(), back_inserter(VariasEditoriales),[](Libro aux1){
            return aux1.TieneVariasEditoriales();
        });
        return VariasEditoriales;
    }

    string EditorialConMasEjemplares(){
        map<string,int>Editoriales;
        for (auto& libro : Libros){
            vector<ejemplar>ejemplares = libro.getEjemplares();
            for_each(ejemplares.begin(),ejemplares.end(),[&Editoriales](ejemplar& aux1){
                Editoriales[aux1.getEditorial()]++;
            });
        }
        
        vector<pair<string,int>>aux(Editoriales.begin(), Editoriales.end());
        sort(aux.begin(),aux.end(),[](pair<string,int>aux1, pair<string,int>aux2){
            return aux1.second > aux2.second;
        });
        return aux[0].first;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
