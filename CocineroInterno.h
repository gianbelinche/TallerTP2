#ifndef CLASE_COCINERO_INTERNO
#define CLASE_COCINERO_INTERNO
#include "ProductorInterno.h"
#include "Inventario.h"
#include "PuntosDeBeneficio.h"
class Inventario;

class CocineroInterno : public ProductorInterno {
public:
    CocineroInterno(Inventario&& inventario,PuntosDeBeneficio&& puntos) :
    ProductorInterno(std::move(inventario), std::move(puntos)) {}
    void producir() override;
};

#endif
