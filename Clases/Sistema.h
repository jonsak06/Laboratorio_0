#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "../Datatypes/DtFecha.h"
#include "Puerto.h"

class Sistema {
    public:
        Sistema();
        ~Sistema();
        void agregarPuerto(string, string, DtFecha&);
        int obtenerPosicionUltimoPuerto();
        void agregarArribo(string, string, float);
        void setFechaHoy(DtFecha);
        DtFecha getFechaHoy() const;
        DtPuerto* listarPuertos();
        void agregarBarco(DtBarco&);
        static DtBarco** listarBarcos();
        int obtenerPosicionUltimoBarco();
    private:
        DtFecha fechaHoy;
};

#endif