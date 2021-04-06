#include "DtPuerto.h"

DtPuerto::DtPuerto() {
}

DtPuerto::~DtPuerto() {
}

DtPuerto::DtPuerto(string Id, string Nombre, DtFecha FechaCreacion, int CantArribos) {
    this->id=Id;
    this->nombre=Nombre;
    this->fechaCreacion=FechaCreacion;
    this->cantArribos=CantArribos;
}

int DtPuerto::getCantArribos() const {
    return cantArribos;
}

DtFecha DtPuerto::getFechaCreacion() const {
    return fechaCreacion;
}

string DtPuerto::getNombre() const {
    return nombre;
}

string DtPuerto::getId() const {
    return id;
}

