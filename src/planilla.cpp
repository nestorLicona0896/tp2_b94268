#include "planilla.h"


#include <iostream>

using namespace std;

Planilla::Planilla(istream *streamEntradaPlanilla,  istream *streamEntradaNomina, istream *streamEntradaRegistroHoras){
    this->entradaPlanilla = streamEntradaPlanilla;
    this->entradaNomina = streamEntradaNomina;
    this->entradaHorasTrabajadas = streamEntradaRegistroHoras;
    this->GenerarLectura();
    this->subtotal = 0;
    this->total = 0;
    this->impuestosRetenidos = 0;
}

Planilla::~Planilla(){
    delete this->director;
}

void Planilla::GenerarLectura(){
    this->GenerarPlanilla();
    this->GenerarNomina();
    this->GenerarHorasTrabajadas();
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
    while(getline(*this->entradaPlanilla, linea)){
        istringstream stream(linea);
        stream >> id >> nombre >> apellido >> correo >> tipo >> idSupervisor;
        if(tipo == 1){ // empleado de nomina
            EmpleadoNomina *en = new EmpleadoNomina(&stream);
        } else { // empleado por hora
            //EmpleadoPorHora *eph = new EmpleadoPorHora(&stream);
        }
    }
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
        