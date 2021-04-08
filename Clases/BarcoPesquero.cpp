#include "BarcoPesquero.h"

BarcoPesquero::BarcoPesquero() {
}

BarcoPesquero::BarcoPesquero(const BarcoPesquero& orig) {
    this->setNombre(orig.getNombre());
    this->setId(orig.getId());
    this->capacidad=orig.getCapacidad();
    this->carga=orig.getCarga();
}

BarcoPesquero::~BarcoPesquero() {
    cout << "\nbarco destruido\n";
}

BarcoPesquero::BarcoPesquero(string Nombre, string Id, int Capacidad, int Carga) : Barco(Nombre,Id) {
    this->capacidad = Capacidad;
    this->carga = Carga;
}

BarcoPesquero::BarcoPesquero(DtBarcoPesquero barcoPesquero){
    this->setNombre(barcoPesquero.getNombre());
    this->setId(barcoPesquero.getId());
    this->capacidad = barcoPesquero.getCapacidad();
    this->carga = barcoPesquero.getCarga();
}

BarcoPesquero::BarcoPesquero(Barco* barco, int capacidad, int carga) {
    this->setNombre(barco->getNombre());
    this->setId(barco->getId());
    this->capacidad = capacidad;
    this->carga = carga;
}

BarcoPesquero::BarcoPesquero(DtBarco& datvalueBarco, int capacidad, int carga) {
    this->setNombre(datvalueBarco.getNombre());
    this->setId(datvalueBarco.getId());
    this->capacidad = capacidad;
    this->carga = carga;
}

void BarcoPesquero::setCarga(int carga) {
    this->carga = carga;
}

int BarcoPesquero::getCarga() const {
    return carga;
}

void BarcoPesquero::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

int BarcoPesquero::getCapacidad() const {
    return capacidad;
}

void BarcoPesquero::arribar(float cargaDespacho) {
    carga -= cargaDespacho;
}

TipoTamanio BarcoPesquero::getTamanio() const {
    //no hace nada, se necesita crear en Barco y aca para poder utilizar el metodo desde el puntero de tipo Barco
}

int BarcoPesquero::getCantPasajeros() const {
}

bool BarcoPesquero::esEsteTipo(const Barco* barco) { 
    return (dynamic_cast<const BarcoPesquero*>(barco) != NULL); 
}