#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "empleado.h"
#include  "registroHora.h"

using namespace std;

class EmpleadoPorHora : public Empleado // tipo 1
{

float costoPorHora;
int horasLaboradas;
RegistroHora *registroHoras;
        
public:
    
    EmpleadoPorHora(istream *streamEmpleadoPorHora);
    ~EmpleadoPorHora();

    float ObtenerCostoPorHora();
    int ObtenerHorasAcumuladas();
    void AgregarRegistroHoras(RegistroHora *registro);    
    virtual float calculoPagoNeto();
    RegistroHora* ObtenerRegistroHoras();

    friend istream &operator>>(istream &i, EmpleadoPorHora *empleadoPorHora);
    friend ostream &operator<<(ostream &o, const EmpleadoPorHora *empleadoPorHora);

    

};

#endif