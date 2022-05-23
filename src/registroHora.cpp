#include "registroHora.h"

using namespace std;

RegistroHora::RegistroHora(istream *streamRegistroHora)
{
    this->streamEntradaRegistroHora = streamRegistroHora;
    this->GenerarRegistroHora();
}

RegistroHora::~RegistroHora()
{
}

void RegistroHora::GenerarRegistroHora(){
    string linea;
    getline(*(this->streamEntradaRegistroHora), linea);
    istringstream streamHora(linea);
    streamHora >> this->idEmpleado >> this->montoPorHora >> this->horasAcumuladas;
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

istream &operator >> (istream &i, RegistroHora *registro)
{
    i >> registro->idEmpleado >> registro->montoPorHora >> registro->horasAcumuladas;
    return i;
}

ostream &operator << (ostream &o,const RegistroHora *registro)
{
    o << registro->idEmpleado << ", " << registro->montoPorHora << ", " << registro->horasAcumuladas;
    return o;
}

