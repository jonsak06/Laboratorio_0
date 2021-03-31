#ifndef BARCOPESQUERO_H
#define BARCOPESQUERO_H

#include "./Barco.h"
#include "../Datatypes/DtBarcoPesquero.h"

#include <string>

using namespace std;

class BarcoPesquero : public Barco 
{
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
    static BarcoPesquero barcosPesqueros[MAX_BARCOS/2-1];
private:
    int capacidad;
    int carga;
};

#endif
