#ifndef BARCOPESQUERO_H
#define BARCOPESQUERO_H

#include "Barco.h"
#include "../../DataType/H/DtBarcoPesquero.h"

using namespace std;

class BarcoPesquero : public Barco {
public:
    BarcoPesquero();
    BarcoPesquero(const BarcoPesquero& orig);
    virtual ~BarcoPesquero();
    BarcoPesquero(string, string, int, int);
    BarcoPesquero(DtBarcoPesquero);
    void SetCarga(int carga);
    int GetCarga() const;
    void SetCapacidad(int capacidad);
    int GetCapacidad() const;
    void arribar(float);
private:
    int capacidad;
    int carga;
};

#endif
