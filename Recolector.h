#ifndef CLASE_RECOLECTOR
#define CLASE_RECOLECTOR

#include "Inventario.h"
#include "ColaBloqueante.h"
#include "RecolectorInterno.h"
#include <thread>

class Recolector {
protected:
    RecolectorInterno rec_interno;
    std::thread thread;
public:
    
    Recolector(ColaBloqueante&& cola,Inventario&& inventario) : rec_interno(std::move(cola),std::move(inventario)) {}
    Recolector(Recolector& copia) = delete;
    Recolector& operator=(Recolector& copia) = delete;
    void empezar();
    void terminar();
    ~Recolector();
};

#endif