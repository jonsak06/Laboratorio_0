#include "DtFecha.h"

DtFecha::DtFecha() {
}

DtFecha::~DtFecha() {
    // cout << "\nfecha destruida\n";
}

DtFecha::DtFecha(int Dia, int Mes, int Anio) {
    if(Dia < 1 || Dia > 31 || Mes < 1 || Mes > 12 || Anio < 1900)
    {
        throw invalid_argument("\nEsta fecha es incorrecta\n");
    }
    else 
    {
        this->dia=Dia;
        this->mes=Mes;
        this->anio=Anio;
    }
}

int DtFecha::getAnio() const {
    return anio;
}

int DtFecha::getMes() const {
    return mes;
}

int DtFecha::getDia() const {
    return dia;
}

