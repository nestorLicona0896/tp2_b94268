#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include <vector>

#include "supervisor.h"
#include "horasTrabajadas.h"
#include "nomina.h"

using namespace std;

class Planilla { // CostoPlanilla
   
    istream *entradaPlanilla; // personas.txt
    istream *entradaHorasTrabajadas; //horastrabajadas.txt
    istream *entradaNomina; //nomina.txt
        
    Nomina *laNomina; // registros para los empleados por nomina
    HorasTrabajadas *lasHorasTrabajadas;   // registro para los empleados contratados por hora
    Supervisor *laPlanilla; // arbol
     
    float subtotal; // total en salario bruto a cancelar    
    float impuestosRetenidos; // la suma de impuestos retenidos
    float total; // subtotal + impuestos

    public :

        Planilla(istream *streamPlanilla,  istream *streamNomina, istream *streamRegistroHoras);
        ~Planilla();

        void AgragarEmpleado(Empleado *empleado);
        Empleado *ObtenerEmpleado(int idEmpleado);
        
        void GenerarLectura();

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

        void AgregarEmpleadoEnNomina(istream *entrada);
        void AgregarProfesionalPorHoras(istream *entrada);
        void AgregarAplanilla(Empleado *emp);

        friend ostream& operator << (ostream &o, Planilla *unaPlanilla);       

};

#endif