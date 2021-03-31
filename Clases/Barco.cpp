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
int ultimoBarcoPasajeros = 0;
int ultimoBarcoPesquero = 0;
int opcion;
int capacidad;
int carga;
int cantidadPasajeros;
int tamanioElegido;
TipoTamanio tamanio;
void Barco::agregarBarco(DtBarco& barco)
{
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
        for(int i=0; i<ultimoBarcoPesquero;i++)
        {
            if(barco.GetId()==BarcoPesquero::barcosPesqueros[i].GetId()){
                throw invalid_argument("El barco ya existe");
                return;
            }
        }
        cout << "Ingrese capacidad del barco: ";
        cin >> capacidad;
        while(true)
        {
            cout << "Ingrese la carga del barco: ";
            cin >> carga;
            if(carga > capacidad)
            {
                cout << "La capacidad debe ser mayor a la carga.\n";
            }else{
                break;
            }
        }
        BarcoPesquero barcoPesquero(barco.GetNombre(),barco.GetId(),capacidad,carga);
        cout << "Barco agregado\n";
    }
    else{
        for(int i=0; i<ultimoBarcoPasajeros;i++)
        {
            if(barco.GetId() == BarcoPasajeros::barcosPasajeros[i].GetId()){
                throw invalid_argument("El barco ya existe");
                return;
            }
        }
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
        BarcoPasajeros barcoPasajeros(barco.GetNombre(), barco.GetId(), cantidadPasajeros, tamanio);
        cout << "Barco agregado\n";
    }

}