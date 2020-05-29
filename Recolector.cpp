#include "Recolector.h"
#include "Inventario.h"
#include "ColaBloqueante.h"
#include <utility>

void Recolector::empezar(){
    std::thread thread(rec_interno);
    this->thread = std::move(thread);
}

void Recolector::terminar(){
    thread.join();
}

Recolector::~Recolector(){
    if (thread.joinable()){
        thread.join();
    }
}
