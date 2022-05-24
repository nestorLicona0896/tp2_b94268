#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "empleado.h"
#include  "registroPago.h"
#include <vector>

using namespace std;

class EmpleadoNomina : public Empleado // tipo 2
{


RegistroPago *registroPagoBruto;
        
public:
    
    EmpleadoNomina(istream *streamEmpleadoNomina);
    ~EmpleadoNomina();

    float ObtenerSalarioBruto();
    void AgregarRegistroPago(RegistroPago *registro);
    virtual float CalculoPagoNeto();  
    RegistroPago* ObtenerRegistroPago();
    void GenerarEmpleadoNomina();
          
};

#endif