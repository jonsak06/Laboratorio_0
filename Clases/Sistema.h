#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtPuerto.h"
#include "../Datatypes/DtBarco.h"
#include "../Datatypes/DtArribo.h"
#include "Puerto.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"

class Sistema {
    public:
        Sistema();
        ~Sistema();
        static DtFecha fechaHoy;
        void agregarPuerto(string, string, DtFecha&);
        int obtenerPosicionUltimoPuerto();
        void agregarArribo(string, string, float);
        DtPuerto* listarPuertos();
        void agregarBarco(DtBarco&);
        DtBarco** listarBarcos();
        int obtenerPosicionUltimoBarco();
        DtArribo* obtenerInfoArribosEnPuerto(string);
        int obtenerPosicionUltimoArribo(string);
        void eliminarArribos(string, const DtFecha&);
};

#endif