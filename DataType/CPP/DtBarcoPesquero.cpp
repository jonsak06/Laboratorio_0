#include "../H/DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero() {
}

DtBarcoPesquero::~DtBarcoPesquero() {
}

DtBarcoPesquero::DtBarcoPesquero(string Nombre, string Id, int Capacidad, int Carga) : DtBarco(Nombre,Id) {
    this->capacidad=Capacidad;
    this->carga=Carga;
}

int DtBarcoPesquero::GetCarga() const {
    return carga;
}

int DtBarcoPesquero::GetCapacidad() const {
    return capacidad;
}

