#include "Col.h"

Col::Col(){
}

Col::Col(const Col& orig){
}

Col::~Col(){
}

DtPuerto Col::datosPuertos[MAX_PUERTOS-1] = {};
int Col::ultimoDatavaluePuerto = 0;

Col::Col(DtPuerto datavaluePuerto) {
    Col::datosPuertos[Col::ultimoDatavaluePuerto] = datavaluePuerto;
    Col::ultimoDatavaluePuerto++;
}

Col colPuertos;
string nombrePuerto, idPuerto;
DtFecha fechaPuerto;
DtPuerto datavaluePuerto;
int ultimaPosicionPuerto, cantArribosPuerto; 

void Col::listarPuertos(){
    ultimaPosicionPuerto = Puerto::ultimoPuerto;
    if(ultimaPosicionPuerto == 0){
        cout << "\nNo hay puertos en el sistema.\n";
        return;
    }
    for(int i=0;i<ultimaPosicionPuerto;i++)
    {
        nombrePuerto = Puerto::puertos[i].getNombre();
        idPuerto = Puerto::puertos[i].getId();
        fechaPuerto = Puerto::puertos[i].getFechaCreacion();
        cantArribosPuerto = Puerto::puertos[i].ultimoArribo + 1;
        datavaluePuerto = DtPuerto(idPuerto, nombrePuerto, fechaPuerto, cantArribosPuerto); //la cantidad de arribos va a ser la cant que haya en el array que los contenga
        colPuertos = Col(datavaluePuerto);
    }
    cout << "\n Informacion de los puertos:";
    for(int i=0;i<ultimaPosicionPuerto;i++)
    {
        cout << "\n/////////////////////////////\n";
        cout << "Id: " << Col::datosPuertos[i].getId() << endl;
        cout << "Nombre: " << Col::datosPuertos[i].getNombre() << endl;
        cout << "Fecha de creacion: "   << Col::datosPuertos[i].getFechaCreacion().getDia() << "/" 
                                        << Col::datosPuertos[i].getFechaCreacion().getMes() << "/" 
                                        << Col::datosPuertos[i].getFechaCreacion().getAnio() << endl;
        cout << "Cantidad de arribos: " << Col::datosPuertos[i].getCantArribos();
    }
    cout << "\n/////////////////////////////\n";
}

DtBarco* Col::datosBarcos[MAX_BARCOS-1] = {};
int Col::ultimoDatavalueBarco = 0;

Col::Col(DtBarco* datavalueBarco) {
    Col::datosBarcos[Col::ultimoDatavalueBarco] = datavalueBarco;
    Col::ultimoDatavalueBarco++;
}

Col colBarcos;
string nombreBarco, idBarco;
int capacidadBarco, cargaBarco, cantPasajerosBarco;
TipoTamanio tamanioBarco;
DtBarco* datavalueBarco;
int ultimaPosicionBarco; 

void Col::listarBarcos(){
    ultimaPosicionBarco = Barco::ultimoBarco;
    if(ultimaPosicionBarco == 0)
    {
        cout << "\nNo hay barcos en el sistema.\n";
        return;
    }
    for(int i=0;i<ultimaPosicionBarco;i++)
    {
        nombreBarco = Barco::barcos[i]->getNombre();
        idBarco = Barco::barcos[i]->getId();

        if(Barco::barcos[i]->mostrarTipoBarco() == pesquero)
        {
            capacidadBarco = Barco::barcos[i]->getCapacidad();
            cargaBarco = Barco::barcos[i]->getCarga();
            datavalueBarco = new DtBarcoPesquero(nombreBarco, idBarco, capacidadBarco, cargaBarco);
        } else {
            cantPasajerosBarco = Barco::barcos[i]->getCantPasajeros();
            tamanioBarco = Barco::barcos[i]->getTamanio();
            datavalueBarco = new DtBarcoPasajeros(nombreBarco, idBarco, cantPasajerosBarco, tamanioBarco);
        }
        colBarcos = Col(datavalueBarco);
    }
    cout << "\n Informacion de los barcos:";
    for(int i=0;i<ultimaPosicionBarco;i++)
    {
        if(Barco::barcos[i]->mostrarTipoBarco() == pesquero)
        {
            cout << "\n/////////////////////////////\n";
            cout << "Nombre: " << Col::datosBarcos[i]->getNombre() << endl;
            cout << "Id: " << Col::datosBarcos[i]->getId() << endl;
            cout << "Tipo de barco: " << Col::datosBarcos[i]->getTipoBarco() << endl;
            cout << "Capacidad: " << Col::datosBarcos[i]->getCapacidad() << endl;
            cout << "Carga: " << Col::datosBarcos[i]->getCarga();
        } else {
            cout << "\n/////////////////////////////\n";
            cout << "Nombre: " << Col::datosBarcos[i]->getNombre() << endl;
            cout << "Id: " << Col::datosBarcos[i]->getId() << endl;
            cout << "Tipo de barco: " << Col::datosBarcos[i]->getTipoBarco() << endl;
            cout << "Cantidad de pasajeros: " << Col::datosBarcos[i]->getCantPasajeros() << endl;
            cout << "Tamanio: " << Col::datosBarcos[i]->getTamanio();
        }
    }
    cout << "\n/////////////////////////////\n";
}