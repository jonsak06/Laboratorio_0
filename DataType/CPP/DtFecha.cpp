#include "../H/DtFecha.h"

DtFecha::DtFecha() {
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

