#include "DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros() {
}

DtBarcoPasajeros::DtBarcoPasajeros(const DtBarcoPasajeros& orig) {
    this->cantPasajeros=orig.GetCantPasajeros();
    this->tamanio=orig.GetTamanio();
}

DtBarcoPasajeros::~DtBarcoPasajeros() {
}

DtBarcoPasajeros::DtBarcoPasajeros(string Nombre, string Id, int CantPasajeros, TipoTamanio Tamanio) : DtBarco( Nombre, Id) {
    this->cantPasajeros=CantPasajeros;
    this->tamanio=Tamanio;
}

TipoTamanio DtBarcoPasajeros::GetTamanio() const {
    return tamanio;
}

int DtBarcoPasajeros::GetCantPasajeros() const {
    return cantPasajeros;
}

