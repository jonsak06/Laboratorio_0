#include "Puerto.h"

Puerto::Puerto() {
}

Puerto::Puerto(const Puerto& orig) {
}

Puerto::~Puerto() {
    //cout << "\nPuerto destruido\n";
}

Puerto::Puerto(string Nombre,string Id,DtFecha Fecha) {
    this->nombre = Nombre;
    this->id = Id;
    this->fechaCreacion = Fecha;
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

Puerto Puerto::puertos[MAX_PUERTOS-1] = {};//como es estatico se tiene que inicializar fuera de la clase
int Puerto::ultimoPuerto = 0;
void Puerto::agregarPuerto(string nombre, string id, DtFecha& fechaCreacion)
{
    for(int i=0; i<ultimoPuerto;i++)
    {
        if(id==Puerto::puertos[i].getId()){
            throw invalid_argument("\nEl puerto ya existe\n");
            return;
        }
    }
    Puerto::puertos[ultimoPuerto] = Puerto(nombre, id, fechaCreacion);
    ultimoPuerto++;
    cout << "\nPuerto agregado.\n";
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

int Puerto::getPosicionPuerto(string idPuerto)
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

Arribo arribo;
Barco* barco;
Puerto puerto;
void Puerto::agregarArribo(string idPuerto, string idBarco, float cargaDespacho)
{
    if(!Puerto::existePuerto(idPuerto))// es el unico que da problemas de bad_alloc y segmentation faults
    {
        throw invalid_argument("\nNo existe el Puerto.\n");
    }
    else if(!Barco::existeBarco(idBarco))
    {
        throw invalid_argument("\nNo existe el Barco.\n");
    }
    else if(cargaDespacho && (Barco::barcos[Barco::getPosicionBarco(idBarco)]->mostrarTipoBarco() == pasajeros))
    {
        throw invalid_argument("\nEl barco es de pasajeros, no puede despachar carga\n");
    }
    else if( (Barco::barcos[Barco::getPosicionBarco(idBarco)]->mostrarTipoBarco() == pesquero) &&
            (-cargaDespacho > ( Barco::barcos[Barco::getPosicionBarco(idBarco)]->getCapacidad() 
            - Barco::barcos[Barco::getPosicionBarco(idBarco)]->getCarga()) ) )
    {
        throw invalid_argument("\nLa capacidad del barco no es suficiente\n");
    }
    else if(cargaDespacho > Barco::barcos[Barco::getPosicionBarco(idBarco)]->getCarga())
    {
        throw invalid_argument("\nEl barco no tiene suficiente carga\n");
    }
    else
    {
        barco = Barco::barcos[Barco::getPosicionBarco(idBarco)];
        puerto = Puerto::puertos[Puerto::getPosicionPuerto(idPuerto)];
        if(barco->mostrarTipoBarco() == pesquero)
        {
            arribo.setCarga(cargaDespacho + barco->getCarga());
        }
        arribo.setBarco(barco);
        barco->arribar(cargaDespacho);
        puerto.setArribo(arribo);
        cout << puerto.getArribos()[0].getCarga() << "\t" << puerto.getArribos()[0].getFecha().getAnio() << "\t";
        cout << "\nArribo agregado\n";
    }
    
}