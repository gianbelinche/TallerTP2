#include "Trigo.h"
#include "Inventario.h"

void Trigo::agregarAInventario(Inventario&& inventario) const{
    inventario.agregarTrigo();
}