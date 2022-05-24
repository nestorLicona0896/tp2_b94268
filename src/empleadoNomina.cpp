#include "empleadoNomina.h"

using namespace std;

EmpleadoNomina::EmpleadoNomina(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo) {
    this->idEmpleado = idEmpleadoNuevo;
    this->nombreEmpleado = nombreEmpleadoNuevo;
    this-> apellidoEmpleado = apellidoEmpleadoNuevo;
    this->emailEmpleado = emailEmpleadoNuevo;
    this->tipoEmpleado = tipoEmpleadoNuevo;
    this->idSupervisorEmpleado = idSupervisorEmpleadoNuevo;
    
}

EmpleadoNomina::EmpleadoNomina(istream *streamEmpleadoNomina) {
    this->streamEntrada = streamEmpleadoNomina;
    this->GenerarEmpleadoNomina();
}

EmpleadoNomina::~EmpleadoNomina(){
   
}


void EmpleadoNomina::GenerarEmpleadoNomina() {
    string linea;
    getline(*streamEntrada, linea);
    istringstream stream(linea);
    stream >> this->idEmpleado >> this->nombreEmpleado >> this->apellidoEmpleado >> this->emailEmpleado >> this->tipoEmpleado >> this->idSupervisorEmpleado;
}

void EmpleadoNomina::AgregarRegistroPago(RegistroPago *registro){
    this->registroPagoBruto =  registro;
}

float EmpleadoNomina::CalculoPagoNeto(){
    float pagoNeto = 0;
    float impuesto = 0.07;
    float retencion = this->ObtenerSalarioBruto() * impuesto ;
    pagoNeto = this->ObtenerSalarioBruto() - retencion;
    return pagoNeto;
}

float EmpleadoNomina::ObtenerSalarioBruto() {
    return this->registroPagoBruto->ObtenerPagoBruto();
}

RegistroPago* EmpleadoNomina::ObtenerRegistroPago(){
    return this->registroPagoBruto;
}
