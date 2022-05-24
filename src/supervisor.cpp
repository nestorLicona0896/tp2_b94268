#include "supervisor.h"

using namespace std;

Supervisor::Supervisor(istream *laEntrada) {
    this->entradaPlanilla = laEntrada;
    this->GenerarLaPlanilla();
    this->totalEmpleados = 0;
}

Supervisor::~Supervisor(){
    delete this->director;
}

void Supervisor::GenerarLaPlanilla() {
    string linea;
    while(getline(*this->entradaPlanilla, linea)) {
        istringstream stream(linea);
        this->AgregarEmpleado(stream);  
        this->totalEmpleados ++;
    }
}

void Supervisor::AgregarEmpleado(istream &elEmpleado) {
    int id{0};
    string nombre{};
    string apellido{};
    string correo{};
    int tipo{0};
    int idSupervisor{0};
    elEmpleado >> id >> nombre >> apellido >> correo >> tipo >> idSupervisor;
    if(tipo == 1) { // empleado de nomina
            this->AgregarEmpleadoEnNomina(id, nombre, apellido, correo, tipo, idSupervisor);           
    } else { // empleado por hora
            this->AgregarProfesionalPorHoras(id, nombre, apellido, correo, tipo, idSupervisor);
    }    
}

void Supervisor::AgregarEmpleadoEnNomina(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo){
    EmpleadoNomina *en = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    this->empleados.insert(pair<int, Empleado*>(en->ObtenerIdSupervisor(), en));
    this->empleados.at(en->ObtenerIdSupervisor())->AsignarEmpleado(en);
    en->AsignarSupervisor(this->empleados.at(en->ObtenerIdSupervisor()));
    //cout << en->ObtenerSupervisor() << endl; 
}

void Supervisor::AgregarProfesionalPorHoras(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo){   
    EmpleadoPorHora *eph = new EmpleadoPorHora(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    this->empleados.insert(pair<int, Empleado*>(eph->ObtenerIdSupervisor(), eph));
    this->empleados.at(eph->ObtenerIdSupervisor())->AsignarEmpleado(eph);
    eph->AsignarSupervisor(this->empleados.at(eph->ObtenerIdSupervisor()));
    //cout << eph->ObtenerSupervisor() << endl;   
}

Empleado *Supervisor::ObtenerEmpleado(int id) {
    return 0;
}

Empleado *Supervisor::ObtenerSupervisor() {
    return this->director;
}

int Supervisor::ObtenerTotalEmpleados() {
    return this->totalEmpleados;
}