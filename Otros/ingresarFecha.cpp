#include "../Datatypes/DtFecha.h"

DtFecha ingresarFecha()
{
    int dia, mes, anio;
    cout << "Ingrese la fecha de hoy en formato dd mm aaaa (separados por espacios): ";
    cin >> dia >> mes >> anio;
    return DtFecha(dia, mes, anio);
}