#ifndef BARCOPASAJEROS_H
#define BARCOPASAJEROS_H

#include "./Barco.h"
#include "../Otros/TipoTamanio.h"
#include "../Datatypes/DtBarcoPasajeros.h"

class BarcoPasajeros : public Barco{
public:
    BarcoPasajeros();
    BarcoPasajeros(const BarcoPasajeros&);
    ~BarcoPasajeros();
    BarcoPasajeros(string, string, int, TipoTamanio);
    BarcoPasajeros(DtBarcoPasajeros);
    BarcoPasajeros(Barco*);
    BarcoPasajeros(DtBarco&);
    void setTamanio(TipoTamanio);
    TipoTamanio getTamanio() const;
    void setCantPasajeros(int);
    int getCantPasajeros() const;
    int getCapacidad() const;
    int getCarga() const;
    void arribar(float);
    static bool esDeEsteTipo(const Barco*);
private:
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

