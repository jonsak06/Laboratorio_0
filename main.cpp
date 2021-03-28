#include <cstdlib>
#include <iostream>
#include <string>

#include "./Otros/ColBarco.h"
#include "./Datatypes/DtBarco.h"
#include "./Clases/Barco.h"

using namespace std;

int main(int argc, char** argv) {
    //Test funcion agregar barco
    DtBarco a = DtBarco("Hola","Chau");
    DtBarco c = DtBarco("Como","Estas");
    cout << a.GetNombre() << "---";
    cout << a.GetId() << "\n";
    cout << c.GetNombre() << "---";
    cout << c.GetId() << "\n";
    ColBarco b;
    try{
        b.agregarBarco(a);
        b.agregarBarco(a);
        b.agregarBarco(c);
    }catch(exception& e){
        cout << e.what();
    }
    
    //Test funcion listar barcos
    /*DtBarco* d[30] = {new DtBarco()};
    d[30] = b.listarBarcos();
    for(int x=0;x<30;x++){
        cout << d[x]->GetNombre();
        cout << d[x]->GetId();
        cout << "\n";
    }*/
    return 0;
}

