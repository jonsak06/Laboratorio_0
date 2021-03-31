#include "Clases/Barco.h"
#include "Clases/BarcoPasajeros.h"
#include "Clases/BarcoPesquero.h"
#include "Datatypes/DtBarco.h"
#include "Otros/ColBarco.h"
#include "Datatypes/DtFecha.h"
#include "Datatypes/DtPuerto.h"
#include "Clases/Puerto.h"
#include "Otros/elegirOpcionDelMenu.cpp"

using namespace std;

DtFecha ingresarFecha();

int main() {


    //Test funcion agregar barco

    // DtBarco a = DtBarco("Hola","Chau");
    // DtBarco c = DtBarco("Como","Estas");
    // cout << a.GetNombre() << "---";
    // cout << a.GetId() << "\n";
    // cout << c.GetNombre() << "---";
    // cout << c.GetId() << "\n";
    // ColBarco b;
    // try{
    //     b.agregarBarco(a);
    //     b.agregarBarco(a);
    //     b.agregarBarco(c);
    // }catch(exception& e){
    //     cout << e.what() << endl;
    // }

    //Test funcion listar barcos
    /*DtBarco* d[30] = {new DtBarco()};
    d[30] = b.listarBarcos();
    for(int x=0;x<30;x++){
        cout << d[x]->GetNombre();
        cout << d[x]->GetId();
        cout << "\n";
    }*/

    cout << "Bienvenido." << endl;

    DtFecha hoy;
    cout << "Fecha de hoy. ";
    try{
        hoy = ingresarFecha();
    }catch(exception& e){
        cout << e.what() << endl;
    }
    cout << hoy.GetDia() << "/" << hoy.GetMes() << "/" << hoy.GetAnio() << endl;
    
    //variables de agregarPuerto
    int opcion;
    string nombrePuerto, idPuerto;
    //esto no es necesario, si lo dejamos seria para que se vea que usamos referencia:
    DtFecha fechaCreacionIngresada;
    DtFecha& fechaCreacion = fechaCreacionIngresada; //no es otra instancia, solamente una variable que apunta a lo mismo

    //variables de agregarBarco
    string nombreBarco, idBarco;
    DtBarco barco;

    do
    {
        opcion = elegirOpcionDelMenu();
        switch (opcion)
        {
        case 1:
            try{
                cout << "Ingrese el nombre del puerto: ";
                cin >> nombrePuerto;
                cout << "Ingrese el id del puerto: ";
                cin >> idPuerto;
                cout << "Fecha de creacion del puerto. ";
                try{
                    fechaCreacionIngresada = ingresarFecha();
                }catch(exception& e){
                    cout << e.what() << endl;
                }
                Puerto::agregarPuerto(nombrePuerto, idPuerto, fechaCreacion);
                cout << Puerto::puertos[0].GetFechaCreacion().GetAnio();
            }catch(exception& e){
                cout << e.what() << endl;
            }
            break;
        case 2:
            //Aun estoy trabajando en la operacion agregarBarco
            cout << "Ingrese el nombre del barco: ";
            cin >> nombreBarco;
            cout << "Ingreses el id del barco: ";
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
        
        default:
            break;
        }
    } while (opcion != 0);
    
    return 0;
}

