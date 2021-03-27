#include "../H/Barco.h"

Barco::Barco() {
}

Barco::Barco(const Barco& orig) {
    this->SetId(orig.GetId());
    this->SetNombre(orig.GetNombre());
}

Barco::~Barco() {
}

Barco::Barco(string nombre, string id) {
    this->SetNombre(nombre);
    this->SetId(id);
}

Barco::Barco(DtBarco barco) {
    this->SetNombre(barco.GetNombre());
    this->SetId(barco.GetId());
}

void Barco::SetId(string id) {
    this->id = id;
}

string Barco::GetId() const {
    return id;
}

void Barco::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Barco::GetNombre() const {
    return nombre;
}

void Barco::arribar(float cargaDespacho) {
    
}

