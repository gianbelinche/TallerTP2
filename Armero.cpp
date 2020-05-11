#include "Armero.h"
#include "ArmeroInterno.h"

Armero::Armero(Inventario&& inventario,PuntosDeBeneficio&& puntos) : 
armero_interno(ArmeroInterno(std::move(inventario),std::move(puntos))) {}

void Armero::empezar(){
    std::thread thread(armero_interno);
    this->thread = std::move(thread);    
}

Armero::~Armero(){
    if (thread.joinable()){
        thread.join();
    }
}
