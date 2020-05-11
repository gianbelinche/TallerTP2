#ifndef CLASE_CARBON
#define CLASE_CARBON
#include "Recurso.h"
class Inventario;

class Carbon : public Recurso {
public:
    Carbon() {}
    Carbon(Carbon&& carbon) = delete;
    Carbon& operator=(Carbon&& carbon) = delete;

    virtual void agregarAInventario(Inventario&& inventario) const override;
    virtual ~Carbon() {}
};

#endif
