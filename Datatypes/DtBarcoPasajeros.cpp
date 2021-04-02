#include "DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros() {
}

DtBarcoPasajeros::~DtBarcoPasajeros() {
}

DtBarcoPasajeros::DtBarcoPasajeros(string Nombre, string Id, int CantPasajeros, TipoTamanio Tamanio) : DtBarco( Nombre, Id) {
    this->cantPasajeros=CantPasajeros;
    this->tamanio=Tamanio;
}

string DtBarcoPasajeros::GetNombre() const {
    return this->nombre;
}

string DtBarcoPasajeros::GetId () const {
    return this->id;
}

TipoTamanio DtBarcoPasajeros::GetTamanio() const {
    return tamanio;
}

int DtBarcoPasajeros::GetCantPasajeros() const {
    return cantPasajeros;
}

