#ifndef SUPERVISOR_H
#define SUPERVISOR_H

#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHora.h"

#include <map>

using namespace std;

class Supervisor {

Empleado *director;
map <int, Empleado*> empleados;
istream *entradaPlanilla;
int totalEmpleados;

public:

    Supervisor(istream *entradaNueva);
    ~Supervisor();

    void GenerarLaPlanilla();
    void AgregarEmpleadoEnNomina(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo);
    void AgregarProfesionalPorHoras(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo);
    void AgregarEmpleado(istream &laEntradaNueva);
    Empleado* ObtenerSupervisor();
    Empleado* ObtenerEmpleado(int id);
    int ObtenerTotalEmpleados();

    friend istream& operator >> (istream &i, Supervisor *planillaNueva);
    friend ostream& operator << (ostream  &o, const Supervisor *planillaNueva);
    
    


};

#endif