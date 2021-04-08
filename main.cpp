#include "Clases/Barco.h"
#include "Clases/BarcoPasajeros.h"
#include "Clases/BarcoPesquero.h"
#include "Datatypes/DtBarco.h"
#include "Datatypes/DtFecha.h"
#include "Datatypes/DtPuerto.h"
#include "Clases/Puerto.h"
#include "Clases/Sistema.h"

using namespace std;

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

DtFecha ingresarFecha()
{
    int dia, mes, anio;
    cout << "\nIngrese la fecha en formato dd mm aaaa (separados por espacios): ";
    cin >> dia >> mes >> anio;
    
    return DtFecha(dia, mes, anio);
}

int main() {
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Bienvenido~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    Sistema sistema;
    DtFecha hoy;
    
    do //en lugar de esto se podria usar libreria para tomar la fecha del dia
    {
        cout << "\nFecha de hoy. ";
        try{
            hoy = ingresarFecha();
        }catch(exception& e){
            cout << e.what() << endl;
        }
    }while(hoy.getDia() < 1 || hoy.getDia() > 31 || hoy.getMes() < 1 || hoy.getMes() > 12 || hoy.getAnio() < 1900);
    cout << hoy.getDia() << "/" << hoy.getMes() << "/" << hoy.getAnio() << endl;
    sistema.setFechaHoy(hoy);

    int opcion;

    do
    {
        opcion = elegirOpcionDelMenu();
        switch (opcion)
        {
            case 1:/*el do while de fechaCreacion funca solo la primera vez que hay error en la fecha, a partir de la segunda 
                    queda guardada la fecha anterior correcta y el puerto se crea con esa. Hay un problema con el destructor de 
                    DtFecha, si se coloca un cout dentro se puede ver que se llama multiples veces*/
            {
                string nombrePuerto, idPuerto;

                try{
                    cout << "\nIngrese el id del puerto: ";
                    getline(cin >> ws, idPuerto);
                    cout << "Ingrese el nombre del puerto: ";
                    getline(cin >> ws, nombrePuerto);
                    DtFecha fechaCreacion;
                    do
                    {
                        cout << "Fecha de creacion del puerto. ";
                        try{
                            fechaCreacion = ingresarFecha();
                        }catch(exception& e){
                            cout << e.what() << endl;
                        }
                    } while (fechaCreacion.getDia() < 1 || fechaCreacion.getDia() > 31 
                            || fechaCreacion.getMes() < 1 || fechaCreacion.getMes() > 12 
                            || fechaCreacion.getAnio() < 1900);

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
                        cout << "Cantidad de arribos: " << datosPuertos[i].getCantArribos();//no esta funcionando
                    }
                    cout << "\n/////////////////////////////\n";
                    delete[] datosPuertos;
                }
            }
            break;

            case 4:
            {
                string idPuertoArribos, idBarcoArribos;
                float cargaDespacho;
                Puerto puertoArribos;
                cout << "Ingrese el id del puerto: ";//tira segmentation fault si el puerto no existe
                cin >> idPuertoArribos;
                cout << "Ingrese el id del barco: ";
                cin >> idBarcoArribos;
                cout << "Ingrese la carga a despachar: ";
                cin >> cargaDespacho;
                try {
                    sistema.agregarArribo(idPuertoArribos, idBarcoArribos, cargaDespacho);
                }
                catch(exception& e)
                {
                    cout << e.what() << endl;
                }
                //hay problemas con los arribos del puerto
                puertoArribos = Puerto::puertos[Puerto::obtenerPosicionPuerto(idPuertoArribos)];
                puertoArribos.getArribos()[puertoArribos.ultimoArribo-1].setFecha(hoy);
                for(int i=0;i<puertoArribos.ultimoArribo;i++)
                {
                    cout << puertoArribos.getArribos()[i].getCarga();
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

