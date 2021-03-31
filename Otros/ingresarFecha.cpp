#include "../Datatypes/DtFecha.h"

DtFecha ingresarFecha()
{
    int dia, mes, anio;
    do
    {
        cout << "Ingrese la fecha en formato dd mm aaaa (separados por espacios): ";
        cin >> dia >> mes >> anio;
    } while (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900);
    
    return DtFecha(dia, mes, anio);
}