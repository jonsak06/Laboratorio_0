#include "Col.h"

Col::Col(){
}

Col::Col(const Col& orig){
}

Col::~Col(){
}

int Col::ultimoDatavaluePuerto = 0;
DtPuerto Col::datosPuertos[MAX_PUERTOS-1] = {};

Col::Col(DtPuerto datavaluePuerto) {
    Col::datosPuertos[Col::ultimoDatavaluePuerto] = datavaluePuerto;
    Col::ultimoDatavaluePuerto++;
}

void Col::SetUltomoDatavaluePuerto(int n){
    Col::ultimoDatavaluePuerto = n;
}

Col colPuertos;
string nombre, id;
DtFecha fecha;
DtPuerto datavaluePuerto;
int ultimaPosicion; /*tuve que crear otra variable porque si cambio ultimoDatavaluePuerto dentro de listarPuertos
                    me tira segmentation fault*/

void Col::listarPuertos(){
    ultimaPosicion = Puerto::ultimoPuerto;
    if(ultimaPosicion == 0){
        cout << "\nNo hay puertos en el sistema.\n";
        return;
    }
    for(int i=0;i<ultimaPosicion;i++)
    {
        nombre = Puerto::puertos[i].GetNombre();
        id = Puerto::puertos[i].GetId();
        fecha = Puerto::puertos[i].GetFechaCreacion();
        datavaluePuerto = DtPuerto(id, nombre, fecha, 0); //la cantidad de arribos va a ser la cant que haya en el array que los contenga
        colPuertos = Col(datavaluePuerto);
    }
    cout << "\n Informacion de los puertos:\n";
    for(int i=0;i<ultimaPosicion;i++)
    {
        cout << "\n/////////////////////////////\n";
        cout << "Id: " << Col::datosPuertos[i].GetId() << endl;
        cout << "Nombre: " << Col::datosPuertos[i].GetNombre() << endl;
        cout << "Fecha de creacion: "   << Col::datosPuertos[i].GetFechaCreacion().GetDia() << "/" 
                                        << Col::datosPuertos[i].GetFechaCreacion().GetMes() << "/" 
                                        << Col::datosPuertos[i].GetFechaCreacion().GetAnio() << endl;
        cout << "Cantidad de arribos: " << Col::datosPuertos[i].GetCantArribos() << endl;
    }
    cout << "/////////////////////////////\n";
}