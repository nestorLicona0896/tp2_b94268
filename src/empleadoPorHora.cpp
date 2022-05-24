#include "empleadoPorHora.h"

using namespace std;

EmpleadoPorHora::EmpleadoPorHora(istream *streamEmpleadoPorHora)
{
    this->streamEntrada = streamEmpleadoPorHora;
    GenerarEmpleadoPorHora();
}

EmpleadoPorHora::~EmpleadoPorHora()
{
   
}

void EmpleadoPorHora::GenerarEmpleadoPorHora(){
    string linea;
    getline(*streamEntrada, linea);
    istringstream stream(linea);
    stream >> this->idEmpleado >> this->nombreEmpleado >> this->apellidoEmpleado >> this->emailEmpleado >> this->tipoEmpleado >> this->idSupervisorEmpleado;

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