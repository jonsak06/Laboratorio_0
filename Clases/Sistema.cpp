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
    Arribo arribo;
    Barco* barco;
    Puerto puerto;

    if(!Puerto::existePuerto(idPuerto))// es el unico que da problemas de bad_alloc y segmentation faults
    {
        throw invalid_argument("\nNo existe el Puerto.\n");
    }
    else if(!Barco::existeBarco(idBarco))
    {
        throw invalid_argument("\nNo existe el Barco.\n");
    }
    else if(cargaDespacho && (BarcoPasajeros::esEsteTipo(Barco::barcos[Barco::getPosicionBarco(idBarco)])) )
    {
        throw invalid_argument("\nEl barco es de pasajeros, no puede despachar carga\n");
    }
    else if( (BarcoPesquero::esEsteTipo(Barco::barcos[Barco::getPosicionBarco(idBarco)])) &&
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
        if(BarcoPesquero::esEsteTipo(barco))
        {
            arribo.setCarga(cargaDespacho);
        }
        arribo.setBarco(barco);
        barco->arribar(cargaDespacho);
        puerto.setArribo(arribo);
        cout << puerto.getArribos()[0].getCarga() << "\t" << puerto.getArribos()[0].getFecha().getAnio() << "\t";
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
    int opcionBarco;
    int capacidad;
    int carga;
    int cantidadPasajeros;
    int tamanioElegido;
    TipoTamanio tamanio;

    for(int i=0; i<Barco::ultimoBarco;i++)
    {
        if(barco.getId() == Barco::barcos[i]->getId())
        {
            throw invalid_argument("\nEl barco ya existe\n");
            return;
        }
    }
    while(true)
    {
        cout << "Tipo de barco:\n" << "1- Barco pesquero\n" << "2- Barco de pasajeros\n";
        cin >> opcionBarco;
        if(opcionBarco == 1 || opcionBarco == 2)
        {
            break;
        }
    }
    
    if(opcionBarco == 1)
    {
        while(true)
        {
            cout << "Ingrese capacidad del barco: ";
            cin >> capacidad;
            if(capacidad < 0)
            {
                cout << "\nLa capacidad debe ser mayor o igual a 0\n";
            }
            else {
                break;
            }
        }
        while(true)
        {
            cout << "Ingrese la carga del barco: ";
            cin >> carga;
            if(carga < 0)
            {
                cout << "\nLa carga no puede ser menor a 0.\n";
            }
            else if(carga > capacidad)
            {
                cout << "\nLa carga no puede ser mayor a la capacidad.\n";
            }
            else {
                break;
            }
        }
        Barco::barcos[Barco::ultimoBarco] = new BarcoPesquero(barco, capacidad, carga);
        Barco::ultimoBarco++;
        cout << "Barco agregado\n";
    }
    else {
        while(true)
        {
            cout << "Ingrese la cantidad de pasajeros: ";
            cin >> cantidadPasajeros;
            if (cantidadPasajeros < 0)
            {
                cout << "\nLa cantidad de pasajeros debe ser mayor o igual a 0\n";
            }
            else {
                break;
            }
        }
        while(true)
        {
            cout << "Elija el tamanio del barco:\n" << "1- Bote\n" << "2- Crucero\n" << "3- Galeon\n" << "4- Transatlantico\n";
            cin >> tamanioElegido;
            if(tamanioElegido == 1 || tamanioElegido == 2 || tamanioElegido == 3 || tamanioElegido == 4)
            {
                break;
            }
        }
        switch (tamanioElegido)
        {
            case 1:
                tamanio = bote;
                break;
            case 2:
                tamanio = crucero;
                break;
            case 3:
                tamanio = galeon;
                break;
            case 4:
                tamanio = transatlantico;
                break;
            default:
                break;
        }
        Barco::barcos[Barco::ultimoBarco] = new BarcoPasajeros(barco, cantidadPasajeros, tamanio); 
        Barco::ultimoBarco++;
        cout << "\nBarco agregado\n";
    }

}

DtBarco** Sistema::listarBarcos() {
    string nombre, id;
    int capacidad, carga, cantPasajeros;
    TipoTamanio tamanioBarco;
    DtBarco** datosBarcos = new DtBarco*[MAX_BARCOS-1];
    int ultimaPosicion = Barco::ultimoBarco;
    BarcoPasajeros* barcoPasajeros;
    BarcoPesquero* barcoPesquero;

    for(int i=0;i<ultimaPosicion;i++)
    {
        nombre = Barco::barcos[i]->getNombre();
        id = Barco::barcos[i]->getId();

        if(BarcoPesquero::esEsteTipo(Barco::barcos[i]))
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