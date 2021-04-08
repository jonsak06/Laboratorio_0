#include "Barco.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"
#include "../Otros/TipoTamanio.h"

Barco::Barco() {
}

Barco::Barco(const Barco& orig) {
    this->id=orig.getId();
    this->nombre=orig.getNombre();
}

Barco::~Barco() {
}

Barco::Barco(string nombre, string id) {
    this->nombre = nombre;
    this->id = id;
}

Barco::Barco(DtBarco& barco) {
    this->nombre = barco.getNombre();
    this->id = barco.getId();
}

void Barco::setId(string id) {
    this->id = id;
}

string Barco::getId() const {
    return id;
}

void Barco::setNombre(string nombre) {
    this->nombre = nombre;
}

string Barco::getNombre() const {
    return nombre;
}

Barco* Barco::barcos[MAX_BARCOS-1] = {};
int Barco::ultimoBarco = 0;

bool Barco::existeBarco(string idBarco)
{
    for(int i=0;i<Barco::ultimoBarco;i++)
    {
        if(idBarco == Barco::barcos[i]->getId())
        {
            return true;
        }
    }
    return false;
}

int Barco::getPosicionBarco(string idBarcoPjs)
{
    for(int i=0;i<Barco::ultimoBarco;i++)
    {
        if(idBarcoPjs == Barco::barcos[i]->getId())
        {
            return i;
        }
    }
    return -1;
}
