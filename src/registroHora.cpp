#include "registroHora.h"

using namespace std;

RegistroHora::RegistroHora(istream *streamRegistro)
{
    this->streamEntradaRegistroHora = streamRegistro;
    string linea;
    getline(*streamEntradaRegistroHora, linea);
    istringstream stream(linea);
    stream >> this->idEmpleado >> this->montoPorHora >> this->horasAcumuladas;
}

RegistroHora::~RegistroHora()
{
}

int RegistroHora::ObtenerHorasAcumuladas()
{
    return this->horasAcumuladas;
}

int RegistroHora::ObtenerIdEmpleado()
{
    return this->idEmpleado;
}

float RegistroHora::ObtenerMontoPorHora()
{
    return this->montoPorHora;
}

istream &operator>>(istream &i, RegistroHora *registro)
{
    i >> registro->idEmpleado >> registro->montoPorHora >> registro->horasAcumuladas;
    return i;
}

ostream &operator<<(ostream &o, const RegistroHora *registro)
{
    o << ", " << registro->idEmpleado << ", " << registro->montoPorHora << ", " << registro->horasAcumuladas;
    return o;
}