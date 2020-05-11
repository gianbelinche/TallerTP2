#include "CocineroInterno.h"
#include "Inventario.h"
#include <unistd.h>
#define TIEMPO_ESPERA 60000

void CocineroInterno::producir(){
    while (true){
        try{
            inventario.extraer(this);
            usleep(TIEMPO_ESPERA);
            puntos.aumentarPuntos(5);
        } catch(InventarioEstaCerradoException& e){
            break;
        }
    }
}
