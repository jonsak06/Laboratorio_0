#ifndef ARRIBO_H
#define ARRIBO_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtArribo.h"
#include "Barco.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"

class Arribo {
public:
    Arribo();
    Arribo(const Arribo&);
    ~Arribo();
    Arribo(DtFecha,float,Barco*);
    void setCarga(float);
    float getCarga() const;
    void setFecha(DtFecha);
    DtFecha getFecha() const;
    void setBarco(Barco*);
    Barco* getBarco() const;
private:
    DtFecha fecha;
    float carga;
    Barco* barco;
};

#endif

