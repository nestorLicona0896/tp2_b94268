#include "horasTrabajadas.h"
#include "iostream"
using namespace std;

HorasTrabajadas::HorasTrabajadas(istream *entradaHorasTrabajadas) {
    //ciclo para leer el documento horastrabajadas.txt
    string linea;
    this->entradaHoras = entradaHorasTrabajadas;
    while(getline(*entradaHoras, linea)){
        istringstream stream(linea);
        RegistroHora *rh = new RegistroHora(&stream);
        
        cout << rh << endl;
        //this->AgregarRegistro(rh);

    }

}