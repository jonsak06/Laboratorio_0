#include "DtBarco.h"

DtBarco::DtBarco() {
}

DtBarco::~DtBarco() {
}

DtBarco::DtBarco(string Nombre, string Id) {
    this->nombre = Nombre;
    this->id = Id;
}

string DtBarco::getId() const {
    return id;
}

string DtBarco::getNombre() const {
    return nombre;
}

int DtBarco::getCapacidad() const {
}

int DtBarco::getCarga() const {
}

int DtBarco::getCantPasajeros() const {
}

TipoTamanio DtBarco::getTamanio() const {
}
