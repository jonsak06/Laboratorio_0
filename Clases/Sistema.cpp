#include "Sistema.h"

Sistema::Sistema() {
}

Sistema::~Sistema() {
}

Puerto Puerto::puertos[MAX_PUERTOS-1] = {};
int Puerto::ultimoPuerto = 0;
void Sistema::agregarPuerto(string nombre, string id, DtFecha& fechaCreacion)
{
    for(int i=0; i<Puerto::ultimoPuerto;i++)
    {
        if(id==Puerto::puertos[i].getId()){
            throw invalid_argument("\nEl puerto ya existe\n");
            return;
        }
    }
    DtPuerto datavaluePuerto(nombre, id, fechaCreacion, 0);
    Puerto::puertos[Puerto::ultimoPuerto] = Puerto(datavaluePuerto);
    Puerto::ultimoPuerto++;
    cout << "\nPuerto agregado.\n";
}

int Sistema::obtenerPosicionUltimoPuerto() {
    return Puerto::ultimoPuerto;
}

void Sistema::agregarArribo(string idPuerto, string idBarco, float cargaDespacho)
{
    if(!Puerto::existePuerto(idPuerto))
    {
        throw invalid_argument("\nNo existe el Puerto.\n");
    }
    else if(!Barco::existeBarco(idBarco))
    {
        throw invalid_argument("\nNo existe el Barco.\n");
    }
    else if(cargaDespacho && (BarcoPasajeros::esDeEsteTipo(Barco::barcos[Barco::obtenerPosicionBarco(idBarco)])) )
    {
        throw invalid_argument("\nEl barco es de pasajeros, no puede despachar carga\n");
    }
    else if( (BarcoPesquero::esDeEsteTipo(Barco::barcos[Barco::obtenerPosicionBarco(idBarco)])) &&
            (-cargaDespacho > ( Barco::barcos[Barco::obtenerPosicionBarco(idBarco)]->getCapacidad() 
            - Barco::barcos[Barco::obtenerPosicionBarco(idBarco)]->getCarga()) ) )
    {
        throw invalid_argument("\nLa capacidad del barco no es suficiente\n");
    }
    else if(cargaDespacho > Barco::barcos[Barco::obtenerPosicionBarco(idBarco)]->getCarga())
    {
        throw invalid_argument("\nEl barco no tiene suficiente carga\n");
    }
    else
    {
        Barco* barco = Barco::barcos[Barco::obtenerPosicionBarco(idBarco)];
        Puerto& puerto = Puerto::puertos[Puerto::obtenerPosicionPuerto(idPuerto)];
        Arribo arribo(Sistema::fechaHoy, cargaDespacho, barco);
        puerto.setArribo(arribo);
        if(BarcoPesquero::esDeEsteTipo(barco))
        {
            arribo.setCarga(cargaDespacho);
        }
        barco->arribar(cargaDespacho);
        cout << "\nArribo agregado\n";
    }
}

DtPuerto* Sistema::listarPuertos(){
    string nombrePuerto, idPuerto;
    DtFecha fechaPuerto;
    int cantArribosPuerto; 
    int ultimaPosicionPuerto = Puerto::ultimoPuerto;
    DtPuerto* datosPuertos = new DtPuerto[MAX_PUERTOS-1];

    for(int i=0;i<ultimaPosicionPuerto;i++)
    {
        nombrePuerto = Puerto::puertos[i].getNombre();
        idPuerto = Puerto::puertos[i].getId();
        fechaPuerto = Puerto::puertos[i].getFechaCreacion();
        cantArribosPuerto = Puerto::puertos[i].ultimoArribo;
        datosPuertos[i] = DtPuerto(nombrePuerto, idPuerto, fechaPuerto, cantArribosPuerto);
    }
    return datosPuertos;   
}

void Sistema::agregarBarco(DtBarco& barco)
{
    if(Barco::existeBarco(barco.getId()))
    {
        throw invalid_argument("\nEl barco ya existe\n");
        return;
    }

    try {//esta es una forma de aplicar el dynamic_cast con referencias en lugar de punteros
        DtBarcoPesquero& barcoPesq = dynamic_cast<DtBarcoPesquero&>(barco);
        Barco::barcos[Barco::ultimoBarco] = new BarcoPesquero(barco);
        Barco::ultimoBarco++;
    } catch(bad_cast) {
        Barco::barcos[Barco::ultimoBarco] = new BarcoPasajeros(barco);
        Barco::ultimoBarco++;
    }

    cout << "Barco agregado\n";
}

DtBarco** Sistema::listarBarcos() {
    string nombre, id;
    int capacidad, carga, cantPasajeros;
    TipoTamanio tamanioBarco;
    DtBarco** datosBarcos = new DtBarco*[MAX_BARCOS-1];
    int ultimaPosicion = Barco::ultimoBarco;

    for(int i=0;i<ultimaPosicion;i++)
    {
        nombre = Barco::barcos[i]->getNombre();
        id = Barco::barcos[i]->getId();

        if(BarcoPesquero::esDeEsteTipo(Barco::barcos[i]))
        {
            capacidad = Barco::barcos[i]->getCapacidad();
            carga = Barco::barcos[i]->getCarga();
            datosBarcos[i] = new DtBarcoPesquero(nombre, id, capacidad, carga);
        } else {
            cantPasajeros = Barco::barcos[i]->getCantPasajeros();
            tamanioBarco = Barco::barcos[i]->getTamanio();
            datosBarcos[i] = new DtBarcoPasajeros(nombre, id, cantPasajeros, tamanioBarco);
        }
    }
    return datosBarcos;
}

int Sistema::obtenerPosicionUltimoBarco() {
    return Barco::ultimoBarco;
}

DtArribo** Sistema::obtenerInfoArribosEnPuerto(string idPuerto) {
    if(!Puerto::existePuerto(idPuerto))
    {
        throw invalid_argument("\nNo existe el Puerto.\n");
    }
    else {
        DtArribo** datosArribos = new DtArribo*[29];
        Puerto& puerto = Puerto::puertos[Puerto::obtenerPosicionPuerto(idPuerto)];
        int ultimaPosicionArribo = puerto.ultimoArribo;
        Barco* barco;
        for(int i=0; i<ultimaPosicionArribo; i++)
        {
            barco = puerto.getArribos()[i].getBarco();

            cout << puerto.getArribos()[i].getBarco()->getNombre() << " ";
            /*en los arribos el barco esta bien, el problema lo mas seguro siga siendo la referencia en la lista de 
            incializacion*/

            if(BarcoPesquero::esDeEsteTipo(barco))
            {
                DtBarcoPesquero dvBarcoPesquero(barco->getNombre(), barco->getId(), barco->getCapacidad(), barco->getCarga());
                datosArribos[i] = new DtArribo(puerto.getArribos()[i].getFecha(), puerto.getArribos()[i].getCarga(), dvBarcoPesquero);
            } else {
                DtBarcoPasajeros dvBarcoPasajeros(barco->getNombre(), barco->getId(), barco->getCantPasajeros(), barco->getTamanio());
                datosArribos[i] = new DtArribo(puerto.getArribos()[i].getFecha(), puerto.getArribos()[i].getCarga(), dvBarcoPasajeros);
            }
        }
        return datosArribos;
    }
}

int Sistema::obtenerPosicionUltimoArribo(string idPuerto) {
    return Puerto::puertos[Puerto::obtenerPosicionPuerto(idPuerto)].ultimoArribo;
}