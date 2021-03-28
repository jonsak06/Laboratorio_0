#ifndef COLBARCO_H
#define COLBARCO_H

#include "../Datatypes/DtBarco.h"

#include <string>
#include <iostream>

using namespace std;

class ColBarco {
public:
    ColBarco();
    ColBarco(const ColBarco& orig);
    virtual ~ColBarco();
    void agregarBarco(DtBarco&);
    //DtBarco* listarBarcos();
private:
    DtBarco arregloBarco[29]; // 29 sería la cantidad de MAX_BARCOS, osea la cantidad de maxima de barcos que tenemos en esta realidad planteada
    unsigned tope;
};

#endif
