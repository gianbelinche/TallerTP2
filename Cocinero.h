#ifndef CLASE_COCINERO
#define CLASE_COCINERO
#include "Inventario.h"
#include "Productor.h"
#include "CocineroInterno.h"
#include "PuntosDeBeneficio.h"

class Cocinero : public Productor {
private:
    CocineroInterno cocinero_interno;     
public:
    Cocinero(Inventario&& inventario,PuntosDeBeneficio&& puntos);
    Cocinero(Cocinero& copia) = delete;
    Cocinero& operator=(Cocinero& copia) = delete;
    Cocinero(Cocinero&& cocinero) = default;
    Cocinero& operator=(Cocinero&& cocinero) = default;
    void empezar() override;    
    virtual ~Cocinero();
};
#endif