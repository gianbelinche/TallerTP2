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
    //Obtiene los recursos necesarios desde el inventario
    //Y guarda los puntos de beneficio correspondientes
    //Se garantiza en ambos casos que será el único en acceder a dichos
    //objetos mientras dure la llamada a las respectivas funciones
    virtual void producir();
    void operator()();
    ~ProductorInterno() {}
};

#endif
