#include "Arribo.h"

Arribo::Arribo() {
}

Arribo::Arribo(const Arribo& orig) {
    this->carga=orig.GetCarga();
    this->fecha=orig.GetFecha();
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
    this->fecha = datavalueArribo.GetFecha();
    this->carga = datavalueArribo.GetCarga();
    this->barco->SetNombre(datavalueArribo.GetBarco().GetNombre());
    this->barco->SetId(datavalueArribo.GetBarco().GetId());
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

void Arribo::setBarco(Barco* barco)
{
    this->barco = barco;
}

Barco* Arribo::getBarco() const {
    return barco;
}