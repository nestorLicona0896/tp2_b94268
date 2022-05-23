#ifndef EMPLEADO_POR_HORA_H
#define EMPLEADO_POR_HORA_H

#include "empleado.h"
#include  "registroHora.h"

using namespace std;

class EmpleadoPorHora : public Empleado // tipo 1
{

RegistroHora *registroHoras;
        
public:
    
    EmpleadoPorHora(istream *streamEmpleadoPorHora);
    ~EmpleadoPorHora();

    void GenerarEmpleadoPorHora();
    float ObtenerCostoPorHora();
    int ObtenerHorasAcumuladas();
    void AgregarRegistroHoras(RegistroHora *registro);    
    virtual float CalculoPagoNeto();
    RegistroHora* ObtenerRegistroHorasEnMes();

    friend istream &operator>>(istream &i, EmpleadoPorHora *empleadoPorHora);
    friend ostream &operator<<(ostream &o, const EmpleadoPorHora *empleadoPorHora);

    

};

#endif