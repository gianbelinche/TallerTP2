#ifndef CLASE_PRODUCTOR_INTERNO
#define CLASE_PRODUCTOR_INTERNO

class PuntosDeBeneficio;
class Inventario;
class ProductorInterno {
protected:
    Inventario& inventario;
    PuntosDeBeneficio& puntos;    
public:
    ProductorInterno(Inventario&& inventario,PuntosDeBeneficio&& puntos) :
    inventario(inventario), puntos(puntos) {}
    virtual void producir();
    void operator()();
};

#endif