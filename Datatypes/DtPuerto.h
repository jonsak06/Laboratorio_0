#ifndef DTPUERTO_H
#define DTPUERTO_H

#include "DtFecha.h"

#include <string>

using namespace std;

class DtPuerto {
public:
    DtPuerto();
    ~DtPuerto();
    DtPuerto(string, string, DtFecha,int);
    int getCantArribos() const;
    DtFecha getFechaCreacion() const;
    string getNombre() const;
    string getId() const;
private:
    string id;
    string nombre;
    DtFecha fechaCreacion;
    int cantArribos;
};

#endif

