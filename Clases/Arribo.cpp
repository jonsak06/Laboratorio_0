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

Arribo::Arribo(DtArribo datavalueArribo) {
    this->fecha = datavalueArribo.GetFecha();
    this->carga = datavalueArribo.GetCarga();
    this->barco = datavalueArribo.GetBarco();
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

void Arribo::setBarco(Barco barco)
{
    this->barco = barco;
}

Barco Arribo::getBarco() const {
    return this->barco;
}