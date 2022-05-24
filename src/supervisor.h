#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHora.h"

#include <map>

using namespace std;

class Supervisor {

Empleado *director;
map <int,Empleado*> empleados;
istream *entradaPlanilla;
int totalEmpleados;

public:

    Supervisor(istream *entradaNueva);
    ~Supervisor();

    void GenerarLaPlanilla();
    void AgregarEmpleadoEnNomina(istream *entrada);
    void AgregarProfesionalPorHoras(istream *entrada);
    void AgregarEmpleado(istream &laEntradaNueva);
    Empleado* ObtenerSupervisor();
    Empleado* ObtenerEmpleado(int id);
    int ObtenerTotalEmpleados();

    // sobrecargas a los operadores para a la hora de añadir una catalogo apartir de informacion proveniente de datos stream
    friend istream& operator >> (istream &i, Supervisor *planillaNueva);
    friend ostream& operator << (ostream  &o, const Supervisor *planillaNueva);
    
    


};

#endif