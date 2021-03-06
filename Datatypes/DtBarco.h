#ifndef DTBARCO_H
#define DTBARCO_H

#include <iostream>
#include <string>
#include "../Otros/TipoTamanio.h"

using namespace std;

class DtBarco {
public:
    DtBarco();
    DtBarco(const string, const string);
    virtual ~DtBarco();
    string getId() const;
    string getNombre() const;
    virtual int getCapacidad() const = 0;
    virtual int getCarga() const = 0;
    virtual int getCantPasajeros() const = 0;
    virtual TipoTamanio getTamanio() const = 0;
    friend ostream& operator<<(ostream&, DtBarco*);
    virtual void mostrarInfo(ostream&) = 0;
private:
    string nombre;
    string id;
};

#endif

