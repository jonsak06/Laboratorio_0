#include "DtArribo.h"

DtBarcoPesquero dtvBarco("","",0,0);//creo un datavalue de barco cualquiera para poder inicializar el DtArribo
DtArribo::DtArribo() : barco(dtvBarco) {
}

DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco& datavalueBarco) : barco(datavalueBarco) { 
    this->fecha = fecha;
    this->carga = carga;
}

DtArribo::~DtArribo() {
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

