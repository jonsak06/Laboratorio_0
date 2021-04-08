#include "DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero() {
}

DtBarcoPesquero::~DtBarcoPesquero() {
}

DtBarcoPesquero::DtBarcoPesquero(string Nombre, string Id, int Capacidad, int Carga) : DtBarco(Nombre,Id) {
    this->nombre=Nombre;
    this->id=Id;
    this->capacidad=Capacidad;
    this->carga=Carga;
}

string DtBarcoPesquero::getNombre() const {
    return this->nombre;
}

string DtBarcoPesquero::getId () const {
    return this->id;
}

int DtBarcoPesquero::getCarga() const {
    return carga;
}

int DtBarcoPesquero::getCapacidad() const {
    return capacidad;
}

int DtBarcoPesquero::getCantPasajeros() const {
}

TipoTamanio DtBarcoPesquero::getTamanio() const {
}