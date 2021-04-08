#ifndef BARCO_H
#define BARCO_H

#include "../Datatypes/DtBarco.h"

#include <string>

using namespace std;

const int MAX_BARCOS = 50;

class Barco {
    public:
        Barco();
        Barco(const Barco&);
        virtual ~Barco();
        Barco(string, string);
        Barco(DtBarco&);
        void setId(string);
        string getId() const;
        void setNombre(string);
        string getNombre() const;
        virtual void arribar(float) = 0;
        virtual int getCapacidad() const = 0;
        virtual int getCarga() const = 0;
        virtual int getCantPasajeros() const = 0;
        virtual TipoTamanio getTamanio() const = 0;
        static Barco* barcos[MAX_BARCOS-1];
        static int ultimoBarco;
        static bool existeBarco(string);
        static int getPosicionBarco(string);
    private:
        string nombre;
        string id;
};

#endif
