#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>

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
        
    Nomina *laNomina; // registros para los empleados por nomina
    HorasTrabajadas *lasHorasTrabajadas;   // registro para los empleados contratados por hora
    

    // arbol
    map <int, Empleado*> arbolEmpleados;
    int totalPersonal;


     
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

        float ObtenerSubtotal();
        float ObtenerTotal();
        float ObtenerImpuestosRetenidos();
        int ObtenerTotalPersonal();

        void AgregarEmpleado(int idEmpleadoNuevo, string nombreEmpleadoNuevo, string apellidoEmpleadoNuevo, string emailEmpleadoNuevo,  int tipoEmpleadoNuevo, int idSupervisorEmpleadoNuevo);
        
        map <int, Empleado*> ObtenerMapa();
        friend ostream &operator << (ostream &o, Planilla *laPlanilla);       

};

#endif