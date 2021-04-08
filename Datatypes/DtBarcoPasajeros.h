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
    string getNombre() const;
    string getId() const;
    TipoTamanio getTamanio() const;
    int getCantPasajeros() const;
    int getCapacidad() const;
    int getCarga() const;
    static bool esEsteTipo(const DtBarco*);
private:
    string nombre;
    string id;
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

