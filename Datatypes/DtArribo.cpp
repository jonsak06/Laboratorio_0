#include "DtArribo.h"

DtArribo::DtArribo() {
}

DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco* datavalueBarco) { 
    this->fecha = fecha;
    this->carga = carga;
    this->barco = datavalueBarco;
}

DtArribo::~DtArribo() {
}

DtBarco* DtArribo::getBarco() {
    return barco;
}

float DtArribo::getCarga() const {
    return carga;
}

DtFecha DtArribo::getFecha() const {
    return fecha;
}

