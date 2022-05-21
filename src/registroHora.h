#ifndef REGISTRO_HORA_H
#define REGISTRO_HORA_H

#include <string>
#include <sstream>

using namespace std;

class RegistroHora
{
    int idEmpleado;
    float montoPorHora;
    int horasAcumuladas;
    istream *streamEntradaRegistroHora;

public:
    RegistroHora(istream *streamRegistroHora);
    ~RegistroHora();

    friend istream &operator>>(istream &i, RegistroHora *registroHora);
    friend ostream &operator<<(ostream &o, const RegistroHora *registroHora);

    float ObtenerMontoPorHora();
    int ObtenerIdEmpleado();
    int ObtenerHorasAcumuladas();
};

#endif