#ifndef CLASE_COCINERO
#define CLASE_COCINERO

#include "Productor.h"

class Inventario;
class CocineroInterno;
class PuntosDeBeneficio;

class Cocinero : public Productor {
private:
    CocineroInterno cocinero_interno;     
public:
    Cocinero(Inventario& inventario,PuntosDeBeneficio& puntos);
    Cocinero(Cocinero& copia) = delete;
    Cocinero& operator=(Cocinero& copia) = delete;
    Cocinero(Cocinero&& cocinero) = default;
    Cocinero& operator=(Cocinero&& cocinero) = default;
    void empezar() override;    
    virtual ~Cocinero();
};
#endif
