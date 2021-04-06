#include "Barco.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"
#include "../Otros/TipoTamanio.h"

Barco::Barco() {
}

Barco::Barco(const Barco& orig) {
    this->id=orig.getId();
    this->nombre=orig.getNombre();
}

Barco::~Barco() {
}

Barco::Barco(string Nombre, string Id) {
    this->nombre = Nombre;
    this->id = Id;
}

Barco::Barco(DtBarco& barco) {
    this->nombre = barco.getNombre();
    this->id = barco.getId();
}

void Barco::setId(string id) {
    this->id = id;
}

string Barco::getId() const {
    return id;
}

void Barco::setNombre(string nombre) {
    this->nombre = nombre;
}

string Barco::getNombre() const {
    return nombre;
}

Barco* Barco::barcos[MAX_BARCOS-1] = {};
int Barco::ultimoBarco = 0;

bool Barco::existeBarco(string idBarco)
{
    for(int i=0;i<Barco::ultimoBarco;i++)
    {
        if(idBarco == Barco::barcos[i]->getId())
        {
            return true;
        }
    }
    return false;
}

int Barco::getPosicionBarco(string idBarcoPjs)
{
    for(int i=0;i<Barco::ultimoBarco;i++)
    {
        if(idBarcoPjs == Barco::barcos[i]->getId())
        {
            return i;
        }
    }
    return -1;
}

int opcionBarco;
int capacidad;
int carga;
int cantidadPasajeros;
int tamanioElegido;
TipoTamanio tamanio;
void Barco::agregarBarco(DtBarco& barco)
{
    for(int i=0; i<Barco::ultimoBarco;i++)
    {
        if(barco.getId() == Barco::barcos[i]->getId())//se utiliza flecha porque el array guarda punteros, no instancias de Barco
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
        Barco::barcos[Barco::ultimoBarco] = new BarcoPesquero(barco, capacidad, carga);//usa constructor que recibe (DtBarco&, capacidad, carga)
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
