#ifndef CLASE_LENADOR
#define CLASE_LENADOR

#include "Recolector.h"

class Lenador : public Recolector{
public:
    Lenador(ColaBloqueante& cola, Inventario& inventario) :
    Recolector(cola,inventario) {}
    ~Lenador() {}
};
#endif
