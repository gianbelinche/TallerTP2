#ifndef CLASE_RECURSO
#define CLASE_RECURSO
#include <iostream>
//#include "Inventario.h"
class Inventario;
class Recurso{
private:    
public:
    Recurso() {}
    Recurso(const Recurso& copia) = default;
    Recurso& operator=(Recurso& copia);
    Recurso(Recurso&& recurso);
    Recurso& operator=(Recurso&& recurso);

    virtual void agregarAInventario(Inventario&& inventario) const {}
};

#endif