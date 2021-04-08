#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "../Datatypes/DtFecha.h"
#include "Puerto.h"

class Sistema {
    public:
        Sistema();
        ~Sistema();
        DtFecha fechaHoy;
        void agregarPuerto(string, string, DtFecha&);
        int obtenerPosicionUltimoPuerto();
        void agregarArribo(string, string, float);
        DtPuerto* listarPuertos();
        void agregarBarco(DtBarco&);
        static DtBarco** listarBarcos();
        int obtenerPosicionUltimoBarco();
};

#endif