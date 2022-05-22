#ifndef REGISTRO_PAGO_H
#define REGISTRO_PAGO_H

#include <string>
#include <sstream>

using namespace std;

class RegistroPago
{
    int idEmpleado;
    float pagoBrutoMensual;
    istream *streamEntradaRegistroPago;

public:
    RegistroPago();
    RegistroPago(istream *streamRegistroPago);
    ~RegistroPago();

    friend istream &operator>>(istream &i, RegistroPago *registroPago);
    friend ostream &operator<<(ostream &o, const RegistroPago *registroPago);

    float ObtenerPagoBruto();
    int ObtenerIdEmpleado();
    void GenerarRegistroPago();
};

#endif