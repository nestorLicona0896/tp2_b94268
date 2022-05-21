#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include <vector>
#include "empleado.h"
#include "horasTrabajadas.h"
#include "nomina.h"

using namespace std;

class Planilla { // CostoPlanilla
   
    istream *entradaPlanilla; // personas.txt
    istream *entradaHorasTrabajadas; //horastrabajadas.txt
    istream *entradaNomina; //nomina.txt
   
    Empleado *director; // raiz
    
    //(-1)
    vector <Nomina> *laNomina; // lista de registros para los empleados por nomina
    vector <HorasTrabajadas> *lasHorasTrabajadas;   // lista de registro para los empleados cnontratados por hora
    map<int, Empleado*> laPlanilla; //(idEmpledo, empleado supervisor de otro empleado xD*) estructura de arbol
    
    float subtotal; // total en salario bruto a cancelar    
    float impuestosRetenidos; // la suma de impuestos retenidos
    float total; // subtotal + impuestos

    public :

        Planilla(istream *streamPlanilla,  istream *streamNomina, istream *streamRegistroHoras);
        ~Planilla();

        void AgragarEmpleado(Empleado *empleado);
        Empleado *ObtenerEmpleado(int idEmpleado);

        friend istream &operator>>(istream &i, Planilla *planilla);
        friend ostream &operator<<(ostream &o, const Planilla *planilla);

        void EscribirArchivo();

        void GenerarPlanilla();
        void GenerarNomina();
        void GenerarHorasTrabajadas();
       
        float CalcularTotalCostoPlanilla();
        float CalcularSubtotalCostoPlanilla();
        float CalcularImpuestosRetenidos();
};

#endif