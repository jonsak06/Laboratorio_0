#include "DtBarcoPesquero.h"

DtBarcoPesquero::DtBarcoPesquero() {
}

DtBarcoPesquero::DtBarcoPesquero(string nombre, string id, int capacidad, int carga) : DtBarco(nombre,id) {
    this->nombre=nombre;
    this->id=id;
    this->capacidad=capacidad;
    this->carga=carga;
}

DtBarcoPesquero::~DtBarcoPesquero() {
}

string DtBarcoPesquero::getNombre() const {
    return this->nombre;
}

string DtBarcoPesquero::getId() const {
    return this->id;
}

int DtBarcoPesquero::getCarga() const {
    return carga;
}

int DtBarcoPesquero::getCapacidad() const {
    return capacidad;
}

int DtBarcoPesquero::getCantPasajeros() const {
}

TipoTamanio DtBarcoPesquero::getTamanio() const {
}

void DtBarcoPesquero::mostrarInfo(ostream&) {
    cout << "\n/////////////////////////////\n";
    cout << "Nombre: " << this->getNombre() << endl;
    cout << "Id: " << this->getId() << endl;
    cout << "Tipo de barco: " << "pesquero\n";
    cout << "Capacidad: " << this->getCapacidad() << endl;
    cout << "Carga: " << this->getCarga();
}