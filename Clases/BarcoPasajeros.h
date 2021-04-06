#ifndef BARCOPASAJEROS_H
#define BARCOPASAJEROS_H

#include "./Barco.h"
#include "../Otros/TipoTamanio.h"
#include "../Datatypes/DtBarcoPasajeros.h"

class BarcoPasajeros : public Barco{
public:
    BarcoPasajeros();
    BarcoPasajeros(const BarcoPasajeros& orig);
    ~BarcoPasajeros();
    BarcoPasajeros(string, string, int, TipoTamanio);
    BarcoPasajeros(DtBarcoPasajeros);
    BarcoPasajeros(Barco*, int, TipoTamanio);
    BarcoPasajeros(DtBarco&, int, TipoTamanio);
    void setTamanio(TipoTamanio tamanio);
    TipoTamanio getTamanio() const;
    void setCantPasajeros(int cantPasajeros);
    int getCantPasajeros() const;
    int getCapacidad() const;
    int getCarga() const;
    void arribar(float);
    TipoBarco mostrarTipoBarco();
private:
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

