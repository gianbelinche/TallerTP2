#include "Carpintero.h"
#include "CarpinteroInterno.h"
#include "PuntosDeBeneficio.h"
#include "Inventario.h"

Carpintero::Carpintero(Inventario& inventario,PuntosDeBeneficio& puntos) : 
carpintero_interno(CarpinteroInterno(inventario,puntos)){}

void Carpintero::empezar(){
    std::thread thread(carpintero_interno);
    this->thread = std::move(thread);
}

Carpintero::~Carpintero(){
    if (thread.joinable()){
        thread.join();
    }
}
