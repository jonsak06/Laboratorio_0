#include "DtFecha.h"

DtFecha::DtFecha() {
}

DtFecha::DtFecha(const DtFecha& orig) {
    this->dia=orig.GetDia();
    this->mes=orig.GetMes();
    this->anio=orig.GetAnio();
}

DtFecha::~DtFecha() {
}

DtFecha::DtFecha(int Dia, int Mes, int Anio) {
    this->dia=Dia;
    this->mes=Mes;
    this->anio=Anio;
}

int DtFecha::GetAnio() const {
    return anio;
}

int DtFecha::GetMes() const {
    return mes;
}

int DtFecha::GetDia() const {
    return dia;
}

