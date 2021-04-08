#include "DtBarco.h"

DtBarco::DtBarco(const string nombre, const string id) {
    this->nombre = nombre;
    this->id = id;
}

DtBarco::~DtBarco() {
}

string DtBarco::getId() const {
    return id;
}

string DtBarco::getNombre() const {
    return nombre;
}
