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
    Arribo(const Arribo& orig);
    ~Arribo();
    Arribo(DtFecha,float,Barco*);
    Arribo(DtArribo);
    void setCarga(float carga);
    float getCarga() const;
    void setFecha(DtFecha fecha);
    DtFecha getFecha() const;
    void setBarco(Barco*);
    Barco* getBarco() const;
private:
    DtFecha fecha;
    float carga;
    Barco* barco;
};

#endif

