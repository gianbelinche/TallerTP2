#ifndef CLASE_PRODUCTOR
#define CLASE_PRODUCTOR
#include <thread>
#include "Inventario.h"
//#include "ProductorInterno.h"


class Productor {
protected:
    std::thread thread;
public:
    virtual void empezar() = 0;
    void terminar();
    ~Productor();
};

#endif
