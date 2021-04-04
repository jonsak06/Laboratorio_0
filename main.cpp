#include "Clases/Barco.h"
#include "Clases/BarcoPasajeros.h"
#include "Clases/BarcoPesquero.h"
#include "Datatypes/DtBarco.h"
#include "Datatypes/DtFecha.h"
#include "Datatypes/DtPuerto.h"
#include "Clases/Puerto.h"
#include "Clases/Col.h"
#include "Otros/elegirOpcionDelMenu.cpp"

using namespace std;

DtFecha ingresarFecha();

int main() {
    {
        BarcoPesquero bp("a","a",5,5);
        cout << bp.GetNombre();
    }

    /*cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Bienvenido~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    DtFecha hoy;
    do
    {
        cout << "\nFecha de hoy. ";
        try{
            hoy = ingresarFecha();
        }catch(exception& e){
            cout << e.what() << endl;
        }
    }while(hoy.GetDia() < 1 || hoy.GetDia() > 31 || hoy.GetMes() < 1 || hoy.GetMes() > 12 || hoy.GetAnio() < 1900);
    cout << hoy.GetDia() << "/" << hoy.GetMes() << "/" << hoy.GetAnio() << endl;

    //variables de agregarPuerto
    int opcion;
    string nombrePuerto, idPuerto; 

    //variables de agregarBarco
    string nombreBarco, idBarco;
    DtBarco barco;

    //variables de agregarArribo
    string idPuertoArribos, idBarcoArribos;
    float cargaDespacho;
    Puerto puertoArribos;

    do
    {
        opcion = elegirOpcionDelMenu();
        switch (opcion)
        {
        case 1:
            try{
                cout << "\nIngrese el id del puerto: ";
                cin >> idPuerto;
                cout << "Ingrese el nombre del puerto: ";
                cin >> nombrePuerto;
                DtFecha fechaCreacion;
                do
                {
                    cout << "Fecha de creacion del puerto. ";
                    try{
                        fechaCreacion = ingresarFecha();
                    }catch(exception& e){
                        cout << e.what() << endl;
                    }
                } while (fechaCreacion.GetDia() < 1 || fechaCreacion.GetDia() > 31 
                        || fechaCreacion.GetMes() < 1 || fechaCreacion.GetMes() > 12 
                        || fechaCreacion.GetAnio() < 1900);
            
                Puerto::agregarPuerto(nombrePuerto, idPuerto, fechaCreacion);
                fechaCreacion.~DtFecha();
            }catch(exception& e){
                cout << e.what() << endl;
            }
            break;
        
        case 2:
            cout << "\nIngrese el nombre del barco: ";
            cin >> nombreBarco;
            cout << "Ingrese el id del barco: ";
            cin >> idBarco;
            barco = DtBarco(nombreBarco,idBarco);
            try
            {
                Barco::agregarBarco(barco);
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
            }
        
            break;
    
        case 3:
            Col::listarPuertos(); /*Lo correcto por lo que entiendo de la letra seria que este metodo devolviese un array y 
                                    luego mostrar el contenido aca directo o con otra funcion. En ese caso no se crearia el 
                                    Col::datosPuertos, se crearia un nuevo array cada vez que se llame la funcion*/
           /* break;

        case 4: //Mañana sigo con esta operacion, ando bastante trancado con segmentation faults y bad_allocs de las excepciones
            /*cout << "Ingrese el id del puerto: ";
            cin >> idPuertoArribos;
            cout << "Ingrese el id del barco: ";
            cin >> idBarcoArribos;
            cout << "Ingrese la carga a despachar: ";
            cin >> cargaDespacho;
            try {
                Puerto::agregarArribo(idPuertoArribos, idBarcoArribos, cargaDespacho);
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
            }  
            puertoArribos = Puerto::puertos[Puerto::getPosicionPuerto(idPuertoArribos)];
            puertoArribos.getArribos()[puertoArribos.ultimoArribo-1].SetFecha(hoy);
            for(int i=0;i<puertoArribos.ultimoArribo;i++)
            {
                cout << puertoArribos.getArribos()[i].GetCarga();
            }
            break;

        default:
            break;
        }
    } while (opcion != 0);*/
    
    return 0;
}

