#include "BarcoPasajeros.h"

BarcoPasajeros::BarcoPasajeros() {
}

BarcoPasajeros::BarcoPasajeros(const BarcoPasajeros& orig) {
    this->setNombre(orig.getNombre());
    this->setId(orig.getId());
    this->cantPasajeros=orig.getCantPasajeros();
    this->tamanio=orig.getTamanio();
}

BarcoPasajeros::~BarcoPasajeros() {
}

BarcoPasajeros::BarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio) : Barco (nombre,id) {
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
}

BarcoPasajeros::BarcoPasajeros(DtBarcoPasajeros barcoPasajeros){
    this->setNombre(barcoPasajeros.getNombre());
    this->setId(barcoPasajeros.getId());
    this->cantPasajeros = barcoPasajeros.getCantPasajeros();
    this->tamanio = barcoPasajeros.getTamanio();
}

BarcoPasajeros::BarcoPasajeros(Barco* barco) {
    this->setNombre(barco->getNombre());
    this->setId(barco->getId());
    this->setCantPasajeros(barco->getCantPasajeros());
    this->setTamanio(barco->getTamanio());
}

BarcoPasajeros::BarcoPasajeros(DtBarco& datavalueBarco) {
    this->setNombre(datavalueBarco.getNombre());
    this->setId(datavalueBarco.getId());
    this->setCantPasajeros(datavalueBarco.getCantPasajeros());
    this->setTamanio(datavalueBarco.getTamanio());
}

void BarcoPasajeros::setTamanio(TipoTamanio tamanio) {
    this->tamanio = tamanio;
}

TipoTamanio BarcoPasajeros::getTamanio() const {
    return tamanio;
}

void BarcoPasajeros::setCantPasajeros(int cantPasajeros) {
    this->cantPasajeros = cantPasajeros;
}

int BarcoPasajeros::getCantPasajeros() const {
    return cantPasajeros;
}

void BarcoPasajeros::arribar(float cargaDespacho) {
}

int BarcoPasajeros::getCapacidad() const {
}

int BarcoPasajeros::getCarga() const {
}

bool BarcoPasajeros::esDeEsteTipo(const Barco* barco) { 
    return (dynamic_cast<const BarcoPasajeros*>(barco) != NULL); 
}