#include "Barco.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"
#include "../Otros/TipoTamanio.h"

Barco::Barco() {
}

Barco::Barco(const Barco& orig) {
    this->id=orig.GetId();
    this->nombre=orig.GetNombre();
}

Barco::~Barco() {
}

Barco::Barco(string Nombre, string Id) {
    this->nombre = Nombre;
    this->id = Id;
}

Barco::Barco(DtBarco barco) {
    this->nombre = barco.GetNombre();
    this->id = barco.GetId();
}

void Barco::SetId(string id) {
    this->id = id;
}

string Barco::GetId() const {
    return id;
}

void Barco::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Barco::GetNombre() const {
    return nombre;
}

void Barco::arribar(float cargaDespacho) {
    
}

BarcoPasajeros BarcoPasajeros::barcosPasajeros[MAX_BARCOS/2-1] = {};
BarcoPesquero BarcoPesquero::barcosPesqueros[MAX_BARCOS/2-1] = {};
int Barco::ultimoBarcoPasajeros = 0;
int Barco::ultimoBarcoPesquero = 0;
int opcion;
int capacidad;
int carga;
int cantidadPasajeros;
int tamanioElegido;
TipoTamanio tamanio;
void Barco::agregarBarco(DtBarco& barco)
{
    for(int i=0; i<ultimoBarcoPesquero;i++)
    {
        if(barco.GetId() == BarcoPesquero::barcosPesqueros[i].GetId() 
        || barco.GetId() == BarcoPasajeros::barcosPasajeros[i].GetId())
        {
            throw invalid_argument("\nEl barco ya existe\n");
            return;
        }
    }
    while(true)
    {
        cout << "Tipo de barco:\n" << "1- Barco pesquero\n" << "2- Barco de pasajeros\n";
        cin >> opcion;
        if(opcion == 1 || opcion == 2)
        {
            break;
        }
    }
    
    if(opcion == 1)
    {
        cout << "Ingrese capacidad del barco: ";
        cin >> capacidad;
        while(true)
        {
            cout << "Ingrese la carga del barco: ";
            cin >> carga;
            if(carga > capacidad)
            {
                cout << "\nLa carga no puede ser mayor a la capacidad.\n";
            }else{
                break;
            }
        }
        BarcoPesquero::barcosPesqueros[ultimoBarcoPesquero] = BarcoPesquero(barco.GetNombre(),barco.GetId(),capacidad,carga);
        ultimoBarcoPesquero++;
        cout << "Barco agregado\n";
    }
    else{
        
        cout << "Ingrese la cantidad de pasajeros: ";
        cin >> cantidadPasajeros;
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
        BarcoPasajeros::barcosPasajeros[ultimoBarcoPasajeros] = BarcoPasajeros(barco.GetNombre(), barco.GetId(), cantidadPasajeros, tamanio);
        cout << "\nBarco agregado\n";
    }

}

bool Barco::existeBarcoPasajeros(string idBarcoPjs)
{
    for(int i=0;i<Barco::ultimoBarcoPasajeros;i++)
    {
        if(idBarcoPjs == BarcoPasajeros::barcosPasajeros[i].GetId())
        {
            return true;
        }
    }
    return false;
}

bool Barco::existeBarcoPesquero(string idBarcoPq)
{
    for(int i=0;i<Barco::ultimoBarcoPesquero;i++)
    {
        if(idBarcoPq == BarcoPesquero::barcosPesqueros[i].GetId())
        {
            return true;
        }
    }
    return false;
}

int Barco::getPosicionBarcoPasajeros(string idBarcoPjs)
{
    for(int i=0;i<BarcoPasajeros::ultimoBarcoPasajeros;i++)
    {
        if(idBarcoPjs == BarcoPasajeros::barcosPasajeros[i].GetId())
        {
            return i;
        }
    }
    return -1;
}

int Barco::getPosicionBarcoPesquero(string idBarcoPq)
{
    for(int i=0;i<BarcoPesquero::ultimoBarcoPesquero;i++)
    {
        if(idBarcoPq == BarcoPesquero::barcosPesqueros[i].GetId())
        {
            return i;
        }
    }
    return -1;
}