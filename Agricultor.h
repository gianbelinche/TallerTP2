#include "Recolector.h"

class Agricultor : public Recolector{
public:
    Agricultor(ColaBloqueante& cola, Inventario& inventario) :
    Recolector(cola,inventario) {}

    ~Agricultor() {}
};
