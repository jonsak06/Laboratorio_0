#include "Clases/Barco.h"
#include "Clases/BarcoPasajeros.h"
#include "Clases/BarcoPesquero.h"
#include "Datatypes/DtBarco.h"
#include "Datatypes/DtFecha.h"
#include "Datatypes/DtPuerto.h"
#include "Clases/Puerto.h"
#include "Clases/Col.h"
#include "Otros/elegirOpcionDelMenu.cpp"
#include "Clases/Sistema.h"

using namespace std;

DtFecha ingresarFecha();

int main() {
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Bienvenido~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    Sistema sistema;
    DtFecha hoy;
    //en lugar de esto usar libreria para tomar la fecha del dia
    do
    {
        cout << "\nFecha de hoy. ";
        try{
            hoy = ingresarFecha();
        }catch(exception& e){
            cout << e.what() << endl;
        }
    }while(hoy.getDia() < 1 || hoy.getDia() > 31 || hoy.getMes() < 1 || hoy.getMes() > 12 || hoy.getAnio() < 1900);
    cout << hoy.getDia() << "/" << hoy.getMes() << "/" << hoy.getAnio() << endl;
    sistema.fechaHoy = hoy;

    int opcion;

    do
    {
        opcion = elegirOpcionDelMenu();
        switch (opcion)
        {
            case 1:/*el do while funca solo la primera vez que hay error en la fecha, a partir de la segunda queda guardada 
                    la fecha anterior y el puerto se crea con la misma, hay un problema con el destructor de DtFecha, si se 
                    muestra algo en la terminal se ve que se llama multiples veces*/
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
                string nombreBarco, idBarco;
                DtBarco barco;
                cout << "\nIngrese el nombre del barco: ";
                getline(cin >> ws, nombreBarco);
                cout << "Ingrese el id del barco: ";
                getline(cin >> ws, idBarco);
                barco = DtBarco(nombreBarco,idBarco);
                try
                {
                    sistema.agregarBarco(barco);
                }
                catch(exception& e)
                {
                    cout << e.what() << endl;
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
                string idPuertoArribos, idBarcoArribos;
                float cargaDespacho;
                Puerto puertoArribos;
                cout << "Ingrese el id del puerto: ";
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
                puertoArribos = Puerto::puertos[Puerto::getPosicionPuerto(idPuertoArribos)];
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
                    cout << "\n Informacion de los barcos:";
                    for(int i=0;i<posicionUltimoBarco;i++)
                    {
                        if(DtBarcoPasajeros::esEsteTipo(datosBarcos[i]))
                        {
                            cout << "\n/////////////////////////////\n";
                            cout << "Nombre: " << datosBarcos[i]->getNombre() << endl;
                            cout << "Id: " << datosBarcos[i]->getId() << endl;
                            cout << "Tipo de barco: " << "pasajeros\n";
                            cout << "Cantidad de pasajeros: " << datosBarcos[i]->getCantPasajeros() << endl;
                            cout << "Tamanio: " << datosBarcos[i]->getTamanio();
                            
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

