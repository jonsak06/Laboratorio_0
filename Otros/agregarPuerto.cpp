#include "../Clases/Puerto.h"

const int MAX_PUERTOS = 49;

Puerto puertos[MAX_PUERTOS];
int ultimoPuerto = 0;
void agregarPuerto(string, string, DtFecha);

void agregarPuerto(string nombre, string id, DtFecha fechaCreacion)
{
    for(int i=0; i<ultimoPuerto;i++)
    {
        if(id==puertos[i].GetId()){
            throw invalid_argument("El puerto ya existe");
            break;
        }
    }
    puertos[ultimoPuerto] = Puerto(nombre, id, fechaCreacion);
    ultimoPuerto++;
}