#include "RecolectorInterno.h"
#include "Inventario.h"
#include "ColaBloqueante.h"
#include "ColaEstaCerradaException.h"
#define TIEMPO_ESPERA 50000

void RecolectorInterno::recolectar(){
    while (true){
        try{
            const char r = cola.desencolar();
            usleep(TIEMPO_ESPERA);
            inventario.agregarRecurso(r);
        } catch(ColaEstaCerradaException& e) {
            break;
        }
    }
}

void RecolectorInterno::operator()(){
    this->recolectar();
}
