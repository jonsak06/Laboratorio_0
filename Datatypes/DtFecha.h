#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>

using namespace std;

class DtFecha {
public:
    DtFecha();
    ~DtFecha();
    DtFecha(int, int, int);
    int GetAnio() const;
    int GetMes() const;
    int GetDia() const;
private:
    int dia;
    int mes;
    int anio;
};

#endif

