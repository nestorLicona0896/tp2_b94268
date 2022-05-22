#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "planilla.h"
#include "horasTrabajadas.h"
#include "nomina.h"
#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoPorHora.h"

using namespace std;

int main (){
    
    
    ifstream ifs("horastrabajadas.txt", std::ifstream::in); // Por default abriendo como texto
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo horastrabajadas.txt" << std::endl;
        return -1;
    }
    //HorasTrabajadas *ht1 = new HorasTrabajadas(&ifs);


    ifstream ifs2("nomina.txt", std::ifstream::in); // Por default abriendo como texto
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo nomina.txt" << std::endl;
        return -1;
    }
    //Nomina *n1 = new Nomina(&ifs2)

    ifstream ifs3("personas.txt", std::ifstream::in); // Por default abriendo como texto
    if (!ifs.is_open())
    {
        cerr << "Error leyendo archivo personas.txt" << std::endl;
        return -1;
    }

    Planilla *planilla1 = new Planilla(&ifs3, &ifs2, &ifs);
    

    ofstream reporte("reporte.csv", ifstream::out); // Por default abriendo como texto
    
    if (!reporte.is_open())
    {
        cerr << "Error abriendo archivo reporte.csv" << endl;
    }    

    reporte << planilla1;
    reporte.close();
    delete planilla1;

    return 0;
}