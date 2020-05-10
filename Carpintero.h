#ifndef CLASE_CARPINTERO
#define CLASE_CARPINTERO
#include "Inventario.h"
#include "Productor.h"
#include "CarpinteroInterno.h"
#include "PuntosDeBeneficio.h"

class Carpintero : public Productor {
private:
    CarpinteroInterno carpintero_interno;    
public:
    Carpintero(Inventario&& inventario,PuntosDeBeneficio&& puntos);
    Carpintero(Carpintero& copia) = delete;
    Carpintero& operator=(Carpintero& copia) = delete;
    Carpintero(Carpintero&& carpintero) = default;
    Carpintero& operator=(Carpintero&& carpintero) = default;
    void empezar() override;
    virtual ~Carpintero();    
};
#endif