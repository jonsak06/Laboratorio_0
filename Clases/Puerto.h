#ifndef PUERTO_H
#define PUERTO_H

#include "../Datatypes/DtFecha.h"
#include "../Datatypes/DtPuerto.h"
#include "../Datatypes/DtArribo.h"
#include "Arribo.h"
#include "BarcoPesquero.h"
#include "BarcoPasajeros.h"
#include <vector>
#include <string>

using namespace std;

const int MAX_PUERTOS = 50;

class Puerto {
public:
    Puerto();
    Puerto(const Puerto& orig);
    ~Puerto();
    Puerto(string, string, DtFecha);
    Puerto(DtPuerto);
    void SetFechaCreacion(DtFecha fechaCreacion);
    DtFecha GetFechaCreacion() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetId(string id);
    string GetId() const;
    static Puerto puertos[MAX_PUERTOS-1];
    static void agregarPuerto(string, string, DtFecha&);
    static int ultimoPuerto;
    static bool existePuerto(string);
    int ultimoArribo;
    void setArribo(Arribo);
    Arribo* getArribos();
    static int getPosicionPuerto(string);
    static void agregarArribo(string, string, float);
private:
    string id;
    string nombre;
    DtFecha fechaCreacion;
    Arribo arribos[29];
};


#endif

