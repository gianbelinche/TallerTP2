#include "Carbon.h"
#include "Inventario.h"

void Carbon::agregarAInventario(Inventario&& inventario) const{
    inventario.agregarCarbon();
}