#ifndef ARRIBO_H
#define ARRIBO_H

#include "../Datatypes/DtFecha.h"
#include "Barco.h"

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

