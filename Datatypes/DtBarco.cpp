#include "DtBarco.h"

DtBarco::DtBarco() {
}

DtBarco::DtBarco(const DtBarco& orig) {
    this->id=orig.GetId();
    this->nombre=orig.GetNombre();
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

