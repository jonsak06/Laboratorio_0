#include "DtArribo.h"

DtArribo::DtArribo() {
}

DtArribo::DtArribo(const DtArribo& orig) {
    this->barco = orig.GetBarco();
    this->carga = orig.GetCarga();
    this->fecha = orig.GetFecha();
}

DtArribo::~DtArribo() {
}

DtArribo::DtArribo(DtFecha Fecha, float Carga, DtBarco Barco) {
    this->fecha = Fecha;
    this->carga = Carga;
    this->barco = Barco;
}

DtBarco DtArribo::GetBarco() const {
    return barco;
}

float DtArribo::GetCarga() const {
    return carga;
}

DtFecha DtArribo::GetFecha() const {
    return fecha;
}

