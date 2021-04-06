#ifndef DTBARCO_H
#define DTBARCO_H

#include <iostream>
#include <string>
#include "../Otros/TipoTamanio.h"
#include "../Otros/TipoBarco.h"

using namespace std;

class DtBarco {
public:
    DtBarco();
    virtual ~DtBarco();
    DtBarco(string, string);
    string getId() const;
    string getNombre() const;
    virtual int getCapacidad() const;
    virtual int getCarga() const;
    virtual int getCantPasajeros() const;
    virtual TipoTamanio getTamanio() const;
    virtual TipoBarco getTipoBarco() const;
private:
    string nombre;
    string id;
};

#endif

