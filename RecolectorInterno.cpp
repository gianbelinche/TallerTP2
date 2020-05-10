#include "RecolectorInterno.h"

void RecolectorInterno::recolectar(){
    while (true){
        try{
            const Recurso* r = cola.desencolar();
            usleep(50000);
            r->agregarAInventario(std::move(inventario));
        } catch (ColaEstaCerradaException& e) {
            break;
        }
    }
}

void RecolectorInterno::operator()(){
    this->recolectar();
}