#include "Arribo.h"

Arribo::Arribo() {
}

Arribo::Arribo(const Arribo& orig) {
    this->carga=orig.getCarga();
    this->fecha=orig.getFecha();
    this->barco = orig.getBarco();

}

Arribo::~Arribo() {
}

Arribo::Arribo(DtFecha Fecha, float Carga, Barco* barco) {
    this->fecha = Fecha;
    this->carga = Carga;
    this->barco = barco;
}

Arribo::Arribo(DtArribo datavalueArribo) {
    this->fecha = datavalueArribo.getFecha();
    this->carga = datavalueArribo.getCarga();
    this->barco->setNombre(datavalueArribo.getBarco().getNombre());
    this->barco->setId(datavalueArribo.getBarco().getId());
}

void Arribo::setCarga(float carga) {
    this->carga = carga;
}

float Arribo::getCarga() const {
    return carga;
}

void Arribo::setFecha(DtFecha fecha) {
    this->fecha = fecha;
}

DtFecha Arribo::getFecha() const {
    return fecha;
}

void Arribo::setBarco(Barco* barco)
{
    this->barco = barco;
}

Barco* Arribo::getBarco() const {
    return barco;
}