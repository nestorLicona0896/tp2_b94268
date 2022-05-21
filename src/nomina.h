#ifndef NOMINA_H
#define NOMINA_H

#include "registroPago.h"
#include <vector>

using namespace std;

class Nomina {

    istream *entradaNomina;
    vector <RegistroPago*> nomina;
    float totalNomina;
    float totalRetencion;

    public:

        Nomina(istream *streamNomina);
        ~Nomina();

        void AgregarRegistro(RegistroPago *registro);
        RegistroPago* ObtenerRegistro(int id);
        vector <RegistroPago*> ObtenerRegistros();    
        float ObtenerTotalNomina();
        float ObtenerTotalRetencion();
};

#endif