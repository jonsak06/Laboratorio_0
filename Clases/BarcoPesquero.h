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
    ~BarcoPesquero();
    BarcoPesquero(string, string, int, int);
    BarcoPesquero(DtBarcoPesquero);
    BarcoPesquero(Barco*, int, int);
    BarcoPesquero(DtBarco&, int, int);
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
