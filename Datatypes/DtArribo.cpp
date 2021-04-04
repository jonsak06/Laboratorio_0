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

DtBarco& DtArribo::GetBarco() const {
    return barco;
}

float DtArribo::GetCarga() const {
    return carga;
}

DtFecha DtArribo::GetFecha() const {
    return fecha;
}

