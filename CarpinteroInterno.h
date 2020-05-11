#ifndef CLASE_CARPINTERO_INTERNO
#define CLASE_CARPINTERO_INTERNO
#include "ProductorInterno.h"
#include "Inventario.h"

class PuntosDeBeneficio;

class CarpinteroInterno : public ProductorInterno {
public:
    CarpinteroInterno(Inventario&& inventario,PuntosDeBeneficio&& puntos) : 
    ProductorInterno(std::move(inventario),std::move(puntos)) {}
    void producir() override;
    ~CarpinteroInterno() {}
};


#endif
