#include "Armero.h"
#include "ArmeroInterno.h"
#include "PuntosDeBeneficio.h"
#include "Inventario.h"

Armero::Armero(Inventario& inventario,PuntosDeBeneficio& puntos) : 
armero_interno(ArmeroInterno(inventario,puntos)) {}

void Armero::empezar(){
    std::thread thread(armero_interno);
    this->thread = std::move(thread);    
}

Armero::~Armero(){
    if (thread.joinable()){
        thread.join();
    }
}
