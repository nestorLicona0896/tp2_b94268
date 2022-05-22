#include "planilla.h"

#include <iostream>
#include <fstream>

using namespace std;

Planilla::Planilla(istream *streamEntradaPlanilla,  istream *streamEntradaNomina, istream *streamEntradaRegistroHoras){
    this->entradaPlanilla = streamEntradaPlanilla;
    this->entradaNomina = streamEntradaNomina;
    this->entradaHorasTrabajadas = streamEntradaRegistroHoras;
    this->GenerarLectura();
    this->subtotal = 0;
    this->total = 0;
    this->impuestosRetenidos = 0;
    this->totalPersonas = 0; 
    
}

Planilla::~Planilla(){
    delete this->director;
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

void Planilla::GenerarPlanilla() { // leer cada linea, generar un nodo, añadirlo al arbol
    string linea;
    int id{0};
    string nombre{};
    string apellido{};
    string correo{};
    int tipo{0};
    int idSupervisor{0};

    while(getline(*this->entradaPlanilla, linea)) {        
        istringstream stream(linea);
        istringstream stream2(linea);
        stream >> id >> nombre >> apellido >> correo >> tipo >> idSupervisor;
        
        if(tipo == 1){ // empleado de nomina
            this->AgregarEmpleadoEnNomina(&stream2);
            this->totalPersonas ++;           
        } else { // empleado por hora
            this->AgregarProfesionalPorHoras(&stream2);
            this->totalPersonas ++;
        }
    }
    this->subtotal = this->CalcularSubtotalCostoPlanilla();
    this->impuestosRetenidos = this->CalcularImpuestosRetenidos();
    this->total = this->CalcularTotalCostoPlanilla();
}

void Planilla::AsignarPadresEhijos(){
    for(int i = 0; i < this->ObtenerTotalPersonas(); i++) {
        Empleado *empleado = this->laPlanilla.at(i);
        Empleado *supervisorEmpleado = this->laPlanilla.at(empleado->ObtenerIdSupervisor()-1);
        if(this->director == 0) {
            this->director = empleado;
        } 
        empleado->AsignarSupervisor(supervisorEmpleado);
        supervisorEmpleado->AsignarEmpleado(empleado);              
    }
}

void Planilla::AgregarEmpleadoEnNomina(istream *entrada){
    EmpleadoNomina *en = new EmpleadoNomina(entrada);
    en->AgregarRegistroPago(this->laNomina->ObtenerRegistro(en->ObtenerId()));
    this->laPlanilla.insert(pair<int, Empleado*>(en->ObtenerIdSupervisor(), en));
    cout << en << endl;   
}

void Planilla::AgregarProfesionalPorHoras(istream *entrada){
    EmpleadoPorHora *eph = new EmpleadoPorHora(entrada);
    eph->AgregarRegistroHoras(this->lasHorasTrabajadas->ObtenerRegistro(eph->ObtenerId()));
    this->laPlanilla.insert(pair<int, Empleado*>(eph->ObtenerIdSupervisor(), eph));
    cout << eph << endl;
}

const int Planilla::ObtenerTotalPersonas() {
    return this->totalPersonas;
}

float Planilla::CalcularTotalCostoPlanilla(){
    float costoTotal = 0;
    costoTotal += (this->CalcularImpuestosRetenidos() + this->CalcularSubtotalCostoPlanilla());
    return costoTotal;    
}

float Planilla::CalcularSubtotalCostoPlanilla(){
    float costoSubtotal = 0;
    costoSubtotal += (this->laNomina->ObtenerTotalNomina() + this->lasHorasTrabajadas->ObtenerTotal());
    return costoSubtotal;
}

float Planilla::CalcularImpuestosRetenidos(){
    float totalImpuestos = 0;
    totalImpuestos += this->laNomina->ObtenerTotalRetencion(); 
    return totalImpuestos;
}

Empleado *Planilla::ObtenerDirector(){
    return this->director;
}

float Planilla::ObtenerSubtotal(){
    return this->subtotal;
}
        
float Planilla::ObtenerTotal(){
    return this->total;
}
        
float Planilla::ObtenerImpuestosRetenidos(){
    return this->impuestosRetenidos;
}

Nomina *Planilla::ObtenerNomina(){
    return this->laNomina;
}

HorasTrabajadas* Planilla::ObtenerRegistroHorasTrabjadas(){
    return this->lasHorasTrabajadas;
}
        
ostream& operator << (ostream &o, Planilla *unaPlanilla){    
    for(int n = 0; n < unaPlanilla->ObtenerTotalPersonas(); n++){
        Empleado *aux = unaPlanilla->laPlanilla.at(n);
        o << aux->ObtenerId() << aux->ObtenerNombre() << aux->ObtenerApellido() << aux->ObtenerSupervisor()->ObtenerNombre() << aux->ObtenerSupervisor()->ObtenerApellido() << aux->CalculoPagoNeto() << endl;
    }
    o << unaPlanilla->ObtenerSubtotal() << unaPlanilla->ObtenerImpuestosRetenidos() << unaPlanilla->ObtenerTotal() << endl;
    return o;
}