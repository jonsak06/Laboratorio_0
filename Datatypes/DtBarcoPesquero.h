#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

#include "DtBarco.h"
#include "../Otros/TipoTamanio.h"

class DtBarcoPesquero : public DtBarco {
public:
    DtBarcoPesquero();
    ~DtBarcoPesquero();
    DtBarcoPesquero(string, string, int, int);
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

