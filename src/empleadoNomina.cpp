#include "empleadoNomina.h"

using namespace std;

EmpleadoNomina::EmpleadoNomina(istream *streamEmpleadoNomina) {
    this->streamEntrada = streamEmpleadoNomina;
    this->GenerarEmpleadoNomina();
}

EmpleadoNomina::~EmpleadoNomina(){
    for(Empleado *e : this->lista) {
        delete e;
    }
}

istream& operator >> (istream &i, EmpleadoNomina *empleado){
    i >> empleado->idEmpleado >> empleado->nombreEmpleado >> empleado->apellidoEmpleado >> empleado->emailEmpleado >> empleado->tipoEmpleado >> empleado->idSupervisorEmpleado;
    return i;
}

ostream& operator << (ostream &o, const EmpleadoNomina *empleado){
    o << empleado->idEmpleado << ", " << empleado->nombreEmpleado << ", " << empleado->apellidoEmpleado << ", " << empleado->emailEmpleado << ", " << empleado->tipoEmpleado << ", " << empleado->idSupervisorEmpleado;
    return o;
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
