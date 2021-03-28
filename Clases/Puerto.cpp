#include "Puerto.h"

Puerto::Puerto() {
}

Puerto::Puerto(const Puerto& orig) {
}

Puerto::~Puerto() {
}

Puerto::Puerto(string Nombre,string Id,DtFecha Fecha) {
    this->nombre = Nombre;
    this->id = Id;
    this->fechaCreacion = Fecha;
}

Puerto::Puerto(DtPuerto puerto){
    this->nombre = puerto.GetNombre();
    this->id = puerto.GetId();
    this->fechaCreacion = puerto.GetFechaCreacion();
}

void Puerto::SetFechaCreacion(DtFecha fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

DtFecha Puerto::GetFechaCreacion() const {
    return fechaCreacion;
}

void Puerto::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Puerto::GetNombre() const {
    return nombre;
}

void Puerto::SetId(string id) {
    this->id = id;
}

string Puerto::GetId() const {
    return id;
}

