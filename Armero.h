#ifndef CLASE_ARMERO
#define CLASE_ARMERO
#include "Inventario.h"
#include "Productor.h"
#include "ArmeroInterno.h"
#include "PuntosDeBeneficio.h"

class Armero : public Productor {
private:
    ArmeroInterno armero_interno;
public:
    Armero(Inventario&& inventario,PuntosDeBeneficio&& puntos);
    Armero(Armero& copia) = delete;
    Armero& operator=(Armero& copia) = delete;
    Armero(Armero&& armero) = default;
    Armero& operator=(Armero&& armero) = default;
    void empezar() override;
    virtual ~Armero();    
};
#endif
