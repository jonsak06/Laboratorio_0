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
}

BarcoPesquero::BarcoPesquero(string nombre, string id, int capacidad, int carga) : Barco(nombre, id) {
    this->capacidad = capacidad;
    this->carga = carga;
}

BarcoPesquero::BarcoPesquero(DtBarcoPesquero barcoPesquero){
    this->setNombre(barcoPesquero.getNombre());
    this->setId(barcoPesquero.getId());
    this->capacidad = barcoPesquero.getCapacidad();
    this->carga = barcoPesquero.getCarga();
}

BarcoPesquero::BarcoPesquero(Barco* barco) {
    this->setNombre(barco->getNombre());
    this->setId(barco->getId());
    
}

BarcoPesquero::BarcoPesquero(DtBarco& datavalueBarco) {
    this->setNombre(datavalueBarco.getNombre());
    this->setId(datavalueBarco.getId());
    this->setCapacidad(datavalueBarco.getCapacidad());
    this->setCarga(datavalueBarco.getCarga());
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
}

int BarcoPesquero::getCantPasajeros() const {
}

bool BarcoPesquero::esDeEsteTipo(const Barco* barco) { 
    return (dynamic_cast<const BarcoPesquero*>(barco) != NULL); 
}