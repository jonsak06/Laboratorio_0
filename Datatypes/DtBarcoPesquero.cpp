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

string DtBarcoPesquero::GetNombre() const {
    return this->nombre;
}

string DtBarcoPesquero::GetId () const {
    return this->id;
}

int DtBarcoPesquero::GetCarga() const {
    return carga;
}

int DtBarcoPesquero::GetCapacidad() const {
    return capacidad;
}

