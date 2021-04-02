#include <iostream>

using namespace std;

int elegirOpcionDelMenu()
{
    int op;
    while (true)
    {
        cout << "\n             Elija la opcion:\n" << "//////////////////////////////////////////\n" << "1- Agregar puerto\n" 
                << "2- Agregar barco\n" << "3- Listar puertos\n" << "4- Agregar arribo\n" 
                << "x5- Obtener info de arribos en un puerto\n" << "x6- Eliminar arribos de un puerto\n" 
                << "x7- Listar barcos\n" <<"0- Salir\n";
        cin >> op;
        if(op == 1 || op == 2 || op == 3 || op == 4 || op == 0)
        {
            break; // o directamente return op; y borrar el de abajo
        }
    }
    return op;
}