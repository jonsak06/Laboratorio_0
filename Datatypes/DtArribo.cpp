#include "DtArribo.h"
DtBarco dvBarco("", "");
DtBarco& rdvBarco(dvBarco);
DtArribo::DtArribo() : barco(rdvBarco) {//https://stackoverflow.com/questions/30069384/provides-no-initializer-for-reference-member
}

DtArribo::~DtArribo() {
}

DtArribo::DtArribo(DtFecha Fecha, float Carga, DtBarco& datavalueBarco) : barco(datavalueBarco) { 
    this->fecha = Fecha;
    this->carga = Carga;
}

DtBarco& DtArribo::getBarco() const {
    return barco;
}

float DtArribo::getCarga() const {
    return carga;
}

DtFecha DtArribo::getFecha() const {
    return fecha;
}

