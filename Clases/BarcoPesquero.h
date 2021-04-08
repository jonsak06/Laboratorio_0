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
    BarcoPesquero(const BarcoPesquero&);
    ~BarcoPesquero();
    BarcoPesquero(string, string, int, int);
    BarcoPesquero(DtBarcoPesquero);
    BarcoPesquero(Barco*);
    BarcoPesquero(DtBarco&);
    void setCarga(int);
    int getCarga() const;
    void setCapacidad(int);
    int getCapacidad() const;
    int getCantPasajeros() const;
    TipoTamanio getTamanio() const;
    void arribar(float);
    static bool esDeEsteTipo(const Barco*);
private:
    int capacidad;
    int carga;
};

#endif
