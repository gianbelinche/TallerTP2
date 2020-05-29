#ifndef CLASE_RECOLECTOR
#define CLASE_RECOLECTOR

#include "RecolectorInterno.h"
#include <thread>
class Inventario;
class ColaBloqueante;

class Recolector {
protected:
    RecolectorInterno rec_interno;
    std::thread thread;
public:
    Recolector(ColaBloqueante& cola,Inventario& inventario) : 
    rec_interno(cola,inventario) {}
    Recolector(Recolector& copia) = delete;
    Recolector& operator=(Recolector& copia) = delete;
    Recolector(Recolector&& recolector) = default;
    Recolector& operator=(Recolector&& recolector) = default;
    //Inicializa el thread del recolector
    void empezar();
    //Se queda esperando a que el thread finalice
    void terminar();
    ~Recolector();
};

#endif
