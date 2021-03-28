#include "Arribo.h"

Arribo::Arribo() {
}

Arribo::Arribo(const Arribo& orig) {
    this->carga=orig.GetCarga();
    this->fecha=orig.GetFecha();
}

Arribo::~Arribo() {
}

Arribo::Arribo(DtFecha Fecha,float Carga) {
    this->fecha = Fecha;
    this->carga = Carga;
}

Arribo::Arribo(DtArribo arribo) {
    this->fecha = arribo.GetFecha();
    this->carga = arribo.GetCarga();
}

void Arribo::SetCarga(float carga) {
    this->carga = carga;
}

float Arribo::GetCarga() const {
    return carga;
}

void Arribo::SetFecha(DtFecha fecha) {
    this->fecha = fecha;
}

DtFecha Arribo::GetFecha() const {
    return fecha;
}

