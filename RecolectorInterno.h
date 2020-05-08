#ifndef CLASE_RECOLECTOR_INTERNO
#define CLASE_RECOLECTOR_INTERNO

#include "Inventario.h"
#include "ColaBloqueante.h"
#include <thread>

class RecolectorInterno {
protected:
    ColaBloqueante& cola;
    Inventario& inventario;
public:
    void operator()(){
        const Recurso* r = cola.desencolar();
        r->agregarAInventario(std::move(inventario));
    }  
    RecolectorInterno(ColaBloqueante&& cola,Inventario&& inventario) :
    cola(cola), inventario(inventario) {}
    
};

#endif