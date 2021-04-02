#ifndef ARRIBO_H
#define ARRIBO_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtArribo.h"
#include "Barco.h"

class Arribo {
public:
    Arribo();
    Arribo(const Arribo& orig);
    ~Arribo();
    Arribo(DtFecha,float);
    Arribo(DtArribo);
    void SetCarga(float carga);
    float GetCarga() const;
    void SetFecha(DtFecha fecha);
    DtFecha GetFecha() const;
    void setBarco(Barco);
    Barco getBarco() const;
private:
    DtFecha fecha;
    float carga;
    Barco barco;
};

#endif

