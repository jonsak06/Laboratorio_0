#ifndef PUERTO_H
#define PUERTO_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtPuerto.h"
#include "../Datatypes/DtArribo.h"
#include "Arribo.h"
#include "BarcoPesquero.h"
#include "BarcoPasajeros.h"
#include <string>

using namespace std;

const int MAX_PUERTOS = 50;

class Puerto {
public:
    Puerto();
    Puerto(const Puerto&);
    ~Puerto();
    Puerto(string, string, DtFecha);
    Puerto(DtPuerto);
    void setFechaCreacion(DtFecha);
    DtFecha getFechaCreacion() const;
    void setNombre(string);
    string getNombre() const;
    void setId(string);
    string getId() const;
    static Puerto puertos[MAX_PUERTOS-1];
    static int ultimoPuerto;
    static bool existePuerto(string);
    int ultimoArribo = 0;
    void setArribo(Arribo);
    Arribo* getArribos();
    static int obtenerPosicionPuerto(string);
private:
    string id;
    string nombre;
    DtFecha fechaCreacion;
    Arribo arribos[29];
};


#endif

