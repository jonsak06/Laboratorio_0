#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

#include "DtBarco.h"
#include "../Otros/TipoTamanio.h"

class DtBarcoPesquero : public DtBarco {
public:
    DtBarcoPesquero(const string, const string, const int, const int);
    ~DtBarcoPesquero();
    string getNombre() const;
    string getId () const;
    int getCarga() const;
    int getCapacidad() const;
    int getCantPasajeros() const;
    TipoTamanio getTamanio() const;
private:
    string nombre;
    string id;
    int capacidad;
    int carga;
};

#endif

