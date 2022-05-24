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
        if(this->ObtenerSupervisor() == 0) {
            this->director = new EmpleadoNomina(&stream);
            this->empleados.insert(pair<int, Empleado*>(this->director->ObtenerId(), this->director)); 
        } else {
            this->AgregarEmpleado(stream);  
        }
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
    string linea;
    getline(elEmpleado, linea);
    istringstream stream(linea);
    elEmpleado >> id >> nombre >> apellido >> correo >> tipo >> idSupervisor;
    //cout << id << nombre << apellido << correo << tipo << idSupervisor;
    if(tipo == 1) { // empleado de nomina
            this->AgregarEmpleadoEnNomina(&stream);           
    } else { // empleado por hora
            this->AgregarProfesionalPorHoras(&stream);
    }    
}

void Supervisor::AgregarEmpleadoEnNomina(istream *entrada){
    EmpleadoNomina *en = new EmpleadoNomina(entrada);
    Empleado *supervisor = this->empleados.at(en->ObtenerIdSupervisor());
    // agregar empleado
    en->AsignarSupervisor(supervisor);
    supervisor->AsignarEmpleado(en);
    this->empleados.insert(pair<int, Empleado*>(en->ObtenerIdSupervisor(), en));
    cout << en << endl; 
}

void Supervisor::AgregarProfesionalPorHoras(istream *entrada){   
    EmpleadoPorHora *eph = new EmpleadoPorHora(entrada);

    // agregar empleado
    cout << eph << endl;   
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