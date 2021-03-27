#include "../H/DtBarco.h"

DtBarco::DtBarco() {
}

DtBarco::~DtBarco() {
}

DtBarco::DtBarco(string Nombre, string Id) {
    this->nombre = Nombre;
    this->id = Id;
}

string DtBarco::GetId() const {
    return id;
}

string DtBarco::GetNombre() const {
    return nombre;
}

