#include "empleadoPorHora.h"

using namespace std;

EmpleadoPorHora::EmpleadoPorHora(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo) {
    
    this->idEmpleado = idEmpleadoNuevo;
    this->nombreEmpleado = nombreEmpleadoNuevo;
    this-> apellidoEmpleado = apellidoEmpleadoNuevo;
    this->emailEmpleado = emailEmpleadoNuevo;
    this->tipoEmpleado = tipoEmpleadoNuevo;
    this->idSupervisorEmpleado = idSupervisorEmpleadoNuevo;     
}

EmpleadoPorHora::~EmpleadoPorHora()
{
   
}

void EmpleadoPorHora::AgregarRegistroHoras(RegistroHora *regis)
{
    this->registroHoras = regis;
}

int EmpleadoPorHora::ObtenerHorasAcumuladas()
{
    return this->registroHoras->ObtenerHorasAcumuladas();
}

float EmpleadoPorHora::ObtenerCostoPorHora()
{
    return this->registroHoras->ObtenerMontoPorHora();
}

float EmpleadoPorHora::CalculoPagoNeto()
{
    float pagoNeto = 0;
    pagoNeto = this->ObtenerHorasAcumuladas() * this->ObtenerCostoPorHora();
    return pagoNeto;
}

RegistroHora *EmpleadoPorHora::ObtenerRegistroHorasEnMes()
{
    return this->registroHoras;
}

void EmpleadoPorHora::AgregarRegistroHorasEnMes(RegistroHora  *nuevoRegistro) {
    this->registroHoras = nuevoRegistro;
}