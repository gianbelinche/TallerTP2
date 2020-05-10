#ifndef CLASE_PRODUCTOR
#define CLASE_PRODUCTOR
#include <thread>
#include "Inventario.h"
//#include "ProductorInterno.h"


class Productor {
protected:
    //ProductorInterno productor_interno;
    std::thread thread;
public:
    
    //Productor(ProductorInterno&& productor) : productor_interno(productor) {}
    //Productor(Productor& copia) = delete;
    //Productor& operator=(Productor& copia) = delete;
    //Productor(Productor&& productor) = default;
    //Productor& operator=(Productor&& productor) = default;
    virtual void empezar() = 0;
    void terminar();
    ~Productor();
};

#endif