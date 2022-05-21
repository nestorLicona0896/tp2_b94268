#include "registroPago.h"

using namespace std;

RegistroPago::RegistroPago(istream *streamRegistro) {
    this->streamEntradaRegistroPago = streamRegistro;
    string linea;
    getline(*streamEntradaRegistroPago, linea);
    istringstream stream(linea);
    stream >> this->idEmpleado >> this->pagoBrutoMensual;
}

RegistroPago::~RegistroPago() {

}

float RegistroPago::ObtenerPagoBruto() {
    return this->pagoBrutoMensual;
}

int RegistroPago::ObtenerIdEmpleado(){
    return this->idEmpleado;
}

istream& operator >> (istream &i, RegistroPago *registro){
    i >> registro->idEmpleado >> registro->pagoBrutoMensual;
    return i;
}

ostream& operator << (ostream &o, const RegistroPago *registro){
    o << ", " << registro->idEmpleado << ", " << registro->pagoBrutoMensual;
    return o;
}