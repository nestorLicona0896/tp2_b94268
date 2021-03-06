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
    
    virtual float CalculoPagoNeto() = 0;       
    virtual void AsignarSupervisor(Empleado *supervisorAsignado);
    virtual void AsignarEmpleado(Empleado *empleadoAsignado);    
    virtual vector <Empleado*> ObtenerEmpleados(); 
    virtual int ObtenerId();
    virtual string ObtenerNombre();
    virtual string ObtenerApellido();
    virtual string ObtenerCorreo();
    virtual int ObtenerTipoEmpleado();
    virtual int ObtenerIdSupervisor();   
    virtual Empleado *ObtenerSupervisor(); 

    friend istream& operator>>(istream &entrada, Empleado *emp);
    friend ostream& operator<<(ostream &salida, Empleado *emp);  
    
};

#endif