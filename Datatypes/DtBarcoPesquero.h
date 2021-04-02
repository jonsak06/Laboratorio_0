#ifndef DTBARCOPESQUERO_H
#define DTBARCOPESQUERO_H

#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco {
public:
    DtBarcoPesquero();
    ~DtBarcoPesquero();
    DtBarcoPesquero(string, string, int, int);
    string GetNombre() const;
    string GetId () const;
    int GetCarga() const;
    int GetCapacidad() const;
private:
    string nombre;
    string id;
    int capacidad;
    int carga;
};

#endif

