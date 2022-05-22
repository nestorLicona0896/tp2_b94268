#include "horasTrabajadas.h"
#include "iostream"
using namespace std;

HorasTrabajadas::HorasTrabajadas(istream *entradaHorasTrabajadas) {
    this->entradaHoras = entradaHorasTrabajadas;
    this->GenerarRegistros();  
}

HorasTrabajadas::~HorasTrabajadas(){
    for(RegistroHora *rh :this->horasTrabajadas){
        delete rh;
    }
}

void HorasTrabajadas::AgregarRegistro(RegistroHora *registroNuevo) {
    this->horasTrabajadas.push_back(registroNuevo);
}

RegistroHora* HorasTrabajadas::ObtenerRegistro(int id){
    bool resp = false;
    RegistroHora *rh;
    int i = 0;
    while (resp == false && i < this->horasTrabajadas.size())
    {
        rh = this->horasTrabajadas.at(i);
        if (rh->ObtenerIdEmpleado() == id)
        {
            resp = true;
        }
        i++;
    }
    return rh;
}

vector <RegistroHora*> HorasTrabajadas::ObtenerRegistros(){
    return this->horasTrabajadas;
}

float HorasTrabajadas::ObtenerTotal() {
    float total = 0;
    for(RegistroHora *rh : this->horasTrabajadas) {
        total += (rh->ObtenerMontoPorHora() * rh->ObtenerHorasAcumuladas());
    }
    return total;
}

void HorasTrabajadas::GenerarRegistros(){
    string linea;
    while(getline(*this->entradaHoras, linea)){
        istringstream stream(linea);
        RegistroHora *rh = new RegistroHora(&stream);        
        //cout << rh << endl;
        this->AgregarRegistro(rh);
    }
}