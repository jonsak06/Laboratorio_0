#ifndef DTPUERTO_H
#define DTPUERTO_H

#include "DtFecha.h"

#include <string>

using namespace std;

class DtPuerto {
public:
    DtPuerto();
    ~DtPuerto();
    DtPuerto(const string, const string, const DtFecha, const int);
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

