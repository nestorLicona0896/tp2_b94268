#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include <vector>

#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHora.h"
#include "horasTrabajadas.h"
#include "nomina.h"

using namespace std;

class Planilla { // CostoPlanilla
   
    istream *entradaPlanilla; // personas.txt
    istream *entradaHorasTrabajadas; //horastrabajadas.txt
    istream *entradaNomina; //nomina.txt
   
    Empleado *director; // raiz
    
    //(-1)
    Nomina *laNomina; // lista de registros para los empleados por nomina
    HorasTrabajadas *lasHorasTrabajadas;   // lista de registro para los empleados cnontratados por hora
    map<int, Empleado*> laPlanilla; //(idEmpledo, empleado supervisor de otro empleado xD*) estructura de arbol
    
    float subtotal; // total en salario bruto a cancelar    
    float impuestosRetenidos; // la suma de impuestos retenidos
    float total; // subtotal + impuestos

    public :

        Planilla(istream *streamPlanilla,  istream *streamNomina, istream *streamRegistroHoras);
        ~Planilla();

        void AgragarEmpleado(Empleado *empleado);
        Empleado *ObtenerEmpleado(int idEmpleado);
        
        void GenerarLectura();

        void EscribirArchivo();

        void GenerarPlanilla();
        void GenerarNomina();
        void GenerarHorasTrabajadas();
       
        float CalcularTotalCostoPlanilla();
        float CalcularSubtotalCostoPlanilla();
        float CalcularImpuestosRetenidos();

        Empleado *ObtenerDirector();
        float ObtenerSubtotal();
        float ObtenerTotal();
        float ObtenerImpuestosRetenidos();

        Nomina *ObtenerNomina();
        HorasTrabajadas* ObtenerRegistroHorasTrabjadas();
        


};

#endif