#include "empleadoPorHora.h"

using namespace std;

EmpleadoPorHora::EmpleadoPorHora(istream *streamEmpleadoPorHora)
{
    this->streamEntrada = streamEmpleadoPorHora;
    string linea;
    getline(*streamEntrada, linea);
    istringstream stream(linea);
    stream >> this->idEmpleado >> this->nombreEmpleado >> this->apellidoEmpleado >> this->emailEmpleado >> this->tipoEmpleado >> this->idSupervisorEmpleado;
}

EmpleadoPorHora::~EmpleadoPorHora()
{
    for (Empleado *e : this->lista)
    {
        delete e;
    }
}

istream &operator>>(istream &i, EmpleadoPorHora *empleado)
{
    i >> empleado->idEmpleado >> empleado->nombreEmpleado >> empleado->apellidoEmpleado >> empleado->emailEmpleado >> empleado->tipoEmpleado >> empleado->idSupervisorEmpleado;
    return i;
}

ostream &operator<<(ostream &o, const EmpleadoPorHora *empleado)
{
    o << ", " << empleado->idEmpleado << ", " << empleado->nombreEmpleado << ", " << empleado->apellidoEmpleado << ", " << empleado->emailEmpleado << ", " << empleado->tipoEmpleado << ", " << empleado->idSupervisorEmpleado;
    return o;
}

void EmpleadoPorHora::AgregarRegistroHoras(RegistroHora *registroHoras)
{
    this->registroHoras = registroHoras;
}

int EmpleadoPorHora::ObtenerHorasAcumuladas()
{
    return this->registroHoras->ObtenerHorasAcumuladas();
}

float EmpleadoPorHora::ObtenerCostoPorHora()
{
    return this->registroHoras->ObtenerMontoPorHora();
}

float EmpleadoPorHora::calculoPagoNeto()
{
    float pagoNeto = 0;
    pagoNeto = this->ObtenerHorasAcumuladas() * this->ObtenerCostoPorHora();
    return pagoNeto;
}

RegistroHora *EmpleadoPorHora::ObtenerRegistroHoras()
{
    return this->registroHoras;
}