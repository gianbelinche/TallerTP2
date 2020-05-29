#ifndef CLASE_TRIGO
#define CLASE_TRIGO
#include "Recurso.h"
class Inventario;

class Trigo : public Recurso{
public:
    Trigo() {}
    Trigo(Trigo&& trigo) = delete;
    Trigo& operator=(Trigo&& trigo) = delete;

    virtual void agregarAInventario(Inventario& inventario) const override;
    virtual ~Trigo() {}
};

#endif
