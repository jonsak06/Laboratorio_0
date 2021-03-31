#include <iostream>

using namespace std;

int elegirOpcionDelMenu()
{
    int op;
    while (true)
    {
        cout << "\nElija la opcion:\n" << "1- Agregar puerto\n" << "2- Agregar barco\n" << "0- Salir\n";
        cin >> op;
        if(op == 1 || op == 2 || op == 0)
        {
            break; // o directamente return op; y borrar el de abajo
        }
    }
    return op;
}