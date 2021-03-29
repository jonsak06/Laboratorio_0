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
    if(Dia < 1 || Dia > 31 || Mes < 1 || Mes > 12 || Anio < 1900)
    {
        throw invalid_argument("Esta fecha es incorrecta");
    }
    else 
    {
        this->dia=Dia;
        this->mes=Mes;
        this->anio=Anio;
    }
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

