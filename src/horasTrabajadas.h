#ifndef HORAS_TRABAJADAS_H  
#define HORAS_TRABAJADAS_H  

#include "registroHora.h"
#include <vector>

using namespace std;

class HorasTrabajadas {

    istream *entradaHoras;
    vector <RegistroHora*> horasTrabajadas;
    float total;

    public:

        HorasTrabajadas(istream *streamHoras);
        ~HorasTrabajadas();

        void AgregarRegistro(RegistroHora *registro);
        RegistroHora* ObtenerRegistro(int id);
        vector <RegistroHora*> ObtenerRegistros();    
        float ObtenerTotal();
};

#endif