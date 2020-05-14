#ifndef CLASE_RECOLECTOR_INTERNO
#define CLASE_RECOLECTOR_INTERNO

#include <unistd.h>

class Inventario;
class ColaBloqueante;

class RecolectorInterno {
protected:
    ColaBloqueante& cola;
    Inventario& inventario;
public:
    RecolectorInterno(ColaBloqueante&& cola,Inventario&& inventario) :
    cola(cola), inventario(inventario) {}
    //Desencola un recurso de la colaBloqueante y lo almacena en el inventario
    //Se garantiza en ambos casos que será el único en acceder a dichos
    //objetos mientras dure la llamada a las respectivas funciones
    void recolectar();
    void operator()();
    ~RecolectorInterno() {}
};

#endif
