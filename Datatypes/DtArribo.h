#ifndef DTARRIBO_H
#define DTARRIBO_H

#include "DtBarco.h"
#include "DtFecha.h"

class DtArribo {
public:
    DtArribo();
    ~DtArribo();
    DtArribo(DtFecha,float,DtBarco&);
    DtBarco& getBarco() const;
    float getCarga() const;
    DtFecha getFecha() const;
private:
    DtFecha fecha;
    float carga;
    DtBarco& barco;
};

#endif

