#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>

using namespace std;

class DtFecha {
public:
    DtFecha();
    DtFecha(const int, const int, const int);
    ~DtFecha();
    int getAnio() const;
    int getMes() const;
    int getDia() const;
private:
    int dia;
    int mes;
    int anio;
};

#endif

