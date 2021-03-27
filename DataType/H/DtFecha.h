#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha {
public:
    DtFecha();
    virtual ~DtFecha();
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

