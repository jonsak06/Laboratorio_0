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
    void setCarga(int carga);
    int getCarga() const;
    void setCapacidad(int capacidad);
    int getCapacidad() const;
    int getCantPasajeros() const;
    TipoTamanio getTamanio() const;
    void arribar(float);
    TipoBarco mostrarTipoBarco();
private:
    int capacidad;
    int carga;
};

#endif
