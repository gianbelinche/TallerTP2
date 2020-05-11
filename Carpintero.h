#ifndef CLASE_CARPINTERO
#define CLASE_CARPINTERO

#include "Productor.h"

class Inventario;
class CarpinteroInterno;
class PuntosDeBeneficio;

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
