#include "DtPuerto.h"

DtPuerto::DtPuerto() {
}

DtPuerto::~DtPuerto() {
}

DtPuerto::DtPuerto(string nombre, string id, DtFecha fechaCreacion, int cantArribos) {
    this->id=id;
    this->nombre=nombre;
    this->fechaCreacion=fechaCreacion;
    this->cantArribos=cantArribos;
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

