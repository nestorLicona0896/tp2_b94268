#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "empleado.h"
#include  "registroPago.h"

using namespace std;

class EmpleadoNomina : public Empleado // tipo 2
{

float salarioBruto;
RegistroPago *registroPagoBruto;

        
public:
    
    EmpleadoNomina(istream *streamEmpleadoNomina);
    ~EmpleadoNomina();

    float ObtenerSalarioBruto();
    void AgregarRegistroPago(RegistroPago *registro);
    virtual float calculoPagoNeto();  
    RegistroPago* ObtenerRegistroPago();
      
    friend istream &operator >> (istream &i, EmpleadoNomina *empleadoNomina);
    friend ostream &operator << (ostream &o, const EmpleadoNomina *empleadoNomina);   
         
};

#endif