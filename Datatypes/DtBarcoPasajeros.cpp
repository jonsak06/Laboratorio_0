#include "DtBarcoPasajeros.h"

DtBarcoPasajeros::DtBarcoPasajeros() {
}

DtBarcoPasajeros::DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio) : DtBarco(nombre,id) {
    this->cantPasajeros=cantPasajeros;
    this->tamanio=tamanio;
}

DtBarcoPasajeros::~DtBarcoPasajeros() {
}

string DtBarcoPasajeros::getNombre() const {
    return this->nombre;
}

string DtBarcoPasajeros::getId () const {
    return this->id;
}

TipoTamanio DtBarcoPasajeros::getTamanio() const {
    return tamanio;
}

int DtBarcoPasajeros::getCantPasajeros() const {
    return cantPasajeros;
}

int DtBarcoPasajeros::getCapacidad() const {
}

int DtBarcoPasajeros::getCarga() const {
}

bool DtBarcoPasajeros::esDeEsteTipo(const DtBarco* barco) { 
    return (dynamic_cast<const DtBarcoPasajeros*>(barco) != NULL); 
}

void DtBarcoPasajeros::mostrarInfo(ostream&) {
    string tamanioBarco;
    switch (this->getTamanio())
    {
        case bote:
            tamanioBarco = "bote";
            break;
        case crucero:
            tamanioBarco = "crucero";
            break;
        case galeon:
            tamanioBarco = "galeon";
            break;
        case transatlantico:
            tamanioBarco = "transatlantico";
            break;
        default:
            break;
    }
    cout << "\n/////////////////////////////\n";
    cout << "Nombre: " << this->getNombre() << endl;
    cout << "Id: " << this->getId() << endl;
    cout << "Tipo de barco: " << "pasajeros\n";
    cout << "Cantidad de pasajeros: " << this->getCantPasajeros() << endl;
    cout << "Tamanio: " << tamanioBarco;
}