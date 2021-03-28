#ifndef DTARRIBO_H
#define DTARRIBO_H

#include "DtBarco.h"
#include "DtFecha.h"

class DtArribo {
public:
    DtArribo();
    DtArribo(const DtArribo& orig);
    virtual ~DtArribo();
    DtArribo(DtFecha,float,DtBarco);
    DtBarco GetBarco() const;
    float GetCarga() const;
    DtFecha GetFecha() const;
private:
    DtFecha fecha;
    float carga;
    DtBarco barco;
};

#endif

