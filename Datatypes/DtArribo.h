#ifndef DTARRIBO_H
#define DTARRIBO_H

#include "DtBarco.h"
#include "DtBarcoPesquero.h"
#include "DtFecha.h"

class DtArribo {
public:
    DtArribo();
    DtArribo(const DtFecha,const float, DtBarco&);
    ~DtArribo();
    DtBarco& getBarco();
    float getCarga() const;
    DtFecha getFecha() const;
private:
    DtFecha fecha;
    float carga;
    DtBarco& barco;
};

#endif

