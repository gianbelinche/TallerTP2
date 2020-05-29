#ifndef CLASE_MADERA
#define CLASE_MADERA
#include "Recurso.h"
class Inventario;

class Madera : public Recurso {
public:
    Madera() {}
    Madera(Madera&& madera) = delete;
    Madera& operator=(Madera&& madera) = delete;

    virtual void agregarAInventario(Inventario& inventario) const override;
    virtual ~Madera() {}
};

#endif
