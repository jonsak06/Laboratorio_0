#include "BarcoPasajeros.h"

BarcoPasajeros::BarcoPasajeros() {
}

BarcoPasajeros::BarcoPasajeros(const BarcoPasajeros& orig) {
    this->SetNombre(orig.GetNombre());
    this->SetId(orig.GetId());
    this->cantPasajeros=orig.GetCantPasajeros();
    this->tamanio=orig.GetTamanio();
}

BarcoPasajeros::~BarcoPasajeros() {
}

BarcoPasajeros::BarcoPasajeros(string Nombre, string Id, int CantPasajeros, TipoTamanio Tamanio) : Barco (Nombre,Id) {
    this->cantPasajeros = CantPasajeros;
    this->tamanio = Tamanio;
}

BarcoPasajeros::BarcoPasajeros(DtBarcoPasajeros barcoPasajeros){
    this->SetNombre(barcoPasajeros.GetNombre());
    this->SetId(barcoPasajeros.GetId());
    this->cantPasajeros = barcoPasajeros.GetCantPasajeros();
    this->tamanio = barcoPasajeros.GetTamanio();
}

BarcoPasajeros::BarcoPasajeros(Barco* barco, int cantPasajeros, TipoTamanio tamanio) {
    this->SetNombre(barco->GetNombre());
    this->SetId(barco->GetId());
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
}

BarcoPasajeros::BarcoPasajeros(DtBarco& datavalueBarco, int cantPasajeros, TipoTamanio tamanio) {
    this->SetNombre(datavalueBarco.GetNombre());
    this->SetId(datavalueBarco.GetId());
    this->cantPasajeros = cantPasajeros;
    this->tamanio = tamanio;
}

void BarcoPasajeros::SetTamanio(TipoTamanio tamanio) {
    this->tamanio = tamanio;
}

TipoTamanio BarcoPasajeros::GetTamanio() const {
    return tamanio;
}

void BarcoPasajeros::SetCantPasajeros(int cantPasajeros) {
    this->cantPasajeros = cantPasajeros;
}

int BarcoPasajeros::GetCantPasajeros() const {
    return cantPasajeros;
}

void BarcoPasajeros::arribar(float cargaDespacho) {
    //No se realiza ningun cambio porque los barcos de pasajeros no poseen carga
}