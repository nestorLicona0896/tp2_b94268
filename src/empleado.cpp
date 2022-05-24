#include "empleado.h"

using namespace std;

Empleado::~Empleado()
{
    for (Empleado *e : this->lista)
    {
        delete e;
    }
}

vector<Empleado *> Empleado::ObtenerEmpleados()
{
    return this->lista;
}

int Empleado::ObtenerId()
{
    return this->idEmpleado;
}

string Empleado::ObtenerNombre()
{
    return this->nombreEmpleado;
}

string Empleado::ObtenerApellido()
{
    return this->apellidoEmpleado;
}

string Empleado::ObtenerCorreo()
{
    return this->emailEmpleado;
}

int Empleado::ObtenerTipoEmpleado()
{
    return this->tipoEmpleado;
}

int Empleado::ObtenerIdSupervisor()
{
    return this->idSupervisorEmpleado;
}

Empleado *Empleado::ObtenerSupervisor()
{
    return this->supervisor;
}

void Empleado::AsignarSupervisor(Empleado *supervisorAsignado)
{
    this->supervisor = supervisorAsignado;
}

void Empleado::AsignarEmpleado(Empleado *empleadoAsignado)
{
    this->lista.push_back(empleadoAsignado);
}

istream &operator>>(istream &i, Empleado *emp)
{
    i >> emp->idEmpleado >> emp->nombreEmpleado >> emp->apellidoEmpleado >> emp->emailEmpleado >> emp->tipoEmpleado >> emp->idSupervisorEmpleado;
    return i;
}

ostream &operator<<(ostream &o, Empleado *emp)
{
    o << emp->idEmpleado << ", " << emp->nombreEmpleado << ", " << emp->apellidoEmpleado << ", " << emp->emailEmpleado << ", " << emp->tipoEmpleado << ", " << emp->idSupervisorEmpleado;
    return o;
}
