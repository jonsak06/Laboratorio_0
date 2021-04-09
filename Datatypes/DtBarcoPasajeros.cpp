#include "DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros() {
}

DtBarcoPasajeros::DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio) : DtBarco(nombre,id) {
    this->cantPasajeros=cantPasajeros;
    this->tamanio=tamanio;
}

DtBarcoPasajeros::~DtBarcoPasajeros() {
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

bool DtBarcoPasajeros::esDeEsteTipo(const DtBarco* barco) { 
    return (dynamic_cast<const DtBarcoPasajeros*>(barco) != NULL); 
}