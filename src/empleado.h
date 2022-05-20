#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <sstream>

using namespace std;

class Empleado
{
    int idEmpleado;
    string nombreEmpleado;
    string apellidoEmpleado;
    string emailEmpleado;
    int tipoEmpleado;
    int idSupervisorEmpleado;

public:
    Empleado();
    Empleado(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo, int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo);
    ~Empleado();

    friend istream &operator>>(istream &i, Empleado *empleado);
    friend ostream &operator<<(ostream &o, const Empleado *empleado);
};

#endif