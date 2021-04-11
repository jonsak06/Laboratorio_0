#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H

#include "DtBarco.h"

#include <string>

class DtBarcoPasajeros : public DtBarco {
public:
    DtBarcoPasajeros();
    DtBarcoPasajeros(const string, const string, const int, const TipoTamanio);
    ~DtBarcoPasajeros();
    TipoTamanio getTamanio() const;
    int getCantPasajeros() const;
    int getCapacidad() const;
    int getCarga() const;
    static bool esDeEsteTipo(const DtBarco*);
    void mostrarInfo(ostream&);
private:
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

