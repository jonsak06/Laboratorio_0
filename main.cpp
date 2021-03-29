#include "./Otros/ColBarco.h"
#include "./Datatypes/DtBarco.h"
#include "./Clases/Barco.h"
#include "./Datatypes/DtFecha.h"
#include "./Datatypes/DtPuerto.h"
#include "./Clases/Puerto.h"
#include "./Otros/agregarPuerto.cpp"

using namespace std;

const int MAX_BARCOS = 49;

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

    // Test ingresar fecha
    // try{
    //     ingresarFecha();
    // }catch(exception& e){
    //     cout << e.what() << endl;
    // }

    //Test agregar puerto
    // DtFecha hoy(2,2,2000);
    // puertos[0] = Puerto("d","d",hoy);
    
    // try{
    //     agregarPuerto("Mont", "pue", hoy);
    //     cout << puertos[0].GetId();
    // }catch(exception& e){
    //     cout << e.what() << endl;
    // }
    // try{
    //     agregarPuerto("Mont", "pue", hoy);
    //     cout << puertos[1].GetId();
    // }catch(exception& e){
    //     cout << e.what() << endl;
    // }
    // try{
    //     agregarPuerto("Mont", "pue", hoy);
    //     cout << puertos[2].GetId();
    // }catch(exception& e){
    //     cout << e.what() << endl;
    // }

    return 0;
}

