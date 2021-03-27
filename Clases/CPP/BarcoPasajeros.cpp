#include "../H/BarcoPasajeros.h"

BarcoPasajeros::BarcoPasajeros() {
}

BarcoPasajeros::BarcoPasajeros(const BarcoPasajeros& orig) {
    this->SetCantPasajeros(orig.GetCantPasajeros());
    this->SetTamanio(orig.GetTamanio());
}

BarcoPasajeros::~BarcoPasajeros() {
}

BarcoPasajeros::BarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio) : Barco (nombre,id) {
    this->SetNombre(nombre);
    this->SetId(id);
    this->SetCantPasajeros(cantPasajeros);
    this->SetTamanio(tamanio);
}

BarcoPasajeros::BarcoPasajeros(DtBarcoPasajeros barcoPasajeros){
    this->SetNombre(barcoPasajeros.GetNombre());
    this->SetId(barcoPasajeros.GetId());
    this->SetCantPasajeros(barcoPasajeros.GetCantPasajeros());
    this->SetTamanio(barcoPasajeros.GetTamanio());
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

