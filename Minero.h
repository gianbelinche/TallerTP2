#include "Recolector.h"

class Minero : public Recolector{
public:
    Minero(ColaBloqueante& cola, Inventario& inventario) :
    Recolector(cola,inventario) {}
    ~Minero() {}
};
