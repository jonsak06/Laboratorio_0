#include "../H/Puerto.h"
using namespace std;

Puerto::Puerto() {
}

Puerto::Puerto(const Puerto& orig) {
}

Puerto::~Puerto() {
}

Puerto::Puerto(string nombre,string id,DtFecha fecha) {
    this->SetNombre(nombre);
    this->SetId(id);
    this->SetFechaCreacion(fecha);
}

Puerto::Puerto(DtPuerto puerto){
    this->SetNombre(puerto.GetNombre());
    this->SetId(puerto.GetId());
    this->SetFechaCreacion(puerto.GetFechaCreacion());
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

