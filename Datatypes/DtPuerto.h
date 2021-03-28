#ifndef DTPUERTO_H
#define DTPUERTO_H

#include "DtFecha.h"

#include <string>

using namespace std;

class DtPuerto {
public:
    DtPuerto();
    DtPuerto(const DtPuerto& orig);
    virtual ~DtPuerto();
    DtPuerto(string, string, DtFecha,int);
    int GetCantArribos() const;
    DtFecha GetFechaCreacion() const;
    string GetNombre() const;
    string GetId() const;
private:
    string id;
    string nombre;
    DtFecha fechaCreacion;
    int cantArribos;
};

#endif

