#include "Cocinero.h"
#include "CocineroInterno.h"
#include "PuntosDeBeneficio.h"
#include "Inventario.h"

Cocinero::Cocinero(Inventario& inventario,PuntosDeBeneficio& puntos) : 
cocinero_interno(CocineroInterno(inventario,puntos)){}

void Cocinero::empezar(){
    std::thread thread(cocinero_interno);
    this->thread = std::move(thread);
}

Cocinero::~Cocinero(){
    if (thread.joinable()){
        thread.join();
    }
}
