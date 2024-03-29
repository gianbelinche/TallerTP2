#ifndef CLASE_ARMERO_INTERNO
#define CLASE_ARMERO_INTERNO
#include "ProductorInterno.h"
#include "Inventario.h"

class PuntosDeBeneficio;

class ArmeroInterno : public ProductorInterno {
public:
    ArmeroInterno(Inventario& inventario,PuntosDeBeneficio& puntos) : 
    ProductorInterno(inventario,puntos) {}
    void producir() override;
    ~ArmeroInterno() {}
};

#endif
