#include "Clases/Barco.h"
#include "Clases/BarcoPasajeros.h"
#include "Clases/BarcoPesquero.h"
#include "Datatypes/DtBarco.h"
#include "Datatypes/DtFecha.h"
#include "Datatypes/DtPuerto.h"
#include "Clases/Puerto.h"
#include "Clases/Sistema.h"

using namespace std;

DtFecha Sistema::fechaHoy = DtFecha();

int elegirOpcionDelMenu()
{
    while (true)
    {
        int op;
        cout << "\n             Elija la opcion:\n" << "/////////////////////////////////////////\n" 
                << "1- Agregar puerto\n" << "2- Agregar barco\n" << "3- Listar puertos\n" << "4- Agregar arribo\n" 
                << "x5- Obtener info de arribos en un puerto\n" << "x6- Eliminar arribos de un puerto\n" 
                << "7- Listar barcos\n" << "0- Salir\n" << "/////////////////////////////////////////\n";
        cin >> op;
        if(op == 1 || op == 2 || op == 3 || op == 4 || op == 7 || op == 0)
        {
            return op;
        }
    }
    return -1;
}

int main() {
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Bienvenido~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    Sistema sistema;

    int dia, mes, anio;
    do
    {
        cout << "\nFecha de hoy. ";
        try{
            cout << "\nIngrese la fecha en formato dd mm aaaa (separados por espacios): ";
            cin >> dia >> mes >> anio;
            Sistema::fechaHoy = DtFecha(dia, mes, anio);
        }catch(exception& e){
            cout << e.what() << endl;
        }
    }while(dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900);

    int opcion;

    do
    {
        opcion = elegirOpcionDelMenu();
        switch (opcion)
        {
            case 1:
            {
                string nombrePuerto, idPuerto;

                try{
                    cout << "\nIngrese el id del puerto: ";
                    getline(cin >> ws, idPuerto);
                    cout << "Ingrese el nombre del puerto: ";
                    getline(cin >> ws, nombrePuerto);
                    DtFecha fechaCreacion;
                    do {
                        cout << "Fecha de creacion del puerto. ";
                        try{
                            cout << "\nIngrese la fecha en formato dd mm aaaa (separados por espacios): ";
                            cin >> dia >> mes >> anio;
                            fechaCreacion = DtFecha(dia, mes, anio);
                        }catch(exception& e){
                            cout << e.what() << endl;
                        }
                    }while(dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900);

                    sistema.agregarPuerto(nombrePuerto, idPuerto, fechaCreacion);

                }catch(exception& e){
                    cout << e.what() << endl;
                }
            }
            break;
            
            case 2:
            {
                int opcionBarco;
                string nombreBarco, idBarco;
                int capacidad;
                int carga;
                int cantidadPasajeros;
                int tamanioElegido;
                TipoTamanio tamanio;

                while(true)
                {
                    cout << "Tipo de barco:\n" << "1- Barco pesquero\n" << "2- Barco de pasajeros\n";
                    cin >> opcionBarco;
                    if(opcionBarco == 1 || opcionBarco == 2)
                    {
                        break;
                    }
                }

                cout << "\nIngrese el nombre del barco: ";
                getline(cin >> ws, nombreBarco);
                cout << "Ingrese el id del barco: ";
                getline(cin >> ws, idBarco);
                
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
                    DtBarcoPesquero datavalueBarcoPesq(nombreBarco, idBarco, capacidad, carga);
                    DtBarco& dataValueBarco = datavalueBarcoPesq;
                    try
                    {
                        sistema.agregarBarco(dataValueBarco);
                    }
                    catch(exception& e)
                    {
                        cout << e.what() << endl;
                    }
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
                    DtBarcoPasajeros datavalueBarcoPsjs(nombreBarco, idBarco, cantidadPasajeros, tamanio);
                    DtBarco& dataValueBarco = datavalueBarcoPsjs; 

                    try
                    {
                        sistema.agregarBarco(dataValueBarco);
                    }
                    catch(exception& e)
                    {
                        cout << e.what() << endl;
                    }
                }
            }
            break;
        
            case 3:
            {
                DtPuerto* datosPuertos = sistema.listarPuertos();
                int posicionUltimoPuerto = sistema.obtenerPosicionUltimoPuerto();

                if(posicionUltimoPuerto == 0){
                    cout << "\nNo hay puertos en el sistema.\n";
                } else {
                    cout << "\n Informacion de los puertos:";
                    for(int i=0;i<posicionUltimoPuerto;i++)
                    {
                        cout << "\n/////////////////////////////\n";
                        cout << "Id: " << datosPuertos[i].getId() << endl;
                        cout << "Nombre: " << datosPuertos[i].getNombre() << endl;
                        cout << "Fecha de creacion: "   << datosPuertos[i].getFechaCreacion().getDia() << "/" 
                                                        << datosPuertos[i].getFechaCreacion().getMes() << "/" 
                                                        << datosPuertos[i].getFechaCreacion().getAnio() << endl;
                        cout << "Cantidad de arribos: " << datosPuertos[i].getCantArribos();
                    }
                    cout << "\n/////////////////////////////\n";
                    delete[] datosPuertos;
                }
            }
            break;

            case 4:
            {
                string idPuerto, idBarco;
                float cargaDespacho;
                cout << "Ingrese el id del puerto: ";
                getline(cin >> ws, idPuerto);
                cout << "Ingrese el id del barco: ";
                getline(cin >> ws, idBarco);
                cout << "Ingrese la carga a despachar: ";
                cin >> cargaDespacho;
                try {
                    sistema.agregarArribo(idPuerto, idBarco, cargaDespacho);
                }
                catch(exception& e)
                {
                    cout << e.what() << endl;
                }
            }
            break;

            case 7:
            {
                DtBarco** datosBarcos = sistema.listarBarcos();
                int posicionUltimoBarco = sistema.obtenerPosicionUltimoBarco();
                DtBarcoPesquero* barcoPesquero;
                if(posicionUltimoBarco == 0)
                {
                    cout << "\nNo hay barcos en el sistema.\n";
                } else {
                    //todos los cout de abajo se va a sustituir por cout << datosBarcos[i] una vez este sobrecargado el 
                    //operador en ambos hijos de DtBarco
                    cout << "\n Informacion de los barcos:";
                    for(int i=0;i<posicionUltimoBarco;i++)
                    {
                        if(DtBarcoPasajeros::esDeEsteTipo(datosBarcos[i]))
                        {
                            cout << "\n/////////////////////////////\n";
                            cout << "Nombre: " << datosBarcos[i]->getNombre() << endl;
                            cout << "Id: " << datosBarcos[i]->getId() << endl;
                            cout << "Tipo de barco: " << "pasajeros\n";
                            cout << "Cantidad de pasajeros: " << datosBarcos[i]->getCantPasajeros() << endl;
                            cout << "Tamanio: " << datosBarcos[i]->getTamanio();
                            //hacer un switch case para que muestre el tamanio y no el int al que corresponde
                            
                        } else {
                            cout << "\n/////////////////////////////\n";
                            cout << "Nombre: " << datosBarcos[i]->getNombre() << endl;
                            cout << "Id: " << datosBarcos[i]->getId() << endl;
                            cout << "Tipo de barco: " << "pesquero\n";
                            cout << "Capacidad: " << datosBarcos[i]->getCapacidad() << endl;
                            cout << "Carga: " << datosBarcos[i]->getCarga();
                        }
                    }
                    cout << "\n/////////////////////////////\n";
                    delete[] datosBarcos;
                }
            }
            break;

            default:
                break;
        } 
        
    } while(opcion);
    
    return 0;
}

