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

int DtPuerto::GetCantArribos() const {
    return cantArribos;
}

DtFecha DtPuerto::GetFechaCreacion() const {
    return fechaCreacion;
}

string DtPuerto::GetNombre() const {
    return nombre;
}

string DtPuerto::GetId() const {
    return id;
}

