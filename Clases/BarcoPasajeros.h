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
    void SetTamanio(TipoTamanio tamanio);
    TipoTamanio GetTamanio() const;
    void SetCantPasajeros(int cantPasajeros);
    int GetCantPasajeros() const;
    void arribar(float);
    static BarcoPasajeros barcosPasajeros[MAX_BARCOS/2-1];
private:
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

