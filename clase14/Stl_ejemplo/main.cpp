#include <iostream>
#include "alumno.h"
#include "curso.h"

using namespace std;

int main()
{
    Alumno unAlumno("Juan");
    unAlumno.addNota(65);
    unAlumno.addNota(88);
    unAlumno.addNota(85);

    Alumno otroAlumno("Pedro");
    otroAlumno.addNota(64);
    otroAlumno.addNota(56);
    otroAlumno.addNota(85);

    Curso cpp("curso c++");
    cpp.addAlumno(unAlumno);
    cpp.addAlumno(otroAlumno);

    cout << "Promedio general :" << cpp.promedioGeneral() << endl;

    return 0;
}
