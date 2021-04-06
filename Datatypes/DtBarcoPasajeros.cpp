#include "DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros() {
}

DtBarcoPasajeros::~DtBarcoPasajeros() {
}

DtBarcoPasajeros::DtBarcoPasajeros(string Nombre, string Id, int CantPasajeros, TipoTamanio Tamanio) : DtBarco( Nombre, Id) {
    this->cantPasajeros=CantPasajeros;
    this->tamanio=Tamanio;
}

string DtBarcoPasajeros::getNombre() const {
    return this->nombre;
}

string DtBarcoPasajeros::getId () const {
    return this->id;
}

TipoTamanio DtBarcoPasajeros::getTamanio() const {
    return tamanio;
}

int DtBarcoPasajeros::getCantPasajeros() const {
    return cantPasajeros;
}

int DtBarcoPasajeros::getCapacidad() const {
}

int DtBarcoPasajeros::getCarga() const {
}

TipoBarco DtBarcoPasajeros::getTipoBarco() const {
    return tipoBarco;
}