#include "nomina.h"
#include "iostream"

using namespace std;

Nomina::Nomina(istream *entradaNominaNueva)
{
    this->entradaNomina = entradaNominaNueva;
    this->GenerarNomina();
}

Nomina::~Nomina()
{
    for (RegistroPago *rp : this->nomina)
    {
        delete rp;
    }
}

void Nomina::AgregarRegistro(RegistroPago *registroNuevo)
{
    this->nomina.push_back(registroNuevo);
}

RegistroPago *Nomina::ObtenerRegistro(int id)
{
    bool resp = false;
    RegistroPago *rp;
    int i = 0;
    while (resp == false && i < this->nomina.size())
    {
        rp = this->nomina.at(i);
        if (rp->ObtenerIdEmpleado() == id)
        {
            resp = true;
        }
        i++;
    }
    return rp;
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
        total += (rp->ObtenerPagoBruto() - (rp->ObtenerPagoBruto() * 0.07));
    }
    return total;
}

float Nomina::ObtenerTotalRetencion()
{
    float retencion = 0;
    float impuesto = 0.07;
    for (RegistroPago *rp : this->nomina)
    {
        retencion += (rp->ObtenerPagoBruto() * impuesto);
    }
    return retencion;
}

void Nomina::GenerarNomina()
{
    string linea;
    while (getline(*this->entradaNomina, linea))
    {
        istringstream streamPago(linea);
        RegistroPago *rp = new RegistroPago(&streamPago);        
        this->AgregarRegistro(rp);
        //cout << rp << endl;
    }
}
