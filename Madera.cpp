#include "Madera.h"
#include "Inventario.h"

void Madera::agregarAInventario(Inventario&& inventario) const{
    inventario.agregarMadera();
}
