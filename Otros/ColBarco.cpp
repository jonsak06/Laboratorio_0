#include "ColBarco.h"


ColBarco::ColBarco(const ColBarco& orig) {
}

ColBarco::~ColBarco() {
}

ColBarco::ColBarco() {
    this->tope=0;
}

void ColBarco::agregarBarco(DtBarco& barco) {
    for(int x = 0; x < 29; x++){
        if(this->arregloBarco[x].GetId().empty() && this->arregloBarco[x].GetNombre().empty()){
            
                for(int y = 0; y < 29; y++){
                    if(this->arregloBarco[y].GetId() == barco.GetId()){
                        throw invalid_argument("Este id de barco ya existe.");
                    }else{
                        this->arregloBarco[x] = barco;
                    }
                }

        }
    }
}

/*DtBarco* ColBarco::listarBarcos() {
    return this->arregloBarco;
}*/



