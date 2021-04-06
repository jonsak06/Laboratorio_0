#ifndef BARCO_H
#define BARCO_H

#include "../Datatypes/DtBarco.h"
#include "../Otros/TipoBarco.h"

#include <string>

using namespace std;

const int MAX_BARCOS = 50;

class Barco {
    public:
        Barco();
        Barco(const Barco& orig);
        virtual ~Barco();
        Barco(string, string);
        Barco(DtBarco&);
        void setId(string id);
        string getId() const;
        void setNombre(string nombre);
        string getNombre() const;
        virtual void arribar(float) = 0; /*Barco pasa a ser abstracta, no se pueden crear instancias directas, solo se puede 
                                        trabajar con punteros o referencia*/
        virtual int getCapacidad() const = 0;
        virtual int getCarga() const = 0;
        virtual int getCantPasajeros() const = 0;
        virtual TipoTamanio getTamanio() const = 0;
        static Barco* barcos[MAX_BARCOS-1];
        static int ultimoBarco;
        static bool existeBarco(string);
        static int getPosicionBarco(string);
        static void agregarBarco(DtBarco& barco);
        virtual TipoBarco mostrarTipoBarco() = 0;
    private:
        string nombre;
        string id;
};

#endif
