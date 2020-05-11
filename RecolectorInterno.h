#ifndef CLASE_RECOLECTOR_INTERNO
#define CLASE_RECOLECTOR_INTERNO

#include <unistd.h>

class Inventario;
class ColaBloqueante;

class RecolectorInterno {
protected:
    ColaBloqueante& cola;
    Inventario& inventario;
public:
    RecolectorInterno(ColaBloqueante&& cola,Inventario&& inventario) :
    cola(cola), inventario(inventario) {}
    void recolectar();
    void operator()();
    ~RecolectorInterno() {}
};

#endif
