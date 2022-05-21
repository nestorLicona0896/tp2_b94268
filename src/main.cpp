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

#include <iostream>

using namespace std;

int main (){
    
    
    ifstream ifs("horastrabajadas.txt", std::ifstream::in); // Por default abriendo como texto
    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo horastrabajadas.txt" << std::endl;
        return -1;
    }
    HorasTrabajadas *ht1 = new HorasTrabajadas(&ifs);




    return 0;
}