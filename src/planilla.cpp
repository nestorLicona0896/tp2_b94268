#include "planilla.h"

#include <iostream>
#include <fstream>

using namespace std;

Planilla::Planilla(istream *streamEntradaPlanilla,  istream *streamEntradaNomina, istream *streamEntradaRegistroHoras){
    this->entradaPlanilla = streamEntradaPlanilla;
    this->entradaNomina = streamEntradaNomina;
    this->entradaHorasTrabajadas = streamEntradaRegistroHoras;
    this->subtotal = 0;
    this->total = 0;
    this->impuestosRetenidos = 0;
    this->GenerarLectura();
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

void Planilla::GenerarPlanilla() { // leer cada linea, generar un nodo, añadirlo al arbol
    this->laPlanilla = new Supervisor(this->entradaPlanilla); 

    //recorrer cada vector de registros y asignarlos mediante el id a los empleados del arbol mapeados  
    
    //this->subtotal = this->CalcularSubtotalCostoPlanilla();
    //this->impuestosRetenidos = this->CalcularImpuestosRetenidos();
    //this->total = this->CalcularTotalCostoPlanilla();
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
    return this->laPlanilla->ObtenerSupervisor();
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
  /*for(int n = 1; n < unaPlanilla->ObtenerTotalPersonas()-1; n++){
        for(Empleado* emp1 : unaPlanilla->laPlanilla.at(n)->ObtenerEmpleados()){
            o << emp1->ObtenerId() << ", " << emp1->ObtenerNombre() << ", " << emp1->ObtenerApellido() << ", " << emp1->ObtenerSupervisor()->ObtenerNombre() << ", " << emp1->ObtenerSupervisor()->ObtenerApellido() << ", " << emp1->CalculoPagoNeto() << endl;
        }
    }*/
    return o;
}