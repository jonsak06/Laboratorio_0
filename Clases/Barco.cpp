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

Barco::Barco(DtBarco& barco) {
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

Barco* Barco::barcos[MAX_BARCOS-1] = {};
int Barco::ultimoBarco = 0;

bool Barco::existeBarco(string idBarco)
{
    for(int i=0;i<Barco::ultimoBarco;i++)
    {
        if(idBarco == Barco::barcos[i]->GetId())
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
        if(idBarcoPjs == Barco::barcos[i]->GetId())
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
        if(barco.GetId() == Barco::barcos[i]->GetId())//se utiliza flecha porque el array guarda punteros, no instancias de Barco
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
        Barco::barcos[Barco::ultimoBarco] = new BarcoPesquero(barco, capacidad, carga);//usa constructor que recibe (DtBarco&, capacidad, carga)
        Barco::ultimoBarco++;
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
        Barco::barcos[Barco::ultimoBarco] = new BarcoPasajeros(barco, cantidadPasajeros, tamanio); 
        Barco::ultimoBarco++;
        cout << "\nBarco agregado\n";
    }

}
