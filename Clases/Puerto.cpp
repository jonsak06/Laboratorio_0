#include "Puerto.h"

Puerto::Puerto() {
}

Puerto::Puerto(const Puerto& orig) {
}

Puerto::~Puerto() {
}

Puerto::Puerto(string nombre,string id,DtFecha fechaCreacion) {
    this->nombre = nombre;
    this->id = id;
    this->fechaCreacion = fechaCreacion;
}

Puerto::Puerto(DtPuerto puerto){
    this->nombre = puerto.getNombre();
    this->id = puerto.getId();
    this->fechaCreacion = puerto.getFechaCreacion();
}

void Puerto::setFechaCreacion(DtFecha fechaCreacion) {
    this->fechaCreacion = fechaCreacion;
}

DtFecha Puerto::getFechaCreacion() const {
    return fechaCreacion;
}

void Puerto::setNombre(string nombre) {
    this->nombre = nombre;
}

string Puerto::getNombre() const {
    return nombre;
}

void Puerto::setId(string id) {
    this->id = id;
}

string Puerto::getId() const {
    return id;
}

bool Puerto::existePuerto(string idPuerto)
{
    for(int i=0;i<Puerto::ultimoPuerto;i++)
    {
        if(idPuerto == Puerto::puertos[i].getId())
        {
            return true;
        }
    }
    return false;
}

void Puerto::setArribo(Arribo arribo)
{
    this->arribos[this->ultimoArribo] = arribo;
    this->ultimoArribo++;
}

int Puerto::obtenerPosicionPuerto(string idPuerto)
{
    for(int i=0;i<Puerto::ultimoPuerto;i++)
    {
        if(idPuerto == Puerto::puertos[i].getId())
        {
            return i;
        }
    }
    return -1;
}

Arribo* Puerto::getArribos()
{
    return this->arribos;
}

void Puerto::setArribos(Arribo* nuevoArray, int nuevaUltimaPosicion) {
    for(int i=0; i<nuevaUltimaPosicion; i++)
    {
        this->arribos[i] = nuevoArray[i];
    }
    for(int i=nuevaUltimaPosicion; i<this->ultimoArribo; i++)
    {
        this->arribos[i].~Arribo();
    }
    this->ultimoArribo = nuevaUltimaPosicion;
}