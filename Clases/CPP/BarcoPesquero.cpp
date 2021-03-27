#include "../H/BarcoPesquero.h"
using namespace std;

BarcoPesquero::BarcoPesquero() {
}

BarcoPesquero::BarcoPesquero(const BarcoPesquero& orig) {
    this->SetCapacidad(orig.GetCapacidad());
    this->SetCarga(orig.GetCarga());
}

BarcoPesquero::~BarcoPesquero() {
}

BarcoPesquero::BarcoPesquero(string nombre, string id, int capacidad, int carga) : Barco(nombre,id) {
    this->SetNombre(nombre);
    this->SetId(id);
    this->SetCapacidad(capacidad);
    this->SetCarga(carga);
}

BarcoPesquero::BarcoPesquero(DtBarcoPesquero barcoPesquero){
    this->SetNombre(barcoPesquero.GetNombre());
    this->SetId(barcoPesquero.GetId());
    this->SetCapacidad(barcoPesquero.GetCapacidad());
    this->SetCarga(barcoPesquero.GetCarga());
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
    this->SetCarga(this->GetCarga() - cargaDespacho);
}

