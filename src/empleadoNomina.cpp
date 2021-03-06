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

EmpleadoNomina::~EmpleadoNomina(){
   
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

void EmpleadoNomina::AsignarRegistroPago(RegistroPago *rp){
    this->registroPagoBruto = rp;
}
