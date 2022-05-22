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
    
    Nomina *laNomina; // lista de registros para los empleados por nomina
    HorasTrabajadas *lasHorasTrabajadas;   // lista de registro para los empleados cnontratados por hora
    map<int, Empleado*> laPlanilla; //(idSupervisor, empleado?) estructura de arbol
    
    float subtotal; // total en salario bruto a cancelar    
    float impuestosRetenidos; // la suma de impuestos retenidos
    float total; // subtotal + impuestos

    int totalPersonas;

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
        void AsignarPadresEhijos();

        const int ObtenerTotalPersonas(); 

        friend ostream& operator << (ostream &o, Planilla *unaPlanilla);
        

};

#endif