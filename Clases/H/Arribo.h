#ifndef ARRIBO_H
#define ARRIBO_H

#include "../../DataType/H/DtFecha.h"
#include "../../DataType/H/DtArribo.h"

class Arribo {
public:
    Arribo();
    Arribo(const Arribo& orig);
    virtual ~Arribo();
    Arribo(DtFecha,float);
    Arribo(DtArribo);
    void SetCarga(float carga);
    float GetCarga() const;
    void SetFecha(DtFecha fecha);
    DtFecha GetFecha() const;
private:
    DtFecha fecha;
    float carga;
};

#endif

