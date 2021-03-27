#include "../H/Arribo.h"
using namespace std;

Arribo::Arribo() {
}

Arribo::Arribo(const Arribo& orig) {
    this->SetFecha(orig.GetFecha());
    this->SetCarga(orig.GetCarga());
}

Arribo::~Arribo() {
}

Arribo::Arribo(DtFecha fecha,float carga) {
    this->SetFecha(fecha);
    this->SetCarga(carga);
}

Arribo::Arribo(DtArribo arribo) {
    this->SetFecha(arribo.GetFecha());
    this->SetCarga(arribo.GetCarga());
}

void Arribo::SetCarga(float carga) {
    this->carga = carga;
}

float Arribo::GetCarga() const {
    return carga;
}

void Arribo::SetFecha(DtFecha fecha) {
    this->fecha = fecha;
}

DtFecha Arribo::GetFecha() const {
    return fecha;
}

