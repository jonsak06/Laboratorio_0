#include "../Datatypes/DtFecha.h"

DtFecha ingresarFecha()
{
    int dia, mes, anio;
    cout << "\nIngrese la fecha en formato dd mm aaaa (separados por espacios): ";
    cin >> dia >> mes >> anio;
    
    return DtFecha(dia, mes, anio);
}