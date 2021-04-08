#ifndef DTARRIBO_H
#define DTARRIBO_H

#include "DtBarco.h"
#include "DtFecha.h"

class DtArribo {
public:
    DtArribo(const DtFecha,const float, DtBarco&);
    ~DtArribo();
    DtBarco& getBarco() const;
    float getCarga() const;
    DtFecha getFecha() const;
private:
    DtFecha fecha;
    float carga;
    DtBarco& barco;
};

#endif

