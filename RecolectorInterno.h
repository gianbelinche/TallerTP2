#ifndef CLASE_RECOLECTOR_INTERNO
#define CLASE_RECOLECTOR_INTERNO

#include "Inventario.h"
#include "ColaBloqueante.h"
#include <thread>
#include <unistd.h>
#include "ColaEstaCerradaException.h"

class RecolectorInterno {
protected:
    ColaBloqueante& cola;
    Inventario& inventario;
public:
    void operator()(){
        while (true){
            try{
                const Recurso* r = cola.desencolar();
                usleep(50000);
                r->agregarAInventario(std::move(inventario));
            } catch (ColaEstaCerradaException& e) {
                break;
            }
        }
    }  
    RecolectorInterno(ColaBloqueante&& cola,Inventario&& inventario) :
    cola(cola), inventario(inventario) {}
    
};

#endif