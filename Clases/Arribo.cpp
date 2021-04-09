#include "Arribo.h"

Barco* objBarco;
Arribo::Arribo() : barco(objBarco) {
}

Arribo::Arribo(const Arribo& orig) : barco(orig.getBarco()) {
    this->carga=orig.getCarga();
    this->fecha=orig.getFecha();
    this->barco = orig.getBarco();
}

Arribo::~Arribo() {
}

Arribo::Arribo(DtFecha fecha, float carga, Barco* barco) : barco(barco) {
    this->fecha = fecha;
    this->carga = carga;
    this->barco = barco;
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