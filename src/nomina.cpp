#include "nomina.h"
#include "iostream"
using namespace std;

Nomina::Nomina(istream *entradaNominaNueva)
{
    this->entradaNomina = entradaNominaNueva;
    this->GenerarNomina();
}

Nomina::~Nomina(){
    for(RegistroPago*rp :this->nomina){
        delete rp;
    }
}

void Nomina::AgregarRegistro(RegistroPago *registroNuevo)
{
    this->nomina.push_back(registroNuevo);
}

RegistroPago *Nomina::ObtenerRegistro(int id)
{
    return this->nomina.at(id - 1);
}

vector<RegistroPago *> Nomina::ObtenerRegistros()
{
    return this->nomina;
}

float Nomina::ObtenerTotalNomina()
{
    float total = 0;
    for (RegistroPago *rp : this->nomina)
    {
        total += (rp->ObtenerPagoBruto() -(rp->ObtenerPagoBruto()*0.07));
    }
    return total;
}

float Nomina::ObtenerTotalRetencion() {
    float retencion = 0;
    float impuesto = 0.07;
    for (RegistroPago *rp : this->nomina)
    {
        retencion += (rp->ObtenerPagoBruto()*impuesto);
    }
    return retencion;
}

void Nomina::GenerarNomina(){
    string linea;
    while (getline(*this->entradaNomina, linea))
    {
        istringstream stream(linea);
        RegistroPago *rp = new RegistroPago(&stream);
        //cout << rp << endl;
        this->AgregarRegistro(rp);
    }
}

