#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Empleado // persona
{

protected:

    istream *streamEntrada;
    int idEmpleado;
    string nombreEmpleado;
    string apellidoEmpleado;
    string emailEmpleado;
    int tipoEmpleado;
    int idSupervisorEmpleado;
    Empleado *supervisor; // el supervisor del empleado puede ser otro empleado
    vector <Empleado*> lista; // un empleado puede ser supervisor y tener mas empleados a cargo, o no
     
public:
    
    virtual ~Empleado();
    
    virtual float calculoPagoNeto() = 0;       
    void aignarSupervisor(Empleado *supervisorAsignado);
    void aignarEmpleado(Empleado *empleadoAsignado);    
    virtual vector <Empleado*> ObtenerEmpleados(); 
    virtual int ObtenerId();
    virtual string ObtenerNombre();
    virtual string ObtenerApellido();
    virtual string ObtenerCorreo();
    virtual int ObtenerTipoEmpleado();
    virtual int ObtenerIdSupervisor();  
    virtual Empleado* ObtenerSupervisor();     
    
};

#endif