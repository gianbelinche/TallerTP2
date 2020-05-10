#ifndef CLASE_RECOLECTOR_INTERNO
#define CLASE_RECOLECTOR_INTERNO

#include "Inventario.h"
#include "ColaBloqueante.h"
#include <unistd.h>
#include "ColaEstaCerradaException.h"

class RecolectorInterno {
protected:
    ColaBloqueante& cola;
    Inventario& inventario;
public:
    RecolectorInterno(ColaBloqueante&& cola,Inventario&& inventario) :
    cola(cola), inventario(inventario) {}
    void recolectar();
    void operator()();
    
};

#endif