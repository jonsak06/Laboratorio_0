#ifndef BARCO_H
#define BARCO_H

#include "../Datatypes/DtBarco.h"

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
        void SetId(string id);
        string GetId() const;
        void SetNombre(string nombre);
        string GetNombre() const;
        virtual void arribar(float) = 0; /*Barco pasa a ser abstracta, no se pueden crear instancias directas, solo se puede 
                                        trabajar con punteros o referencia*/
        static Barco* barcos[MAX_BARCOS-1];
        static int ultimoBarco;
        static bool existeBarco(string);
        static int getPosicionBarco(string);
        static void agregarBarco(DtBarco& barco);
    private:
        string nombre;
        string id;
};

#endif
