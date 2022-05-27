#include "planilla.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Planilla::Planilla(istream *streamEntradaPlanilla,  istream *streamEntradaNomina, istream *streamEntradaRegistroHoras){
    this->totalPersonal = 0;
    this->entradaPlanilla = streamEntradaPlanilla;
    this->entradaNomina = streamEntradaNomina;
    this->entradaHorasTrabajadas = streamEntradaRegistroHoras;   
    this->GenerarLectura();
    this->subtotal = this->CalcularSubtotalCostoPlanilla();
    this->impuestosRetenidos = this->CalcularImpuestosRetenidos();
    this->total = this->CalcularTotalCostoPlanilla();
}

Planilla::~Planilla(){
    
}

void Planilla::GenerarLectura(){ 
    this->GenerarNomina();  
    this->GenerarHorasTrabajadas();  
    this->GenerarPlanilla();    
}

void Planilla::GenerarNomina() {
    this->laNomina = new Nomina(this->entradaNomina);
}

void Planilla::GenerarHorasTrabajadas() {
    this->lasHorasTrabajadas = new HorasTrabajadas(this->entradaHorasTrabajadas);
}

void Planilla::GenerarPlanilla() { // leer cada linea, generar un nodo, añadirlo al arbol, generar el costo de la planilla
    string linea;
    int id{0};
    string nombre{};
    string apellido{};
    string correo{};
    int tipo{0};
    int idSupervisor{0};
    
    while(getline(*this->entradaPlanilla, linea)) {
        istringstream stream(linea);
        stream >> id >> nombre >> apellido >> correo >> tipo >> idSupervisor;
        this->AgregarEmpleado(id, nombre, apellido, correo,  tipo, idSupervisor);  
        this->totalPersonal ++;
    }     
}

void Planilla::AgregarEmpleado(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo){
    
    if(tipoEmpleadoNuevo == 1) { // empleado de nomina        
        EmpleadoNomina *en = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
        en->AsignarRegistroPago(this->laNomina->ObtenerRegistro(en->ObtenerId()));
        this->arbolEmpleados.insert(pair<int, Empleado*>(en->ObtenerId(), en));
        en->AsignarSupervisor(this->arbolEmpleados.at(en->ObtenerIdSupervisor()));
        this->arbolEmpleados.at(en->ObtenerIdSupervisor())->AsignarEmpleado(en);
        this->arbolEmpleados.insert(pair<int, Empleado*>(en->ObtenerIdSupervisor(), en));     
        //cout << en->ObtenerRegistroPago()  << endl;               
    
    } else { // empleado por hora
        EmpleadoPorHora *eph = new EmpleadoPorHora(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
        eph->AgregarRegistroHorasEnMes(this->lasHorasTrabajadas->ObtenerRegistroHoras(eph->ObtenerId()));
        this->arbolEmpleados.insert(pair<int, Empleado*>(eph->ObtenerId(), eph));
        eph->AsignarSupervisor(this->arbolEmpleados.at(eph->ObtenerIdSupervisor()));
        this->arbolEmpleados.at(eph->ObtenerIdSupervisor())->AsignarEmpleado(eph);
        this->arbolEmpleados.insert(pair<int, Empleado*>(eph->ObtenerIdSupervisor(), eph));     
        //cout << eph->ObtenerRegistroHorasEnMes() << endl;        
    }     
}  

float Planilla::CalcularTotalCostoPlanilla(){
    float costoTotal = 0;
    costoTotal += this->ObtenerSubtotal() + this->ObtenerImpuestosRetenidos();
    return costoTotal;    
}

float Planilla::CalcularSubtotalCostoPlanilla(){
    float costoSubtotal = 0;     
    costoSubtotal = this->laNomina->ObtenerTotalCostoNomina() + this->lasHorasTrabajadas->ObtenerTotalCostoHoras();   
    return costoSubtotal;
}

float Planilla::CalcularImpuestosRetenidos(){
    float totalImpuestos = 0;
    totalImpuestos = this->laNomina->ObtenerTotalRetencionImpuestos(); 
    return totalImpuestos;
}

float  Planilla::ObtenerSubtotal(){
    return this->subtotal;
}
        
float  Planilla::ObtenerTotal(){
    return this->total;
}
        
float Planilla::ObtenerImpuestosRetenidos(){
    return this->impuestosRetenidos;
}

int Planilla::ObtenerTotalPersonal() {
    return this->totalPersonal;
}

        
ostream &operator << (ostream &o, Planilla *unaPlanilla) {  

    for(int n = 1; n <= unaPlanilla->ObtenerTotalPersonal(); n++) {

       o << unaPlanilla->ObtenerMapa().at(n)->ObtenerId() << ", " << unaPlanilla->ObtenerMapa().at(n)->ObtenerNombre() << " " << unaPlanilla->ObtenerMapa().at(n)->ObtenerApellido() << ", Supervisor: " << unaPlanilla->ObtenerMapa().at(n)->ObtenerSupervisor()->ObtenerNombre() << " " << unaPlanilla->ObtenerMapa().at(n)->ObtenerSupervisor()->ObtenerApellido() << ", " << unaPlanilla->ObtenerMapa().at(n)->CalculoPagoNeto() << endl; 
    }

    o << "subtotal: " << setprecision(10) << unaPlanilla->ObtenerSubtotal() << ", impuesto retenido: " << unaPlanilla->ObtenerImpuestosRetenidos() << ", total por costo de planilla: " << unaPlanilla->ObtenerTotal() << endl;
    return o;
}

 map <int, Empleado*> Planilla::ObtenerMapa() {
     return this->arbolEmpleados;
 }