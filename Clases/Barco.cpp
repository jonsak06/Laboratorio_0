#include "Barco.h"

Barco::Barco() {
}

Barco::Barco(const Barco& orig) {
    this->id=orig.GetId();
    this->nombre=orig.GetNombre();
}

Barco::~Barco() {
}

Barco::Barco(string Nombre, string Id) {
    this->nombre = Nombre;
    this->id = Id;
}

Barco::Barco(DtBarco barco) {
    this->nombre = barco.GetNombre();
    this->id = barco.GetId();
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

