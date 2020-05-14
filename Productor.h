#ifndef CLASE_PRODUCTOR
#define CLASE_PRODUCTOR
#include <thread>
#include "Inventario.h"

class Productor {
protected:
    std::thread thread;
public:
    //Inicializa el thread del productor
    virtual void empezar() = 0;
    //Se queda esperando a que el thread finalice
    void terminar();
    ~Productor();
};

#endif
