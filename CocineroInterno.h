#ifndef CLASE_COCINERO_INTERNO
#define CLASE_COCINERO_INTERNO
#include "ProductorInterno.h"
#include "Inventario.h"

class PuntosDeBeneficio;

class CocineroInterno : public ProductorInterno {
public:
    CocineroInterno(Inventario& inventario,PuntosDeBeneficio& puntos) :
    ProductorInterno(inventario, puntos) {}
    void producir() override;
    ~CocineroInterno() {}
};

#endif
