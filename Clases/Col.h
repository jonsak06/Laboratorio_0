#include "Puerto.h"
#include "Arribo.h"


class Col {
    public:
        Col();
        Col(const Col& orig);
        ~Col();
        Col(DtPuerto);
        Col(DtArribo);
        Col(DtBarco*);
        static DtPuerto datosPuertos[MAX_PUERTOS-1];
        static int ultimoDatavaluePuerto;
        static void SetUltomoDatavaluePuerto(int);
        static void coleccionarDatosPuertos(Puerto[]);
        static void listarPuertos();
};