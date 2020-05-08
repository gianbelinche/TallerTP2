#ifndef CLASE_HIERRO
#define CLASE_HIERRO
#include "Recurso.h"
class Inventario;

class Hierro : public Recurso {
public:
    Hierro(Hierro&& hierro) = delete;
    Hierro& operator=(Hierro&& hierro) = delete;

    void agregarAInventario(Inventario&& inventario) const override;
};

#endif