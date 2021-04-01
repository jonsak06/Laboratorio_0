#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco {
public:
    DtBarcoPesquero();
    ~DtBarcoPesquero();
    DtBarcoPesquero(string, string, int, int);
    int GetCarga() const;
    int GetCapacidad() const;
private:
    int capacidad;
    int carga;
};

#endif

