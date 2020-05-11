#include "Recolector.h"

class Minero : public Recolector{
public:
    Minero(ColaBloqueante&& cola, Inventario&& inventario) :
    Recolector(std::move(cola),std::move(inventario)) {}
};
