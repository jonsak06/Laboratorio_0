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

BarcoPasajeros::BarcoPasajeros(string Nombre, string Id, int CantPasajeros, TipoTamanio Tamanio) : Barco (Nombre,Id) {
    this->cantPasajeros = CantPasajeros;
    this->tamanio = Tamanio;
}

BarcoPasajeros::BarcoPasajeros(DtBarcoPasajeros barcoPasajeros){
    this->setNombre(barcoPasajeros.getNombre());
    this->setId(barcoPasajeros.getId());
    this->cantPasajeros = barcoPasajeros.getCantPasajeros();
    this->tamanio = barcoPasajeros.getTamanio();
}

BarcoPasajeros::BarcoPasajeros(Barco* barco, int cantPasajeros, TipoTamanio tamanio) {
    this->setNombre(barco->getNombre());
    this->setId(barco->getId());
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
}

BarcoPasajeros::BarcoPasajeros(DtBarco& datavalueBarco, int cantPasajeros, TipoTamanio tamanio) {
    this->setNombre(datavalueBarco.getNombre());
    this->setId(datavalueBarco.getId());
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
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
    //No se realiza ningun cambio porque los barcos de pasajeros no poseen carga
}

int BarcoPasajeros::getCapacidad() const {
    //no hace nada, se necesita crear en Barco y aca para poder utilizar el metodo desde el puntero de tipo Barco
}

int BarcoPasajeros::getCarga() const {
}

bool BarcoPasajeros::esEsteTipo(const Barco* barco) { 
    return (dynamic_cast<const BarcoPasajeros*>(barco) != NULL); 
}