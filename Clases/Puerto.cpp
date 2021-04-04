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

Puerto Puerto::puertos[MAX_PUERTOS-1] = {};//como es estatico se tiene que inicializar fuera de la clase
int Puerto::ultimoPuerto = 0;
void Puerto::agregarPuerto(string nombre, string id, DtFecha& fechaCreacion)
{
    for(int i=0; i<ultimoPuerto;i++)
    {
        if(id==Puerto::puertos[i].GetId()){
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
        if(idPuerto == Puerto::puertos[i].GetId())
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
        if(idPuerto == Puerto::puertos[i].GetId())
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

// Puerto puerto;
// Arribo arribo;
// Barco* barco;
// BarcoPasajeros barcoPj;
// BarcoPesquero barcoPq;
// void Puerto::agregarArribo(string idPuerto, string idBarco, float cargaDespacho)
// {
//     if(!Puerto::existePuerto(idPuerto))
//     {
//         throw invalid_argument("\nNo existe el Puerto.\n");
//         return;
//     }
//     else if(!Barco::existeBarcoPesquero(idBarco) && !Barco::existeBarcoPasajeros(idBarco))
//     {
//         throw invalid_argument("\nNo existe el Barco.\n");
//         return;
//     }
//     else if(cargaDespacho && Barco::existeBarcoPasajeros(idBarco))
//     {
//         throw invalid_argument("\nEl barco es de pasajeros, no puede despachar carga\n");
//         return;
//     }
//     else if(-cargaDespacho > BarcoPesquero::barcosPesqueros[Barco::getPosicionBarcoPesquero(idBarco)].GetCapacidad())
//     {
//         throw invalid_argument("\nLa capacidad del barco no es suficiente\n");
//         return;
//     }
//     else if(cargaDespacho > BarcoPesquero::barcosPesqueros[Barco::getPosicionBarcoPesquero(idBarco)].GetCarga())
//     {
//         throw invalid_argument("\nEl barco no tiene suficiente carga\n");
//         return;
//     }
//     else
//     {
//         if(Barco::existeBarcoPasajeros) {
//             barcoPj = BarcoPasajeros::barcosPasajeros[Barco::getPosicionBarcoPasajeros(idBarco)];
//         }
//         else {
//             barcoPq =  BarcoPesquero::barcosPesqueros[Barco::getPosicionBarcoPesquero(idBarco)];
//         }
//         puerto = Puerto::puertos[Puerto::getPosicionPuerto(idPuerto)];
//         arribo.SetCarga(cargaDespacho + BarcoPesquero::barcosPesqueros[Barco::getPosicionBarcoPesquero(idBarco)].GetCarga());
//         arribo.setBarco(barco);
//         puerto.setArribo(arribo);
//         barcoPq.arribar(cargaDespacho);
//         Puerto::puertos[Puerto::getPosicionPuerto(idPuerto)].setArribo(arribo);
//     }
    
// }