#include "BarcoPesquero.h"

BarcoPesquero::BarcoPesquero() {
}

BarcoPesquero::BarcoPesquero(const BarcoPesquero& orig) {
    this->SetNombre(orig.GetNombre());
    this->SetId(orig.GetId());
    this->capacidad=orig.GetCapacidad();
    this->carga=orig.GetCarga();
}

BarcoPesquero::~BarcoPesquero() {
}

BarcoPesquero::BarcoPesquero(string Nombre, string Id, int Capacidad, int Carga) : Barco(Nombre,Id) {
    this->capacidad = Capacidad;
    this->carga = Carga;
}

BarcoPesquero::BarcoPesquero(DtBarcoPesquero barcoPesquero){
    this->SetNombre(barcoPesquero.GetNombre());
    this->SetId(barcoPesquero.GetId());
    this->capacidad = barcoPesquero.GetCapacidad();
    this->carga = barcoPesquero.GetCarga();
}

BarcoPesquero::BarcoPesquero(Barco* barco, int capacidad, int carga) {
    this->SetNombre(barco->GetNombre());
    this->SetId(barco->GetId());
    this->capacidad = capacidad;
    this->carga = carga;
}

BarcoPesquero::BarcoPesquero(DtBarco& datvalueBarco, int capacidad, int carga) {
    this->SetNombre(datvalueBarco.GetNombre());
    this->SetId(datvalueBarco.GetId());
    this->capacidad = capacidad;
    this->carga = carga;
}

void BarcoPesquero::SetCarga(int carga) {
    this->carga = carga;
}

int BarcoPesquero::GetCarga() const {
    return carga;
}

void BarcoPesquero::SetCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

int BarcoPesquero::GetCapacidad() const {
    return capacidad;
}

void BarcoPesquero::arribar(float cargaDespacho) {
    this->carga = carga - cargaDespacho;
}

