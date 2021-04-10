#ifndef DTBARCOPASAJEROS_H
#define DTBARCOPASAJEROS_H

#include "../Otros/TipoTamanio.h"
#include "DtBarco.h"

#include <string>

using namespace std;

class DtBarcoPasajeros : public DtBarco {
public:
    DtBarcoPasajeros();
    DtBarcoPasajeros(const string, const string, const int, const TipoTamanio);
    ~DtBarcoPasajeros();
    string getNombre() const;
    string getId() const;
    TipoTamanio getTamanio() const;
    int getCantPasajeros() const;
    int getCapacidad() const;
    int getCarga() const;
    static bool esDeEsteTipo(const DtBarco*);
    void mostrarInfo(ostream&);
private:
    string nombre;
    string id;
    int cantPasajeros;
    TipoTamanio tamanio;
};

#endif

