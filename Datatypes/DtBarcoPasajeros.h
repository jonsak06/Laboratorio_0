#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H

#include "../Otros/TipoTamanio.h"
#include "DtBarco.h"

#include <string>

using namespace std;

class DtBarcoPasajeros : public DtBarco {
public:
    DtBarcoPasajeros();
    ~DtBarcoPasajeros();
    DtBarcoPasajeros(string, string, int, TipoTamanio);
    TipoTamanio GetTamanio() const;
    int GetCantPasajeros() const;
private:
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

