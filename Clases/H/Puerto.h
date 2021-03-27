#ifndef PUERTO_H
#define PUERTO_H

#include "../../DataType/H/DtFecha.h"
#include "../../DataType/H/DtPuerto.h"
#include <string>

using namespace std;

class Puerto {
public:
    Puerto();
    Puerto(const Puerto& orig);
    virtual ~Puerto();
    Puerto(string, string, DtFecha);
    Puerto(DtPuerto);
    void SetFechaCreacion(DtFecha fechaCreacion);
    DtFecha GetFechaCreacion() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetId(string id);
    string GetId() const;
private:
    string id;
    string nombre;
    DtFecha fechaCreacion;
};

#endif

