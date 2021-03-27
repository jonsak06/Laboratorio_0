#ifndef DTBARCO_H
#define DTBARCO_H

#include <string>

using namespace std;

class DtBarco {
public:
    DtBarco();
    virtual ~DtBarco();
    DtBarco(string, string);
    string GetId() const;
    string GetNombre() const;
private:
    string nombre;
    string id;
};

#endif

