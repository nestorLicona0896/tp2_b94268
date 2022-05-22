#include "empleado.h"

using namespace std;

Empleado::~Empleado(){
    /*for (Empleado *e : this->lista) {
        delete e;
    }*/
}

vector <Empleado*> Empleado::ObtenerEmpleados(){
    return this->lista;
}

int Empleado::ObtenerId() {
    return this->idEmpleado;
}

string Empleado::ObtenerNombre() {
    return this->nombreEmpleado;
}

string Empleado::ObtenerApellido() {
    return this->apellidoEmpleado;
}

string Empleado::ObtenerCorreo() {
    return this->emailEmpleado;
}

int Empleado::ObtenerTipoEmpleado(){
    return this->tipoEmpleado;
}

int Empleado::ObtenerIdSupervisor() {
    return this->idSupervisorEmpleado;
}

Empleado* Empleado::ObtenerSupervisor() {
    return this->supervisor;
}

void Empleado::aignarSupervisor(Empleado *supervisorAsignado){
    this->supervisor = supervisorAsignado;
}

void Empleado::aignarEmpleado(Empleado *empleadoAsignado){
    this->lista.push_back(empleadoAsignado);
}  
