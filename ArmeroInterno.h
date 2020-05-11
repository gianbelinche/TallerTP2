#ifndef CLASE_ARMERO_INTERNO
#define CLASE_ARMERO_INTERNO
#include "ProductorInterno.h"
#include "Inventario.h"
#include "PuntosDeBeneficio.h"

class ArmeroInterno : public ProductorInterno {
public:
    ArmeroInterno(Inventario&& inventario,PuntosDeBeneficio&& puntos) : 
    ProductorInterno(std::move(inventario),std::move(puntos)) {}
    void producir() override;
    ~ArmeroInterno() {}
};

#endif
