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
    string GetNombre() const;
    string GetId() const;
    TipoTamanio GetTamanio() const;
    int GetCantPasajeros() const;
private:
    string nombre;
    string id;
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

