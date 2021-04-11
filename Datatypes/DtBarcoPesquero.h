#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco {
public:
    DtBarcoPesquero();
    DtBarcoPesquero(const string, const string, const int, const int);
    ~DtBarcoPesquero();
    int getCarga() const;
    int getCapacidad() const;
    int getCantPasajeros() const;
    TipoTamanio getTamanio() const;
    void mostrarInfo(ostream&);
private:
    int capacidad;
    int carga;
};

#endif

